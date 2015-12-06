#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Thing.h"
#include "Chara.h"
using namespace std;

vector<Thing> getThings(string);
vector<Chara> setCharacteristics(vector<Thing>);
int appFile(string filename, string newLine, int linenum);
string getLineFromIndex(string filename, int linenum);
string addToLine(string, vector<string>);
string trim(string);
int max(int, int);
bool existsInList(Thing t, vector<Thing> v);
void addNewThingToFile(Thing t, string filename);
bool stringExistsInList(string t, vector<string> v);



/**
 * add in a loop to ask if it has charas
 * If yes, check to see if each thing in possiblethings has that chara
 * then do no XP
 * */
int main(int argc, char* argv[]) 
{
	string filename=argv[1]; //add in a test
	vector<Thing> thingList=getThings(filename);
	ifstream outstream;
	outstream.open(filename.c_str());
	outstream.open(filename,ios::app);
	
	/*for(int i=0; i<thingList.size(); i++)
	{
		Thing t=thingList[i];
		//cout << "Name: " << t.getName() << endl;
		vector <string> cha= t.getChara();

		for(int t=0; t<cha.size(); t++){
			cout<< "Chara " << t << ":" <<cha[t] <<endl;
		}
		
	}*/
	//cout << "~~LISTING CHARACTERISTICS~~" << endl;
	vector <Chara> ch=setCharacteristics(thingList); 
	
	/*for(int k=0; k<ch.size(); k++){
		Chara c=ch[k];
		cout << "Chara: " << c.getName() << endl;
		vector<Thing> th=c.getThingList();
		cout << "TH SIZE: " << th.size() <<endl;
		
		for(int l=0; l<th.size(); l++){
			cout << "Thing #"<<l<<": "<< th[l].toString()<<endl;
		}
	}
	*/
	vector <Thing> possibleThings;
	//Keep track of each chara and check each new thing
	vector <Chara> charas; 
	vector <Chara> noChara; // charas the thing doesn't have.
	int tracker=0;
	for(int f=0; f<ch.size(); f++) //looping through each chara
	{	
		tracker++;
		bool answered=false;
		string answer;
		while(!answered){
		cout << "Does it have the characteristic:" << ch[f].toString() << "?" << endl;
		cin >> answer;
		vector <Thing> charaThing=ch[f].getThingList(); //The things that have the Chara
		if(answer=="y"||answer=="yes"||answer=="Y"||answer=="Yes")
		{
			answered=true;
			charas.push_back(ch[f]);
			
			for(int d=0; d < charaThing.size(); d++) //go through each thing that has the Chara
			{
				bool addToList=true;
				cout << "THING: " << charaThing[d].toString()<< endl;
				vector <string> charasOfThing=charaThing[d].getChara(); //get the chara of each thing
				int hasCharaSize=charas.size();
				int noCharaSize=noChara.size();
				//CHECK TO SEE IF IT EXISTS IN THE LIST 
				bool hasChara=false;
				bool hasNoChara=false;
				for(int n=0; n < max(hasCharaSize, noCharaSize); n++) //loop through the list of charas
				{
					string charaInList="";
					if(n<hasCharaSize){
						charaInList=charas[n].toString(); //the charas that user entered 'yes' to
					}
					string charaInNoList="";
					if(n<noCharaSize){
						charaInNoList=noChara[n].toString();
					}

					for(int rr=0; rr< charasOfThing.size(); rr++) //go through the charas of each thing
					{
						string charaOfThing=charasOfThing[rr];
						
						if(charaInList!=""){
							if(charaOfThing==charaInList){ //if it matches the chara entered
								cout << "comparison returns true." << endl;
								hasChara=true; 
								if(n>noCharaSize){
									//rr=charasOfThing.size()+1;
								}
							}
							cout << "Chara of Thing: " << charaOfThing << " Chara in List: " << charaInList <<" has chara " << hasChara<< endl;
						}
						if(charaInNoList!=""){
							
							if(charaOfThing==charaInNoList){ //if it has a chara that's the user answered no to
								hasNoChara=true;
								//rr=charasOfThing.size()+1;
							}
							cout << "Chara of Thing: " << charaOfThing << " Chara in No List: " << charaInNoList << " hasNoChara " << hasNoChara<< endl;
						}
					}
					cout << "hasChara: " << hasChara << " Has no chara: " << hasNoChara << endl;
					if(hasChara==false||hasNoChara==true){ //if it's missing a chara in charas, or has a chara
						addToList=false;					//in nocharas don't add to possibleThings
						cout << "Not adding to list" << endl;
						//n=charas.size()+1;
					}
				}
				if(addToList){
					if(!existsInList(charaThing[d], possibleThings)){
						possibleThings.push_back(charaThing[d]);
						cout << "Added to list" << endl;
					}
					else cout << "Exists already" << endl;
				}
			}
				
					
			cout << "Charas: ";
			for(int tt=0; tt< charas.size(); tt++){
				cout << charas[tt].toString();
			}
			
			
			cout << "\nPossible things: " << endl;
			for(int i=0; i< possibleThings.size(); i++){ //check each thing in possibleThings for Chara
				Thing thingInPossibleThings=possibleThings[i];
				vector <string> possibleThingCharas=thingInPossibleThings.getChara();
				bool hasChara=false;
				for(int ee=0; ee<possibleThingCharas.size(); ee++){
					//cout << "Possible Thing Charas " << possibleThingCharas[ee] << " thinginpossiblethings " << ch[f].toString() << endl;
					if(possibleThingCharas[ee]==ch[f].toString()){
						hasChara=true;
					}
				}
				if(hasChara==false){
					possibleThings.erase(possibleThings.begin()+i);
					cout << "Erased thing " << thingInPossibleThings.toString() << endl;
				}
					
				cout << possibleThings[i].toString() << endl;
				
			}
		}
		
		else if(answer=="n"||answer=="no"||answer=="N"||answer=="No") 
		{
			answered=true;
			noChara.push_back(ch[f]);
			for(int w=0; w<charaThing.size(); w++)
			{ 
				for(int y=0; y< possibleThings.size(); y++)
				{
					if(possibleThings[y].toString()==charaThing[w].toString()){
						cout << "Erasing: " << possibleThings[y].toString()<< endl;
						possibleThings.erase(possibleThings.begin()+y);
						
						cout << "Possible things: " << endl;
						for(int r=0; r< possibleThings.size(); r++){
							cout << possibleThings[r].toString() << endl;
						}
					}
				}
			}
		}
		/** make sure you make it so that if there isn't anything in the list it makes a new one
		 * make it a method call most likly
		 * */
		if(possibleThings.size()==1||tracker==(ch.size())) 
		{
			cout << "End of the line" << endl;
			cin.ignore();
			answered=true;
			string won="";
			if(tracker==(ch.size())){
				won="no";
			}
			else{
				cout << "Is your thing: " << possibleThings[0].toString() << "?" << endl;
				getline(cin,won);
				cout << "Answer: " << won << endl;
				
			}
			if(won=="y"||won=="yes"||won=="Y"||won=="Yes")
			{
				cout << "I WIN! :D" <<endl;
				ch.clear();
			}
		
			else if(won=="n"||won=="no"||won=="N"||won=="No") 
			{
				//cin.ignore();
				//if(tracker==ch.size()){ //TAKE THIS OUT MAYBE
					cout << "What were you thinking of?" << endl;
					string newThing;
					getline(cin, newThing);
					cout << "New Thing: " << newThing << endl;
					int indexInFile=-1;
					cout << "Thinglist Size: " << thingList.size() << endl;
					for(int j=0; j< thingList.size(); j++) //I have some problems with this loop
					{
						answered=true;
						cout << "checking existance" << endl;
						
						
						Thing existing=thingList[j];
						cout << "Existing: " << thingList[j].toString() << endl;
						
						if(newThing==existing.toString()) //thing is already in file
						{
							indexInFile=j;
							
						}
						else
							cout << "Doesn't exist here" << endl;
					}
				cout << "Got out of existing loop" << endl;
				if(indexInFile<0) //if it doesn't exist already
				{ 
					cout << "Chara size: " << charas.size();
					cout << "Didn't find in file" << endl;
					
					vector<string> newestCharas; 

					for(int kk=0;kk<charas.size(); kk++){
						cout << "Adding: " << charas[kk].toString();
						newestCharas.push_back(charas[kk].toString());
					}
					cout << "Lists copied" << endl;
					string going="";

					while(going!="q"||newestCharas.size()==0)
					{
						string chara="";
						cout << "Please enter a new characteristic." << endl;
						
						getline(cin, chara);
						if(!stringExistsInList(chara, newestCharas)){
							newestCharas.push_back(chara); 
						}
						cout << "New chara: " << chara << endl;
						cout << "If you are done entering characteristics, type 'q'. Otherwise, hit enter to continue." << endl;
						cin>>going;
						cin.ignore();
					}
		
					cout << "New thing created" << endl;
					addNewThingToFile(Thing(newThing, newestCharas, thingList.size()+1), filename);
					
					ch.clear();
				}
				else  //HEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRRRRRREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
				{
					Thing existing=thingList[indexInFile];
					cout << existing.toString() << " already exists in my system." << endl;
					vector<string> newestCharas; 

					for(int kk=0;kk<charas.size(); kk++){
						cout << "Adding: " << charas[kk].toString();
						newestCharas.push_back(charas[kk].toString());
					}
					cout << "Lists copied" << endl;
					string going="";

					while(going!="q"||newestCharas.size()==0)
					{
						string chara="";
						cout << "Please enter a new characteristic." << endl;
						
						getline(cin, chara);
						if(!stringExistsInList(chara, newestCharas)){
							newestCharas.push_back(chara); 
						}
						cout << "New chara: " << chara << endl;
						cout << "If you are done entering characteristics, type 'q'. Otherwise, hit enter to continue." << endl;
						cin>>going;
						cin.ignore();
					}
					int index=existing.getLineNum();
					Thing testingThing=thingList[index];
					vector<string> testingCharas=testingThing.getChara();
					for(int er=0; er<newestCharas.size(); er++){
						for(int lm=0; lm< testingCharas.size();lm++){
							if(newestCharas[er]==testingCharas[lm]){
								newestCharas.erase(newestCharas.begin()+er);
							}
						}
					}
		
						
							
					string line=getLineFromIndex(filename, existing.getLineNum());
					line=addToLine(line, newestCharas);
					int test=appFile(filename, line, existing.getLineNum()); 
					if(test == -1)
					{
						cout << "ERROR!!!" << endl;
					}
					ch.clear(); //Exits loop
				//}
			}
		}

	}
}

}
	outstream.close();
	return 0;
	
}

