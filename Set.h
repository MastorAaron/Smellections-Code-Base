#ifndef SET_H
#define SET_H
#include "AbstractSet.h"
#include "List.h"
#include <string>
using namespace std;

class Set : public AbstractList{
	public:
		Set();

		void Setify(List& l);			
		bool remove(string element);
		
	private:
};
#endif // SET_H