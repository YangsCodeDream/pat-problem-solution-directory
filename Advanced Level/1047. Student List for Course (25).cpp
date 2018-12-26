#include<bits/stdc++.h>
using namespace std;
char name[40005][5];//存储名字
//排序函数
bool cmp(const int a,const int b){
    return strcmp(name[a],name[b])<0;
}
int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    vector<int>course[K+1];//其数组下标存储课程号，数组元素存储选修该课程的学生的名字在name中的下标
    for(int i=0;i<N;++i){
        int C;
        scanf("\n%s %d",name[i],&C);
        while(C--){
            int a;
            scanf("%d",&a);
            course[a].push_back(i);
        }
    }
    for(int i=1;i<=K;++i){
        printf("%d %d\n",i,course[i].size());
        sort(course[i].begin(),course[i].end(),cmp);//排序
        for(int j=0;j<course[i].size();++j)
            printf("%s\n",name[course[i][j]]);
    }
    return 0;
}
