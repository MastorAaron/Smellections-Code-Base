#ifndef LIST_H
#define LIST_H
#include "AbstractList.h"
#include <string>
using namespace std;

class List : public AbstractList{
	public:
		List();
		virtual ~List();
		bool isEmpty();
		
		bool contains(string element);
		bool remove(string element);
		void add(string element);
		
		int getSize();
		string get(int i);
		int getCapacity();
		
		void set(int i, string value);
		void setReadOnly(bool b);

	private:
		friend class ListTest;
		enum 	{INITIAL_CAPACITY = 10};
		int 	m_capacity;
		string* m_elements;
		int 	m_size;
		bool 	m_readOnly;
};
#endif // LIST_H