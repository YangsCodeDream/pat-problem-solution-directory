#include <bits/stdc++.h>
using namespace std;
const int MAX=1005;
bool isPalindromic(char*s){//判断是否回文
    int len=strlen(s);
    for(int i=0,j=len-1; i<j; ++i,--j)//定义两个指针从数组两端同时向中间遍历，检测指向的字符是否一致，不一致，则返回false
        if(s[i]!=s[j])
            return false;
    return true;//都一致，返回true
}
void add(char*n1,char*n2){//大整数加法，从索引为0的位置开始进行逐位加法，如果有最终进位可以放在数组末尾
    int len=strlen(n1);
    int jinwei=0;//进位
    for(int i=0; i<len; ++i){
        int k=n1[i]+n2[i]-'0'-'0'+jinwei;
        jinwei=k/10;
        n1[i]=k%10+'0';
    }
    if(jinwei>0)//有最终进位放在数组末尾
        n1[len++]=jinwei+'0';
    n1[len]='\0';//补充'\0'结束符
}
int main(){
    char*n1=new char[MAX],*n2=new char[MAX];
    gets(n1);
    int k=0;
    while(k<10&&!isPalindromic(n1)){//如果不是回文数且未超过指定步数，继续循环
        int len=strlen(n1);
        strcpy(n2,n1);//拷贝n1数组到n2中
        reverse(n2,n2+len);//翻转n2数组
        printf("%s + %s = ",n1,n2);
        add(n1,n2);//进行加法
        reverse(n1,n1+strlen(n1));//翻转n1数组（因为n1是从数组向数组末位进行逐位加法的）
        printf("%s\n",n1);
        ++k;
    }
    if(isPalindromic(n1))
        printf("%s is a palindromic number.",n1);
    else
        printf("Not found in 10 iterations.");
    return 0;
}
