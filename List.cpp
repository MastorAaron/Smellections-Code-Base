#include "List.h"
// #include "ArrayIndexOutOfBoundsException.h"
using namespace std;

List::List() : AbstractList() {}

List::List(){
	delete[] m_elements;
}

void List::set(int i, string value){
	if(m_readOnly)
		return;

	if(i >= m_size)
		handleOutOfBounds();
	
	m_elements[i] = value;
}