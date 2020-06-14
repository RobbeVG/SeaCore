#pragma once

class BinaryReader
{
public:
	BinaryReader();
	~BinaryReader() = default; // No need to delete file! Is managed by files manager

	BinaryReader(const BinaryReader& yRef) = delete;
	BinaryReader& operator=(const BinaryReader& yRef) = delete;

	template<class T>
	T Read()
	{
		if (m_pFile == nullptr)
			return T();

		T value;
		m_pFile->read((char*)&value, sizeof(T));
		return value;
	}

	int GetReaderPosition() const;
	bool SetReaderPosition(int pos) const;
	bool MoveReaderPosition(int offset) const;

	void SetStream(std::fstream* fsteam) { m_pFile = fsteam; };
	
private:	
	std::fstream* m_pFile;
};

