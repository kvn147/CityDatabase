//Kevin Nguyen
//CSE222
//01/26/2024
//The printAll function lists all cities if the user inputs * from the main program
#include <stdio.h>
#include "list.h"
//Function takes the total amount if cities and the structure, and prints all the cities and their information
void printAll(int size, struct city data[]) {
	//Goes through the city data set
	for (int i=1; i <= size; i++) {
		//Print city information
		printf("(%i) Name: %s\nLatitude: %lf\nLongitude: %lf\nPopulation: %d\n\n", i, data[i].name, data[i].lat, data[i].lon, data[i].pop);
	}
}

