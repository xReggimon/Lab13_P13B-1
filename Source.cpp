#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);


int main() {
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
		if (!(iss >> inputMonth >> inputDay >>  inputYear)) {
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
	int dow = dayOfWeek(inputMonth, inputDay, inputYear);

	cout << dayNames[dow] << "," << months[inputMonth - 1] << " " << inputDay << ", " << inputYear << endl;

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