#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int main(){
    char input[2000005];
    gets(input);//读取输入数据
    int sum=0;//求英文字母序号之和
    for(int i=0;input[i]!='\0';++i)
        if(isalpha(input[i]))
            sum+=tolower(input[i])-'a'+1;
    if(sum==0){//如果sum为0，输出"0 0"
        printf("0 0");
        return 0;
    }
    int len=0;
    do{//转化成2进制字符串存储在input中
        input[len++]=sum%2+'0';
        sum/=2;
    }while(sum!=0);
    int a=0,b=0;
    for(int i=0;i<len;++i)//查找0和1的个数
        if(input[i]=='0')
            ++a;
        else if(input[i]=='1')
            ++b;
    printf("%d %d",a,b);//输出
    return 0;
}
