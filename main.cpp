#include "io/io.h"
#include "helpers/validate.h"
#include <iostream>

int main()
{
	double entry1{ Io::getEntryHours() };
	if (!Validate::isEntryHoursValid(entry1)) {
		std::cout << "Entry hours invalid!";

		return EXIT_FAILURE;
	}

	double entry2{ Io::getEntryHours() };
	if (!Validate::isEntryHoursValid(entry2)) {
		std::cout << "Entry hours invalid!";

		return EXIT_FAILURE;
	}

	double entry3{ Io::getEntryHours() };
	if (!Validate::isEntryHoursValid(entry3)) {
		std::cout << "Entry hours invalid!";

		return EXIT_FAILURE;
	}

	double entry4{ Io::getEntryHours() };
	if (!Validate::isEntryHoursValid(entry4)) {
		std::cout << "Entry hours invalid!";

		return EXIT_FAILURE;
	}

	Io::printEnrtyInfo(1, entry1);
	Io::printEnrtyInfo(2, entry2);
	Io::printEnrtyInfo(3, entry3);
	Io::printEnrtyInfo(4, entry4);

	return EXIT_SUCCESS;
}