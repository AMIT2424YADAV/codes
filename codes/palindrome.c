#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>


int kk=0,hash[26]={0};
char data[10000];


/* Define your support function ptototypes here */

void palindrome_odd(int hash[],char data[],int n);
void palindrome_even(int hash[],char data[],int n);





/* Define your actual support functions code here */

void palindrome_odd(int hash[],char data[],int n)
{
	int i;
	for(i=0;i<26;i++)
	{
		if(hash[i]>0)
		{
			data[0]='a'+i;
			data[1]='\0';
			printf("%s\n",data);
			hash[i]--;
			palindrome_even(hash,data,1);
			hash[i]++;
			kk++;
		}
	}

}



void palindrome_even(int hash[],char data[],int n)
{

        int i,j;
	for(j=n;j>0;j--)
		data[j]=data[j-1];
        for(i=0;i<26;i++)
        {
                if(hash[i]>1)
                {
			char temp[1000];
			data[0]='a'+i;
                        data[n+1]='a'+i;
			data[n+2]='\0';
			printf("%s\n",data);
                        hash[i]-=2;
			for(j=0;j<n+2;j++)
				temp[j]=data[j];
                        palindrome_even(hash,temp,n+2);
                        hash[i]+=2;
			kk++;
                }
        }

}


/* 
* The function Palindrome accepts one parameter 
* Inputs 
* The first parameter inStr contains the input string 
* Outputs 
* The function returns the number of unique palindromes generated 
* The function also prints each unique palindrome on a separate standard output line 
*/ 

int Palindrome(char *inStr) 
{ 
/* Write your local variables, code here */
	int n = strlen(inStr);
	int i,j;
	for(i=0;i<n;i++)
		hash[inStr[i]-'a']++;
	palindrome_odd(hash,data,0);
	palindrome_even(hash,data,0);
    return kk;

}

int main()
{
	char s[1000];
	scanf("%s",s);
	int asd=Palindrome(s);
	printf("%d\n",asd);
	return 0;
}

