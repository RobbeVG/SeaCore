#pragma once
#include "BaseLoader.h"
#include <fstream>

class FileManager : public BaseLoader<std::fstream>
{
public:
	FileManager();

	void SetOpenMode(std::ios_base::openmode openMode = std::ios::out | std::ios::in);
protected:
	std::basic_fstream<char>* LoadContent(const std::string& path) override;

	std::ios_base::openmode m_OpenMode;
};

