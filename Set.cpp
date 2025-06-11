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

	int newSize = m_size + 1;
	if(newSize > m_capacity){
		m_capacity += INITIAL_CAPACITY;
		string* newElements = new string[m_capacity];
		for(int i = 0; i < m_size; i++)
			newElements[i] = m_elements[i];
		delete[] m_elements;
		m_elements = newElements;
	}
	m_elements[m_size++] = element;
}
bool Set::contains(string element){
	for(int i = 0; i < m_size; i++)
		if(m_elements[i] == element)
			return true;
	return false;
}

bool Set::remove(string element){
	if(m_readOnly)
		return false;

	for(int i = 0; i < getSize(); i++){
		if(m_elements[i] == element){
			m_elements[i] = "";
			m_capacity = m_size - 1;
			string* newElements = new string[m_capacity];
			
			int k = 0;
			for(int j = 0; j < m_size; j++){
				if(m_elements[j] != "")
					newElements[k++] = m_elements[j];
			}

			m_size--;
			delete[] m_elements;
			m_elements = newElements;
			return true;
		}
	}
	return false;
}

string Set::getEle(int index){
	if(index >= m_size){
		// ArrayIndexOutOfBoundsException e;
		string e ="Array Index Out Of Bounds Exception";
		throw e;
	}
	return m_elements[index];
}

void Set::addAll(List& l){
	for(int i=0; i < l.getSize(); i++){
		if(!contains(l.getEle(i))){
			m_elements[m_size++] = l.getEle(i);
		}
	}
}

int Set::getCapacity(){
	return m_capacity;
}

void Set::setReadOnly(bool b){
	m_readOnly = b;
}