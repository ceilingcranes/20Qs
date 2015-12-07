/** Author: Maxine Hartnett
 * 
*/

#ifndef THING_H
#define THING_H

#include <vector>
#include <iostream>


class Thing{
	private:
		std::string name;
		std::vector<std::string> characteristics;
		int lineNum;
	public:
		Thing(std::string name, std::vector<std::string>, int);
		std::string getName();
		void setName(std::string);
		std::vector<std::string> getChara();
		void setChara(int index, std::string);
		void addChara(std::string);
		bool equals(Thing);
		void printChara();
		std::string toString();
		void setLineNum(int);
		int getLineNum();
		
	
};




#endif
