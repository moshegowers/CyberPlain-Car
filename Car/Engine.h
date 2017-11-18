#ifndef ENGINE_H
#define ENGINE_H

enum EngineType
{
	Default = 0,
	Regular = 1,
	Elctric = 2
};

class Engine
{
public:
	virtual void printEngineDetailes()
	{}
	virtual bool getEngineDetailes()
	{
		return EngineType::Default;
	}
};

#endif