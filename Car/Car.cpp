#include <string>
#include <iostream>
#include "Car.h"

Car::Car() :m_isValid(true){}

Car::Car(const Car &car)
{
	strcpy_s(m_make, sizeof(m_make), car.m_make);
	strcpy_s(m_model, sizeof(m_model), car.m_model);
	m_year = car.m_year;
	m_engineVolume = car.m_engineVolume;
	strcpy_s(m_color, sizeof(m_color), car.m_color);
}

char* Car::getMake()
{
	return m_make;
}
void Car::setMake(const char *make)
{
	if (make == NULL || strlen(make) == 0)
	{
		printf("Please enter company make name\n");
		m_isValid = false;
	}
	else if (strlen(make) > 10)
	{
		printf("The max size of company make name be 10\n");
		m_isValid = false;
	}
	else
	{
		strcpy_s(m_make, sizeof(m_make), make);
	}
}

char* Car::getModel()
{
	return m_model;
}
void Car::setModel(const char *model)
{
	if (model == NULL || strlen(model) == 0)
	{
		printf("Please enter model name\n");
		m_isValid = false;
	}
	else if (strlen(model) > 10)
	{
		printf("The max size of model name be 10\n");
		m_isValid = false;
	}
	else
	{
		strcpy_s(m_model, sizeof(m_model), model);
	}
}

size_t Car::getYear() const
{
	return m_year;
}
void Car::setYear(int year)
{
	if (year <= 0 || year >= MAX_YEAR)
	{
		printf("The year of car is not valid\n");
		m_isValid = false;
	}
	else
	{
		m_year = year;
	}
}

size_t Car::getEngineVolume() const
{
	return m_engineVolume;
}
void Car::setEngineVolume(int engineVolume)
{
	if (engineVolume <= 0 || engineVolume >= MAX_VOLUME)
	{
		printf("The engine volume of car is not valid\n");
		m_isValid = false;
	}
	else
	{
		m_engineVolume = engineVolume;
	}
}

char* Car::getColor()
{
	return m_color;
}
void Car::setColor(const char *color)
{
	if (color == NULL || strlen(color) == 0)
	{
		printf("Please enter color of car\n");
		m_isValid = false;
	}
	else if (strlen(color) > 10)
	{
		printf("The max size of color be 10\n");
		m_isValid = false;
	}
	else
	{
		strcpy_s(m_color, sizeof(m_color), color);
	}
}

bool Car::getIsValid() const
{
	return m_isValid;
}

const Car& Car::compareTowCarsByYear(const Car &lhs, const Car &rhs)
{
	if (lhs.getYear() == rhs.getYear())
	{
		return lhs;
	}
	else
	{
		return lhs.getYear() > rhs.getYear() ? lhs : rhs;
	}
}

const Car& Car::compareTowCarsByVolume(const Car &lhs, const Car &rhs)
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

void Car::printCarDetailes()
{
	std::cout << "\n\nDetailes of car is\n-----------------------------" << std::endl;
	std::cout << "Company make name: " << this->getMake() << std::endl;
	std::cout << "Model: " << this->getModel() << std::endl;
	std::cout << "Year: " << this->getYear() << std::endl;
	std::cout << "Engine volume: " << this->getEngineVolume() << std::endl;
	std::cout << "Color: " << this->getColor() << std::endl;
	std::cout << "-----------------------------" << std::endl;
}