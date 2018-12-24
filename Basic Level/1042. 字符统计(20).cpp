#include<bits/stdc++.h>
using namespace std;
int main(){
    char input[1005]={0};
    int hashTable[128]={0};
    gets(input);
    for(int i=0;input[i]!='\0';++i)
        if(isalpha(input[i])){
            char c=tolower(input[i]);//按小写字母储存
            ++hashTable[c];
        }
    int maxIndex=0;
    for(int i=1;i<128;++i)
        if(hashTable[i]>hashTable[maxIndex])
            maxIndex=i;
    printf("%c %d",maxIndex,hashTable[maxIndex]);
    return 0;
}
