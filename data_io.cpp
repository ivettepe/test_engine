#include "data_io.h"
#include "test_stand.h"
#include <iostream>

using namespace std;

void data_io::intput_temperature(double *outside_temperature) {
	cout << "Enter temperature => ";
	while (true) {
		if ((cin >> *outside_temperature).good()) break;
		if (cin.fail()) {
			cin.clear();
			cout << "Incorrect data. Enter new temperature => ";
		}
		cin.ignore(100, '\n');
	}
}

void data_io::output_time(const int time) {
	if (time == MAX_TIME)
		cout << "At this temperature, the engine cannot overheat.";
	else 
		cout << "Time of engine overheating: " << time << " sec";
}
