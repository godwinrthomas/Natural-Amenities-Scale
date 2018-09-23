/*  Name : Godwin Richard Thomas
 *  CSCI 689/0001
 *  TA Name : Nithin Devang
 *  Assignment Number : 7
 *  Due Date : 05/04/2018
 */

// include header files
#include "Amenity.h"
#include "Goodguy.h"

// function prototypes
void getLine(vector<Amenity> &, Amenity &,string); // reads the data into a vector of amenities
void Print_Select(vector<Amenity> &, Amenity &, Goodguy &); // prints the sorted rankings of the amenities
void Composite_Amenity(vector<Amenity> &); // find the composite amenity
float Standard_Deviation(vector<float> &); // find the standard deviation of vector of floats
float Average(vector<float> &); // find the average of vector of floats
int Standard_Deviation(vector<int> &); // find the standard deviation of vector of ints
int Average(vector<int> &); // find the average of vector of ints

// main function
int main(int argc, char* argv[])
{
	// if the name of the file is not given in the argument, an error msg is displayed
	if(argc!=2)
	{
		cerr<<"Please enter the name of the file as second argument\n";
		return -1;
	}

	
	// the variable Filename is declared to store the name of the file
	string Filename;
	Filename = argv[1];

	
	// variable declared for file manipulation
	ifstream inp;

	// opens the file
	inp.open(Filename); 

	// if the file cannot be opened, an error msg is displayed
	if(!inp)
	{
		cerr<<"Unable to open file try again\n";
		return -1;
	}

	// vector of Amenity	
	vector<Amenity> v_amenity;

	// instance of Amenity
	Amenity a;
	
	// instance of Goodguy
	Goodguy g;

	// a string is declared
	string good;

	// declaration of a variable i for counting the number of records and calculating the size
	int i=0;
	
	// gets every line until there are no records left
	while(getline(inp, good))
	{
		getLine(v_amenity, a, good); // reads the records and stores them into the vector
		i++; // tracks the number of records read
	}

	// prints the number of records read
	cout<<"The number of records read are : "<<i;

	// prints the top n and bottom n values of the rankings of sorted amenities
	Print_Select(v_amenity,a,g);

	// finds the composite amenity value and stores them
	Composite_Amenity(v_amenity);
	
	// closes the file
	inp.close();
	
	// exits the program
	return 0;
}

