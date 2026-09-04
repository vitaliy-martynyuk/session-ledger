#include "io/io.h"
#include "helpers/validate.h"
#include "globals/globals.h"
#include <iostream>

int main()
{
	double entry1{ Io::getEntryHours() };
	if (!Validate::isEntryHoursValid(entry1)) {
		std::cout << "Entry hours invalid!";

		return EXIT_FAILURE;
	}
	Globals::recordEntry(entry1);

	double entry2{ Io::getEntryHours() };
	if (!Validate::isEntryHoursValid(entry2)) {
		std::cout << "Entry hours invalid!";

		return EXIT_FAILURE;
	}
	Globals::recordEntry(entry2);

	double entry3{ Io::getEntryHours() };
	if (!Validate::isEntryHoursValid(entry3)) {
		std::cout << "Entry hours invalid!";

		return EXIT_FAILURE;
	}
	Globals::recordEntry(entry3);

	double entry4{ Io::getEntryHours() };
	if (!Validate::isEntryHoursValid(entry4)) {
		std::cout << "Entry hours invalid!";

		return EXIT_FAILURE;
	}
	Globals::recordEntry(entry4);

	Io::printEnrtyInfo(Globals::id(), entry1);
	Io::printEnrtyInfo(Globals::id(), entry2);
	Io::printEnrtyInfo(Globals::id(), entry3);
	Io::printEnrtyInfo(Globals::id(), entry4);

	Io::printSessionSummary(Globals::getTotalEntries(), Globals::getTotalHours(), Globals::getLongShiftAverageHours());

	return EXIT_SUCCESS;
}