#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *cipher(char *plain_text,char *key){
	int i=0;
	int l1=strlen(plain_text);
	int l2=strlen(key);
	char *cipher_text=malloc(sizeof(char)*(l1+1));
	while(plain_text[i]){
		cipher_text[i]='a'+((plain_text[i]-'a'+(key[i%l2]-'a'))%26);
		i++;
	}
	return cipher_text;
}

int main(void){
	printf("Enter the plain text: ");
	char plain_text[1001];
	scanf("%[^\n]%*c",plain_text);
	char key[1001];
	printf("Enter the key: ");
	scanf("%[^\n]%*c",key);
	printf("The cipher text of %s with key %s is %s\n",plain_text,key,cipher(plain_text,key));
	return 0;
}