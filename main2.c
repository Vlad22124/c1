#include <stdio.h> 
#include <math.h>
#include <stdlib.h>


/***Summary***
	1 - Happy tickets 
	2 - Defined random massive
	3 - Bubble sorting
	4 - Select sorting
	0 - Exit
*/

//Section voids list
void HT();
void ran_Mas();
void sorting(int option);


int main(int argc, char const *argv[])
{
	int command;
	short drop;

	printf(" Welcome!\n");
	drop = 1;
	do
	{
		printf("****Menu****\n 1. Happy Tickets; \n 2. Defined random massive;\n 3. Bubble sorting;\n 4. Select sorting.\n 0. Exit\n Waiting for input...\n");
		scanf("%i", &command);
		switch (command)
		{
			case 1: 
				HT();
				break;
				
			case 2:
				ran_Mas();
				break;

			case 3:
				sorting(1);
				break;

			case 4:
				sorting(2);
				break;

			case 0:
				drop = 0;
				break;

			default:
				printf("This command cannot be recognized. Please correct you command and try again.\n");
				break;
		};
	}while (drop == 1);
	return 0;
}


void HT(){

	printf("\nHappy Tickets\n\n");
	int count, x, y, left, right;
	count = 1;

	for (int i = 1; i <= 999999; i++)
	{
		right = i; //v
		left = 0; //z

		//сount sum of last three numbers
		while (left < 3)
		{
			left += 1;
			x = (right % 10) + x;
			right = right / 10;
		} 

		//count sum of first three numbers
		while (left < 6)
		{
			left += 1;
			y = (right % 10) + y;
			right = right / 10;
		}

		if (x == y) count += 1;
		x = 0;
		y = 0;
	}
	printf("Count of happy tickets: %i \n\n", count);
}


void ran_Mas(){

	int x_var, y_var, rand(void), size;

	//pointers
	int *mass;
	
	printf("\nDefined random massive\n\n");

	printf("Enter two random numbers, separating by spaces or ''Enter'':\n ");

	scanf("%d %d", &x_var, &y_var);

	//Calculate size of massive and range

	size = rand() % 80;
	x_var = x_var + rand() % (y_var - x_var + 1);
	y_var = x_var + rand() % (y_var - x_var + 1);

	mass = calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() % 100;
		printf(" %d. %d \n", i, mass[i]);
	}
	y_var = 0;

	//Local search loop

	do{
		x_var = 0;

		printf("\nEnter the number for which you want to determine the index(es):\n-- ");

		scanf("%d", &x_var);

		int k = 0;

		for (int j = 0; j < size; j++){
			if (mass[j] == x_var) k++;
		}
		if (k == 0){
			printf("Entered number %d haven't indexes!\n", x_var);
		} 
		else{
			k = 0;
			printf("Entered number %d have next indexes:\n", x_var);
			for (int j = 0; j < size; j++){
				if (mass[j] == x_var) printf("%d. %d \n", ++k, j);
			}
		}

		printf("\n-- Continue search? Yes=1, No=2\n-- ");

		scanf("%d", &y_var);

	}while(y_var == 1);
	free(mass);
}


void sorting(int option){
	int size, temp, k;
	int *mass;

	printf("\n-- Enter the number of size of massive:\n-- ");

	scanf("%d", &size);

	// allocate memory

	mass = calloc(size, sizeof(int));

	// fill in massive with random values

	printf("\n-- Initial massive:\n");

	for (int i = 0; i < size; i++){
		mass[i] = rand() % 500;
		printf("-- %d. %d \n", i, mass[i]);
	}

	printf("\n-- Sorted massive:\n");

	switch (option)
	{		
		// Bubble Sorting
		case 1:
			temp = 0;
			for (int j = 0; j < size; j++){
				for (int k = size - 1; k > j; k--){
					if (mass[k - 1] > mass[k]){
						temp = mass[k - 1];
						mass[k - 1] = mass[k];
						mass[k] = temp;
					}
				}
			}
		break;

		// Select sorting
		case 2:
			temp = 0;
			for (int i = 0; i < size; i++){
				k = i;
				temp = mass[i];
				for (int j = i + 1; j < size; j++){
					if (mass[j] < temp){
						k = j;
						temp = mass[j];
					}
				}
				mass[k] = mass[i];
				mass[i] = temp;
			}
		break;
	};
	for (int x = 0; x < size; x++){
		printf("-- %d. %d\n", x, mass[x]);
	}
	free(mass);
}