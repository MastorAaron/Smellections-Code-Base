#ifndef ABSTRACT_COLLECTION_H
#define ABSTRACT_COLLECTION_H
#include "Collection.h"

using namespace std;
class AbstractCollection : public Collection{
	public:
		virtual ~AbstractCollection() {};
		void addAll(AbstractCollection& c){};
		virtual void add(string key, string value){};
		virtual void add(string element) = 0;
	};
#endif // ABSTRACT_COLLECTION_H