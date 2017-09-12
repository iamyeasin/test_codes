#include<bits/stdc++.h>

using namespace std;

struct info{
    char name[22];
    int money=0;
} ;

int n;
info arr[3005];

void addMoney(char *names, int money){
    for(int i=1; i<=n; i++){
        if(!strcmp(names,arr[i].name)){
            arr[i].money += (money);
        }
    }
}


int main(){

//    freopen("in.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);

    int m = 0;
    while(scanf("%d",&n) != EOF){
            if(m > 0)puts("");
            for(int i=1; i<= n; i++){
                scanf("%s",&arr[i].name);
            }
            m++;

        int frns=0, amnt=0;

        for(int i=1; i <= n; i++){
            char words[20];
            scanf("%s %d %d",words,&amnt,&frns);
                int each;
                if(frns > 0) each = (amnt/frns);
                addMoney(words,(-1*amnt));
                if((amnt - (each*frns) ) > 0) addMoney(words,(amnt - (each*frns)));

                for(int i=1; i<=frns; i++){
                        char ns[22];
                       scanf("%s",ns);
                       addMoney(ns,each);
                }
        }

        for(int i=1; i <= n; i++){
            if(i == n) printf("%s %d\n",arr[i].name, arr[i].money);
            else printf("%s %d\n",arr[i].name, arr[i].money);
        }

        for(int i=1; i<=n; i++){
            arr[i].money = 0;
        }


    }



    return 0;
}
