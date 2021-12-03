#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define max 1000

int main(){
    int s,pi,ci;
    char plain[max], cipher[max];

    printf("\nEnter the plain text: ");
    fgets(plain, max, stdin);
    printf("Enter the number of shifts: ");
    scanf("%d", &s);

    for(ci=0,pi=0;plain[pi]!='\0';pi++)
    if(isalpha(plain[pi])) cipher[ci++]=((toupper(plain[pi])-'A')+s%26)%26 + 'A';  
   
    cipher[ci]='\0';
    printf("The ciphered text: %s", cipher);

    printf("\n\nDecryption\nEnter the key for decryption: ");
    scanf("%d", &s);

    for(ci=0,pi=0;cipher[ci]!='\0';ci++)
    plain[pi++]=((cipher[ci]-'A')+ (26-s))%26+'A';
    plain[pi]='\0';
    printf("The deciphered text: %s", plain);
}