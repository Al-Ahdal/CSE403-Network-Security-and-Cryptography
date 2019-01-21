/*
*	Caesar Cipher modified for all integer keys
*	Made by Shubham Kumar
*	sshubhamk1@hotmail.com
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define MSG_SIZE 1001	// maximum size of plain text


// This function encrypt the plain text to cipher text with the help of key 
char *Cipher_Caesar(char *plain_text,int key){
	int len=strlen(plain_text);
	char *cipher_text = malloc(sizeof(char)*(len+1));
	for(int i=0;i<len;i++){
		if(!isalnum(plain_text[i])){
			cipher_text[i]=plain_text[i];
		}
		else{
			if(isdigit(plain_text[i])){
				cipher_text[i]=(plain_text[i]-48+key%10)%10+48;
			}
			else if(islower(plain_text[i])){
				cipher_text[i]=(plain_text[i]-97+key%26)%26+97;
			}
			else{
				cipher_text[i]=(plain_text[i]-65+key%26)%26+65;
			}
		}
	}
	cipher_text[len]='\0';
	return cipher_text;
}


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
	char plain_text[MSG_SIZE];
	scanf("%[^\n]s",plain_text);
	printf("Enter youe key: ");
	int key;
	scanf("%d",&key);
	char *cipher_text = Cipher_Caesar(plain_text,key);
	char *orignal_text = Decipher_Caesar(cipher_text,key);
	printf("plain Text: %s\n",plain_text);
	printf("Cipher Text with key %d : %s\n",key,cipher_text);
	printf("Decrypting Text with key %d : %s\n",key,orignal_text);
	return 0;
}