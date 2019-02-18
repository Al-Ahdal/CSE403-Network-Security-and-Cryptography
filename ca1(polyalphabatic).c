#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int modify(char a){
	if(isdigit(a))return a-'0';
	else if(isupper(a))return a-'A';
	else if(islower(a))return a-'a';
	else return 0;
}

char *polyalphabatic(char *plain,char *key){
	int len_plain=strlen(plain);
	int len_key=strlen(key);
	char *cipher=(char *)malloc(sizeof(char)*(len_plain+1));
	for(int i=0;i<len_plain;i++){
		if(isalnum(plain[i])){
			if(isdigit(plain[i])){
				cipher[i]=(modify(plain[i])+modify(key[i%len_key]))%10+'0';
			}
			else if(islower(plain[i])){
				cipher[i]=(modify(plain[i])+modify(key[i%len_key]))%26+'a';
			}
			else {
				cipher[i]=(modify(plain[i])+modify(key[i%len_key]))%26+'A';
			}
			//alnum
		}
		else{
			cipher[i]=plain[i];
		}
	}
	cipher[len_plain]='\0';
	return cipher;
}

int main(void){
	printf("Enter the plain text: ");
	char *plain=(char *)malloc(sizeof(char)*1024);
	scanf("%s",plain);
	printf("Enter the key: ");
	char *key=(char *)malloc(sizeof(char)*1024);
	scanf("%s",key);
	char *cipher = polyalphabatic(plain,key);
	printf("\n\n\n");
	printf("Plain text: %s\n",plain);
	printf("cipher text: %s\n",cipher);
	printf("Key used: %s\n",key);
	return 0;
}