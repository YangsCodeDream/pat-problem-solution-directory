#include<bits/stdc++.h>
using namespace std;
int main(){
    char s1[85],s2[85];
    scanf("%s%s",s1,s2);
    bool hashTable[128]={false};
    for(int i=0;s2[i]!='\0';++i)
        hashTable[toupper(s2[i])]=true;
    for(int i=0;s1[i]!='\0';++i)
        if(!hashTable[toupper(s1[i])]){
            printf("%c",toupper(s1[i]));
            hashTable[toupper(s1[i])]=true;
        }
    return 0;
}
