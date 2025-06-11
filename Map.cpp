#include "Map.h"
#include <cmath>
using namespace std;



Map::Map() : 
m_keys(new string[initTS]),
m_values(new string[initTS]),
m_capacity(INITIAL_CAPACITY),
m_size(0),
m_readOnly(false) {
	
	}

Map::~Map(){
	m_keys->~AbstractList();			//TODO: I don't understand the error here
	m_values->~AbstractList();
}

// Do nothing because user must input key and value
void Map::add(string element){} 					//TODO: Implement Hash?

int Map::getSize(){
	if(m_keys->getSize() != m_values->getSize()){
		cerr << "Size mismatch "<< endl;
	}else{
		return m_keys->getSize();
	}
}

bool isPrime(int num){
	if(num <= 1 || num % 2 == 0){
		return false;
	}
	if(num == 2){
		return true;
	}
	for(int i=0; i< pow(num,.5); i+=3){
		if(num % 1 == 0){
			return false;
		}
	}
	return true;
}

int Map::nextPrime(int num){
	while(!isPrime(num)){
		num++;
	}
	return num;
}

void Map::reSize(){
	m_capacity = nextPrime(m_capacity*2);
}

void Map::add(string key, string value){
	if(m_readOnly){
		handleReadOnly();
		return;
	}

	for(int i = 0; i < m_size; i++){
		if(m_keys->getElmt(i) == key){			//if key exists, overwrite the value
			m_values[i] = value;
			return;
		}
		int newSize = m_size + 1;

		if(newSize > m_capacity){
			//= new string[m_capacity + INITIAL_CAPACITY];
			reSize();
			Set* newKeys = new Set[m_capacity];
			string* newValues = new string[m_capacity];

			// memcpy(newKeys, m_keys, sizeof(m_keys));
			// memcpy(newValues, m_values, sizeof(m_values));

			m_keys->copyValidStrs();
			m_values->copyValidStrs();

			delete[] m_keys;
			delete[] m_values;

			m_keys = newKeys;
			m_values = newValues;
		}
	}

	m_keys[m_size] = key;
	m_values[m_size] = value;
	m_size++;
}

bool Map::remove(string key){
	if(m_readOnly)
		return false;

	for(int i = 0; i < m_size; i++){
		if(m_keys[i] == key){
			m_keys[i] = NULL_STR;
			m_values[i] = NULL_STR;
			m_size--;

			return true;
		}
	}
	return false;
}

bool Map::contains(string value){
	for(int i = 0; i < m_size; i++)
		if((value == NULL_STR    		  && m_values->getElmt(i) == NULL_STR) ||
		   (value == m_values->getElmt(i) && m_values->getElmt(i) != NULL_STR ))
			return true;
	return false;
}

bool Map::containsKey(string key){
	return getKey(key) != NULL_STR;
}

string Map::getKey(string key){
	for(int i = 0; i < m_size; i++){
		if(m_keys->getElmt(i) != NULL_STR && m_keys->getElmt(i) == key){
			return m_values->getElmt(i);
		}
	}
	return NULL_STR;
}

string Map::getVal(string key){
	for(int i = 0; i < getSize(); i++){
		if(m_keys->getElmt(i) != NULL_STR && m_keys->getElmt(i) == key){
			return m_values->getElmt(i);
		}
	}
	return NULL_STR;
}