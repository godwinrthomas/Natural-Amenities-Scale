// header guards
#ifndef GOODGUY_H
#define GOODGUY_H


// definitions
const int JAN_TEMP = 0;  // for indicating january temparature
const int JAN_SUN = 1; // for indicating the january sunshine
const int JUL_TEMP = 2; // for indicating july temperature
const int JUL_HUM = 3; // for indicating july humidity
const int LANDFORM = 4; // for indicating the landform
const int WATER_TERRAIN = 5; // for indicating the water terrain

// definition of class Amenity
class Amenity;

// Goodguy class 
class Goodguy
{
	// data members
	int data; // value to be set for accessing the individual amenities

	public:

	// setter method for setting the data
	int set_data(int val){ data=val; return data;}

	// the function operator is overloaded to print the country, state and respective amenity
	void operator()(Amenity &a);

	// comparision of composite amenity value
	bool operator()(Amenity &a, Amenity &b);	
};

// the function operator is overloaded to print the country, state and respective entity
void Goodguy::operator()(Amenity &a)
{
	// indicates that the field is average january temparature and prints the country, state and january temperature
	if(data == JAN_TEMP)
		cout<<a.get_country_name()<<" "<<a.get_state_name()<<" "<<a.get_jan_temp()<<"\n";
	
	// indicates that the field is average january sunshine and prints the country, state and january sunshine
	else if(data==JAN_SUN)
		cout<<a.get_country_name()<<" "<<a.get_state_name()<<" "<<a.get_jan_sun()<<"\n";
	
	// indicates that the field is average july temparature and prints the country, state and july temperature
	else if(data==JUL_TEMP)
		cout<<a.get_country_name()<<" "<<a.get_state_name()<<" "<<a.get_jul_temp()<<"\n";

	// indicates that the field is average july humidity and prints the country, state and july humidity
	else if(data==JUL_HUM)
		cout<<a.get_country_name()<<" "<<a.get_state_name()<<" "<<a.get_jul_humidity()<<"\n";

	// indicates that the field is average landform  and prints the country, state and landform
	else if(data==LANDFORM)
		cout<<a.get_country_name()<<" "<<a.get_state_name()<<" "<<a.get_landform()<<"\n";

	// indicates that the field is average water terrain and prints the country, state and water terrain
	else if(data==WATER_TERRAIN)
		cout<<a.get_country_name()<<" "<<a.get_state_name()<<" "<<a.get_water_terrain()<<"\n";
}

// compares the composite amenity values
bool Goodguy::operator()(Amenity &a, Amenity &b)
{
	if(a.get_amenity() > b.get_amenity())
		return true;
	else
		return false;
}

// prints the first n and last n values of the amenities
void print_top_bottom_n(vector<Amenity> &va, int n, Goodguy &g )
{
	
	// the first ten values
	for(int i=0; i<n;i++)
	{
		g(va[i]); // prints the value by calling the overloaded function operator
		
	}

	// formatting
	cout<<"\n";
	cout<<"................";
	cout<<"\n";
	cout<<"\n";

	// the last ten values
	for(unsigned int k = (va.size()-n); k<va.size();k++)
	{
		g(va[k]); // prints the value by calling the overloaded function operator
	}
}

// end of header guard
#endif
