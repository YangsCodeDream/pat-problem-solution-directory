#include<bits/stdc++.h>
using namespace std;
int N,M,K;
vector<int>graph[205];//图
bool Hamiltonian(const vector<int>&v){//判断一个序列是否是哈密顿环
    if(v.size()!=N+1||v.front()!=v.back())//判断结点个数是否为图中结点总数+1、判断首尾结点是否相同
        return false;
    unordered_set<int>s;
    for(int i=0;i<v.size()-1;++i){//判断除尾节点外每个结点是否只出现一次
        if(s.find(v[i])!=s.cend())
            return false;
        s.insert(v[i]);
    }
    for(int i=1;i<v.size();++i)//判断序列中每两个相邻数之间是否有路径
        if(find(graph[v[i-1]].cbegin(),graph[v[i-1]].cend(),v[i])==graph[v[i-1]].cend())
            return false;
    return true;
}
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    scanf("%d",&K);
    while(K--){
        scanf("%d",&M);
        vector<int>A(M);
        for(int i=0;i<M;++i)
            scanf("%d",&A[i]);
        printf("%s\n",Hamiltonian(A)?"YES":"NO");
    }
    return 0;
}
