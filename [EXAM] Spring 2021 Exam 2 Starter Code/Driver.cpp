/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc 
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>       /* fabs */
using namespace std;


#include "EarthQuake.h"


int main()
{
	/* create QuakeDataSegment pointer to hold the data array */
	QuakeDataSegment* dataSegment = nullptr;
	/* earthquake object will manage all the quakedata array manipulation */
	EarthQuake bigTest;

	/* load data into array */
	//bigTest.displayDataSegment(dataSegment);

	try
	{
		bigTest.loadEarthquakeData(dataSegment, "gooddata1.txt"); // handles data length
	}
	catch (std::invalid_argument& e) {
		std::cout << "Invalid File: " << e.what() << std::endl;
		return 0;
	}


	//bigTest.loadEarthquakeData(dataSegment, "gooddata2.csv");
	//bigTest.displayDataSegment(dataSegment);
	
	/* now SET all data from EarthQuake Data */
	bigTest.setMaxAmplitude(dataSegment);
	bigTest.setMinAmplitude(dataSegment);
	bigTest.setSWaveIndex(dataSegment);
	bigTest.setEarthquakeLocation(dataSegment);
	bigTest.setChangeInLatLong(dataSegment);
	bigTest.setDistanceFromQuake();
	bigTest.setChangeInDepth(dataSegment);

	/* use overloaded operator to output EarthQuake Data */
	cout << bigTest << endl; // should display ALL results
	
	/* free any memory pointed to by the data array */
	delete[] dataSegment;
//	QuakeDataSegment* segarr = {};
//	EarthQuake::resizeArray(segarr);
	return 0;
}
