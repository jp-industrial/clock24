//24-hour clock, 1/23 jp-ind.

//v1- copied from youtube video, cleaned up a little.
//v2- added error detection.
//v3- added comments.

#include "c:\Users\james\Desktop\std_lib_facilities.h"
#include <Windows.h> //we get the sleep() function from here.

void errors(string s) {
	throw runtime_error(s);
}

int main()
{
	int h = 0, m = 0, s = 0; //initialisation
	try {
		cout << "Hour: ";
		cin >> h;

		cout << "Minutes: ";
		cin >> m;

		cout << "Seconds: ";
		cin >> s;

		if (h > 23 || m > 59 || s > 59) //some basic input validation.
			errors("Entered time is impossibly large.\n");

		if (h < 0 || m < 0 || s < 0)
			errors("Negative values!\n");

		if (!cin) //is input even numerical?
			errors("input not recognised.\n");


		while (TRUE) {//assuming time value is valid, do:

			cout << h << ":" << m << ":" << s;
			Sleep(1000); //stop program execution for 1000ms.
			system("cls"); //clear the screen.

			s++; //increase second by one, and then check...

			if (s > 59) { 
				s = 0;
				++m;
			}

			if (m > 59) {
				m = 0;
				++h;
			}

			if (h > 23) {
				h = 0;
			}
		}
	}
	catch (runtime_error& e) { //catches errors from earlier.
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
}