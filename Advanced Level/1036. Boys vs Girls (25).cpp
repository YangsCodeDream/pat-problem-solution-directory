#include<bits/stdc++.h>
using namespace std;
struct Person{
    char name[11];
    char id[11];
    int score;
    Person(int s=0):score(s){}
};
int main(){
    int N;
    scanf("%d",&N);
    Person female(-1),male(101),temp;
    char gender;
    for(int i=0;i<N;++i){
        scanf("\n%s %c %s %d",&temp.name,&gender,&temp.id,&temp.score);
        if(gender=='F'&&temp.score>female.score)
                female=temp;
        else if(gender=='M'&&temp.score<male.score)
                male=temp;
    }
    if(female.score==-1)
        printf("Absent\n");
    else
        printf("%s %s\n",female.name,female.id);
    if(male.score==101)
        printf("Absent\n");
    else
        printf("%s %s\n",male.name,male.id);
    if(female.score!=-1&&male.score!=101)
        printf("%d",female.score-male.score);
    else
        printf("NA");
    return 0;
}
