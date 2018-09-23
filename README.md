# Natural-Amenities-Scale

Processing the DataSet and Storage:-

A list of all the counties in the United Statesand the values of their natural amenities like Temperature, Humidity, Landform and Water
Terrain are taken from the dataset of Economic Research Service, USA found in "amenity.dat". Different vectors are created for each
amenity and the values along with the county name are stored in the respective vectors.

Displaying individually:-

The top 10 and bottom 10 counties are displayed for each of the amenity value.

Finding the Z-Score:-

The combiniation of all the amenity values is said to be the composite amenity score of a county. To find the composite amenity, the
average and the standard deviation are calculated individually for the amenities. From that, the z-score is obtained. Using the z-score,
the counties are ranked from top to bottom, which is equivalent to to the ranking by the Natural Amenity Scale.

Interesting Note:-

To display the top 10 or bottom 10 values, an algorith called sort is used. An helper class called "Goodguy.h" is created and then
the function operator is overloaded. The overloaded function operator is used as an argument to the sort algorithm to display
the rankings.
