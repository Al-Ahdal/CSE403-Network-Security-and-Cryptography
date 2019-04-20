#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char **transform(char *plain){
	int len = strlen(plain);
	if(len%2)len+=1;
	char **cipher= malloc(sizeof(char *)*len);
	int count=0;
	int i=0;
	while((plain[i]) &&(count<len)){
		cipher[count]=malloc(sizeof(char)*2);
		cipher[count][0]=plain[i];
		i++;
		if(cipher[count][0]==plain[i]){
			cipher[count][1]='X';

		}
		else{
			if(plain[i])cipher[count][1]=plain[i];
			else cipher[count][1]='X';
			i++;
		}
		count++;
	}
	cipher = realloc(sizeof(char *)*count);
	return cipher;
}
char *removeSpace(char *str){
	int len=strlen(str);
	int count=0;
	int i=0;
	while(i<len){
		if(plain[i]!=' '){
			plain[count++]=plain[i];
		}
		i++;
	}
	str[count]='\0';
	return str;
}
int main(void){
	char *plain=malloc(sizeof(char)*1024);
	printf("Enter the plain Text: ");
	scanf("%[^\n]%*c",plain);
	char *key = malloc(sizeof(char)*1024);
	printf("Enter the key for encrypt: ");
	scanf("%[^\n]%*c",key);
	plain=removeSpace(plain);
	printf("new plain text is %s\n",plain);
	plain=transform(plain);
	char **cipher=playfair(plain);
	int count=0;
	while(cipher[count][0]|| cipher[count][1]){
		printf("%c %c\n",cipher[count][0],cipher[count][1]);
		count++;
	}
	printf("The modified plain Text was %s\n",plain);
	//printf("The Corresponding Cipher Text is %s\n",cipher);
	return 0;
}