#ifndef IO_H
#define IO_H

namespace Io
{
	double getEntryHours();
	void printEnrtyInfo(int id, double hours);
	void printSessionSummary(int totalEntries, double totalHours, double longShiftAverage);
}

#endif