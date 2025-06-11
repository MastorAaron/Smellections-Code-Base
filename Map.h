#ifndef MAP_H
#define MAP_H

#include "AbstractCollection.h"
using namespace std;

class Map : public AbstractCollection{
public:
    Map();
        virtual ~Map(); 
        bool isEmpty();
        void add(string element);
        void add(string key, string value);
        int getSize();
        bool remove(string key);
        bool contains(string value);
        bool containsKey(string key);
        string get(string key);
        int getCapacity();
        void setReadOnly(bool b);
        string *m_keys;
        string *m_values;

        private:
            enum { INITIAL_CAPACITY = 10 };
            int m_capacity;
            int m_size;
            int m_indexWhereKeyFound;
            bool m_readOnly;
};

#endif // MAP_H