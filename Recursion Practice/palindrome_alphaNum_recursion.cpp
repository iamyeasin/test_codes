#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

void isPalin(char *st, int i, int len){
    if(i < len/2){
        if(st[i] != st[len - i - 1]){
            pf("Not palindrom\n"); return ;
        }
        isPalin(st, i+1, len);
    }
    else printf("Palingdrome!");

}

int main(){

    char st[23442], str[34324];
    gets(str);

    int ln = strlen(str);
    int k=0;
    for(int i=0 ; i<ln; i++){
        if(!(isspace(str[i]) || !isalnum(str[i]))){
            st[k++] = str[i];
        }
    }
    st[k] = '\0';

    isPalin(st, 0, k);

    return 0;
}
