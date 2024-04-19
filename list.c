//Kevin Nguyen
//CSE222
//02/09/2024
//list.c handles all functions used in the main program such as to add and delete nodes, print city information and linked list structures
#include "list.h"

struct node* init() {
	struct node *temp;
	temp = malloc(sizeof(struct node));
	temp->next = NULL;
	return(temp);
}

struct node* newNode(struct city data) {
	struct node* temp;
	temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return(temp);
}
//addCity adds a city as node in the list and also sorts it properly based on its population in descending order
void addCity(struct node *handle, struct city data) {
	struct node *temp; //Create temp node
	temp = handle; //Temp points to sentinel node
	
	struct node *newNodePtr = newNode(data); //Create new node pointer to data node
	
	//While next node is not empty AND next city pop is greater than the current city pop, make temp point to next node
	while(temp->next != NULL && temp->next->data.pop > data.pop) {
			temp = temp->next;
		}
	newNodePtr->next = temp->next;
	temp->next = newNodePtr;
}
//print will either print all city's and their information or print a city's information matching user input cityName as a * or a string
int print(struct node *handle, const char *cityName) {
	struct node *temp; //Create temp node
       	temp = handle->next; //Temp points to sentinel node
	if (cityName[0] == '\0') {
		while(temp != NULL) {
			printf("Name: %s, Latitude: %lf, Longitude: %lf, Population: %d\n", temp->data.name, temp->data.lat, temp->data.lon, temp->data.pop);
			temp = temp->next;
		}
		return(1);
	}
	else {
		while(temp != NULL) {
			if(strcmp(temp->data.name, cityName) == 0) {
				printf("Name: %s, Latitude: %lf, Longitude: %lf, Population: %d\n", temp->data.name, temp->data.lat, temp->data.lon, temp->data.pop);
				return(1);
			}
			temp = temp->next;
		}
	return(0);	
	}

}
//deleteCity takes the list and the user input cityName to match a city node in the list and delete it if found
int deleteCity(struct node* handle, const char *cityName) {
	struct node *temp; //Create temp node
	temp = handle->next; //Temp points to sentinel node
	while (temp->next != NULL) {
		//If the next city name of the list is the same as the user's city name
		if (strcmp(temp->next->data.name, cityName) == 0) {
			struct node *deleteNode = temp->next; //New node points to the city before we delete in order to free the malloc used by the city
			temp->next = temp->next->next;
			free(deleteNode);
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}
//clean goes through the list from sentinel to end to free allocated memory
void cleanup(struct node *handle) {
	struct node *temp = handle->next;
	struct node *prev = handle;

	while (temp != NULL) {
		free(prev);
		prev = temp;
		temp = temp->next;
	}
	free(prev); //Frees the last node
}


