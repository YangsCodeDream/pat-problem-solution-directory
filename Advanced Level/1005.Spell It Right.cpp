#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<s.size();++i)
        sum+=s[i]-'0';
    s=to_string(sum);
    char temp[10][6]={
        "zero","one","two","three","four","five","six","seven","eight","nine"
    };
    for(int i=0;i<s.size();++i)
        printf("%s%s",i>0?" ":"",temp[s[i]-'0']);
    return 0;
}
