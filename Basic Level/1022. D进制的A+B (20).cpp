#include<bits/stdc++.h>
using namespace std;
int main(){
    int A,B,D;
    scanf("%d%d%d",&A,&B,&D);
    A+=B;
    if(A==0)
        printf("0");
    char result[32];
    int i=0;
    while(A!=0){
        result[i++]=(char)(A%D)+'0';
        A/=D;
    }
    while(i>0)
        printf("%c",result[--i]);
    return 0;
}
