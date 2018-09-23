/*  Name : Godwin Richard Thomas
 *  CSCI 689/0001
 *  TA Name : Nithin Devang
 *  Assignment Number : 7
 *  Due Date : 05/04/2018
 */


#include "Amenity.h"
// accessor method for the composite amenity value
float Amenity::get_amenity() const
{
	return COMP_AMENITY;
}

// accesor method for the average January temperature
float Amenity::get_jan_temp() const
{
	return AVG_JAN_TEMP;
}

// accesor method for the total amount of January sunshine
float Amenity::get_jan_sun()const
{
	return TOTAL_JAN_SUN;
}

// accesor method for the average July temperature
float Amenity::get_jul_temp()const 
{
	return AVG_JUL_TEMP;
}

// accesofr method for the aveage July humidity
float Amenity::get_jul_humidity()const
{
	return AVG_JUL_HUMIDITY;
}

// accessor method for the terrain next to water
float Amenity::get_water_terrain()const
{
	return WATER_TERRAIN;
}

// accesor method for the landform
int Amenity::get_landform()const
{
	return landform;
}

// accesor method for the ID
int Amenity::get_ID()const
{
	return ID;
}

// accessor method for the country name
string Amenity::get_country_name() const
{
	return COUNTRY_NAME;
}

// accesor method for the state code
string Amenity::get_state_name()const
{
	return STATE_NAME;
}

// setter method for the composite amenity value
void Amenity::set_amenity(float val)
{
	COMP_AMENITY = val;	
}

// setter method for the average January temperature
void Amenity::set_jan_temp(float val)
{
	AVG_JAN_TEMP = val;
}

// setter method for the total amount of January sunshine
void Amenity::set_jan_sun(float val)
{
	TOTAL_JAN_SUN = val;
}

// setter method for the average July temperature
void Amenity::set_jul_temp(float val)
{
	AVG_JUL_TEMP = val;
}

// setter method for the aveage July humidity
void Amenity::set_jul_humidity(float val)
{
	AVG_JUL_HUMIDITY = val;;
}

// setter method for the terrain next to water
void Amenity::set_water_terrain(float val)
{
	WATER_TERRAIN = val;
}

// setter method for the landform
void Amenity::set_landform(int val)
{
	landform = val;
}

// seter method for ID
void Amenity::set_ID(int val)
{
	ID = val;
}

// setter method for the country name
void Amenity::set_country_name(string val)
{
	COUNTRY_NAME = val;
}

// setter method for the state code
void Amenity::set_state_name(string val)
{
	STATE_NAME = val;
}

// helper function to compare the average january temparature
bool COMPARISON_AVG_JAN_TEMP(Amenity &a, Amenity &b)
{
	if(a.get_jan_temp() > b.get_jan_temp())
		return true;
	else	
		return false;
}
// helper function to compare the average january sunshine
bool COMPARISON_AVG_JAN_SUN(Amenity &a, Amenity &b)
{
	if(a.get_jan_sun() > b.get_jan_sun())
		return true;
	else	
		return false;
}
// helper function to compare the average july temparature
bool COMPARISON_AVG_JUL_TEMP(Amenity &a, Amenity &b)
{
	if(a.get_jul_temp() > b.get_jul_temp())
		return true;
	else	
		return false;
}
// helper function to compare the average july humidity
bool COMPARISON_AVG_JUL_HUMIDITY(Amenity &a, Amenity &b)
{
	if(a.get_jul_humidity() > b.get_jul_humidity())
		return true;
	else	
		return false;

} 
// helper function to compare the average landform
bool COMPARISON_AVG_LANDFORM(Amenity &a, Amenity &b)
{
	if(a.get_landform() > b.get_landform())
		return true;
	else	
		return false;
}
// helper function to compare the average water terrain
bool COMPARISON_AVG_WATER_TERRAIN(Amenity &a, Amenity &b)
{
	if(a.get_water_terrain() > b.get_water_terrain())
		return true;
	else	
		return false;
}


