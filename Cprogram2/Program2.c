/*
 * Program2.c
 *
 *  Created on: Feb 8, 2023
 *      Author: a364k236
 */

#include<stdio.h>

int main(){

	int score;

	while(1){
		printf("Enter 0 or 1 to stop\n");
		printf("Type in an NFL game score: ");
		scanf("%d", &score);
		if(score < 2) break;

		for(int i = 0; i <= score/8; i++){
			int num8s = i;
			for(int j=0; j <= score/7; j++){
				int num7s = j;
				for(int k=0; k <= score/6; k++){
					int num6s = k;
					for(int l=0; l <= score/3; l++){
						int num3s = l;
						for(int m=0; m <= score/2; m++){
							int num2s = m;
							if((score - 8*num8s - 7*num7s - 6*num6s - 3*num3s - 2*num2s) == 0){
								printf("%d TD+2pt, %d TD+FG, %d TD, %d 3ptFG, %d Safety\n", num8s, num7s, num6s, num3s, num2s);
								break;
							}

						}

					}

				}

			}

		}



	}

	return 0;
}
