#ifndef GROCERYLIST_H
#define GROCERYLIST_H

//GroceryList class definition
class GroceryList {

public:
	void SearchList();
	void PrintList();
	void PrintHistogram();
	void ReadDataToOutputFile();

private:
	map<string, int> itemList;

};

#endif