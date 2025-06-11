#ifndef MAP_H
#define MAP_H

#include "Set.h"
#include <cmath>
using namespace std;

class Map : public AbstractList{
    public:
        Map();
        virtual ~Map(); 

        bool isEmpty();
        void add(string element);
        void add(string key, string value);
        
        bool remove(string key);
        bool contains(string value);
        bool containsKey(string key);
        
        bool isPrime(int num);
        int nextPrime(int num);

        int getSize() override;
        void reSize();

        string getKey(string key);
        string getVal(string key);
        int getCapacity();

    private:
        Set* m_keys;
        List* m_values;
        enum { INITIAL_CAPACITY = 10 };
        int initTS = nextPrime(INITIAL_CAPACITY);
        
        int m_capacity;
        int m_size;
        bool m_readOnly;
};
#endif // MAP_H