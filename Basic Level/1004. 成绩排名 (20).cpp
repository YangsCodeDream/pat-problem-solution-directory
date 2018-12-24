#include<bits/stdc++.h>
using namespace std;
struct Student{
    char name[12];
    char number[12];
    int score;
    Student(int s=0):score(s){}
};
int main(){
    int N;
    scanf("%d",&N);
    Student Max(-1),Min(101),temp;
    for(int i=0;i<N;++i){
        scanf("\n%s%s%d",temp.name,temp.number,&temp.score);
        if(Max.score<temp.score)
            Max=temp;
        if(Min.score>temp.score)
            Min=temp;
    }
    printf("%s %s\n",Max.name,Max.number);
    printf("%s %s",Min.name,Min.number);
    return 0;
}
