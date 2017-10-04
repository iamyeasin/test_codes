#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

void stCat(char *st1, char *st2, int i, int k, int ln1, int ln2){

    if(i < ln1){
        stCat(st1, st2 , i+1, 0, ln1,ln2);
    } else if(i >= ln1 && k<ln2) {
        st1[i] = st2[k];
        stCat(st1, st2, i+1 , k+1, ln1, ln2);
    } else {
        st1[ln1+ln2] = '\0';
        return ;
    }


}

int main(){

    char st[23442], str[34324];
    gets(st);
    int ln  = strlen(st);
    gets(str);
    int ln2  = strlen(str);
    stCat(st, str, 0, 0, ln, ln2);
    puts(st);



    return 0;
}
