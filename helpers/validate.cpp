#include "validate.h"
#include "compare.h"
#include "../consts/consts.h"

namespace Validate
{
	bool isEntryHoursValid(double hours)
	{
		return
			hours > Consts::minEntryHours
			&& Compare::doubles::isLessOrEqual(hours, Consts::maxEntryHours);
	}
}