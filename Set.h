#ifndef SET_H
#define SET_H
#include "AbstractSet.h"
#include "List.h"
#include <string>
using namespace std;

class Set : public AbstractList{
	public:
		Set();
		virtual ~Set();

		void addAll(List& l);			//TODO: Remove this Legacy Denial Code Smell
		void add(string element);

		bool contains(string element);	//TODO: Generalize This for Set and List
		bool remove(string element);
		
		string getEle(int index);

		int getCapacity();
		void setReadOnly(bool b);

	private:
		enum {INITIAL_CAPACITY = 10};
		int m_capacity;
		string* m_elements;
};
#endif // SET_H