// reads the records and stores it into the vector of amenities
void getLine(vector<Amenity> &vector_of_amenity,Amenity &x, string good)
{
	// the starting position of the line
	int STARTING_POSITION=0;

	// first position where a comma character is found
	int POSITION_OF_COMMA1=0;
	
	// finds the first position where the comma is present
	POSITION_OF_COMMA1 =good.find(",");
	
	// copies the values until the first position of comma into a string
	string ID;
	ID = good.substr(STARTING_POSITION,POSITION_OF_COMMA1);
	
	// converts the string into integer
	int POSITION_INT;
	POSITION_INT = stoi(ID);

	// sets the value of ID
	x.set_ID(POSITION_INT);
	
	// second position where a comma character is found	
	int POSITION_OF_COMMA2=0;

	// moves past the comma
	string good2 = good.substr((POSITION_OF_COMMA1)+1);
	
	// finds the second position where the comma character is present
	POSITION_OF_COMMA2 = good2.find(",");
	
	// copies the values until the second of position of comma into the string
	string STATE_CODE;
	STATE_CODE = good2.substr(STARTING_POSITION, POSITION_OF_COMMA2);

	// sets the value of state code
	x.set_state_name(STATE_CODE);
	
	// third position of coma
	int POSITION_OF_COMMA3;

	// moves past the comma
	string good3= good2.substr((POSITION_OF_COMMA2)+1);
	
	// finds the third position of comma
	POSITION_OF_COMMA3 = good3.find(",");

	// copies the values until the third position of comma into the string
	string COUNTRY_NAME;
	COUNTRY_NAME = good3.substr(STARTING_POSITION, POSITION_OF_COMMA3);

	// sets the value of country name
	x.set_country_name(COUNTRY_NAME);
	
	// fourth position of comma
	int POSITION_OF_COMMA4;

	// moves past the comma
	string good4= good3.substr((POSITION_OF_COMMA3)+1);
	
	// finds the fourth position of comma
	POSITION_OF_COMMA4= good4.find(",");

	// copies the values until the fourth of position of comma into the string
	string AVG_JAN_TEMP;
	AVG_JAN_TEMP = good4.substr(STARTING_POSITION, POSITION_OF_COMMA4);

	// converts the value from string to float
	float AVG_JAN_TEMP_FLOAT;
	AVG_JAN_TEMP_FLOAT = stof(AVG_JAN_TEMP);

	// sets the value of average january temperature
	x.set_jan_temp(AVG_JAN_TEMP_FLOAT);

	// fifth position of comma
	int POSITION_OF_COMMA5;

	// moves past comma
	string good5= good4.substr((POSITION_OF_COMMA4)+1);
	
	// finds the fifth position of comma
	POSITION_OF_COMMA5= good5.find(",");

	// copies the values until the fifth position of comma
	string AVG_JAN_SUN;
	AVG_JAN_SUN = good5.substr(STARTING_POSITION, POSITION_OF_COMMA5);

	// conversion from string to float
	float AVG_JAN_SUN_FLOAT;
	AVG_JAN_SUN_FLOAT = stof(AVG_JAN_SUN);

	// sets the value of average jan sunshine
	x.set_jan_sun(AVG_JAN_SUN_FLOAT);
	
	// sixth position of comma
	int POSITION_OF_COMMA6;

	// moves past comma
	string good6= good5.substr((POSITION_OF_COMMA5)+1);
	
	// finds the sixth position of comma
	POSITION_OF_COMMA6= good6.find(",");

	// copies the contents until the sixth position of comma
	string AVG_JUL_TEMP;
	AVG_JUL_TEMP = good6.substr(STARTING_POSITION, POSITION_OF_COMMA6);

	// conversion from string to float
	float AVG_JUL_TEMP_FLOAT;
	AVG_JUL_TEMP_FLOAT = stof(AVG_JUL_TEMP);

	// sets the value of average july temperature
	x.set_jul_temp(AVG_JUL_TEMP_FLOAT);
	
	// seventh position of comma
	int POSITION_OF_COMMA7;

	// moves past comma
	string good7= good6.substr((POSITION_OF_COMMA6)+1);

	// finds the seventh position of comma
	POSITION_OF_COMMA7= good7.find(",");

	// copies the contents until the seventh position of comma
	string AVG_JUL_HUMIDITY;
	AVG_JUL_HUMIDITY = good7.substr(STARTING_POSITION, POSITION_OF_COMMA7);

	// conversion from string to float
	float AVG_JUL_HUMIDITY_FLOAT;
	AVG_JUL_HUMIDITY_FLOAT = stof(AVG_JUL_HUMIDITY);

	// sets the value of average july humidity
	x.set_jul_humidity(AVG_JUL_HUMIDITY_FLOAT);
	
	// eight position of comma
	int POSITION_OF_COMMA8;

	// moves past comma
	string good8= good7.substr((POSITION_OF_COMMA7)+1);
	
	// finds the eight position of comma
	POSITION_OF_COMMA8= good8.find(",");

	// copies the values until the eight position of comma
	string LANDFORM;
	LANDFORM = good8.substr(STARTING_POSITION, POSITION_OF_COMMA8);

	// conversion from string to int
	int LANDFORM_INT;
	LANDFORM_INT = stoi(LANDFORM);

	// sets the value of average landform
	x.set_landform(LANDFORM_INT);
	
	// ninth position of comma
	int POSITION_OF_COMMA9;

	// moves past comma
	string good9= good8.substr((POSITION_OF_COMMA7)+1);
	
	// finds the ninth position of newline
	POSITION_OF_COMMA9= good9.find('\n');

	// copies the contents until the nineth position of comma
	string WATER_TERRAIN;
	WATER_TERRAIN = good9.substr(STARTING_POSITION, POSITION_OF_COMMA9);

	// conversion from string to float
	float WATER_TERRAIN_FLOAT;
	WATER_TERRAIN_FLOAT = stof(WATER_TERRAIN);

	// sets the value of water terrain
	x.set_water_terrain(WATER_TERRAIN_FLOAT);

	// all the values which were read are stored into the vector of ameneties
	vector_of_amenity.push_back(x);
	
}

