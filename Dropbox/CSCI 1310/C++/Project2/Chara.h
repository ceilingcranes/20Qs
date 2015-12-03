#ifndef CHARA_H
#define CHARA_H

#include "Thing.h"

class Chara{
	private:
		std::string name;
		std::vector<Thing> thingList;
	public:
		Chara(std::string);
		Chara(std::string, Thing); //name and one thing
		Chara(std::string, std::vector<Thing>);
		std::string getName();
		void setName(std::string);
		void addThing(Thing);
		void setThing(int, Thing);
		std::vector<Thing> getThingList();
		std::string toString();
};



#endif
