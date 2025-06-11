#include "Map.h"
using namespace std;

Map::Map(): 
	m_keys(new string[INITIAL_CAPACITY]),
	m_values (new string[INITIAL_CAPACITY]),
	m_capacity(INITIAL_CAPACITY),
	m_size(0),
	m_readOnly(false){}

Map::~Map(){
	delete[] m_keys;
	delete[] m_values;
}

// Do nothing because user must input key and value
void Map::add(string element){} 					//TODO: Implement Hash?

void Map::add(string key, string value){
	if(m_readOnly)
		handleReadOnly();
		return;

	for(int i = 0; i < m_size; i++){
		if(m_keys[i] == key){
			m_values[i] = value;
			return;
		}
		int newSize = m_size + 1;

		if(newSize > m_capacity){
			Set newKeys;
			//= new string[m_capacity + INITIAL_CAPACITY];
			string* newValues = new string[m_capacity + INITIAL_CAPACITY];

			m_capacity += INITIAL_CAPACITY;
			memcpy(newKeys, m_keys, sizeof(m_keys));
			memcpy(newValues, m_values, sizeof(m_values));

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
		if((value == NULL_STR    && m_values[i] == NULL_STR) ||
		   (value == m_values[i] && m_values[i] != NULL_STR ))
			return true;
	return false;
}

bool Map::containsKey(string key){
	return getKey(key) != NULL_STR;
}

string Map::getKey(string key){
	for(int i = 0; i < m_size; i++){
		if(m_keys[i] != NULL_STR && m_keys[i] == key){
			return m_values[i];
		}
	}
	return NULL_STR;
}

string Map::getVal(string Val){
	for(int i = 0; i < getSize(); i++){
		if(m_keys[i] != NULL_STR && m_keys[i] == key){
			return m_values[i];
		}
	}
	return NULL_STR;
}