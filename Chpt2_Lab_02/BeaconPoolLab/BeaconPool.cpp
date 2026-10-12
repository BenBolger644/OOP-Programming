#include "BeaconPool.h"

int BeaconPool::s_successfulRequests{ 0 };

bool BeaconPool::release(int t_index)
{
	if (t_index < 0 || t_index >= CAPACITY)
	{
		return false; // Invalid index
	}

	if (!m_beacons[t_index].active())
	{
		return false; // Already free, nothing to release
	}

	m_beacons[t_index].reset();
	return true;
}

int BeaconPool::strengthAt(int t_index) const
{
	if (t_index < 0 || t_index >= CAPACITY)
	{
		return -1; // Invalid index
	}

	return m_beacons[t_index].strength();
}

int BeaconPool::successfulRequests()
{
	return s_successfulRequests;
}

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