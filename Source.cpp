#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);


int main() {
	// Sa Fr Th We Tu Mo Su
		// returned by DoW funct.: 00 01 02 03 04 05 06 07 08 09 10 11 12
		// character positions: 012345678901234567890123456789012345678
	string calendar[] = { "						   1 2 3 4 5 6 7 ",
						 "  2  3  4  5  6  7  8  9 10 11 12 13 14 ",
						 "  9 10 11 12 13 14 15 16 17 18 19 20 21 ",
						 " 16 17 18 19 20 21 22 23 24 25 26 27 28 ",
						 " 23 24 25 26 27 28 29 30 31             ",
						 " 30 31								  " };
	string userInput;
	int inputYear;
	int inputMonth;
	int inputDay;

	vector<string> months = { "January", "February", "March", "April", "May", "June," "July", "August", "September", "October", "November", "December" };
	vector<string> dayNames = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };


	while (true) {
		cout << "Enter a month and year (MM YYYY) or Q to quit: ";
		getline(cin,userInput);

		if (userInput == "Q" || userInput == "q") {
			break;
		}

		istringstream iss(userInput);
		if (!(iss >> inputMonth >>  inputYear || inputMonth < 1 || inputMonth > 12 || inputYear < 1582)) {
			cout << "Invalid input." << endl;
			continue;
		}

/*		if (inputMonth < 1 || inputMonth > 12 || inputYear < 1582) {
			cout << "Invalid input. Months need to be between 1-12 and the year greater than at least 1582." << endl;
		}
		else {
			cout << months[inputMonth-1] << " " << inputYear << " has " << daysInMonth(inputMonth, inputYear) << " days." << endl;
			cout << inputYear << " is not a leap year." << endl;
		}
*/
	int firstDay = dayOfWeek(inputMonth, 1, inputYear);

	string adjustedCalendar[6];
	for (int i = 0; i < 6; i++) {
		adjustedCalendar[i] = calendar[i].substr(firstDay * 3);
	}

	cout << "   Su   M   Tu   W   Th   F   Sa" << endl;
	for (const auto& week : adjustedCalendar) {
		cout << week << endl;
	}
	}
	return 0;	
}

//This function determines whether a given year is a leap year under the Gregorian calendar
bool isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

//This function determines the number of days in a specified month. 

int daysInMonth(int month, int year) {
	switch (month) {
	case 2:
		return isLeapYear(year) ? 29 : 28;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	default: 
		return 31;
	}
}

int dayOfWeek(int month, int day, int year) {
	if (month < 3) {
		month += 12;
		year--;
	}

	int K = year % 100;
	int J = year / 100;
	int h = (day + (13 * (month + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
	return h;
}