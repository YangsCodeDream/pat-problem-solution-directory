#include<bits/stdc++.h>
using namespace std;
struct Testee{
    int rank=1,NS=0;//排名、考生人数
    double TWS=0.0;//加权总分
    string school="";//单位名
};
//比较函数
bool cmp(const Testee&t1,const Testee&t2){
    if(t1.TWS!=t2.TWS)
        return t1.TWS>t2.TWS;
    else if(t1.NS!=t2.NS)
        return t1.NS<t2.NS;
    else
        return t1.school<t2.school;
}
int main(){
    int N;
    scanf("%d",&N);
    unordered_map<string,Testee>school;
    while(N--){
        char id[7],s[7];
        double score;
        scanf("\n%s %lf %s",id,&score,s);
        for(int i=0;s[i]!='\0';++i)
            s[i]=tolower(s[i]);//转化为小写
        string str(s);
        if(id[0]=='B')
            score/=1.5;
        else if(id[0]=='T')
            score*=1.5;
        school[str].TWS+=score;//累加加权总分
        ++school[str].NS;//递增考试人数
        school[str].school=str;//更新单位名称
    }
    vector<Testee>v;
    for(auto i=school.begin();i!=school.end();++i){
        (i->second).TWS=floor((i->second).TWS);//向下取整
        v.push_back(i->second);//将数据搬迁到vector中
    }
    sort(v.begin(),v.end(),cmp);//排序
    for(int i=1;i<v.size();++i)
        if(v[i].TWS!=v[i-1].TWS)//当前考生加权总分和排在其前面考生加权总分不一致
            v[i].rank=i+1;//排名为i+1
        else//当前考生加权总分和排在其前面考生加权总分一致
            v[i].rank=v[i-1].rank;//排名与排在其前面考生一致
    printf("%d\n",v.size());
    for(Testee&t:v)
        printf("%d %s %.0f %d\n",t.rank,t.school.c_str(),t.TWS,t.NS);
    return 0;
}
