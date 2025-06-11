#ifndef ABSTRACT_LIST_H
#define ABSTRACT_LIST_H
#include "AbstractCollection.h"

#include <string>
#include <iostream>

using namespace std;

const std::string NULL_STR = "\x01\x02\x03__NULL_STRING__\x04\x05\x06";



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

        bool isEmpty();                 
        
        void placeAt(int i, string value);
        int elmtIndex(string element);  
        
        bool contains(string element);  
        bool remove(string element);    
        
        virtual int getSize();                  
        void setSize();                  
        int getCapacity();              
        string getElmt(int i);
        
        void setReadOnly(bool b);
        
        virtual void add(string element);
        void growToSize(int scale);
        void copyValidStrs();
        
        void handleOutOfBounds();
        void handleReadOnly();

        
        template <class temp>
        temp& operator[](int i) {
            if (i >= m_size) handleOutOfBounds();
            return m_elements[i];
        }
        
        template <class temp>
        const temp& operator[](int i) const {
            if (i >= m_size) handleOutOfBounds();
            return m_elements[i];
        }


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

void AbstractList::handleReadOnly(){
    cout << "Read Only: Immutable" << endl;
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
        return NULL_STR;
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
        if(m_elements[i] != NULL_STR)
		    newElements[k++] = m_elements[i];
	}
    m_size = k;

    delete[] m_elements;
	m_elements = newElements;
}

void AbstractList::add(string element){
	if(m_readOnly){
        handleReadOnly();
		return;
    }
    growToSize();
	copyValidStrs();

	m_elements[m_size-1] = element;
}

bool AbstractList::remove(string element){
	if(m_readOnly){
        handleReadOnly();
		return;
    }
    int index = elmtIndex(element);
    if(index == - 1)
		return false;

    m_elements[index] = NULL_STR;
    copyValidStrs(); // handles m_size update internally
    
    return true;
}

void AbstractList::placeAt(int i, string value){
	if(m_readOnly){
        handleReadOnly();
		return;
    }
	if(i >= m_size)
		handleOutOfBounds();
    string atIndex = getElmt(i);
    if(atIndex != NULL_STR){
        cout << atIndex <<" replaced by "<< value << endl;
    }

    m_elements[i] = value;
}

#endif // ABSTRACT_LIST_H