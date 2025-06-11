#ifndef LIST_H
#define LIST_H
#include "AbstractList.h"
#include <string>
using namespace std;

class List : public AbstractList{
	public:
		List();
		virtual ~List();
		
		void add(string element);
		string getEle(int i);
		
		void set(int i, string value);
		void setReadOnly(bool b);

	private:
		friend class ListTest;
		enum {INITIAL_CAPACITY = 10};
};
#endif // LIST_H