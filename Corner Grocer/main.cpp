#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;

#include "GroceryList.h"

//function to display the main menu
int displayMainMenu() {
	//variable to track the user input
	int input =  0;
	while (input == 0) {
		cout << "Main Menu" << endl;
		cout << "[1] Search for item quantity by item name" << endl;
		cout << "[2] Print each item with its quantity" << endl;
		cout << "[3] Print histogram of item quantities" << endl;
		cout << "[4] Exit program" << endl;

		cin >> input;
		//make sure that the cin didnt fail
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
		//make sure that the input is actually one of the 4 integer options
		set<int> menuOptions = { 1, 2, 3, 4 };
		if (menuOptions.find(input) == menuOptions.end()) {
			cout << "Invalid entry. Please try again." << endl << endl;
			input = 0;
		}
	}
	return input;
}


int main() {
	// create a new GroceryList object
	GroceryList gl;
	// read the data from the input file to initialize the GroceryList itemList property and create a dat file to back up the data. 
	gl.ReadDataToOutputFile();
	int menuOption = -1;
	while (menuOption != 0) {
		cout << endl;
		//display the main menu for the user
		menuOption = displayMainMenu();
		if (menuOption == 1) {
			//if option 1 selected, run GroceryList searchList function
			gl.SearchList();
		}
		else if (menuOption == 2) {
			//if option 2 selected, run GroceryList printList function
			gl.PrintList();
		}
		else if (menuOption == 3) {
			//if option 3 selected, run GroceryList PrintHistogram function
			gl.PrintHistogram();
		}
		else if (menuOption == 4) {
			//if option 4 selected, exit the loop to end the program
			cout << "Thank you and goodbye!" << endl;
			break;
		}
	}
	return 0;
}