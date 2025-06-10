#ifndef LIST_H
#define LIST_H
#include "AbstractList.h"
#include <string>
class List : public AbstractList 
{
public:
	List();
	virtual ~List();
	bool isEmpty();
	void add(std::string element);
	bool contains(std::string element);
	int getSize();
	bool remove(std::string element);
	std::string get(int i);
	int getCapacity();
	void set(int i, std::string value);
	void setReadOnly(bool b);
private:
	friend class ListTest;
	enum {INITIAL_CAPACITY = 10};
	int m_capacity;
	std::string* m_elements;
	int m_size;
	bool m_readOnly;
};
#endif // LIST_H