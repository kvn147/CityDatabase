//Kevin Nguyen
//CSE222
//01/26/2024
//The printCity function is used to print city information back to the main program using the city number the user inputs from the main program
#include <stdio.h>
#include "list.h"
//Function takes the city number and city structure, and prints the matching city number's information
void printCity(int num, struct city data[]) {
	//Print city information
	printf("(%i) Name: %s\nLatitude: %lf\nLongitude: %lf\nPopulation: %d\n\n", num, data[num].name, data[num].lat, data[num].lon, data[num].pop);
}

