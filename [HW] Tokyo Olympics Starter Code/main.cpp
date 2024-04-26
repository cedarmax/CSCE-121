/******************************************************************************

File: ArraysHW.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section: 
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track 
event with 9 lanes. The code will sort the order, then display the results

Data File Information
name: data.csv
content: The csv file will contain data in the constant form of:
<Time (float)>,<Abbreviated Country (String)>,<Uniform number (int)>,<Lastname (String)>
32.7,USA,12,Moore
36.5,RUS,35,Polsley
45.8,ENG,73,Teale
52.34,CHN,14,Nemec
76.45,ITY,23,Lupoli     

* max 2 decimals

*******************************************************************************/

#include "parallel_tracks.h"
#include <fstream>

int main()
{
    // create arrays needed
	
    // prep all arrays
	
	// prompt until both the file and the contained data are valid
	
	// determine ranking, notice the rank array receives the results

	float timeArray[SIZE];
	std::string countryArray[SIZE];
	unsigned int numberArray[SIZE];
	std::string lastnameArray[SIZE];
	unsigned int rankArray[SIZE];
	prep_float_array(timeArray);
	prep_unsigned_int_array(numberArray);
	prep_unsigned_int_array(rankArray);
	prep_string_array(countryArray);
	prep_string_array(lastnameArray);
	std::ifstream inFS;
	std::string file;
	while (true) {
		try {
			std::cout << "Enter file name: ";
			std::cin >> file;
			get_runner_data(file, timeArray, countryArray, numberArray, lastnameArray);
			break;
		} catch (std::exception &e) {
			std::cout << "Invalid File: " << e.what() << std::endl;
		}
	}
	get_ranking(timeArray, rankArray);
	print_results(timeArray, countryArray, lastnameArray, rankArray);
    return 0;
}

