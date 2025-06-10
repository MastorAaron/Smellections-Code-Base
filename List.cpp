#include "List.h"
#include "ArrayIndexOutOfBoundsException.h"
using std::string;
List::List() : m_capacity(10), m_elements(new string[10]), 
			m_size(0), m_readOnly(false)
{
}
List::~List() 
{
	delete[] m_elements;
}
bool List::isEmpty() 
{
	return m_size == 0;
}
void List::add(string element) 
{
	if (!m_readOnly) 
	{
		int newSize = m_size + 1;
		if (newSize > getCapacity()) 
		{
			m_capacity += 10;
			string* elements2 = new string[m_capacity];
			for (int i = 0; i < m_size; i++)
				elements2[i] = m_elements[i];
			delete[] m_elements;
			m_elements = elements2;
		}
		m_elements[m_size++] = element;
	}
}
bool List::contains(string element) 
{
	for (int i=0; i<m_size; i++) 
		if (m_elements[i] == element)
			return true;
	return false;
}
int List::getSize() 
{
	return m_size;
}
bool List::remove(string element) 
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
string List::get(int i) 
{
	if (i >= getSize()) 
	{	
		ArrayIndexOutOfBoundsException e;
		throw e;
	}
	return m_elements[i];
}
int List::getCapacity() 
{
	return m_capacity;
}
void List::set(int i, string value) 
{
	if (!m_readOnly) 
	{
		if (i >= m_size) 
		{
			ArrayIndexOutOfBoundsException e;
			throw e;
		}
		m_elements[i] = value;
	}
}
void List::setReadOnly(bool b) 
{
	m_readOnly = b;
}
