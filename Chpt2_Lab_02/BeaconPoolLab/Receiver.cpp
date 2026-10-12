#include "Receiver.h"
#include "Beacon.h"
#include <cstdlib>

Receiver::Receiver(int t_x) //initialize m_x directly from t_x using a member initializer list
	: m_x{t_x}
{
}

int Receiver::rangeTo(Beacon const& t_beacon) const // Return the non-negative distance between receiver x and beacon x
{
	return std::abs(m_x - t_beacon.x());
}