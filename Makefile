assign7: assign7.o
	g++ -o assign7 assign7.cc Amenity.cc 
	
assign7.o: assign7.cc Amenity.cc 
	g++ -c -Wall assign7.cc Amenity.cc 

clean:
	rm *.o assign7
