/*
 * Program1.c
 *
 *  Created on: Feb 8, 2023
 *      Author: a364k236
 */

#include<stdio.h>;
#include<string.h>;

int main(){

	FILE *dataFile = fopen("salesNumbers.txt", "r");
	double sales[12];
	int orderedIndex[12] = { [0 ... 11] = 13};
	double avg;
	double mAVG [7];
	double tempmAVG;
	char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


	if(dataFile == NULL){
		return 0;
	}

	for(int i = 0; i<12; i++){
		fscanf(dataFile, "%lf", &sales[i]);
	}

	double max[2] = {sales[0], 0};
	double min[2] = {sales[0], 0};

	for(int i = 0; i<12; i++){
		if (sales[i] <= min[0]){
			min[0] = sales[i];
			min[1] = i;
		}
		if (sales[i] >= max[0]){
			max[0] = sales[i];
			max[1] = i;
		}
		avg += sales[i];

		if(i<5){
			tempmAVG += sales[i];
		}
		else{
			tempmAVG += sales[i];
			mAVG[i-5] = tempmAVG/6;
			tempmAVG -= sales[i-5];
		}

		int j = 0;
		orderedIndex[i] = i;
		while(orderedIndex[j] != 13 && j < 12){
			if (sales[i] > sales[j]){
				orderedIndex[i] -= 1;
				orderedIndex[j] += 1;
			}
			j++;
		}
	}
	avg /= 12;

	printf("12 Month Sales Report\n");

	printf("%-12s %-10s\n", "Month", "Sales");
	for(int i = 0; i<12; i++){
		printf("%-12s %-10.2f\n", months[i], sales[i]);
	}

	printf("\nSales summary:\n");
	printf("Minimum sales: %.2f (%s)\n", min[0], months[(int)(min[1])]);
	printf("Maximum sales: %.2f (%s)\n", max[0], months[(int)(max[1])]);
	printf("Average sales: %.2f\n", avg);

	printf("\nSix-Month Moving Average Report:\n");
	for(int i = 0; i<7; i++){
		char text[200];
		strcpy(text, months[i]);
		strcat(text, "-");
		strcat(text, months[i+5]);
		printf("%-16s", text);

		printf("%.2f\n", mAVG[i]);
	}

	printf("\nSales report (highest to lowest):\n");
	printf("%-12s %-10s\n", "Month", "Sales");

	int k;
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 12; j++){
			if(i == orderedIndex[j]){
				printf("%-13s", months[j]);
				k=j;
				break;
			}
		}
		printf("$%-10.2f\n", sales[k]);
	}

	return 0;
}


