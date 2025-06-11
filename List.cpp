#include "List.h"
// #include "ArrayIndexOutOfBoundsException.h"
using namespace std;

List::List() : AbstractList() {}

List::List(){
	delete[] m_elements;
}

void List::add(string element){
	if(!m_readOnly){
		int newSize = m_size + 1;
		if(newSize > m_capacity){
			m_capacity += 10;
			string* elements2 = new string[m_capacity];
			for(int i = 0; i < m_size; i++){
				elements2[i] = m_elements[i];
			}
			delete[] m_elements;
			m_elements = elements2;
		}
		m_elements[m_size++] = element;
	}
}


void List::set(int i, string value){
	if(!m_readOnly){
		if(i >= m_size){
			// ArrayIndexOutOfBoundsException e;
			string e ="Array Index Out Of Bounds Exception";
			throw e;
		}
		m_elements[i] = value;
	}
}