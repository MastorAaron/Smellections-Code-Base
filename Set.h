#ifndef SET_H
#define SET_H
#include "AbstractSet.h"
#include "List.h"
#include <string>
class Set : public AbstractSet 
{
public:
	Set();
	virtual ~Set();
	bool isEmpty();
	void add(std::string element);
	bool contains(std::string element);
	int getSize();
	bool remove(std::string element);
	std::string getElementAt(int index);
	void addAll(List& l);
	int getCapacity();
	void setReadOnly(bool b);
private:
	enum {INITIAL_CAPACITY = 10};
	int m_capacity;
	std::string* m_elements;
	int m_size;
	bool m_readOnly;
};
#endif // SET_H