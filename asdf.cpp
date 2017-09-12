#include<bits/stdc++.h>

using namespace std;

struct info{
    char name[22];
    int money=0;
} ;

int n;
info arr[2005];

void addMoney(char *name, int money){
    for(int i=1; i<=n; i++){
        if(!strcmp(name,arr[i].name)){
            arr[i].money += (money);
        }
    }
}


int main(){
    
    while(scanf("%d",&n) != EOF){
        for(int i=1; i<= n; i++){
            scanf("%s",arr[i].name);
        }
    
    int frns=0, amnt=0;
    
    for(int i=1; i <= n; i++){
        char words[20];
        scanf("%s %d %d",words,&amnt,&frns);
            int each = (amnt/frns);
            addMoney(words,(-1*amnt));
            if((amnt - (each*frns) ) > 0) addMoney(word,(amnt - (each*frns)));
            
            for(int i=1; i<=frns; i++){
                    char n[22];
                   scanf("%s",n);
                   addMoney(n,each);
            }
    }
    
    for(int i=1; i <= n; i++){
        printf("%s %d\n",arr[i].name, arr[i].money);
    }    
    
    
    
        
    }
    
    
    
    return 0;    
}
