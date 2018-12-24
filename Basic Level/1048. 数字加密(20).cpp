#include<bits/stdc++.h>
using namespace std;
int main(){
    char A[105],B[105];
    char trans[14]="0123456789JQK";
    scanf("%s %s",A,B);
    int Alen=strlen(A),Blen=strlen(B);
    //翻转A、B字符串
    reverse(A,A+Alen);
    reverse(B,B+Blen);
    int len=max(Alen,Blen);//取A、B字符串中最长的长度
    for(int i=0;i<len;++i){
        int numA=i<Alen?A[i]-'0':0;//记录相应A字符串位置的数字，如果超过了A的长度，记0
        int numB=i<Blen?B[i]-'0':0;//记录相应B字符串位置的数字，如果超过了B的长度，记0
        //字符串下标从0开始，而题目中个位从1开始编号，所以对于奇数位偶数位的处理要反过来
        if(i%2==0)
            B[i]=trans[(numA+numB)%13];
        else{
            int t=numB-numA;
            if(t<0)
                t+=10;
            B[i]=t+'0';
        }
    }
    B[len]='\0';//在B字符串末位补'\0'字符
    reverse(B,B+len);//翻转B字符串
    puts(B);//输出
    return 0;
}
