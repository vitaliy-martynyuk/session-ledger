#ifndef COMPARE_H
#define COMPARE_H

namespace Compare
{
	namespace doubles
	{
		inline bool isLessOrEqual(double x, double y, double eps = 1e-9)
		{
			return (y - x) >= -eps;
		}

		inline bool isGreaterOrEqual(double x, double y, double eps = 1e-9)
		{
			return (x - y) >= -eps;
		}
	}
}

#endif
