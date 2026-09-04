#ifndef GLOBALS_H
#define GLOBALS_H

namespace Globals
{
	int id();
	void addTotalHours(double hours = 0.0);
	void addLongShiftTotalHours(double hours = 0.0);
	int getTotalEntries();
	double getTotalHours();
	double getLongShiftAverageHours();
}

#endif
