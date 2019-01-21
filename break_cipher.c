/*
*	Program to break the cipher text encrypted with caeser cipher and obtain all the possible plain texts
*	Made By Shubham Kumar
*	sshubhamk1@hotmail.com
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define MSG_SIZE 1001	// maximum size of plain text

// This function decrypt the cipher text to original text with the help of key
char *Decipher_Caesar(char *cipher_text,int key){
	int len= strlen(cipher_text);
	char *orignal_text= malloc(sizeof(char)*(len+1));
	for(int i=0;i<len;i++){
		if(!isalnum(cipher_text[i])){
			orignal_text[i]= cipher_text[i];
		}
		else{
			if(isdigit(cipher_text[i])){
				orignal_text[i]= (cipher_text[i]-38-key%10)%10+48;
			}
			else if(islower(cipher_text[i])){
				orignal_text[i]= (cipher_text[i]-71-key%26)%26+97;
			}
			else{
				orignal_text[i]= (cipher_text[i]-39-key%26)%26+65;
			}
		}
	}
	orignal_text[len]='\0';
	return orignal_text;
}


int main(void){
	printf("Enter Your message: ");
	char cipher_text[MSG_SIZE];
	scanf("%[^\n]s",cipher_text);
	printf("Cipher Text: %s\n",cipher_text);
	for(int i=1;i<26;i++){
		printf("Decrypting with key %d : %s\n",i,Decipher_Caesar(cipher_text,i));
	}
	return 0;
}