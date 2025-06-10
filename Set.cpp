#include "Set.h"
#include "ArrayIndexOutOfBoundsException.h"
using std::string;

Set::Set()
	: m_capacity(INITIAL_CAPACITY),
	m_elements(new string[INITIAL_CAPACITY]),
	m_size(0),
	m_readOnly(false) 
{
}
Set::~Set() 
{
	delete[] m_elements;
}
bool Set::isEmpty() 
{
	return m_size == 0;
}
void Set::add(string element) 
{
	if (!m_readOnly) 
	{
		int newSize = m_size + 1;
		if (newSize > m_capacity) 
		{
			m_capacity += INITIAL_CAPACITY;
			string* newElements = new string[m_capacity];
			for (int i = 0; i < m_size; i++)
				newElements[i] = m_elements[i];
			delete[] m_elements;
			m_elements = newElements;
		}
		if (contains(element))
			return;
		m_elements[m_size++] = element;
	}
}
bool Set::contains(string element) 
{
	for (int i = 0; i < m_size; i++)
		if (m_elements[i] == element)
			return true;
	return false;
}
int Set::getSize() 
{
	return m_size;
}
bool Set::remove(string element) 
{
	if (m_readOnly)
		return false;
	for (int i = 0; i < m_size; i++)
		if (m_elements[i] == element) 
		{
			m_elements[i] = "";
			m_capacity = m_size - 1;
			string* newElements = new string[m_capacity];
			int k = 0;
			for (int j = 0; j < m_size; j++) 
			{
				if (m_elements[j] != "")
					newElements[k++] = m_elements[j];
			}
			m_size--;
			delete[] m_elements;
			m_elements = newElements;
			return true;
		}
	return false;
}
string Set::getElementAt(int index) 
{
	if (index >= m_size) 
	{
		ArrayIndexOutOfBoundsException e;b
		throw e;
	}
	return m_elements[index];
}
void Set::addAll(List& l) 
{
	for (int i=0; i < l.size(); i++) 
	{
		if (!contains(l.get(i))) 
		{
			m_elements[m_size++] = l.get(i);
		}
	}
}
int Set::getCapacity() 
{
	return m_capacity;
}
void Set::setReadOnly(bool b) 
{
	m_readOnly = b;
}