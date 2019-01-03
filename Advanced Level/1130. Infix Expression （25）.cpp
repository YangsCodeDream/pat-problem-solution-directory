#include<bits/stdc++.h>
using namespace std;
struct Node{//结点类
    string data;
    int left=-1,right=-1;
};
Node tree[25];
int N;
bool isLeaf(int v){//判断是否是叶子结点
    return tree[v].left==-1&&tree[v].right==-1;
}
void DFS(int v){//深度优先遍历
    if(tree[v].left!=-1){//左子树非空
        printf("%s",!isLeaf(tree[v].left)?"(":"");//如果左子树不是叶子结点输出(
        DFS(tree[v].left);
        printf("%s",!isLeaf(tree[v].left)?")":"");//如果左子树不是叶子结点输出)
    }
    cout<<tree[v].data;
    if(tree[v].right!=-1){//右子树非空
        printf("%s",!isLeaf(tree[v].right)?"(":"");//如果右子树不是叶子结点输出(
        DFS(tree[v].right);
        printf("%s",!isLeaf(tree[v].right)?")":"");//如果右子树不是叶子结点输出)
    }
}
int main(){
    scanf("%d",&N);
    bool child[N+1]={false};
    for(int i=1;i<=N;++i){
        cin>>tree[i].data>>tree[i].left>>tree[i].right;
        if(tree[i].left!=-1)
            child[tree[i].left]=true;
        if(tree[i].right!=-1)
            child[tree[i].right]=true;
    }
    DFS(find(child+1,child+N+1,false)-child);//child中为false的结点就是根节点
    return 0;
}
