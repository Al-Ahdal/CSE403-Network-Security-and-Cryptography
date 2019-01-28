#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int get(char a){
	if(isupper(a))return a-'A';
	else if(islower(a))return a-'a';
	else if(isdigit(a))return a-'0';
	else return a;
}

char tranform(char a, char b){
	if(isupper(a)){
		a=(a-'A'+get(b))%26+'A';
	}
	else if(islower(a)){
		a=(a-'a'+get(b))%26+'a';
	}
	else{
		a=(a-'0'+get(b))%10+'0';
	}
	return a;
}

char *vigenere(char *plain,char *key){
	int len=strlen(plain);
	char *cipher = malloc((sizeof(char)*(len+1)));
	int key_len=strlen(key);
	for(int i=0;i<len;i++){
		if(!isalpha(plain[i]))cipher[i]=plain[i];
		else cipher[i]=tranform(plain[i],key[i%key_len]);
	}
	cipher[len]='\0';
	return cipher;
}

int main(void){
	printf("Enter the cipher Text: ");
	char plain[1001];
	scanf("%[^\n]%*c",plain);
	char key[1001];
	printf("Enter the key for ciphering: ");
	scanf("%[^\n]%*c",key);
	printf("Plained Text: %s\n",plain);
	printf("Cipher Text: %s\n",vigenere(plain,key));
	printf("Key used: %s\n",key);
}