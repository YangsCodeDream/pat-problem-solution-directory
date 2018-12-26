#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,num=0,index=1;
    scanf("%d",&N);
    int position[N];//下标表示数字i，数组元素表示i在第几位
    for(int i=0;i<N;++i){
        int a;
        scanf("%d",&a);
        position[a]=i;
    }
    while(true){
        while(position[0]!=0){//0不在0号位
            swap(position[0],position[position[0]]);
            ++num;
        }
        for(;index<N;++index)//0在0号位，从index位开始查找序列中不在本位的数
            if(position[index]!=index){
                swap(position[0],position[index]);
                ++num;
                break;
            }
        if(index==N)//没有找到不在本位的数，跳出循环
            break;
    }
    printf("%d",num);
    return 0;
}
