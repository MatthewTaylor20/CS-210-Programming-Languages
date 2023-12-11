#include <iostream>
#include <map>
#include <fstream>
using namespace std;

#include "GroceryList.h"

void GroceryList::SearchList() {
	//variable to store the item the user inputs
	string item;
	while (true) {
		//ask the user what item they want to search for
		cout << "What item would you like to know the quantity for?" << endl;
		cin >> item;
		//if the cin fails then retry
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input. Try again.";
			continue;
		}
		//if the item is on the list, print the associated quantity
		else if (itemList.count(item) == 1) {
			cout << "The quantity is: " << itemList.find(item)->second << endl;
			break;
		}
		//if the item is not on the list print quantity 0
		else {
			cout << "The quantity is: " << 0 << endl;
			break;
		}
	}
}

void GroceryList::PrintList() {
	//iterate through the map and print each key value pair
	for (auto i : itemList) {
		cout << i.first << " " << i.second << endl;
	}
	cout << endl;
}

void GroceryList::PrintHistogram() {
	//iterate through the map and print each key with the quantity represented by the number of asterisks. 
	for (auto i : itemList) {
		cout << i.first << " ";
		//print the correct number of asterisks. 
		for (int j = i.second; j > 0; --j) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}

void GroceryList::ReadDataToOutputFile() {
	//create the input and output streams from and to files
	ifstream inFS;
	ofstream outFS;
	string word;
	map<string, int> wordList;

	//open the appropriate to and from files
	inFS.open("input.txt");
	outFS.open("frequency.dat");

	//verify that both files opened correctly
	if (!inFS.is_open()) {
		cout << "Could not open file input.txt." << endl;
		return;
	}
	if (!outFS.is_open()) {
		cout << "Could not open file frequency.dat." << endl;
		return;
	}

	//read the input file into a map
	inFS >> word;
	while (!inFS.fail()) {
		map <string, int>::iterator itr;
		itr = wordList.find(word);
		if (itr != wordList.end()) {
			itr->second = wordList.at(word) + 1;
		}
		else {
			wordList.emplace(word, 1);
		}
		inFS >> word;
	}
	//add the map data to the new data file
	for (auto i : wordList) {
		outFS << i.first << " " << i.second << endl;
	}
	//close files when done with them.
	inFS.close();
	outFS.close();

	//set the GroceryList property item List equal to the wordList
	itemList = wordList;
}