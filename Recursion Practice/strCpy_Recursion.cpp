#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

void stCpy(char *st1, char *st2, int i,int ln){
    if(i < ln){
        st2[i] = st1[i];
        stCpy(st1, st2, i+1,ln);
    } else {
        st2[i] = '\0';
        return;
    }
}

int main(){

    char st[23442], str[34324];
    gets(st);
    int ln  = strlen(st);
    stCpy(st, str, 0, ln);
    puts(str);



    return 0;
}
