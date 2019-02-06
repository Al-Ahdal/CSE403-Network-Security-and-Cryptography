#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(void){
	int arr[8][8];
	int count=58,temp;
	for(int i=0;i<4;i++){
		temp=count;
		for(int j=0;j<8;j++){
			arr[i][j]=temp;
			arr[4+i][j]=temp-1;
			temp-=8;
		}
		count+=2;
	}
	printf("The ip table is :\n");
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			printf("%02d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}