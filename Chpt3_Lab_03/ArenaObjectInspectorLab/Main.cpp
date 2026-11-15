#include <iostream>
#include <typeinfo>
#include "ArenaObjects.h"
#include "Inspector.h"

int main()
{
	std::cout << std::boolalpha;
	std::cout << "Arena Object Inspector\n";

	Guard guard{ 60 };
	EliteGuard elite{ 90, 15 };
	SupplyCrate crate{ 4 };
	ArenaObject const* selected{ &guard };

	std::cout << "Shared Behaviour\n";
	selected->report();
	selected = &elite;
	selected->report();
	selected = &crate;
	selected->report();

	std::cout << "Checked Guard Views\n";
	std::cout << "Guard: " << readGuardHealth(&guard) << "\n";
	std::cout << "Elite Guard: " << readGuardHealth(&elite) << "\n";
	std::cout << "Supply Crate: " << readGuardHealth(&crate) << "\n";
	std::cout << "None: " << readGuardHealth(nullptr) << "\n";

	std::cout << "Exact Guard Checks\n";
	selected = &elite;
	std::cout << "Guard is exact Guard: " << isExactGuard(&guard) << "\n";
	std::cout << "Elite is exact Guard: " << isExactGuard(&elite) << "\n";
	std::cout << "Elite is exact EliteGuard: " << (typeid(*selected) == typeid(EliteGuard)) << "\n";
	std::cout << "Crate is exact Guard: " << isExactGuard(&crate) << "\n";
	std::cout << "Pointer is ArenaObject const*: " << (typeid(selected) == typeid(ArenaObject const*)) << "\n";

	std::cout << "Reference Casts\n";
	std::cout << "Guard Reference: " << requireGuardHealth(guard) << "\n";
	std::cout << "Crate Reference: ";
	try
	{
		std::cout << requireGuardHealth(crate) << "\n";
	}
	catch (std::bad_cast const&)
	{
		std::cout << "Not a guard\n";
	}

	ArenaObject const* slots[]{ &guard, &elite, &crate, nullptr };

	std::cout << "Selection\n";
	std::cout << "Guard-compatible: " << countGuardViews(slots, 4) << "\n";
	std::cout << "Exact guards: " << countExactGuards(slots, 4) << "\n";
	std::cout << "Empty selection: " << countGuardViews(nullptr, 0) << "\n";
	std::cout << "Missing storage: " << countGuardViews(nullptr, 1) << "\n";
}
