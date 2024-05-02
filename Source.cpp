#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year);


int main() {

	
}

//This function determines whether a given year is a leap year under the Gregorian calendar
bool isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}