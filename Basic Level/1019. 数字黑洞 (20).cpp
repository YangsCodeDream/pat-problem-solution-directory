#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,n1,n2;
    scanf("%d",&n);
    char temp[5];//4位正整数要存到5位的字符数组中，末位是'\0'
    do{
        sprintf(temp,"%d",n);//将输入的n存储到字符数组
        int len=strlen(temp);
        while(len<4)
            temp[len++]='0';//整数不够4位要补0
        temp[len]='\0';
        sort(temp,temp+len);//按数字从小到大的顺序对字符数组排序
        sscanf(temp,"%d",&n2);//将字符数组转换为整数
        reverse(temp,temp+len);//翻转字符数组
        sscanf(temp,"%d",&n1);
        n=n1-n2;
        printf("%04d - %04d = %04d\n",n1,n2,n);//确保输出为4位整数，不够在高位补0
    }while(n!=6174&&n!=0);
    return 0;
}
