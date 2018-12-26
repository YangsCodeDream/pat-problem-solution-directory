#include<bits/stdc++.h>
using namespace std;
int N,M,S,weight[105];
vector<int> tree[105],path;//tree存储整棵树的信息，path存储所求路径
bool visit[105];
void DFS(int v,int pathWeight){//v记录当前遍历到的结点，pathWeight记录遍历到当前结点时路径的权重和
    pathWeight+=weight[v];//权重和加上当前结点的权重
    if(pathWeight>S||(pathWeight==S&&!tree[v].empty()))//如果当前权重和比S大或者等于S且当前结点不是叶子结点
        return;//直接返回
    visit[v]=true;//置visit为true，表示当前结点已访问过
    path.push_back(v);//将当前结点压入path路径中
    if(pathWeight==S)//如果当前权重和与S相等，说明当前路径即为所求，按要求输出整个路径
        for(int i=0;i<path.size();++i)
            printf("%s%d%s",i>0?" ":"",weight[path[i]],i==path.size()-1?"\n":"");
    for(int i:tree[v])//递归遍历当前结点的邻接点
        if(!visit[i])
            DFS(i,pathWeight);
    visit[v]=false;//置visit为false，回溯到上一结点
    path.pop_back();//将当前结点在path路径中弹出，回溯到上一结点
}
bool cmp(int a,int b){//比较函数
    return weight[a]>weight[b];
}
int main(){
    scanf("%d%d%d",&N,&M,&S);
    for(int i=0;i<N;++i)
        scanf("%d",&weight[i]);
    while(M--){//读取数据
        int id,K,a;
        scanf("%d%d",&id,&K);
        while(K--){
            scanf("%d",&a);
            tree[id].push_back(a);
        }
        sort(tree[id].begin(),tree[id].end(),cmp);//按权重从大到小排序，确保输出时先输出权重大的，再输出权重小的
    }
    DFS(0,0);//深度优先遍历
    return 0;
}
