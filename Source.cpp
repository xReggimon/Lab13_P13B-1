#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);

void printCalendar(int month, int year);
void copyToFile(int month, int year);

// Sa Fr Th We Tu Mo Su
	// returned by DoW funct.: 00 01 02 03 04 05 06 07 08 09 10 11 12
	// character positions: 012345678901234567890123456789012345678
string calendar[6] =	  {"                    1  2  3  4  5  6  7 ",
					       "  2  3  4  5  6  7  8  9 10 11 12 13 14 ",
					       "  9 10 11 12 13 14 15 16 17 18 19 20 21 ",
					       " 16 17 18 19 20 21 22 23 24 25 26 27 28 ",
					       " 23 24 25 26 27 28 29 30 31             ",
					       " 30 31                                  " };
int year;
string month;
char check[1];
string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
string days[7] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
string fileName;

int main() {
	
	while (true) {
		cout << "Enter a month and year or Q to quit: ";
		cin >> month >> year;

		if (month == "Q" || month == "q") {
			return 0;
		}

		int monthIndex;
		for (int i = 0; i < 12; i++) {
			if (month == months[i]) {
				monthIndex = i + 1;
			}
		}

		printCalendar(monthIndex, year);
		copyToFile(monthIndex, year);

	}
	return 0;
}

//This function determines whether a given year is a leap year under the Gregorian calendar
bool isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

//This function determines the number of days in a specified month. 

int daysInMonth(int month, int year) {
	isLeapYear(year);
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
	int K;
	int J;

	if (month < 3) {
		K = year - 1;
		J = month + 12;
	}
	else {
		K = year;
		J = month;
	}

	int h = (day + (int)floorf((J + 1) * 26 / 10) + K + (int)floorf(K / 4) + 6 * (int)floorf(K / 100) + (int)floorf(K / 400));
	return h % 7;
}

void printCalendar(int monthIndex, int year) {
	int daysMonth = daysInMonth(monthIndex, year);
	int startingDay = dayOfWeek(monthIndex, 1, year);
	int startPosition[7] = { 0,18,15,12,9,6,3 };
	cout << month << " " << year << endl;
	cout << " Su Mo Tu We Th Fr Sa" << endl;
	cout << calendar[0].substr(startPosition[startingDay], 21) << endl;
	cout << calendar[1].substr(startPosition[startingDay], 21) << endl;
	cout << calendar[2].substr(startPosition[startingDay], 21) << endl;
	cout << calendar[3].substr(startPosition[startingDay], 21) << endl;
	if (monthIndex == 11) {
		cout << calendar[4].substr(startPosition[startingDay], 15) << endl;
	}
	else if (monthIndex == 2) {
		cout << calendar[4].substr(startPosition[startingDay], 15) << endl;
	}
	else {
		cout << calendar[4].substr(startPosition[startingDay], 21) << endl;
	}
	cout << calendar[5].substr(startPosition[startingDay], 21) << endl;
}

void copyToFile(int monthIndex, int year) {
	int startingDay = dayOfWeek(monthIndex, 1, year);
	int startPosition[7] = { 0,18,15,12,9,6,3 };
	cout << "Output file: ";
	cin >> fileName;

	ofstream file;
	file.clear();
	file.open(fileName);
	file << month << " " << year << endl;
	file << "Su Mo Tu We Th Fr Sa" << endl;
	file << calendar[0].substr(startPosition[startingDay], 21) << endl;
	file << calendar[1].substr(startPosition[startingDay], 21) << endl;
	file << calendar[2].substr(startPosition[startingDay], 21) << endl;
	file << calendar[3].substr(startPosition[startingDay], 21) << endl;
	if (monthIndex == 11) {
		file << calendar[4].substr(startPosition[startingDay], 15) << endl;
	}
	else if (monthIndex == 2) {
		file << calendar[4].substr(startPosition[startingDay], 15) << endl;
	}
	else {
		file << calendar[4].substr(startPosition[startingDay], 21) << endl;
	}
	file << calendar[5].substr(startPosition[startingDay], 21) << endl;
	cout << calendar[5];
	file.close();
}
