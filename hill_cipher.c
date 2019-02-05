#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COLUMN 4

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


char **matrix_multiply(char a[][4],char b[][4],int row, int column){
	char **ans =(char **)malloc(sizeof(char *)*row);
	for(int i=0;i<row;i++)ans[i]=(char *)malloc(sizeof(char)*column);
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			int temp=0;
			for(int k=0;k<column;k++){
				temp+=a[i][k]*b[k][j];
			}
			ans[i][j]=temp%26;
		}
	}
	return ans;
}
int main(void){
	char *plain = (char *)malloc(sizeof(char)*1024);
	printf("Enter the plain Text: ");
	scanf("%[^\n]s",plain);
	char key[4][4] = {{9,7,11,13},{4,7,5,6},{2,21,14,9},{3,23,21,8}};
	char *word= transform(plain);
	int total_length=strlen(word);
	int rows=ceil((1.0*total_length)/COLUMN);
	char plain_table[rows][COLUMN];
	for(int i=0;i<rows;i++)for(int j=0;j<COLUMN;j++)plain_table[i][j]=25;
	int count=0;
	while(count<total_length){
		plain_table[count/total_length][count%total_length]=word[count]-'a';
		count++;
	}
	char **result=matrix_multiply(plain_table,key,rows,COLUMN);
	printf("Word is %s\n",word);
	printf("plain table is\n");
	for(int i=0;i<rows;i++){
		for(int j=0;j<COLUMN;j++){
			printf("%c ",plain_table[i][j]+'a');
		}
		printf("\n");
	}
	printf("Cipher text is : ");
	for(int i=0;i<rows;i++){
		for(int j=0;j<COLUMN;j++)printf("%c",result[i][j]+'a');
	}
	printf("\n");
	return 0;
}