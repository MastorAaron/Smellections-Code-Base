#ifndef LIST_H
#define LIST_H
#include "AbstractList.h"
using namespace std;

class List : public AbstractList{
	public:
		List(): AbstractList(){};

	private:
		friend class ListTest;
};
#endif // LIST_H