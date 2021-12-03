#include<stdio.h>
#include<string.h>
#define DLE 16
#define STX 2
#define ETX 3

void main(){
    char ch, arr[50]={DLE, STX}, rec[50];
    int len=2,j,i;

    printf("Enter the data stream \ncntrl+p -> DLE cntrl+->STX cntrl+c->ETX \n");
    while((ch=getchar())!='\t'){
        if(ch==DLE){
            arr[len++]=DLE;
            printf("DLE");
        }
        else if(ch==STX) printf("STX");
        else if(ch==ETX) printf("ETX");
        else printf("%c", ch);
        arr[len++]=ch;
    }

    arr[len++]=DLE;
    arr[len++]=ETX;

    printf("\nStuffed stream: ");
    for(i=0;i<len;i++){
        ch=arr[i];
        if(ch==DLE) printf("DLE");
        else if(ch==STX) printf("STX");
        else if(ch==ETX) printf("ETX");
        else printf("%c", ch);
    }

    //Destuffing

    printf("\nDestuffed stream: ");
    for(j=2;j<len-2;j++){
        ch=arr[j];
        if(ch==DLE){
            printf("DLE");
            j++;
        }
        else if(ch==STX) printf("STX");
        else if(ch==ETX) printf("ETX");
        else printf("%c", ch);        
    }
}
