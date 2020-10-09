
/*
	Aman Garlapati
	agarlap@g.clemson.edu
	TAs: Elliot and Victoria
	FALL 2020
	CPSC 1020 - 003
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct Employee{
	string lastName;
	string firstName;
	int birthYear;
	double hourlyWage;
}employee;

bool name_order(const employee& lhs, const employee& rhs);
int myrandom (int i) { return rand()%i;}

int main(int argc, char const *argv[]) {

	int entry, shuffleindex; // loop constants
	employee employee_list[10]; // our employee struct
	employee * startingptr = &employee_list[0];
	employee * endingptr = &employee_list[10];
	
	employee subset[5]; // 5 employees from first 5 cards of random shuffle

	// seeding random generator

	srand(unsigned (time(0)));

	// making and filling array of 10 employees

	for (entry = 0; entry < 10; entry++) {
	
		cout << "\nEnter employee " << entry+1 << " first name\n";
		cin >> employee_list[entry].firstName;
		
		cout << "Enter employee " << entry+1 << " last name\n";
		cin >> employee_list[entry].lastName;
		
		cout << "Enter employee " << entry+1 << " birth year\n";
		cin >> employee_list[entry].birthYear;

		cout << "Enter employee " << entry+1 << " hourly wage\n";
		cin >> employee_list[entry].hourlyWage;
	}

	// calling random shuffle function to shuffle our 10 employee entries

	random_shuffle(startingptr, endingptr, myrandom);

	
	// making small array of 5 employees from first 5 cards of array
	// 	made above

	for(shuffleindex = 0; shuffleindex < 5; shuffleindex++)
	{
		subset[shuffleindex] = employee_list[shuffleindex];
	}

	// sorting new array with the subset struct and the name_order
	// 	boolean comparator

	sort(subset, subset + 5, name_order);

	// printing the subset array

	for(entry = 0; entry < 5; entry++) {
		
		cout << "\nEmployee " << entry+1 << "\n";

		cout << setw(25) << right << subset[entry].lastName + ", " + subset[entry].firstName << "\n";
		cout << setw(25) << right << subset[entry].birthYear << "\n";
		cout << setw(25) << right << subset[entry].hourlyWage << "\n";

	}

	return 0;

}


// function used as the comparator to sort the subset structs by last name
// 	by checking if each
// inputs: employee struct addresses of lhs and rhs
// outputs: comparator boolean value to tell if two entries should stay or swap
bool name_order(const employee& lhs, const employee& rhs) {

	return lhs.lastName < rhs.lastName;

}


