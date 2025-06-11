#ifndef LIST_H
#define LIST_H
#include "AbstractList.h"
using namespace std;

class List : public AbstractList{
	public:
		List();
		
		void set(int i, string value);

	private:
		friend class ListTest;
		enum {INITIAL_CAPACITY = 10};
};
#endif // LIST_H