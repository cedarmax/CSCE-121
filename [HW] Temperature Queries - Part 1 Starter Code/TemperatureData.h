/*
 * TemperatureData.h
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA
#include <string>

struct TemperatureData {
	// Put data members here
	TemperatureData();
	TemperatureData(std::string id, int year, int month, double temperature);
	virtual ~TemperatureData();
	bool operator<(const TemperatureData& b);
	std::string id;
	int year;
	int month;
	double temperature;
};

#endif /* TEMPERATUREDATA */
