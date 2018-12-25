#include<bits/stdc++.h>
using namespace std;
char input[25],result[25];//输入的大整数、2倍后的大整数
int hashTable[10];//辅助数组
int mul(){//大整数乘法
    int len=strlen(input),num=0;//进位num初始化为0
    result[len]='\0';//将新数相应位置置为'\0'字符，方便输出
    for(int i=len-1;i>=0;--i){//从个位开始乘2
        int k=2*(input[i]-'0')+num;//获取每一位乘2的值
        result[i]=k%10+'0';//取个位字符
        num=k/10;//将十位数作为进位
        ++hashTable[input[i]-'0'];//在相应的hashTable数组下标下进行递增
        --hashTable[result[i]-'0'];//在相应的hashTable数组下标下进行递减
    }
    return num;//返回最终进位
}
int main(){
    gets(input);
    int num=mul();//获得最终进位
    bool yes=true;//输出Yes或者No的标志
    if(num!=0)
        --hashTable[num];
    for(int i=0;i<10&&yes;++i)//遍历整个hashTable数组，看是否有不为0的元素，如果有置yes为false
        if(hashTable[i]!=0)
            yes=false;
    printf("%s\n",num==0&&yes?"Yes":"No");
    if(num!=0)//如果进位不是0，先输出进位
        printf("%d",num);
    printf("%s",result);//输出新数
    return 0;
}
