#include <iostream>
#include <string>
#include <vector>

#include "Thing.h"

using namespace std;

Thing::Thing(string n, vector<string> ch/*, int i*/){
	name=n;
	characteristics=ch;
	/*lineNum=i;*/
	cout << "Thing created in Thing.cpp. Chara:" << endl;
	for(int i=0; i< ch.size(); i++){
		cout << ch[i] << endl;
	}
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

void Thing::printChara(){
	for(int i=0; i<characteristics.size(); i++){
		cout << characteristics[i] <<endl;
	}
}

void Thing::setLineNum(int i){
	lineNum=i;
}

int Thing::getLineNum(){
	return lineNum;
}

string Thing::toString(){
	return name;
}
