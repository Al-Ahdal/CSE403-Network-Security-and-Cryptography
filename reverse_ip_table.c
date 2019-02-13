#include <stdio.h>


int main(void){
	int arr[8][8];
	int count=33;
	for(int i=7;i>=0;i--)arr[0][i]=count++;
	count=1;
	for(int i=7;i>=0;i--)arr[1][i]=count++;
	for(int i=1;i<4;i++){
		for(int j=0;j<8;j++){
			arr[2*i][j]=arr[2*(i-1)][j]+8;
			arr[2*i+1][j]=arr[2*(i-1)+1][j]+8;
		}
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++)printf("%d\t",arr[j][i]);
		printf("\n");
	}
	return 0;
}