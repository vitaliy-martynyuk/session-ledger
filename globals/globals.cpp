#include "globals.h"

namespace Globals
{
	static int sId{ 0 };
	static double sTotal{ 0.0 };
	static double sLongShiftTotal{ 0.0 };
	static int sLongShiftAmount{ 0 };

	int id()
	{
		return ++sId;
	}

	void addTotalHours(double hours)
	{
		sTotal += hours;
	}

	void addLongShiftTotalHours(double hours)
	{
		sTotal += hours;
		sLongShiftTotal += hours;
		++sLongShiftAmount;
	}

	int getTotalEntries()
	{
		return sId;
	}

	double getTotalHours()
	{
		return sTotal;
	}

	double getLongShiftAverageHours()
	{
		return sLongShiftAmount ? sLongShiftTotal / static_cast<double>(sLongShiftAmount) : 0;
	}
}