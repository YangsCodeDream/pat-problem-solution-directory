#include<bits/stdc++.h>
using namespace std;
int main(){
    char s1[100005]="",s2[100005]="";
    bool broken[128]={false};//true表示该键坏了，false表示该键完好
    gets(s1);
    gets(s2);
    for(int i=0;s1[i]!='\0';++i)
        broken[s1[i]]=true;//在数组broken中把坏掉的键置true
    for(int i=0;s2[i]!='\0';++i)
        if(!broken[toupper(s2[i])])//如果对应的键没有坏
            if(isupper(s2[i])&&!broken['+']||!isupper(s2[i]))//如果该键是大写字母并且上档键没有坏或者不是大写字母则予输出
                printf("%c",s2[i]);
    printf("\n");//如果没有一个字符能被打出，则输出空行。(测试点并未检测)
    return 0;
}
