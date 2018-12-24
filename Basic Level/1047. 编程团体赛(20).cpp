#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int teamScore[1005]={0};
    while(n--){
        int a,b,c;
        scanf("%d-%d %d",&a,&b,&c);
        teamScore[a]+=c;
    }
    int maxIndex=0;
    for(int i=1;i<1005;++i)
        if(teamScore[i]>teamScore[maxIndex])
            maxIndex=i;
    printf("%d %d",maxIndex,teamScore[maxIndex]);
    return 0;
}