// prints the sorted rankings of the individual amenities
void Print_Select(vector<Amenity> &v_amenity, Amenity &a, Goodguy &g)
{
	/* Average January Temparature */

	// for sorting the values of the average january temparature
	sort(v_amenity.begin(), v_amenity.end(), COMPARISON_AVG_JAN_TEMP);

	// sets the data member to print the values of avg jan temp
	g.set_data(JAN_TEMP);

	// prints the top ten and bottom ten values of avg jan temp
	cout<<"\nRanking by Average January Temparature:"<<"\n\n";
	print_top_bottom_n(v_amenity, 12, g);
	
	/* Average January Sunshine */

	// for sorting the values of the average january sunshine
	sort(v_amenity.begin(), v_amenity.end(), COMPARISON_AVG_JAN_SUN);

	// sets the data member to print the values of avg jan sun
	g.set_data(JAN_SUN);

	// prints the top ten and bottom ten values of avg jan sun
	cout<<"\nRanking by Average January Sunshine:"<<"\n\n";
	print_top_bottom_n(v_amenity, 12, g);

	/* Average July Temparature */

	// for sorting the values of the average july temparature
	sort(v_amenity.begin(), v_amenity.end(), COMPARISON_AVG_JUL_TEMP);

	// sets the data member to print the values of avg july temp
	g.set_data(JUL_TEMP);

	// prints the top ten and bottom ten values of avg july temp
	cout<<"\nRanking by Average July Temparature:"<<"\n\n";
	print_top_bottom_n(v_amenity, 12, g);

	/* Average July Humidity */

	// for sorting the values of the average july humidity
	sort(v_amenity.begin(), v_amenity.end(), COMPARISON_AVG_JUL_HUMIDITY);

	// sets the data member to print the values of avg july humdty
	g.set_data(JUL_HUM);

	// prints the top ten and bottom ten values of avg july humdty
	cout<<"\nRanking by Average July Humidity:"<<"\n\n";
	print_top_bottom_n(v_amenity, 12, g);

	/* Average Landform */

	// for sorting the values of the average landform
	sort(v_amenity.begin(), v_amenity.end(), COMPARISON_AVG_LANDFORM);

	// sets the data member to print the values of avg landform
	g.set_data(LANDFORM);

	// prints the top ten and bottom ten values of avg landform
	cout<<"\nRanking by Average Landform:"<<"\n\n";
	print_top_bottom_n(v_amenity, 12, g);

	/* Amount of Water Terrain */

	// for sorting the values of the amount water terrain
	sort(v_amenity.begin(), v_amenity.end(), COMPARISON_AVG_WATER_TERRAIN);

	// sets the data member to print the values of amount of water terrain
	g.set_data(WATER_TERRAIN);

	// prints the top ten and bottom ten values of amount of water terrain
	cout<<"\nRanking by Amount of Water Terrain:"<<"\n\n";
	print_top_bottom_n(v_amenity, 12, g);
}
/*
void Average(vector<float> &vf)
{
	for_each(vf.begin(), vf.end(),  [&](float val){ sum2 = sum2+val;});
}
*/
void Composite_Amenity(vector<Amenity> &va)
{
	/* Average January Temparature */
	
	// vector of floats for extracting the Jan temp
	vector<float> vect_Jan_Temp;

	// copies the values from the vector of amenities into the vector of floats
	for(unsigned int i=0 ; i<va.size(); i++)
	{
		vect_Jan_Temp.push_back(va[i].get_jan_temp());
	}
	
	/* Average January Sunshine */
	
	// vector of floats for extracting the January Sunshine
	vector<float> vect_Jan_Sun;

	// copies the values from the vector of amenities into the vector of floats
	for(unsigned int i=0 ; i<va.size(); i++)
	{
		vect_Jan_Sun.push_back(va[i].get_jan_sun());
	}

	/* Average July Temparature */
	
	// vector of floats for extracting the July temp
	vector<float> vect_July_Temp;

	// copies the values from the vector of amenities into the vector of floats
	for(unsigned int i=0 ; i<va.size(); i++)
	{
		vect_July_Temp.push_back(va[i].get_jul_temp());
	}

	/* Average July Humidity */
	
	// vector of floats for extracting the July humidity
	vector<float> vect_July_Humidity;

	// copies the values from the vector of amenities into the vector of floats
	for(unsigned int i=0 ; i<va.size(); i++)
	{
		vect_July_Humidity.push_back(va[i].get_jul_humidity());
	}	

	/* Average Landform */
	
	// vector of ints for extracting the landform
	vector<int> vect_Landform;

	// copies the values from the vector of amenities into the vector of floats
	for(unsigned int i=0 ; i<va.size(); i++)
	{
		vect_Landform.push_back(va[i].get_landform());
	}		

	/* Average Water Terrain */
	
	// vector of floats for extracting the water terrain
	vector<float> vect_Water_Terrain;

	// copies the values from the vector of amenities into the vector of floats
	for(unsigned int i=0 ; i<va.size(); i++)
	{
		vect_Water_Terrain.push_back(log((va[i].get_water_terrain()) * (100))); 
	}

	// standard deviation and average of all the Amenities
	
	float SD_Jan_Temp = Standard_Deviation(vect_Jan_Temp);
	float Avg_Jan_Temp = Average(vect_Jan_Temp);
	
	float SD_Jan_Sun = Standard_Deviation(vect_Jan_Sun);
	float Avg_Jan_Sun = Average(vect_Jan_Sun);
	
	float SD_Jul_Temp = Standard_Deviation(vect_July_Temp);
	float Avg_Jul_Temp = Average(vect_July_Temp);

	float SD_Jul_Hum = Standard_Deviation(vect_July_Humidity);
	float Avg_Jul_Hum = Average(vect_July_Humidity);
	
	int SD_Landform = Standard_Deviation(vect_Landform);
	int Avg_Landform= Average(vect_Landform);

	float SD_Water = Standard_Deviation(vect_Water_Terrain);
	float Avg_Water = Average(vect_Water_Terrain);


	// printing out the values of standard deviation and average	
	cout<<"\nJan Temperature ";
	cout<<"\nAverage : "<<Avg_Jan_Temp<<" "<<"Standard Deviation : "<<SD_Jan_Temp;

	cout<<"\n";

	cout<<"\nJan Sunshine ";
	cout<<"\nAverage : "<<Avg_Jan_Sun<<" "<<"Standard Deviation : "<<SD_Jan_Sun;

	cout<<"\n";

	cout<<"\nJuly Temperature ";
	cout<<"\nAverage : "<<Avg_Jul_Temp<<" "<<"Standard Deviation : "<<SD_Jul_Temp;

	cout<<"\n";

	cout<<"\nJuly Humidity ";
	cout<<"\nAverage : "<<Avg_Jul_Hum<<" "<<"Standard Deviation : "<<SD_Jul_Hum;

	cout<<"\n";

	cout<<"\nLandform ";
	cout<<"\nAverage : "<<Avg_Landform<<" "<<"Standard Deviation : "<<SD_Landform;

	cout<<"\n";

	cout<<"\nWater_Terrain ";
	cout<<"\nAverage : "<<Avg_Water<<" "<<"Standard Deviation : "<<SD_Water;

	
	// finding the composite amenity
	for(unsigned int i=0; i<vect_Jan_Temp.size();i++)
	{
		// finding the z-score of all the individiual amenities
		float z_Jan_Temp = (vect_Jan_Temp[i] - Avg_Jan_Temp) / SD_Jan_Temp;
		float z_Jan_Sun = (vect_Jan_Sun[i] - Avg_Jan_Sun) / SD_Jan_Sun;	
		float z_Jul_Temp = (vect_July_Temp[i] - Avg_Jul_Temp) / SD_Jul_Temp;
		float z_Jul_Hum = (vect_July_Humidity[i] - Avg_Jul_Hum) / SD_Jul_Hum;
		int z_Landform = (vect_Landform[i] - Avg_Landform) / SD_Landform;
		float z_Water = (vect_Water_Terrain[i] - Avg_Water) / SD_Water;

		// finding the composite amenity score
		float Composite_Amenity_Score = z_Jan_Temp + z_Jan_Sun + z_Jul_Temp + z_Jul_Hum
			+ z_Landform + z_Water;
		va[i].set_amenity(Composite_Amenity_Score);
	}

	Goodguy g;

	// sorting the ranking by compposite score
	sort(va.begin(), va.end(),g );

	// printing the top 10 and bottom 10 values
	cout<<"\n\n\nComposite Ranking Score\n";
	for(int i=0;i<10;i++)
	{
		cout<<"\n"<<va[i].get_country_name()<<" "<<va[i].get_state_name()<<" "<<va[i].get_amenity();
	}

	cout<<"\n";
	cout<<"\n";
	cout<<"....................";
	cout<<"\n";
	for(unsigned int i=va.size()-10;i<va.size();i++)
	{
		cout<<"\n"<<va[i].get_country_name()<<" "<<va[i].get_state_name()<<" "<<va[i].get_amenity();
	}
	cout<<"\n";
	 
}
// calculate the average of vector of float

