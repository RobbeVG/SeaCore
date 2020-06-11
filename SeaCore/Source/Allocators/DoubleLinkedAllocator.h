#pragma once
#include <limits>
#include "MemoryAllocator.h"

using namespace dae;

class DoubleLinkedAllocator : public MemoryAllocator
{
public:
#pragma region Stucts
	enum class Status : size_t { Free, Reserved };
	struct Header
	{
		Status status : 1;
		size_t count : std::numeric_limits<size_t>::digits - 1;
	};
	//Header is either 4 bytes(x86) or 8 bytes(x64)
	
	struct Block : Header
	{
		//Why enum ?
		enum { Size = (sizeof(void *) * 4)};
		//x86 -> void* = 4 bytes ; x64 -> void* = 8 bytes
		//Which means 
		struct Links
		{
			Block* next;
			Block* prev;
		};
		union
		{
			Links link;
			char data[Size - sizeof(Header)];
		};
	};
#pragma endregion 
	explicit DoubleLinkedAllocator(size_t sizeOfBytes);
	~DoubleLinkedAllocator();

	void* Acquire(size_t nbBytes) override;
	void Release(void* pointerToBuffer) override;

	const Block* GetHead() const;
	size_t GetSize() const;

private:
	static void InsertAfter(Block& firstBlock, Block& secondBlock);
	static void Unlink(Block& block);

	size_t size;
	Block* head;
};
