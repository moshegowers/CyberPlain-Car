#include <string>
#include <iostream>
#include "Car.h"
using namespace CarNamespace;

int Car::s_licenseNum = 10000001;

Car::Car() :m_isValid(true)
{
	this->m_licenseNum = ++Car::s_licenseNum;
}

Car::Car(const Car &car)
{
	m_licenseNum = car.m_licenseNum;
	strcpy_s(m_make, sizeof(m_make), car.m_make);
	strcpy_s(m_model, sizeof(m_model), car.m_model);
	m_year = car.m_year;
	strcpy_s(m_color, sizeof(m_color), car.m_color);
}

int Car::getLicenseNum()
{
	return m_licenseNum;
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
	if (year < MIN_YEAR || year > MAX_YEAR)
	{
		printf("The year of car is not valid\n");
		m_isValid = false;
	}
	else
	{
		m_year = year;
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
void Car::setIsValid(bool isValid)
{
	m_isValid = isValid;
}

void Car::printCarDetailes()
{
	std::cout << "\n\nDetailes of car is\n-----------------------------" << std::endl;
	std::cout << "License number: " << this->getLicenseNum() << std::endl;
	std::cout << "Company make name: " << this->getMake() << std::endl;
	std::cout << "Model: " << this->getModel() << std::endl;
	std::cout << "Year: " << this->getYear() << std::endl;
	std::cout << "Color: " << this->getColor() << std::endl;
	std::cout << "-----------------------------" << std::endl;
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