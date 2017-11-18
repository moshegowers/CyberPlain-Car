#include <string>
#include <iostream>
#include "RegularEngine.h"
#include "ElectricEngine.h"
#include "Car.h"
using namespace CarNamespace;

void main(void)
{
	Car car;
	Engine *engine;
	EngineType enumEngineType = EngineType::Default;
	while (enumEngineType == EngineType::Default)
	{
		enumEngineType = car.getCarDetailes();
	}
	if (enumEngineType == EngineType::Regular)
	{
		engine = new RegularEngine;		
	}
	else if (enumEngineType == EngineType::Elctric) 
	{
		engine = new ElectricEngine;
	}
	engine->getEngineDetailes();
	car.setEngine(engine);
	car.printCarDetailes();

	std::cout << "\n************************************";
	std::cout << "\n* now we wiil change engine of car *";
	std::cout << "\n************************************\n";

	size_t engineType = static_cast<int>(EngineType::Default);
	do
	{
		printf("Please insert engine of car (use %d for regular or %d for electric\n", EngineType::Regular, EngineType::Elctric);
		std::cin >> engineType;
	} while (engineType != EngineType::Regular && engineType != EngineType::Elctric);

	if (engineType == EngineType::Regular)
	{
		engine = new RegularEngine;
	}
	else if (engineType == EngineType::Elctric)
	{
		engine = new ElectricEngine;
	}
	engine->getEngineDetailes();
	car.setEngine(engine);
	car.printCarDetailes();
}
