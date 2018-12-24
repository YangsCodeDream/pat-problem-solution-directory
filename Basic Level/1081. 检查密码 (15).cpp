#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    getchar();
    while(N--){
        bool digit=false,letter=false,legal=true;
        string str;
        getline(cin,str);
        if(str.size()<6){
            cout<<"Your password is tai duan le."<<endl;
            continue;
        }
        for(int i=0;i<str.size()&&legal;++i)
            if(!isalnum(str[i])&&str[i]!='.')
                legal=false;
            else if(isalpha(str[i]))
                letter=true;
            else if(isdigit(str[i]))
                digit=true;
        if(!legal)
            cout<<"Your password is tai luan le."<<endl;
        else if(letter&&digit)
            cout<<"Your password is wan mei."<<endl;
        else if(!digit)
            cout<<"Your password needs shu zi."<<endl;
        else if(!letter)
            cout<<"Your password needs zi mu."<<endl;
    }
    return 0;
}
