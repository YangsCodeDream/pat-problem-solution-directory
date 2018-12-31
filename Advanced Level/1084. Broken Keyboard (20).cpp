#include<bits/stdc++.h>
using namespace std;
int main(){
    char s1[85],s2[85];
    scanf("%s%s",s1,s2);
    unordered_set<char>s;
    for(int i=0;s2[i]!='\0';++i)
        s.insert(toupper(s2[i]));
    for(int i=0;s1[i]!='\0';++i)
        if(s.find(toupper(s1[i]))==s.cend()){
            printf("%c",toupper(s1[i]));
            s.insert(toupper(s1[i]));
        }
    return 0;
}
