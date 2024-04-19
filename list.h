//Kevin Nguyen
//CSE222
//02/09/2024
//The header file includes all the necessary libraries for the main program, linked list structures for city data and nodes, and function prototypes to print city information, and to add and delete city nodes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Define main city structure
struct city{
	char name[50];
	double lat,lon;
	int pop;
};

struct node{
	struct city data;
	struct node *next;
};

struct node* init();
struct node* newNode(struct city data);

void addCity(struct node *handle, struct city data);
int print(struct node *handle, const char*);
int deleteCity(struct node *handle, const char*);
void cleanup(struct node *handle);

