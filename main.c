#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variable
int N = 50; // N = no. of cars

// Structure Definition
typedef struct car_tag
{
	int year;
	char regNo[15];
	char colour[10];
	float engVol;
	int tax;
} car_type;

// Main Function
int main(void) 
{
	// Opening the files
	FILE* fp;
	fp = fopen( "indata.txt","r");
	  // Making sure the file loaded succesfully
		if(fp == NULL) {
				printf("Error opening file");
				return(-1);
		}

  // Define Variables
	int i, no_of_data;
	car_type car[50]; 

		// Assigning values to variables
		no_of_data = 0; // Stores how many entries from file

	// Print Welcome message
	printf("Welcome to car tax checker\n");
	
	// Reading/ Storing data from file
	while(!feof(fp)) // Reads until the end of file
	{
		/* read on record from file */
		fscanf(fp, "%d %s %s %f", &car[no_of_data].year, car[no_of_data].regNo, car[no_of_data].colour, &car[no_of_data].engVol);
		//printf("file read success\n");

		// Increase the number of data read
		no_of_data++;
	}

	// --------------- Calculating tax ---------------
	for(i = 0; i < no_of_data; i++)
	{
		// If car is younger than 5 years old
		if ( (2021 - car[i].year) <= 5 )
		{
			// If car is younger than 5 years old and its engine is less than 1.6L, tax is €150
			if( car[i].engVol <= 1.6 )
			{
				car[i].tax = 150;
			}
			// If car is younger than 5 years old and cars engine is more than 1.6L, tax is €300
			else
			{	
				car[i].tax = 300;
			}
		}
		// If car is older than 5 years old		
		else 
		{
			// If car is older than 5 years old and cars engine is less than 1.4L, tax is €200
			if( car[i].engVol <= 1.4 )
			{
				car[i].tax = 200;
			}
			// If car is older than 5 years old and cars engine is between 1.4-1.6L, tax is €400
			else if( (car[i].engVol > 1.4) && (car[i].engVol <= 1.6) )
			{	
				car[i].tax = 400;
			}
			// If car is older than 5 years old and cars engine is more than 1.4L, tax is €600
			else if( car[i].engVol > 1.6 )
			{	
				car[i].tax = 600;
			}
		}

		// If car is black or white, apply discount of €10
		if( (strcmp(car[i].colour, "black") == 0) || (strcmp(car[i].colour, "white") == 0) )
		{
			car[i].tax = car[i].tax - 10;
		}
	}

	// Printing out table
	for(i = 0; i < no_of_data; i++)
	{
		printf("Year :  %d\t", car[i].year);
		printf("Reg : %s\t\t ", car[i].regNo);
		printf("Colour : %s\n", car[i].colour);
		printf("Engine Size :  %1.1fL\t\t", car[i].engVol);
		printf("Tax :  €%d /year\n\n", car[i].tax);
	}
	
	// Printing closing statements
	printf("Thanks for using!\n");

	// Close files
	fclose(fp);
	return 0;
}