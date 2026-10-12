#include <iostream>
#include "Beacon.h"
#include "Receiver.h"
#include "BeaconPool.h"

int main()
{

	std::cout << std::boolalpha; // Print bools as true/false instead of 1/0

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

	std::cout << "Active beacons: " << poolA.activeCount() << '\n';
	std::cout << "Successful requests: " << BeaconPool::successfulRequests() << '\n';

	std::cout << "\nRelease and reuse\n";
	bool released{ poolA.release(second) };
	std::cout << "Released slot " << second << ": " << released << '\n';
	std::cout << "Strength after release: " << poolA.strengthAt(second) << '\n';
	int reused{ poolA.request(75) };
	std::cout << "Request 75 -> slot " << reused << '\n';
	std::cout << "Active beacons: " << poolA.activeCount() << '\n';
	std::cout << "Successful requests: " << BeaconPool::successfulRequests() << '\n';



	return 0;
}