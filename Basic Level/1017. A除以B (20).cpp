#include<bits/stdc++.h>
using namespace std;
int main(){
    char A[1005],Q[1005];
    int B,R=0,size=0;
    scanf("%s %d",A,&B);
    for(int i=0;A[i]!='\0';++i){//大整数除法
        R=R*10+A[i]-'0';
        Q[size++]=R/B+'0';
        R%=B;
    }
    bool output=false;
    for(int i=0;i<size;++i)//输出Q并检测Q是否为0，output指示Q是否为0
        if(Q[i]!='0'||output){
            printf("%c",Q[i]);
            output=true;
        }
    printf("%s %d",output?"":"0",R);//Q为0先输出一个0再输出R
    return 0;
}
