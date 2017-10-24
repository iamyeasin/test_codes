#include<bits/stdc++.h>
#define pf printf
#define sf scanf

using namespace std;

char arr[1234],ans[1234];
bool taken[1234],flag=0,printed=0;
int k=0; unsigned long long int n;

unsigned long long int f[25];

void fact(){
    f[0] = 1;
    f[1] = 1;
    for(int i=2; i<=22; i++){
        f[i] = i * f[i-1];
    }
}

void backTrack(int idx, int  st,int len){
    if(idx == len){
        ans[idx] = '\0';
        puts(ans);

        if(flag) st = 0;
        else flag = 1;
        return;
    }
    cout << "st " << st  << " " << idx << " "<< " len = "  << len << endl;
    //if(printed)return;

    if(flag) st = 0;
    else flag = 1;

    for(int i=st; i<n; i++){
        if(!taken[i]){
            taken[i] = 1;
            ans[idx] = arr[i];
            backTrack(idx+1, st, len);
        }
        taken[i] = 0;
    }
}


int main(){

    freopen("in.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);

    fact();
    int tc;
    sf("%d",&tc);

    while(tc--){
        memset(taken, 0 ,sizeof(taken));
        cin >> arr;
//        cout << arr << endl;
        cin >> n;
        printed = 0;
        flag=0;

        int look = 0;
        for(int i=0; i<22; i++){
            if(f[i] < n && f[i+1] >= n){
                look = i+1;
            }
        }

        int d = f[look]/look;
        int p = n/d;
        k = p*d;

        int len = strlen(arr);
//        cout << len << endl;
        int st = p;
        backTrack(0, st, len);

    }


    return 0;
}
