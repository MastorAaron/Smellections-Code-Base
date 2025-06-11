#include "Map.h"
using namespace std;

Map::Map()
	: m_keys(new string[INITIAL_CAPACITY]),
	m_values (new string[INITIAL_CAPACITY]),
	m_capacity(INITIAL_CAPACITY),
	m_size(0),
	m_readOnly(false){
}

Map::~Map(){
	delete[] m_keys;
	delete[] m_values;
}

bool Map::isEmpty(){
	return m_size == 0;
}

// Do nothing because user must input key and value
void Map::add(string element){
}

void Map::add(string key, string value){
	if (!m_readOnly){
		for (int i = 0; i < m_size; i++){
			if (m_keys[i] == key){
				m_values[i] = value;
				return;
			}
		int newSize = m_size + 1;
		if (newSize > m_capacity){
			string* newKeys   = new string[m_capacity + INITIAL_CAPACITY];
			string* newValues = new string[m_capacity + INITIAL_CAPACITY];
			m_capacity += INITIAL_CAPACITY;
			memcpy(newKeys, m_keys, sizeof(m_keys));
			memcpy(newValues, m_values, sizeof(m_values));
			delete[] m_keys;
			delete[] m_values;
			m_keys = newKeys;
			m_values = newValues;
		}
		m_keys[m_size] = key;
		m_values[m_size] = value;
		m_size++;
		}
	}
}

int Map::getSize(){
	return m_size;
}

bool Map::remove(string key){
	if (m_readOnly)
		return false;

	for (int i = 0; i < m_size; i++){
		if (m_keys[i] == key){
			m_keys[i] = "";
			m_values[i] = "";
			m_size--;
			return true;
		}
	}
	return false;
}

bool Map::contains(string value){
	for (int i = 0; i < m_size; i++)
		if ((value == "" && m_values[i] == "")
			|| (m_values[i] != "" && m_values[i] == value))
			return true;
	return false;
}

bool Map::containsKey(string key){
	for (int i = 0; i < m_size; i++){
		if (m_keys[i] != "" && m_keys[i] == key){
			m_indexWhereKeyFound = i;
			return true;
		}
	}
	return false;
}

string Map::get(string key){
	if (!containsKey(key))
		return "";
	return m_values[m_indexWhereKeyFound];
}

int Map::getCapacity(){
	return m_capacity;
}

void Map::setReadOnly(bool b){
	m_readOnly = b;
}