float Average(vector<float> &vf)
{
	float sum = accumulate(vf.begin(), vf.end(), 0.0);

	float avg = sum/vf.size();

	return avg;
}


// finding the standard deviation of vector of float
float Standard_Deviation(vector<float> &vf)
{
	float sum = accumulate(vf.begin(), vf.end(), 0.0);

	float avg = sum/vf.size();


	vector<float> good(vf.size());

	

	transform(vf.begin(), vf.end(), good.begin(), [avg](float x){ return x-avg;});
	float sq_sum2 = inner_product(good.begin(), good.end(), good.begin(), 0.0);
	float sdev2 = sqrt(sq_sum2/vf.size());

	return sdev2;
}

// average for vector of int (landform)
int Average(vector<int> &vf)
{
	int sum = accumulate(vf.begin(), vf.end(), 0.0);

	int avg = sum/vf.size();

	return avg;
}


// finding the standard deviation
int Standard_Deviation(vector<int> &vf)
{
	int sum = accumulate(vf.begin(), vf.end(), 0.0);

	int avg = sum/vf.size();


	vector<int> good(vf.size());

	

	transform(vf.begin(), vf.end(), good.begin(), [avg](int x){ return x-avg;});
	int sq_sum2 = inner_product(good.begin(), good.end(), good.begin(), 0.0);
	int sdev2 = sqrt(sq_sum2/vf.size());

	return sdev2;
}






		
			



	


	

		
	
	


