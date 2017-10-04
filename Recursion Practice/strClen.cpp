#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int stClen(char *st1, int i){
    if(!st1[i]) return i;
    stClen(st1, i+1);
}

int main(){

    char st[23442], str[34324];
    gets(st);
    cout << stClen(st, 0) << endl;

    return 0;
}
