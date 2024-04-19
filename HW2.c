//Kevin Nguyen
//CSE222
//02/09/2024
//Main program takes argument for file to be used. Tokenizes data set into name, lon, lat, and pop fields while checking for missing fields or parsing errors. Uses stdin to get commands such as a city's info, all cities and their information in descending order using the addCity function, help information, and delete a city using deleteCity function.
//Include Header File with Function Prototypes and other Include Files
#include "list.h"
//Main Function
void main(int argc, char* argv[]) {
	//Initialize Variables
        char temp[120];
        char buffer[1024];
	char *word;
	int num;
	int error = 0;

	//Make list and initialize it
	struct node *list;
	list = init();

	//File Pointer to the City Data Set
        if (argc == 2) {
		FILE *fp;
        	fp=fopen(argv[1], "r");
		if (fp == NULL) {
			printf("No Matching File\n");
			return;
		}

		//While Loop until end of Data Set
        	while (NULL != fgets(buffer, 1024, fp)) {
			struct city *data;
			data = malloc(sizeof(struct city));
			//Split String from Data Set by Name, Latitude, Longitude, and Population
                	word = strtok(buffer, "|");
			if(word == NULL) {
				printf("ERROR: Short line %s\n", buffer);
				error = 1;
				continue;
			}
			if(strlen(word) >= sizeof(data->name)) {
				printf("Error Parsing %s\n", buffer);
				error = 1;
				continue;
			}
                	strcpy(data->name, word);

                	word = strtok(NULL, "|");
			if(word == NULL) {
				printf("ERROR: Short line %s\n", buffer);
				error = 1;
				continue;
			}
			if(sscanf(word, "%lf", &data->lat) != 1) {
				printf("Error Parsing %s\n", buffer);
				error = 1;
				continue;
			}

                	word = strtok(NULL, "|");
			if(word == NULL) {
				printf("ERROR: Short line %s\n", buffer);
				error = 1;
				continue;
			}
			if(sscanf(word, "%lf", &data->lon) != 1) {
				printf("Error Parsing %s\n", buffer);
				error = 1;
				continue;
			}

                	word = strtok(NULL, "|");
			if(word == NULL) {
				printf("ERROR: Short line %s\n", buffer);
				error = 1;
				continue;
			}
			if(sscanf(word, "%d", &data->pop) != 1) {
				printf("Error Parsing %s\n", buffer);
				error = 1;
				continue;
			}
			addCity(list, *data); //Add data pointer to the list
			free(data);
        	}
		//Close File Pointer
		fclose(fp);

		if (error != 1) {
		//Formatting for stdin
		printf("> ");
		//While Loop until User inputs CTRL+D
		while (fgets(temp,120,stdin) != NULL) {
			//Initialize Matching State for if user input is invalid and print error message
			int matching = 0;
                	sscanf(temp, "%d", &num);
			//Replace the '\n' to null terminator at the end of the temp string
			temp[strlen(temp)-1]='\0';
				//If user input is begins with *
                    		if (temp[0] == '*') {
					char *star = strtok(temp, " ");
					if(strcmp(star, "*delete") == 0) {
						char *cityName = strtok(NULL, "|");
						//char cityName[100];
						sscanf(temp, "*delete %s", cityName);
						if(deleteCity(list, cityName) == 1) {
							printf("Deleted <%s>\n", cityName);
							matching = 1;
						}
						else {
							matching = 0;
						}
					}
					else if(strcmp(star, "*") == 0) {
						char *cityName = strtok(NULL, "|");
						if(cityName == NULL) {
							char cityName[100] = "";
							print(list, cityName);
							matching = 1;
						}
					}
                        	}
				//Else if user input is ?
				else if (temp[0] == '?') {
					//Print Help Message
        				printf("Command summary:\n * - print all city data \n cityname - print that city's info \n ? - print this help message \n ^D - exit \n");
					matching = 1;
				}
				//Else if user input is enter key enter set matching state to 0 to print error message
				else if (strlen(temp) <= 1) {
					matching = 0;
				}
				//Else check if user input matches a city name
				else {
					char cityName[100];
					sscanf(temp, "%[^\n]", cityName);
					if (print(list, cityName) != 0) {
						matching = 1;
					}
					else if (print(list, cityName) == 0) {
						matching = 0;
						}
					}
			//If matching state is 0 then print error message
			if (matching == 0) {
				printf("No City Found Matching \"%s\"\n", temp);
			}
			//Formatting for stdin
			printf("> ");
		}

		//Once user exits program print goodbye
		printf("Goodbye!\n");
		}
		else if (error != 1) {
			printf("No Matching File\n");
		}
	}
	cleanup(list);
}

	
