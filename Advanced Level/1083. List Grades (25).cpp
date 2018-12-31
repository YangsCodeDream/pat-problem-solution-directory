#include<bits/stdc++.h>
using namespace std;
struct Student{
    char name[11],id[11];
    int grade;
};
bool cmp(const Student&s1,const Student&s2){
    return s1.grade>s2.grade;
}
int main(){
    int N,g1,g2;
    scanf("%d",&N);
    Student stu[N];
    for(int i=0;i<N;++i)
        scanf("\n%s %s %d",stu[i].name,stu[i].id,&stu[i].grade);
    sort(stu,stu+N,cmp);
    scanf("%d%d",&g1,&g2);
    bool output=false;
    for(int i=0;i<N;++i)
        if(stu[i].grade>=g1&&stu[i].grade<=g2){
            printf("%s %s\n",stu[i].name,stu[i].id);
            output=true;
        }
    if(!output)
        printf("NONE");
    return 0;
}
