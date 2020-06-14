#pragma once
#include <unordered_map>


/**
 * @brief We are using a map to determine which textures are created
 * -> Key = hashed string
 * -> Val = texture*
 */
template<typename T>
class BaseLoader
{
protected:
	BaseLoader();
public:
	virtual ~BaseLoader();
	BaseLoader(const BaseLoader& other) = delete;
	BaseLoader(BaseLoader&& other) noexcept = delete;
	BaseLoader& operator=(const BaseLoader& other) = delete;
	BaseLoader& operator=(BaseLoader&& other) noexcept = delete;

	void SetDataPath(const std::string& rootPath) { m_DataPath = rootPath; };
	T* Load(const std::string& file);
	void UnLoad(const std::string& file);

protected:
	/**
	 * @brief Gets called when the content is not found in the map of references to those content types.
	 */
	virtual T* LoadContent(const std::string& path) = 0;
	
	std::unordered_map<size_t, T*> m_References;
private:	
	std::string m_DataPath;
};

template <typename T>
BaseLoader<T>::BaseLoader()
	:m_DataPath("Data/")
{
}

template <typename T>
BaseLoader<T>::~BaseLoader()
{
	for (std::pair<size_t, T*> resource : m_References)
	{
		delete resource.second;
	}
}

template <typename T>
T* BaseLoader<T>::Load(const std::string& file)
{
	size_t id = std::hash<std::string>()(file);

	if (m_References.find(id) == m_References.end())
	{
		T* pContent = LoadContent(m_DataPath + file);
		if (!pContent)
			return nullptr;
		m_References[id] = pContent;
	}
	return m_References[id];
}

template <typename T>
void BaseLoader<T>::UnLoad(const std::string& file)
{
	size_t id = std::hash<std::string>()(file);
	if (m_References.find(id) != m_References.end())
	{
		delete m_References[id]; //Deleting reference
		m_References.erase(id); //
	}
}
