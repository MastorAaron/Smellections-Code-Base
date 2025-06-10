#include "AbstractCollection.h"
#include "Set.h"
#include "List.h"
#include "Map.h"
using std::string;
void AbstractCollection::addAll(AbstractCollection& c) 
{
	Set*  pSet = dynamic_cast<Set*>(&c);
	List* pList= dynamic_cast<List*>(&c);
	Map*  pMap = dynamic_cast<Map*>(&c);
	if (pSet != NULL) 
	{
		for (int i=0; i < pSet->getSize(); i++) 
		{
			if (!contains(pSet->getElementAt(i))) 
			{
				add(pSet->getElementAt(i));
			}
		}
	} else if (pList != NULL) 
	{
		for (int i=0; i < pList->getSize(); i++) 
		{
			if (!contains(pList->get(i))) 
			{
				add(pList->get(i));
			}
		}
	} else if (pMap != NULL) 
	{
		for (int i=0; i< pMap->getSize(); i++) 
			add(pMap->m_keys[i], pMap->m_values[i]);			
	}
}
void AbstractCollection::add(string key, string value) 
{
}