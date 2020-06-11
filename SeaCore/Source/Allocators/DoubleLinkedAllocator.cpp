#include "SeaCore_pch.h"
#include "DoubleLinkedAllocator.h"

#include <stdexcept>

DoubleLinkedAllocator::DoubleLinkedAllocator(size_t sizeOfBytes)
	: MemoryAllocator()
	, size((sizeOfBytes + sizeof(Header) + sizeof(Block) - 1) / sizeof(Block))
	, head(new Block[size + 1])
{
	//printf("Size of Block = %i", static_cast<int>(sizeof(Block)));
	//printf("Size void * = %i", static_cast<int>(Block::Size));
	//printf("Size void * = %i \n", static_cast<int>(sizeof(void *)));
	
	Block* nextBlock = reinterpret_cast<Block*>(head + 1);
	head->status = Status::Reserved;
	head->count = 0;
	head->link.next = nextBlock;
	head->link.prev = nextBlock;
	
	nextBlock->count = size;
	nextBlock->link.next = head;
	nextBlock->link.prev = head;
}

DoubleLinkedAllocator::~DoubleLinkedAllocator()
{
	delete[] head;
}

void* DoubleLinkedAllocator::Acquire(const size_t nbBytes)
{
	//Amount of bytes + header(count)
	//Because of an integer division you add just less then a block
//This way you always have the right amount of blocks
	const size_t nbBlocks = (nbBytes + sizeof(Header) + sizeof(Block) - 1) / sizeof(Block);
	
	// Iterate over all nodes in free list

	
	Block* firstBlock = head;
	Block* secondBlock = head->link.next;
	while (secondBlock->count < nbBlocks)
	{
		//Check if mergeable
		Block* freeBlock = secondBlock + secondBlock->count;
		if (freeBlock->status == Status::Free)
		{
			secondBlock->count += freeBlock->count;
			Unlink(*freeBlock);
			continue;
		}

		firstBlock = secondBlock;
		secondBlock = secondBlock->link.next;

		if (secondBlock == head)
		{
			throw std::overflow_error("Requested too many bytes of allocator");
		}
	}
	
	Block* blockReserved = secondBlock;

	// Chop off an area sized as required and add the remaining to the free area list
	if (blockReserved->count != nbBlocks)
	{
		secondBlock += nbBlocks;
		secondBlock->status = Status::Free;
		secondBlock->count = blockReserved->count - nbBlocks;	
		blockReserved->count = nbBlocks;
		InsertAfter(*firstBlock, *secondBlock);
	}
	Unlink(*blockReserved);
	// Set status flag
	blockReserved->status = Status::Reserved;

	return blockReserved->data;
}

void DoubleLinkedAllocator::Release(void* pointerToBuffer)
{
	Block* block = reinterpret_cast<Block*>(reinterpret_cast<Header*>(pointerToBuffer) - 1);
	InsertAfter(*head, *block);
	block->status = Status::Free;
}

const DoubleLinkedAllocator::Block* DoubleLinkedAllocator::GetHead() const
{
	return head;
}

size_t DoubleLinkedAllocator::GetSize() const
{
	return size;
}

void DoubleLinkedAllocator::InsertAfter(Block& firstBlock, Block& secondBlock)
{
	secondBlock.link.next = firstBlock.link.next;
	secondBlock.link.prev = &firstBlock;
	
	firstBlock.link.next = &secondBlock;
	secondBlock.link.next->link.prev = &secondBlock;
}

void DoubleLinkedAllocator::Unlink(Block& block)
{
	block.link.next->link.prev = block.link.prev;
	block.link.prev->link.next = block.link.next;
}
