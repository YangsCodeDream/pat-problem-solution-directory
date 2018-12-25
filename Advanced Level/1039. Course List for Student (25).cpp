#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>hashTable((int)1e6);//存储相应编号所指代的学生选的课,散列数组的大小尽量要开大一点
int strhash(char *s){//散列函数
    int k=0;
    for(int i=0;i<3;++i)
        k=k*26+s[i]-'A';
    k=k*26+s[3]-'0';
    return k;
}
int main(){
    int N,K;
    char name[5];
    scanf("%d%d",&N,&K);
    for(int i=1;i<=K;++i){//读取数据
        int course,num;
        scanf("%d%d",&course,&num);
        while(num--){
            scanf("%s",name);
            int k=strhash(name);//将读取到的名字散列为一个整数
            hashTable[k].push_back(course);//让该整数下的vector存储选的课
        }
    }
    while(N--){
        scanf("%s",name);
        int k=strhash(name);//将名字散列为一个整数
        printf("%s %d",name,hashTable[k].size());//按要求输出
        sort(hashTable[k].begin(),hashTable[k].end());
        for(int i=0;i<hashTable[k].size();++i)
            printf(" %d",hashTable[k][i]);
        printf("\n");
    }
    return 0;
}
