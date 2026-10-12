#include <iostream>
#include "Beacon.h"
#include "Receiver.h"
#include "BeaconPool.h"

int main()
{
	std::cout << "Beacon Pool Lab\n";

	std::cout << "\nConnection Check\n";

	Beacon demoBeacon{ 10 };
	Receiver receiver{ 35 };
	std::cout << "Range to Beacon: " << receiver.rangeTo(demoBeacon) << "\n";

	std::cout << "\nPool A\n";
	BeaconPool poolA{};
	std::cout << "Start Active: " << poolA.activeCount() << "\n";

	int first{ poolA.request(30) };
	int second{ poolA.request(60) };
	int third{ poolA.request(90) };
	int full{ poolA.request(50) };

	std::cout << "Request 30 -> slot " << first << '\n';
	std::cout << "Request 60 -> slot " << second << '\n';
	std::cout << "Request 90 -> slot " << third << '\n';
	std::cout << "Request 50 -> slot " << full << '\n';



	return 0;
}