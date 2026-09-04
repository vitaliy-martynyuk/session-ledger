#include "validate.h"
#include "../consts/consts.h"
#include <cmath>
#include <algorithm>

namespace Validate
{
	bool isEntryHoursValid(double hours, double eps)
	{
		return (hours > Consts::minEntryHours) && ((Consts::maxEntryHours - hours) >= -eps);
	}
}