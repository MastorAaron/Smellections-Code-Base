#ifndef SET_H
#define SET_H
#include "AbstractList.h"

#include <string>
using namespace std;

class Set : public AbstractList{
	public:
		Set() : AbstractList() {};
		void Setify(List& l);			
		void add(string element) override;			
};
#endif // SET_H