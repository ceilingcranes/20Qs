#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Thing.h"
#include "Chara.h"
using namespace std;

vector<Thing> getThings(string);
vector<Chara> setCharacteristics(vector<Thing>);

int main(int argc, char* argv[])
{
	string filename=argv[1]; //add in a test
	vector<Thing> thingList=getThings(filename);
	
	
	for(int i=0; i<thingList.size(); i++)
	{
		Thing t=thingList[i];
		cout << "Name: " << t.getName() << endl;
		vector <string> cha= t.getChara();

		for(int t=0; t<cha.size(); t++){
			cout<< "Chara " << t << ":" <<cha[t] <<endl;
		}
		
	}
	cout << "~~LISTING CHARACTERISTICS~~" << endl;
	vector <Chara> ch=setCharacteristics(thingList); 
	
	for(int k=0; k<ch.size(); k++){
		Chara c=ch[k];
		cout << "Chara: " << c.getName() << endl;
		vector<Thing> th=c.getThingList();
		cout << "TH SIZE: " << th.size() <<endl;
		
		for(int l=0; l<th.size(); l++){
			cout << "Thing #"<<l<<": "<< th[l].toString()<<endl;
		}
	}

	return 0;
}

/**
 * Will loop through the vector of things and add each characteristic to a vector of Chara. 
 * Each Chara instance has all the things that have that characteristic.
 * */
vector<Chara> setCharacteristics(vector<Thing> thingList)  
{
	cout << "doing the thing" << endl;
	vector<Chara> c;
	
	for(int i=0; i< thingList.size(); i++){ //for each thing in vector
		Thing thing=thingList[i];
		cout << "THING: " << thing.toString() << endl;
		vector<string> thingCharaList=thing.getChara(); //thingCharaList is the list of characteristics for each thing
		cout << "thingCharaList.size()= "<< thingCharaList.size()<<endl;
		for(int t=0; t<thingCharaList.size(); t++){ //loop through each thing's characteristics
			
			string thingChara=thingCharaList[t]; //thingChara=characteristic
			cout << "thing chara #"<<t<<": "<<thingChara<<endl;
			int existingI=-1;
			
			for(int k=0; k<c.size(); k++){ //loop through chara in c 
				if(thingChara==c[k].getName()){ //if the chara exists in vector c already
					existingI=k;
					cout<< "Index: " << existingI << endl;
				}
				
			}
			if(existingI>=0){
				c[existingI].addThing(thing);
				cout<< "existing " << thingChara<< endl;
			}
			else{
					c.push_back(Chara(thingChara, thing)); //adds a new chara to vector with name thingChara and one thing in vector
					cout << "New "<<thingChara << endl;
			}	
		}
	}
	cout << "All done!" << endl;
	return c;
}
		


/**
 * Will pull info in from the file filename (format: name@chara1,chara2,chara3) and return a vector of things
 * with name=name and charaList consisting of a vector of the characteristics.
 * */
vector<Thing> getThings(string filename)
{
	ifstream in;
	in.open(filename.c_str());
	vector<Thing> thingList;
	string line;
	while( getline(in, line) ){
		if(!line.empty()){
			cout << "Line: " << line << endl;
			int at_delim=line.find("@"); 
			
			if(at_delim!=std::string::npos){
				string thingName=line.substr(0, at_delim); //the string before the @ symbol
				line=line.substr(at_delim+1);
				int com_delim=line.find(",");
				vector<string> charas;
		
				while(com_delim!=std::string::npos){ //will loop through all the commas
					charas.push_back(line.substr(0, com_delim)); //add to charas vector
					line=line.substr(com_delim+1);
					com_delim=line.find(",");
				}
				
				charas.push_back(line);
				if(charas.size()>0){
					thingList.push_back(Thing(thingName, charas));
				}
				else{
					cout<<"Error: No Charactoristics found for " << thingName <<endl;  //If the thing has no characteristics- error in file.
				}
			}
		}
	}
	cout << "Success!" << endl;
	return thingList;
			
}



