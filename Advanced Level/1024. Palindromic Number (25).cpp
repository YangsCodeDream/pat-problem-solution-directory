#include<bits/stdc++.h>
using namespace std;
char s1[50],s2[50];
int K;
void add(){//大整数加法
    int num=0,i=0;
    for(;s1[i]!='\0';++i){//开始进行大整数加法
        int k=s1[i]-'0'+s2[i]-'0'+num;//k储存对应位置下s1与s2的数字之和
        s1[i]=k%10+'0';//取各位数存入s1的相应位置
        num=k/10;//十位数作为进位
    }
    if(num!=0)//最终进位不为0
        s1[i++]=num+'0';//添加到s1末尾
    s1[i]='\0';//加字符串截止符
}
bool isPalindromic(char*s){
    for(int i=0,j=strlen(s)-1;i<j;++i,--j)//从字符串两端同时向中间遍历查看有没有不同字符，有返回false，若都相同返回true
        if(s[i]!=s[j])
            return false;
    return true;
}
int main(){
    scanf("%s %d",s1,&K);
    int step=0;
    while(!isPalindromic(s1)&&step<K){
        strcpy(s2,s1);//将s1复制到s2中
        reverse(s1,s1+strlen(s1));//翻转s1
        add();//进行加法
        ++step;//步骤数+1
    }
    reverse(s1,s1+strlen(s1));//将s1翻转，以便输出
    printf("%s\n%d",s1,step);
}
