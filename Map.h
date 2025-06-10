#define MAP_H
#include "AbstractCollection.h"
class Map : public AbstractCollection 
{
public:
	Map();
	virtual ~Map();
	bool isEmpty();
	void add(std::string element);
	void add(std::string key, std::string value);
	int getSize();
	bool remove(std::string key);
	bool contains(std::string value);
	bool containsKey(std::string key);
	std::string get(std::string key);
	int getCapacity();
	void setReadOnly(bool b);
	std::string* m_keys;
	std::string* m_values;
private:
	enum {INITIAL_CAPACITY = 10};
	int m_capacity;
	int m_size;
	int m_indexWhereKeyFound;
	bool m_readOnly;
};
#endif // MAP_H
