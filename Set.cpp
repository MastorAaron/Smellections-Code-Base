#include "Set.h"
// #include "ArrayIndexOutOfBoundsException.h"
using namespace std;

void Set::add(string element){
	if(m_readOnly)
		return;

	if(contains(element))
		return;

	AbstractList::add(element);
}

void Set::Setify(List& l){
	for(int i=0; i < l.getSize(); i++){
		add(l.getElmt(i));
	}
}