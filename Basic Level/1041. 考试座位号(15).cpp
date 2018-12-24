#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    long long id[1005],testid[1005];
    for(int i=0;i<N;++i){
        long long a;
        int b,c;
        scanf("%lld%d%d",&a,&b,&c);
        id[b]=a;
        testid[b]=c;
    }
    scanf("%d",&N);
    while(N--){
        int a;
        scanf("%d",&a);
        printf("%014lld %d\n",id[a],testid[a]);
    }
    return 0;
}
