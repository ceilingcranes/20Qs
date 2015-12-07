#include <iostream>
#include <vector>
#include <string>

#include "Chara.h"
#include "Thing.h"

using namespace std;

Chara::Chara(string n){
	name=n;
}

Chara::Chara(string n, Thing t){
	name=n;
	thingList.push_back(t);
}
Chara::Chara(string n, vector<Thing> t){
	name=n;
	thingList=t;
}


void Chara::addThing(Thing t){
	bool hasThing=false;
	for(int i=0; i<thingList.size(); i++){
		if(thingList[i].toString()==t.toString()){
			hasThing=true;
			cout << "Thing is in thingList already!!!!!!" << endl;
		}
	}
	if(!hasThing){
		cout << "Added " << t.toString() << " to " << name << endl;
		thingList.push_back(t);
	}
}

vector<Thing> Chara::getThingList(){
	return thingList;
}

string Chara::getName(){
	return name;
}

void Chara::setName(string str){
	name=str;
}

void Chara::setThing(int index, Thing t){
	thingList[index]=t;
}

string Chara::toString(){
	return name;
}
