#include "Engine.h"

#ifndef REGULAR_ENGINE_H
#define REGULAR_ENGINE_H

#define MAX_ENGINE_VOLUME 3500
#define MIN_ENGINE_VOLUME 900
class	RegularEngine : public Engine
{
public:
	RegularEngine(size_t engineVolume) : m_engineVolume(engineVolume)
	{}


	// return engine volume of car
	size_t getEngineVolume() const;
	// assine engine volume of car
	void setEngineVolume(size_t engineVolume);

	//return the greater car, compare it by engine volume of car
	static const RegularEngine& compareTowCarsByVolume(const RegularEngine &lhs, const RegularEngine &rhs);

	bool getRegularEngineDetailes();
	void printEngineDetailes();

private:
	size_t	m_engineVolume;
};

#endif
