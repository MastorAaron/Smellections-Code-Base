#ifndef MAP_H
#define MAP_H

#include "List.h"
using namespace std;

class Map : public List{
    public:
        Map();
        virtual ~Map(); 
        
        bool isEmpty();
        void add(string element);
        void add(string key, string value);
        
        bool remove(string key);
        bool contains(string value);
        bool containsKey(string key);
        
        int getSize();
        string getKey(string key);
        int getCapacity();

        void setReadOnly(bool b);
            
    private:
        string *m_keys;
        string *m_values;
        enum { INITIAL_CAPACITY = 10 };
        int m_capacity;
        int m_size;
        bool m_readOnly;
};

#endif // MAP_H