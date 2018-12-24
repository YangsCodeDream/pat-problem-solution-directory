#include<bits/stdc++.h>
using namespace std;
int main(){
    char low[13][5]={//数字到火星文低位的映射
        "tret","jan","feb","mar", "apr", "may", "jun", "jly",
        "aug", "sep", "oct", "nov", "dec"
    };
    char high[13][5]={//数字到火星文高位的映射
        "tret","tam", "hel", "maa", "huh", "tou", "kes",
        "hei", "elo", "syy", "lok", "mer", "jou"
    };
    unordered_map<string,int>temp;//火星文到数字的映射
    for(int i=0;i<13;++i){
        temp[string(low[i])]=i;
        temp[string(high[i])]=i*13;
    }
    int n;
    scanf("%d",&n);
    char digit[10];
    getchar();//吸收n后面的换行符
    while(n--){
        gets(digit);
        if(isdigit(digit[0])){//如果是数字
            int k;
            sscanf(digit,"%d",&k);//转换成10进制
            bool f=false;//判断是否有高位输出
            if(k/13!=0){
                printf("%s",high[k/13]);
                f=true;
            }
            if(f){//有高位输出
                if(k%13!=0)//低位不为0，输出
                    printf(" %s",low[k%13]);
                printf("\n");
            }else//没有高位输出，直接输出低位，即使低位为0
                printf("%s\n",low[k%13]);
        }else{//是火星文
            string num="";
            int k=0;
            for(int i=0;digit[i]!='\0';++i)//按空格分割火星文
                if(digit[i]==' '){//如果到达空格则把已得到的火星文转换成数字
                    k+=temp[num];
                    num="";
                }else
                    num+=digit[i];
            //将最后一个空格到字符串结尾部分的火星文转换成数字
            k+=temp[num];
            printf("%d\n",k);
        }
    }
    return 0;
}
