#include <stdio.h>
#include <stdlib.h>

int power(int a,int b,int P)
{
	if(b==0)return 1;
	if(b%2==0)return power((a*a)%P,b/2,P);
	return a*(power((a*a)%P,b/2,P))%P;
}

int main(void)
{
	int G,P;
	printf("Enter the value of G: ");
	scanf("%d",&G);
	printf("Enter the value of P: ");
	scanf("%d",&P);
	printf("Enter the secret key(a) for user1: ");
	int a;
	scanf("%d",&a);
	printf("Enter the secret key(b) for user2: ");
	int b;
	scanf("%d",&b);
	int x = power(G,a,P)%P;
	int y = power(G,b,P)%P;
	int secret_1 = power(y,a,P)%P;
	int secret_2 = power(x,b,P)%P;
	printf("Shared key to user2 is x = %d and to user1 is y = %d\n ",x,y);
	printf("Secret key generated for user one is %d and for user2 is %d\n",secret_1,secret_2);
	return 0;
}