#include<bits/stdc++.h>
#define pf printf
#define sf scanf

using namespace std;

void perm(int n, int idx, char *pos, int *taken, char *arr){

    if(idx == n){
        pos[n] = '\0';
        puts(pos);
        return;
    }

    for(int i=0; i<n; i++){
        if(taken[i] == false){
            taken[i] = true;
            pos[ idx ] = arr[i];
            perm(n , idx+1, pos, taken, arr);
            taken[i] = false;
        }
    }

}


int main(){

    int n;
    char ch,arr[655]; //cin >> ch;
    char pos[324]; int taken[324];
    memset(taken,0, sizeof(taken));
    gets(arr);
  //  puts(arr);

    n = strlen(arr);

//    cout << n << endl;
    perm(n, 0, pos, taken,arr);

    return 0;

}
