#include <stdio.h>


int main(void){
	int arr[8][8];
	int count=33;
	for(int i=7;i>=0;i--)arr[i][0]=count++;
	count=1;
	for(int i=7;i>=0;i--)arr[i][1]=count++;
	for(int j=1;j<4;j++){
		for(int i=0;i<8;i++){
			arr[i][2*j]=arr[i][2*(j-1)]+8;
			arr[i][2*j+1]=arr[i][2*(j-1)+1]+8;
		}
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++)printf("%d\t",arr[i][j]);
		printf("\n");
	}
	return 0;
}