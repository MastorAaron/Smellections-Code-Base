#ifndef ABSTRACT_COLLECTION_H
#define ABSTRACT_COLLECTION_H
#include "Collection.h"
class AbstractCollection : public Collection 
{
public: 
	virtual ~AbstractCollection() {}
	void addAll(AbstractCollection& c);
	virtual void add(std::string key, std::string value);
	virtual void add(std::string element) = 0;
};
#endif // ABSTRACT_COLLECTION_H