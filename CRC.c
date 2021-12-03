#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N strlen(g)

char t[128], cs[128], g[]="10110";
int a,e,c;

void xor(){
    for(c=1;c<N;c++){
        cs[c]=((cs[c]==g[c]?'0':'1'));
    }
}

void crc(){
    for(e=0;e<N;e++) cs[e]=t[e];
        do{
            if (cs[0]=='1') xor();
            for(c=0;c<N-1;c++){
                cs[c]=cs[c+1];
            }
            cs[c]=t[e++];            
        }while (e<=a+N-1);
}

void main(){
    printf("\nEnter the polygon: ");
    scanf("%s", t);
    
    printf("Generating Polynomial: %s", g);

    a=strlen(t);
    for(e=a;e<a+N-1;e++) t[e]='0';

    printf("\n\nModified t[u]: %s", t);
    crc();
    printf("\nChecksum: %s", cs);

    for(e=a;e<a+N-1;e++) t[e]=cs[e-a];
    printf("\n\nFinal codeword: %s", t);

    //Useless piece of code 
    int check,pos;
    printf("\n\nTest error detection 0(yes) 1(no)?");
    scanf("%d",&check);

    if(check==0){
        printf("Enter the position to insert error: ");
        scanf("%d", &pos);
        t[pos]=(t[pos]=='1'?'0':'1');
        printf("\nErroneous data: %s", t);
        printf("\nError detected");
    }

    else{
        printf("\nNo error");
    }
}