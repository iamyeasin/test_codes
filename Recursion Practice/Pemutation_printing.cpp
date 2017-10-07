#include<bits/stdc++.h>
#define pf printf
#define sf scanf

using namespace std;

void pGen(int n, int idx , int *pos, int *taken, int *arr){
    if(idx == n+1){
        for(int i=1; i<=n; i++){
            pf(" %d ",pos[i]);
        }
        puts("");
        return;
    }

    for(int i=1; i<=n; i++){
        if(taken[arr[i]] == false){
            taken[arr[i]] = true;

            pos[idx] = arr[i];
            pGen( n, idx+1 , pos , taken , arr );
            taken[ arr[i] ] = false;
         }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[234],position[234],taken[345];

    memset(taken,0,sizeof(taken));
    for(int i=1; i<=n; i++){
        cin >> arr[i] ;
    }

    pGen(n,1,position,taken,arr);


    return 0;
}
