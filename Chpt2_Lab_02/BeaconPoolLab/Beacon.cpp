#include "Beacon.h"

Beacon::Beacon(int t_x) // Initializes m_x directly from t_x using an member initializer list
	: m_x{ t_x }
{

}

int Beacon::x() const // Return the stored x coordinate of the beacon
{
	return m_x;
}

int Beacon::strength() const // Returns the stored strength of the beacon
{
	return m_strength;
}

bool Beacon::active() const // Return whether the beacon is active or not
{
	return m_active;
}

void Beacon::activate(int t_strength)
{
	m_strength = t_strength; // Set the strength of the beacon to the provided value
	m_active = true;
}

void Beacon::reset()
{
	m_strength = 0;
	m_active = false;
}