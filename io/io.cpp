#include "io.h"
#include <iostream>

namespace Io
{
	using std::cin;
	using std::cout;

	double getEntryHours()
	{
		cout << "Enter entry hours(0<hours<=12.0): ";
		double input{};
		cin >> input;

		return input;
	}

	void printEnrtyInfo(int id, double hours)
	{
		cout << "Entry #" << id << ": " << hours << " hours\n";
	}

	void printSessionSummary(int totalEntries, double totalHours, double longShiftAverage)
	{
		cout << "--- Session Summary ---\n";
		cout << "Total entries: " << totalEntries << '\n';
		cout << "Total hours: " << totalHours << '\n';
		cout << "Long-shift average: " << longShiftAverage << '\n';
	}
}