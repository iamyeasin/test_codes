#include<bits/stdc++.h>
#define pf printf
#define sf scanf

using namespace std;

char arr[1234],arr2[1234],ans[1234];
bool taken[1234],flag=0,printed=0;
int k=0;
unsigned long long int n;
string anss = "";

unsigned long long int f[25];

void fact(){
    f[0] = 1;
    f[1] = 1;
    for(int i=2; i<=22; i++){
        f[i] = i * f[i-1];
    }
}

void backTrack(int idx, int len){
    if(idx == len){
        k++;
        if(k == n+1){
            ans[idx] = '\0';
            puts(ans);
            flag=1;
        }
        return;
    }

    if(flag)return;

    for(int i=0; i<len; i++){
        if(!taken[i] && !flag){
            taken[i] = 1;
            ans[idx] = anss[i];
            backTrack(idx+1, len);
            taken[i] = false;
        }
    }

}


int main(){

//    freopen("in.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);

    fact();
    int tc;
    sf("%d\n",&tc);

    while(tc--){
        memset(taken, 0 ,sizeof(taken));
        sf("%s",arr);
        sf("%llu",&n);

        flag = 0;
        printed = 0;

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
        sort(arr,arr+len);

        anss  += arr[p];
        for(int i=0; i<len; i++){
            if(arr[i] != arr[p])anss += arr[i];
        }
        backTrack(0, len);
        anss = "";
    }


    return 0;
}
