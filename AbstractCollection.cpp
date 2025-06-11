#include "AbstractCollection.h"
#include "List.h"
#include "Map.h"
#include "Set.h"
using namespace std;

void AbstractCollection::addAll(AbstractCollection &c){
	Set*  pSet 	= dynamic_cast<Set*> (&c);
	List* pList = dynamic_cast<List*>(&c);
	Map*  pMap 	= dynamic_cast<Map*> (&c);

	if(pSet != NULL){
		for(int i = 0; i < pSet->getSize(); i++){
			if(!contains(pSet->getEle(i))){
				add(pSet->getEle(i));
			}
		}
	}else if(pList != NULL){
		for(int i = 0; i < pList->getSize(); i++){
			if(!contains(pList->getEle(i))){
				add(pList->getEle(i));
			}
		}
	}else if(pMap != NULL){
		for(int i = 0; i < pMap->getSize(); i++)
			add(pMap->m_keys[i], pMap->m_values[i]);
	}
}

void AbstractCollection::add(string key, string value){
}