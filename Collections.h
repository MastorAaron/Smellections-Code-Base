#ifndef COLLECTION_H
#define COLLECTION_H
#include <string>
using namespace std;

class Collection{
	public:
		virtual ~Collection() {}
		virtual bool isEmpty() = 0;
		
		virtual bool contains(string element) = 0;
		virtual bool remove(string element) = 0;
		virtual void add(string element) = 0;

		virtual int getSize() = 0;
};
#endif // COLLECTION_H