#ifndef ABSTRACT_LIST_H
#define ABSTRACT_LIST_H
#include "AbstractCollection.h"

class AbstractList : public AbstractCollection{
    protected:
        enum {INITIAL_CAPACITY = 10};
        bool m_readOnly;
        int m_size;
        int m_capacity;
        string* m_elements;

    public:
        ~AbstractList();
        AbstractList();

        bool isEmpty();                 //TODO: Generalize This for Set and List
        
        bool contains(string element);  //TODO: Generalize This for Set and List
        bool remove(string element);    //TODO: Generalize This for Set and List
        
        int getSize();                  //TODO: Generalize This for Set and List
        int getCapacity();              //TODO: Generalize This for Set and List
        string getEle(int i);
        
        void setReadOnly(bool b);
        
        void add(string element);
        void reSize();
        void copyOver();
        
        void handleOutOfBounds();
}; 

AbstractList::AbstractList():
	m_capacity(INITIAL_CAPACITY),
	m_elements(new string[INITIAL_CAPACITY]),
	m_size(0),
	m_readOnly(false){
}

bool AbstractList::isEmpty(){
	return m_size == 0;
}

int AbstractList::getCapacity(){
	return m_capacity;
}

void AbstractList::setReadOnly(bool b){
	m_readOnly = b;
}

int AbstractList::getSize(){
	return m_size;
}

void AbstractList::handleOutOfBounds(){
    // ArrayIndexOutOfBoundsException e;
    string e ="Array Index Out Of Bounds Exception";
    throw e;
}

bool AbstractList::remove(string element){
	if(m_readOnly)
		return false;

	for(int i = 0; i < m_size; i++){
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

string AbstractList::getEle(int i){
	if(i >= m_size){
        handleOutOfBounds();
    }
	return m_elements[i];
}

void AbstractList::reSize(){
	int newSize = m_size + 1;
	if(newSize > m_capacity){
		m_capacity += INITIAL_CAPACITY;
	}
}

void AbstractList::copyOver(){
	string* newElements = new string[m_capacity];
	for(int i = 0; i < m_size; i++){
		newElements[i] = m_elements[i];
	}
	delete[] m_elements;
	m_elements = newElements;
}

void AbstractList::add(string element){
	reSize();
	copyOver();
	m_elements[m_size++] = element;

	if(m_readOnly)
		return;
}


#endif // ABSTRACT_LIST_H