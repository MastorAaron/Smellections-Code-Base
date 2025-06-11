#include "Set.h"
// #include "ArrayIndexOutOfBoundsException.h"
using std::string;

Set::Set(): AbstractList() {}

Set::~Set(){
	delete[] m_elements;
}

void Set::add(string element){
	if(m_readOnly)
		return;

	if(contains(element))
		return;

	AbstractList::add(element);
}
bool Set::contains(string element){
	for(int i = 0; i < m_size; i++)
		if(m_elements[i] == element)
			return true;
	return false;
}

void Set::Setify(List& l){
	for(int i=0; i < l.getSize(); i++){
		add(l.getEle(i));
	}
}