#include <bits/stdc++.h>
using namespace std;
struct Student{
    int id,grade;
    char name[10];
};
bool cmp1(const Student&s1,const Student&s2){
    return s1.id<s2.id;
}
bool cmp2(const Student&s1,const Student&s2){
    return strcmp(s1.name,s2.name)!=0?strcmp(s1.name,s2.name)<0:s1.id<s2.id;
}
bool cmp3(const Student&s1,const Student&s2){
    return s1.grade!=s2.grade?s1.grade<s2.grade:s1.id<s2.id;
}
int main(){
    int N,C;
    scanf("%d%d",&N,&C);
    vector<Student>stu(N);
    for(int i=0;i<N;++i)
        scanf("%d %s %d",&stu[i].id,stu[i].name,&stu[i].grade);
    if(C==1)
        sort(stu.begin(),stu.end(),cmp1);
    else if(C==2)
        sort(stu.begin(),stu.end(),cmp2);
    else if(C==3)
        sort(stu.begin(),stu.end(),cmp3);
    for(int i=0;i<N;++i)
        printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
    return 0;
}
