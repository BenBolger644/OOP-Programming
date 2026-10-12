#include <iostream>
#include "Beacon.h"
#include "Receiver.h"
#include "BeaconPool.h"

int main()
{
	std::cout << "Beacon Pool Lab\n";

	std::cout << "\nConnection Check\n";

	BeaconPool testPool{};

	Beacon demoBeacon{ 10 };
	Receiver receiver{ 35 };
	std::cout << "Range to Beacon: " << receiver.rangeTo(demoBeacon) << "\n";

	return 0;
}