#include <iostream>
using namespace std;

//This is the border display for the menu and clocks
void Asterisk26() {
	cout << string(26, '*');
}

//Display the menu options for the clock
void DisplayMenu() {
	Asterisk26();
	cout << endl;
	cout << "* 1-Add One Hour         *" << endl;
	cout << endl;
	cout << "* 2-Add One Minute       *" << endl;
	cout << endl;
	cout << "* 3-Add One Second       *" << endl;
	cout << endl;
	cout << "* 4-Exit Program         *" << endl;
	Asterisk26();
	cout << endl;
}

//Formatting single digits into two digits
void FormatTwoDigits(int number) {
	
	if (number < 10) {
		cout << "0" << number;
	}
	else {
		cout << number;
	}
}


//An attempt to display both clocks accurately
void DisplayClock(int hours, int minutes, int seconds) {
	Asterisk26();
	cout << "     ";
	Asterisk26();
	cout << endl;	
	cout << "*      12-Hour Clock     *" << "    " << " *      24-Hour Clock     *" << endl;
	cout << "*      ";
	if (hours >= 22) {
		cout << hours - 12 << ":";
		FormatTwoDigits(minutes);
		cout << ":";
		FormatTwoDigits(seconds);
		cout << " P M";
	}
	else if (hours >= 13 && hours <= 21) {
		cout << "0" << hours - 12 << ":";
		FormatTwoDigits(minutes);
		cout << ":";
		FormatTwoDigits(seconds);
		cout << " P M";
	}
	else if (hours == 12) {
		cout << hours << ":";
		FormatTwoDigits(minutes); 
		cout << ":";
		FormatTwoDigits(seconds);
		cout << " P M";
	}
	else {
		FormatTwoDigits(hours);
		cout << ":";
		FormatTwoDigits(minutes);
		cout << ":";
		FormatTwoDigits(seconds);
		cout << " A M";
	}

	cout << "      *" << "     " << "*        ";
	FormatTwoDigits(hours);
	cout << ":";
	FormatTwoDigits(minutes);
	cout << ":";
	FormatTwoDigits(seconds);
	cout << "        *" << endl;
	
	Asterisk26();
	cout << "     ";
	Asterisk26();
	cout << endl;
		
}


void AddHour(int& hour) {
	if (hour < 24 && hour >= 0) {
		hour += 1;
	}
	if (hour == 24) {
		hour = 0;
	}

}
void AddMinute(int& minute) {
	if (minute < 60 && minute >= 0) {
		minute += 1;
	}
	if (minute == 60) {
		minute = 0;
	}
}
void AddSecond(int& second) {
	if (second < 60 && second >= 0) {
		second += 1;
	}
	if (second == 60) {
		second = 0;
	}
}



int main () {
	bool quit = false;
	bool end = false;
	int choice;
	int hours;
	int minutes;
	int seconds;
	
	while (!end) {
		cout << "What is the initial time in military time?" << endl;
		cout << "Hours(HH):" << endl;
		cin >> hours;
		if (hours < 0 || hours > 23) {
			cout << "Hours must be between 0 and 23." << endl;
			cout << "Hours:" << endl;
			cin >> hours;
		}
		cout << "Minutes(MM):" << endl;
		cin >> minutes;
		if (minutes < 0 || minutes > 59) {
			cout << "Minutes must be between 0 and 59." << endl;
			cout << "Minutes:" << endl;
			cin >> minutes;
		}
		cout << "Seconds(SS):" << endl;
		cin >> seconds;
		if (seconds < 0 || seconds > 59) {
			cout << "Seconds must be between 0 and 59." << endl;
			cout << "Seconds:" << endl;
			cin >> seconds;
		}
		end = true;
	}
	
	
	while (!quit) {
		cout << "Choose an option:" << endl;
		DisplayMenu();
		cin >> choice; //User input for menu option

		if (choice == 1) {
			//Add hour
			AddHour(hours);
			DisplayClock(hours,minutes,seconds);
			continue;
		}
		else if (choice == 2) {
			//add minute
			AddMinute(minutes);
			DisplayClock(hours, minutes, seconds);
			continue;
		}
		else if (choice == 3) {
			//add second
			AddSecond(seconds);
			DisplayClock(hours, minutes, seconds);
			continue;
		}
		else if (choice == 4) {
			//exit
			quit = true;
		}
		else {
			cout << "Enter valid input" << endl;
			continue;
		}
	}
	

	cout << "program terminated";


	return 0;
}