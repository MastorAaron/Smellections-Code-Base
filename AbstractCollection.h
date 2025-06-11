#ifndef ABSTRACT_COLLECTION_H
#define ABSTRACT_COLLECTION_H

#include "List.h"
#include "Map.h"
#include "Set.h"
#include "AbstractList.h"

using namespace std;
class AbstractCollection{
	private:
		int INITAL_CAP = 10;
		AbstractList* coll;
	
	public:
		virtual ~AbstractCollection() {};
		void addAll(AbstractCollection& c){};
		virtual void add(string key, string value){};
		virtual void add(string element) = 0;
};
#endif // ABSTRACT_COLLECTION_H