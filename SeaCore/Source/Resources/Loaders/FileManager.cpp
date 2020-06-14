#include "SeaCore_pch.h"
#include "FileManager.h"


FileManager::FileManager()
	: m_OpenMode(std::ios::out | std::ios::in)
{
}

void FileManager::SetOpenMode(const std::ios_base::openmode openMode)
{
	m_OpenMode = openMode;
}

std::basic_fstream<char>* FileManager::LoadContent(const std::string& path)
{
	std::fstream* file = new std::fstream(path, m_OpenMode);
	if (file->is_open())
		return file;

	delete file;
	return nullptr;
}
