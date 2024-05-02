#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year);


int main() {
	string userInput;
	int inputYear;

	while (true) {
		cout << "Enter a year or Q to quit: ";
		cin >> userInput;

		if (userInput == "Q" || userInput == "q") {
			break;
		}

		try {
			inputYear = stoi(userInput);

			if (isLeapYear(inputYear)) {
				cout << inputYear << " is a leap year." << endl;
			}
			else {
				cout << inputYear << " is not a leap year." << endl;
			}
		}
		catch (const invalid_argument& e) {
			cout << "Invalid input." << endl;
		}
	}
	return 0;
	
}

//This function determines whether a given year is a leap year under the Gregorian calendar
bool isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	//
}