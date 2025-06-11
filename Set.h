#ifndef SET_H
#define SET_H
#include "AbstractSet.h"
#include "List.h"
#include <string>
using namespace std;

class Set : public AbstractSet{
	public:
		Set();
		virtual ~Set();

		void addAll(List& l);
		void add(string element);
		bool remove(string element);
		bool contains(string element);
		bool isEmpty();
		int getSize();
		
		string getElementAt(int index);
		int getCapacity();
		void setReadOnly(bool b);
	private:
		enum {INITIAL_CAPACITY = 10};
		int m_capacity;
		string* m_elements;
		int m_size;
		bool m_readOnly;
};
#endif // SET_H