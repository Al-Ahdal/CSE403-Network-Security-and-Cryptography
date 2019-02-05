#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *transform(char *plain){
	int l=strlen(plain);
	int count=0;
	char *result = (char *)(malloc(sizeof(char)*(l+1)));
	for(int i=0;i<l;i++){
		if(plain[i]!=' ')result[count++]=plain[i];
	}
	result[count]='\0';
	return result;
}

int main(void){
	char *plain=(char *)malloc(sizeof(char)*1024);
	printf("Enter the plain text: ");
	scanf("%[^\n]s",plain);
	int i=0;
	plain= transform(plain);
	int len=strlen(plain);
	while(i<len){
		if(i%2==0)printf("%c",plain[i]);
		i+=2;
	}
	i=1;
	while(i<len){
		if(i%2)printf("%c",plain[i]);
		i+=2;
	}
	printf("\n");
	return 0;
}