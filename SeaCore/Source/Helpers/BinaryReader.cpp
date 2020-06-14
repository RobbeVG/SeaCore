#include "SeaCore_pch.h"
#include "BinaryReader.h"

BinaryReader::BinaryReader()
	: m_pFile(nullptr)
{
}

int BinaryReader::GetReaderPosition() const
{
	if (m_pFile)
		return int(m_pFile->tellg());
	return -1;
}

bool BinaryReader::SetReaderPosition(const int pos) const
{
	if (m_pFile)
	{
		m_pFile->seekg(pos);
		return true;
	}
	return false;
}

bool BinaryReader::MoveReaderPosition(const int offset) const
{
	const auto pos = GetReaderPosition();
	if (pos >= 0)
		return SetReaderPosition(pos + offset);

	return false;
}
