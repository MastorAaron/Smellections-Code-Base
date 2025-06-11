#include "AbstractCollection.h"
#include "AbstractList.h"
#include "List.h"
#include "Map.h"
#include "Set.h"
using namespace std;

void AbstractCollection::addAll(AbstractCollection &c){
	if(auto* pAbsList = dynamic_cast<AbstractList*>(&c)){
		for(int i = 0; i < pAbsList->getSize(); i++){
			add(pAbsList->getElmt(i));
		}
	}
	auto* pMap  = dynamic_cast<Map*> (&c);
	if(pMap != NULL){
		for(int i = 0; i < pMap->getSize(); i++)
			add(pMap->getKey(i), pMap->getValue(i));
	}
}

void AbstractCollection::add(string key, string value){}