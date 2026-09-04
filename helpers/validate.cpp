#include "validate.h"
#include "../consts/consts.h"
#include "../globals/globals.h"
#include <cmath>
#include <algorithm>

namespace Validate
{
	bool isEntryHoursValid(double hours, double eps)
	{
		if (((Consts::maxEntryHours - hours) >= -eps) && ((hours - Consts::minLongShiftHours) >= -eps)) {
			Globals::addLongShiftTotalHours(hours);

			return true;
		}
		else if ((hours > Consts::minEntryHours) && ((Consts::maxEntryHours - hours) >= -eps)) {
			Globals::addTotalHours(hours);

			return true;
		}

		return false;
	}
}