/**
 * Will loop through the vector of things and add each characteristic to a vector of Chara. 
 * Each Chara instance has all the things that have that characteristic.
 * */
vector<Chara> setCharacteristics(vector<Thing> thingList)  
{
	//cout << "doing the thing" << endl;
	vector<Chara> c;
	
	for(int i=0; i< thingList.size(); i++){ //for each thing in vector
		Thing thing=thingList[i];
		//cout << "THING: " << thing.toString() << endl;
		vector<string> thingCharaList=thing.getChara(); //thingCharaList is the list of characteristics for each thing
		//cout << "thingCharaList.size()= "<< thingCharaList.size()<<endl;
		for(int t=0; t<thingCharaList.size(); t++){ //loop through each thing's characteristics
			
			string thingChara=thingCharaList[t]; //thingChara=characteristic
			thingChara=trim(thingChara);// remove whitespace
			//cout << "thing chara #"<<t<<": "<<thingChara<<endl;
			int existingI=-1;
			
			for(int k=0; k<c.size(); k++){ //loop through chara in c 
				if(thingChara==c[k].getName()){ //if the chara exists in vector c already
					existingI=k;
					//cout<< "Index: " << existingI << endl;
				}
				
			}
			if(existingI>=0){
				c[existingI].addThing(thing);
				//cout<< "existing " << thingChara<< endl;
			}
			else{
					c.push_back(Chara(thingChara, thing)); //adds a new chara to vector with name thingChara and one thing in vector
					//cout << "New "<<thingChara << endl;
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
	if(in){
		int i=0;
	while( getline(in, line) ){
		if(!line.empty()){
			cout << "Line: " << line << endl;
			int at_delim=line.find("@"); 
			
			if(at_delim!=std::string::npos)
			{
				string thingName=line.substr(0, at_delim); //the string before the @ symbol
				cout << "ThingName: " << thingName << endl;
				line=line.substr(at_delim+1);
				int com_delim=line.find(",");
				vector<string> charas;
		
				while(com_delim!=std::string::npos){ //will loop through all the commas
					cout << "Chara: " << line << endl;
					charas.push_back(line.substr(0, com_delim)); //add to charas vector
					line=line.substr(com_delim+1);
					line=trim(line);
					com_delim=line.find(",");
				}
				
				cout << "Final chara " << line << endl;
				charas.push_back(line);
				if(charas.size()>0){
					cout << "Attempting creating, line num: " << i << endl;
					thingList.push_back(Thing(thingName, charas, i)); //getting seg faults on this line when index==2
					cout << "New thing created, line num: " << i << endl;
					i++;
				}
				else{
					cout<<"Error: No Charactoristics found for " << thingName <<endl;  //If the thing has no characteristics- error in file.
				}
			}
		}
	}
	in.close();
	cout << "Success!" << endl;

}
else{
	cout << "Error opening file." << endl;
}
return thingList;
			
}


int appFile(string filename, string newLine, int linenum){
	ofstream outfile("temp.txt");
	ifstream infile(filename.c_str());
	string tempStr;
	int l=0;
	if(!outfile){
		cout<< "error opening temp file" << endl;
		return -1;
	}
	while( getline(infile, tempStr) ){
		if(l==linenum){
			tempStr=newLine;
			tempStr+="\n";
		}
		l++;
		
		outfile << tempStr;
	}
	rename("temp.txt", filename.c_str());
	outfile.close();
	infile.close();
	return 0;
}


string getLineFromIndex(string filename, int linenum){
	ifstream infile(filename.c_str());
	string tempstr;
	string line="";
	int currLine=0;
	if(!infile)
	{
		cout << "Error opening file: getLineFromIndex" << endl;
		return "";
	}
	while( getline(infile, tempstr) )
	{
		if(linenum==currLine){
			line=tempstr;
			break; //have to exit loop somehow
		}
		currLine++;
	}
	if(line==""){
		cout << "Index out of bounds: getLinefromIndex" << endl;
	}
	infile.close();
	return line;
}

string addToLine(string line, vector<string> v){
	for(int i=0; i < v.size(); i++){
		line=line+","+v[i];
	}
	return line;
}

string trim(string str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}
int max (int one, int two){
	int r=one;
	if(two>one){
		r=two;
	}
	return r;
}

bool existsInList(Thing t, vector<Thing> v){
	bool b=false;
	for(int i=0; i<v.size(); i++){
		if(t.toString()==v[i].toString()){
			return true;
		}
	}
	return b;
}
bool stringExistsInList(string t, vector<string> v){
	bool b=false;
	for(int i=0; i<v.size(); i++){
		if(t==v[i]){
			return true;
		}
	}
	return b;
}

void addNewThingToFile(Thing t, string filename){
	ofstream ofile(filename, ios::app);
	if(!ofile.is_open()){
		cout << "Error opening file." << endl;
		return;
	}
	string addedString=t.getName()+"@";
	vector<string> charas=t.getChara();
	string str="";
	for(int i=0; i< charas.size(); i++){
		if(i==0){
			str+=charas[i];
		}
		else
			str=str+","+charas[i];
		
	}
	addedString+=(str+"\n");
	ofile<<addedString;
	ofile.close();
	cout << "Added to file " << endl;
}


