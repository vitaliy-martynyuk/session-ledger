#include "globals.h"
#include "../helpers/compare.h"
#include "../consts/consts.h"

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

	void recordEntry(double hours)
	{
		sTotal += hours;
		if (Compare::doubles::isGreaterOrEqual(hours, Consts::minLongShiftHours)) {
			sLongShiftTotal += hours;
			++sLongShiftAmount;
		}
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