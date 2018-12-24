#include<bits/stdc++.h>
using namespace std;
int main(){
    char carry[25],n1[25],n2[25];
    scanf("%s%s%s",carry,n1,n2);
    int c=0,len1=strlen(n1),len2=strlen(n2),len=max(len1,len2);
    reverse(carry,carry+strlen(carry));
    reverse(n1,n1+len1);
    reverse(n2,n2+len2);
    ++len;//为了循环中能直接处理最后进位的情况，令len递增
    for(int i=0;i<len;++i){
        int a=i<len1?n1[i]-'0':0;
        int b=i<len2?n2[i]-'0':0;
        int mod=10;
        if(i<strlen(carry)&&carry[i]!='0')
            mod=carry[i]-'0';
        n1[i]=(a+b+c)%mod+'0';
        c=(a+b+c)/mod;
    }
    while(n1[len-1]=='0')--len;
    if(len==0)   
        n1[len++]='0';
    n1[len]='\0';
    reverse(n1,n1+len);
    puts(n1);
    return 0;
}
