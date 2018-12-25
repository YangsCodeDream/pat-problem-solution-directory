#include<bits/stdc++.h>
using namespace std;
struct Person{
    char id[16];
    int h,m,s;
    Person(int hh=0,int mm=0,int ss=0):h(hh),m(mm),s(ss){}
    bool operator <(const Person&p)const{//重载小于运算符
        if(this->h!=p.h)
            return this->h<p.h;
        else if(this->m!=p.m)
            return this->m<p.m;
        else
            return this->s<p.s;
    }
};
int main(){
    int N;
    scanf("%d",&N);
    Person p,minTime(INT_MAX,INT_MAX,INT_MAX),maxTime;
    for(int i=0;i<N;++i){
        scanf("%s %d:%d:%d",p.id,&p.h,&p.m,&p.s);
        minTime=min(minTime,p);
        scanf("%d:%d:%d",&p.h,&p.m,&p.s);
        maxTime=max(maxTime,p);
    }
    printf("%s %s",minTime.id,maxTime.id);
    return 0;
}
