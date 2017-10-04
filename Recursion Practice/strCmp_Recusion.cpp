#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int stCmp(char *st1, char *st2, int i){

    int ln1 = strlen (st1); int ln2 = strlen (st2);
    if( ln1 > ln2 ) return 1;
    if ( ln1 < ln2 ) return -343;
    if( ln1 == ln2 && i < ln1) {
        if(st1[i] != st2[i]) return -1;
        stCmp(st1, st2, i+1);
    }
    else  return 0;
}

int main(){

    char st[23442], str[34324];
    gets(st);
    int ln  = strlen(st);
    gets(str);
    cout << stCmp(st, str, 0) << endl;

    return 0;
}
