#include <iostream>
#include <string>
#include <vector>

#include "Thing.h"

using namespace std;

Thing::Thing(string n, vector<string> ch){
	name=n;
	characteristics=ch;
}

string Thing::getName(){
	return name;
}

void Thing::setName(string str){
	name=str;
}

vector<string> Thing::getChara(){
	return characteristics;
}

void Thing::setChara(int i, string str){
	characteristics[i]=str;
}

void Thing::addChara(string str){
	characteristics.push_back(str);
}

bool Thing::equals(Thing other){ //to see if the objects are equal- I'm not sure if I need to do this. Coming from java.
	if(name==other.getName()){ //check chara list?
		return true;
	}
}

string Thing::toString(){
	return name;
}
