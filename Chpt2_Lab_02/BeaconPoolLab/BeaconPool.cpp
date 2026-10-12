#include "BeaconPool.h"

int BeaconPool::s_successfulRequests{ 0 };

int BeaconPool::request(int t_strength)
{
	if (t_strength < 1 || t_strength > 100)
	{
		return -1; // Invalid strength, return -1
	}

	for (int i{ 0 }; i < CAPACITY; ++i)
	{
		if (!m_beacons[i].active())
		{
			m_beacons[i].activate(t_strength);
			++s_successfulRequests;
			return i; // Return the index of the activated beacon
		}
	}

	return -1; // Every slot is active, return -1

}

int BeaconPool::activeCount() const
{
	int count{ 0 };
	for (int i{ 0 }; i < CAPACITY; ++i)
	{
		if (m_beacons[i].active())
		{
			++count;
		}
	}
	return count;
}