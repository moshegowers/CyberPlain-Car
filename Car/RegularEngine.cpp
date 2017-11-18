#include "RegularEngine.h"
#include <iostream>

size_t RegularEngine::getEngineVolume() const
{
	return m_engineVolume;
}

void RegularEngine::setEngineVolume(size_t engineVolume)
{
	if (engineVolume >= MIN_ENGINE_VOLUME && engineVolume <= MAX_ENGINE_VOLUME)
	{
		m_engineVolume = engineVolume;
	}
}

const RegularEngine & RegularEngine::compareTowCarsByVolume(const RegularEngine & lhs, const RegularEngine & rhs)
{
	if (lhs.getEngineVolume() == rhs.getEngineVolume())
	{
		return lhs;
	}
	else
	{
		return lhs.getEngineVolume() > rhs.getEngineVolume() ? lhs : rhs;
	}
}

bool RegularEngine::getEngineDetailes()
{
	size_t engineVolume = 0;
	printf("Please insert engine volume of car\n");
	std::cin >> engineVolume;
	if (engineVolume < MIN_ENGINE_VOLUME || engineVolume > MAX_ENGINE_VOLUME)
	{
		printf("The engine volume is not valid. please insert value between %d and %d.\n", MIN_ENGINE_VOLUME, MAX_ENGINE_VOLUME);
		return false;
	}
	this->setEngineVolume(engineVolume);
	return true;
}

void RegularEngine::printEngineDetailes()
{
	std::cout << "The engine type is Regular and this engine volume is: " << m_engineVolume << std::endl;
}
