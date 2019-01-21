/*
*	Program to find Greatest Common Divisor of two numbers
*	
*/
#include <stdio.h>

int GCD(int num1,int num2){
	if(num2==0){
		return num1;
	}
	return GCD(num2,num1%num2);
}

int main(void){
	int num1,num2;
	printf("Enter the number 1: ");
	scanf("%d",&num1);
	printf("Enter the number 2: ");
	scanf("%d",&num2);
	printf("The GCD of %d and %d is %d\n",num1,num2,GCD(num1,num2));	
	return 0;
}