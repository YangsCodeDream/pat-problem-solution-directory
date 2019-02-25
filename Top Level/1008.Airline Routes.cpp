#include<bits/stdc++.h>
using namespace std;
const int MAX=10005;
vector<int>graph[MAX];
//index[i]表示i是第几个被访问的结点,lowLink[i]表示从i出发经有向边可到达的所有节点中最小的index,sccno[i]表示i所属的强连通分量的编号
int index[MAX],lowLink[MAX],sccno[MAX],dfsNo=0,scc_cnt=0;
stack<int>s;
void DFS(int v){
    index[v]=lowLink[v]=++dfsNo;
    s.push(v);
    for(int i:graph[v]){
        if(index[i]==0){
            DFS(i);
            lowLink[v]=min(lowLink[v],lowLink[i]);
        }else if(sccno[i]==0)
            lowLink[v]=min(lowLink[v],index[i]);
    }

    if(lowLink[v]==index[v]){
        ++scc_cnt;
        int t;
        do{
            t=s.top();
            s.pop();
            sccno[t]=scc_cnt;
        }while(t!=v);
    }
}
int main(){
    int n,m,k,a,b;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
    }
    for(int i=1;i<=n;++i)
        if(index[i]==0)
            DFS(i);
    scanf("%d",&k);
    while(k--){
        scanf("%d%d",&a,&b);
        puts(sccno[a]==sccno[b]?"Yes":"No");
    }
    return 0;
}
