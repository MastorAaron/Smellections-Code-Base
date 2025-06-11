#ifndef ABSTRACT_LIST_H
#define ABSTRACT_LIST_H
#include "AbstractCollection.h"
#include <string>

const std::string DELETED_SENTINEL = "\x01\x02\x03__DELETED__\x04\x05\x06";

class AbstractList : public AbstractCollection{
    protected:
        enum {INITIAL_CAPACITY = 10};
        string* m_elements;
        bool m_readOnly;
        int m_size;
        int m_capacity;

    public:
        ~AbstractList();
        AbstractList();

        bool isEmpty();                 //TODO: Generalize This for Set and List
        
        int elmtIndex(string element);  //TODO: Generalize This for Set and List
        bool contains(string element);  //TODO: Generalize This for Set and List
        bool remove(string element);    //TODO: Generalize This for Set and List
        
        int getSize();                  //TODO: Generalize This for Set and List
        int getCapacity();              //TODO: Generalize This for Set and List
        string getElmt(int i);
        
        void setReadOnly(bool b);
        
        void add(string element);
        void growToSize(int scale);
        void copyValidStrs();
        
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

int AbstractList::elmtIndex(string element){
	for(int i = 0; i < m_size; i++)
		if(getElmt(i) == element)
			return i;
	return -1;
}

bool AbstractList::contains(string element){
    return elmtIndex(element) != -1;
}

string AbstractList::getElmt(int i){
	if(i >= m_size){
        handleOutOfBounds();
    }
	return m_elements[i];
}

void AbstractList::growToSize(int scale=1){
	int newSize = m_size + scale;
	if(newSize > m_capacity){
		m_capacity += INITIAL_CAPACITY; //Scale by 10s
	}
    m_size = newSize;
}

void AbstractList::copyValidStrs(){
    string* newElements = new string[m_capacity];
    
    int k = 0;
	for(int i = 0; i < m_size; i++){
        if(m_elements[i] != DELETED_SENTINEL)
		    newElements[k++] = m_elements[i];
	}
    m_size = k;

    delete[] m_elements;
	m_elements = newElements;
}

void AbstractList::add(string element){
	if(m_readOnly)
		return;
	
    growToSize();
	copyValidStrs();

	m_elements[m_size-1] = element;
}

bool AbstractList::remove(string element){
	if(m_readOnly)
		return false;

    int index = elmtIndex(element);
    if(index == - 1)
		return false;

    m_elements[index] = DELETED_SENTINEL;
    copyValidStrs(); // handles m_size update internally
    
    return true;
}

#endif // ABSTRACT_LIST_H