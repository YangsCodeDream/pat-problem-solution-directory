#include<bits/stdc++.h>
using namespace std;
int main(){
    int K1,K2;
    scanf("%d",&K1);
    int A1[K1+1];
    for(int i=0;i<K1;++i)
        scanf("%d",&A1[i]);
    scanf("%d",&K2);
    int A2[K2+1];
    for(int i=0;i<K2;++i)
        scanf("%d",&A2[i]);
    A1[K1]=A2[K2]=INT_MAX;//保证扫描过程中，不会出现一个序列已经扫描完但是还没有得到结果的情况下数组访问越界的问题
    int i=0,j=0,result;//i,j分别作为A1、A2两个数组的索引，result储存最后结果
    for(int k=0;k<(K1+K2+1)/2;++k)//给result赋值为A1当前位置的数与A2当前位置的数中较小的数，并将指向较小的数的索引右移一位，重复该操作直至找到两个数组第(K1+k2+1)/2个数即为最后结果
        if(A1[i]<A2[j])
            result=A1[i++];
        else
            result=A2[j++];
    printf("%d",result);
    return 0;
}
