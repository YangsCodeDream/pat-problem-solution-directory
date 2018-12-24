#include <bits/stdc++.h>
using namespace std;
struct Student{//学生结构体，把成绩均初始化为-1，以便输出
    char id[25];
    int Gp=-1,Gmid=-1,Gfinal=-1,G=0;
};
bool cmp(const Student&s1,const Student&s2){//比较函数
    if(s1.G!=s2.G)
        return s1.G>s2.G;
    else
        return strcmp(s1.id,s2.id)<0;
}
int main(){
    unordered_map<string,Student>m;//学生id到学生结构体的映射
    int P,M,N;
    scanf("%d%d%d",&P,&M,&N);
    char temp[25];
    int score;
    for(int i=0; i<P; ++i){
        scanf("\n%s %d",temp,&score);
        m[string(temp)].Gp=score;
    }
    for(int i=0; i<M; ++i){
        scanf("\n%s %d",temp,&score);
        m[string(temp)].Gmid=score;
    }
    for(int i=0; i<N; ++i){
        scanf("\n%s %d",temp,&score);
        string s(temp);
        m[s].Gfinal=score;
        if(m[s].Gmid>m[s].Gfinal)//计算最终成绩
            m[s].G=(int)round(m[s].Gmid*0.4+m[s].Gfinal*0.6);
        else
            m[s].G=m[s].Gfinal;
    }
    vector<Student>v;//存储合格学生的数组
    for(auto i=m.begin(); i!=m.end(); ++i){//将合格学生加入数组v中
        if((i->second).Gp>=200&&(i->second).G>=60){
            strcpy((i->second).id,(i->first).c_str());//进行Id拷贝
            v.push_back(i->second);
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0; i<v.size(); ++i)
        printf("%s %d %d %d %d\n",v[i].id,v[i].Gp,v[i].Gmid,v[i].Gfinal,v[i].G);
    return 0;
}
