#include<bits/stdc++.h>
using namespace std;
char intTochar[5]="ACME";//将数组下标映射到相应字符
struct StudentScore{//存储学生id和分数的结构体
    int id;
    double score;
    StudentScore(int i,double s):id(i),score(s){}
};
bool cmp(const StudentScore&s1,const StudentScore&s2){//比较函数，按分数由大到小排序，分数相同按id从小到大排序
    if(s1.score!=s2.score)
        return s1.score>s2.score;
    else
        return s1.id<s2.id;
}
unordered_map<int,array<int,4>>studentRank;//存储学生id和4门成绩的排名，4门成绩排名存储在一个数组中，下标0123分别代表ACME四个成绩排名
int N,MM;//学生总数和要查询的学生数量
void setRank(const vector<StudentScore>&temp,int index){//找出学生在某一成绩上的排名，index值为0123，分别代表ACME四个成绩排名
    studentRank[temp[0].id][index]=1;
    for(int i=1;i<temp.size();++i){
        if(temp[i].score!=temp[i-1].score)
            studentRank[temp[i].id][index]=i+1;
        else
            studentRank[temp[i].id][index]=studentRank[temp[i-1].id][index];
    }
}
int main(){
    scanf("%d%d",&N,&MM);
    vector<StudentScore>ACME[4];//下标为0123的vector分别存储ACME四个成绩
    for(int i=0;i<N;++i){
        int id;
        double A[4];//下标为0123的元素分别临时存储ACME四个成绩
        scanf("%d%lf%lf%lf",&id,&A[1],&A[2],&A[3]);
        A[0]=(A[1]+A[2]+A[3])/3;
        for(int i=0;i<4;++i)
            ACME[i].push_back(StudentScore(id,A[i]));
    }
    for(int i=0;i<4;++i)//进行排序
        sort(ACME[i].begin(),ACME[i].end(),cmp);
    for(int i=0;i<4;++i)
        setRank(ACME[i],i);
    while(MM--){
        int id;
        scanf("%d",&id);
        if(studentRank.find(id)==studentRank.cend()){//如果没有这样的学生，输出N/A
            printf("N/A\n");
        }else{//如果有这样的学生
            auto i=min_element(studentRank[id].begin(),studentRank[id].end());//标准库函数，按ACME优先级顺序找到排名最靠前的迭代器
            printf("%d %c\n",*i,intTochar[i-studentRank[id].begin()]);//输出结果
        }
    }
    return 0;
}
