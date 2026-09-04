#include "validate.h"
#include "compare.h"
#include "../consts/consts.h"
#include "../globals/globals.h"
#include <cmath>
#include <algorithm>

namespace Validate
{
	bool isEntryHoursValid(double hours, double eps)
	{
		return
			hours > Consts::minEntryHours
			&& Compare::doubles::isLessOrEqual(hours, Consts::maxEntryHours);
	}
}