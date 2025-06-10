#ifndef COLLECTION_H
#define COLLECTION_H
#include <string>
class Collection 
{
public:
	virtual ~Collection() {}
	virtual bool isEmpty() = 0;
	virtual void add(std::string element) = 0;
	virtual bool remove(std::string element) = 0;
	virtual bool contains(std::string element) = 0;
	virtual int getSize() = 0;
};
#endif // COLLECTION_H