#include "io/io.h"
#include <iostream>

int main()
{
	double entry1{ Io::getEntryHours() };
	double entry2{ Io::getEntryHours() };
	double entry3{ Io::getEntryHours() };
	double entry4{ Io::getEntryHours() };

	Io::printEnrtyInfo(1, entry1);
	Io::printEnrtyInfo(2, entry2);
	Io::printEnrtyInfo(3, entry3);
	Io::printEnrtyInfo(4, entry4);

	return 0;
}