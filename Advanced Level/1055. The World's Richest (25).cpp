#include<bits/stdc++.h>
using namespace std;
struct Person{//存储相应信息的结构体
    string name;
    int age,worth;
};
Person person[(int)(1e5+5)];
int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;++i)
        cin>>person[i].name>>person[i].age>>person[i].worth;
    sort(person,person+N,[](const Person&p1,const Person&p2){//比较函数
        if(p1.worth!=p2.worth)
            return p1.worth>p2.worth;
        else if(p1.age!=p2.age)
            return p1.age<p2.age;
        else
            return p1.name<p2.name;
    });//排序
    for(int i=1;i<=K;++i){
        int M,Amin,Amax;
        bool f=false;
        scanf("%d%d%d",&M,&Amin,&Amax);
        printf("Case #%d:\n",i);
        for(int j=0;j<N&&M>0;++j)//遍历数组
            if(person[j].age>=Amin&&person[j].age<=Amax){//找到符合要求的人
                printf("%s %d %d\n",person[j].name.c_str(),person[j].age,person[j].worth);//输出
                --M;//将M递减
                f=true;//表示已输出过
            }
        if(!f)//在该年龄段没有任何输出
            printf("None\n");//输出None
    }
    return 0;
}
