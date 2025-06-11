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
};

#endif // ABSTRACT_LIST_H