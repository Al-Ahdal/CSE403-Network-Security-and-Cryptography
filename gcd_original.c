#include <stdio.h>

int gcd(int num1,int num2){
	int q=num1/num2,r1=num1,r2=num2,r;
	r=r1%r2;
	printf("q:%d\tr1:%d\tr2:%d\tr:%d\n",q,r1,r2,r);
	if(r==0)return r2;
	while(r!=0){
		r1=r2;
		r2=r;
		r=r1%r2;
		q=r1/r2;
		printf("q:%d\tr1:%d\tr2:%d\tr:%d\n",q,r1,r2,r);
	}
	return r2;
}


int main(void){
	int num1,num2;
	printf("Enter the number 1: ");
	scanf("%d",&num1);
	printf("Enter the number 2: ");
	scanf("%d",&num2);
	printf("The GCD of %d and %d is %d\n",num1,num2,gcd(num1,num2));
	return 0;
}