#include <bits/stdc++.h>
using namespace std;
const int INF=1e4+5;
int pre[INF],in[INF],father[INF],depth[INF];
void createTree(int root,int left,int right,int Depth,int Father){
    if(left>right)
        return;
    int i=0;
    while(in[i]!=pre[root])
        ++i;
    father[i]=Father;
    depth[i]=Depth;
    createTree(root+1,left,i-1,Depth+1,i);
    createTree(root+1+i-left,i+1,right,Depth+1,i);
}
int main(){
    int M,N;
    scanf("%d%d",&M,&N);
    for(int i=0;i<N;++i){
        scanf("%d",&pre[i]);
        in[i]=pre[i];
    }
    sort(in,in+N);
    createTree(0,0,N-1,1,INT_MAX);
    while(M--){
        int a,b;
        scanf("%d%d",&a,&b);
        int f1=lower_bound(in,in+N,a)-in,f2=lower_bound(in,in+N,b)-in;
        if((f1==N||in[f1]!=a)&&(f2==N||in[f2]!=b))
            printf("ERROR: %d and %d are not found.\n",a,b);
        else if(f1==N||in[f1]!=a)
            printf("ERROR: %d is not found.\n",a);
        else if(f2==N||in[f2]!=b)
            printf("ERROR: %d is not found.\n",b);
        else{
            if(depth[f1]<depth[f2])
                swap(f1,f2);
            while(depth[f1]!=depth[f2])
                f1=father[f1];
            if(in[f1]==in[f2])
                printf("%d is an ancestor of %d.\n",in[f2],in[f2]==a?b:a);
            else{
                while(in[f1]!=in[f2]){
                    f1=father[f1];
                    f2=father[f2];
                }
                printf("LCA of %d and %d is %d.\n",a,b,in[f1]);
            }
        }
    }
    return 0;
}
