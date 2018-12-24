#include<bits/stdc++.h>
using namespace std;
int main(){
    char input[10005];
    gets(input);
    char s[7]="PATest";//将数组下标映射到PATest这6个字符
    unordered_map<char,int>m;//记录字符及其出现次数
    for(int i=0;input[i]!='\0';++i)//统计字符出现的次数
        ++m[input[i]];
    bool f=true;//跳出循环的标志
    while(f){//不断遍历输出
        f=false;
        for(int i=0;i<6;++i)
            if(m[s[i]]-->0){//如果有元素不为0
                printf("%c",s[i]);//输出一次对应字符
                f=true;//有元素不为0置f为true，表示不允许跳出循环
            }
    }
    return 0;
}
