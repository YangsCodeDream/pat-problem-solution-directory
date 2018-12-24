#include<bits/stdc++.h>
using namespace std;
int main(){
    int M,N,S;
    scanf("%d%d%d",&M,&N,&S);
    vector<string>v(M+1);//储存输入的字符串
    for(int i=1;i<=M;++i)
        cin>>v[i];
    unordered_set<string>s;//储存中奖的字符串
    for(int i=S;i<=M;i+=N){
        while(i<=M&&s.find(v[i])!=s.cend())//该字符串中过奖
            ++i;//跳过顺次取下一位
        if(i<=M){
            cout<<v[i]<<endl;//输出该中奖字符串
            s.insert(v[i]);//将该中奖字符串加入s中
        }
    }
    if(s.empty())//如果没有字符串中过奖，按要求输出
        cout<<"Keep going..."<<endl;
    return 0;
}
