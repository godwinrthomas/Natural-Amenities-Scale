// header guard
#ifndef AMENITY_H
#define AMENITY_H

// include header files
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <numeric>

// for declaring the scope
using std::string;
using std::ifstream;
using std::cout;
using std::cerr;
using std::vector;
using std::accumulate;
using std::inner_product;


// amenity class
class Amenity
{
	// data members
	
	float COMP_AMENITY; // composite amenity value
	float AVG_JAN_TEMP; // average January temperature
	float TOTAL_JAN_SUN; // total amount of January sunshine
	float AVG_JUL_TEMP; // average July temperature
	float AVG_JUL_HUMIDITY; // average July humidity
	float WATER_TERRAIN; // amount of terrain next to water
	int landform; // landform type based on terrain variations
	int ID; // for identification purposes
	string COUNTRY_NAME; // name of the country
	string STATE_NAME; // two letter abbreviation for State
	
	public:

	// accesor methods
	float get_amenity() const; // accessor method for the composite amenity value
	float get_jan_temp() const; // accessor method for the average January temparture
	float get_jan_sun() const; // accessor method for the total January sunshine
	float get_jul_temp() const; // accessor method for the average July temperature
	float get_jul_humidity() const; // accessor method for the average July humidity
	float get_water_terrain() const; // accessor method for the terrain next to water
	int get_landform() const; // accessor method for the landform
	int get_ID() const; // accessor method for the ID
	string get_country_name() const; // accessor method for the country name
	string get_state_name() const; // accessor method for the state name

	// setter methods
	void set_amenity(float); // setter method for the composite amenity value
	void set_jan_temp(float); // setter method for the average January temparture
	void set_jan_sun(float); // setter method for the total January sunshine
	void set_jul_temp(float); // setter method for the average July temperature
	void set_jul_humidity(float); // setter method for the average July humidity
	void set_water_terrain(float); // setter method for the terrain next to water
	void set_landform(int); // setter method for the landform
	void set_ID(int); // seter method for the ID
	void set_country_name(string); // setter method for the country name
	void set_state_name(string); // setter method for the state name	
};

// helper functions
bool COMPARISON_AVG_JAN_TEMP(Amenity &, Amenity&); // compare the average january temparature
bool COMPARISON_AVG_JAN_SUN(Amenity &, Amenity&); // compare the average january sunshine
bool COMPARISON_AVG_JUL_TEMP(Amenity &, Amenity&); // compare the average july temparature
bool COMPARISON_AVG_JUL_HUMIDITY(Amenity &, Amenity&); // compare the average july humidity
bool COMPARISON_AVG_LANDFORM(Amenity &, Amenity&); // compare the average landform
bool COMPARISON_AVG_WATER_TERRAIN(Amenity &, Amenity&); // compare the average water terrain
	
// end of header guard
#endif 
