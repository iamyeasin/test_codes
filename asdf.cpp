#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int arr[1234],taken[1234], ans[1234], ans2[1234],fsum=0,till=0;
bool flag=0;

void backTrack(int idx, int n, int t, int sum){
    if(sum == n){
        for(int i=0; i<idx; i++)pf("%d ",ans[i]);
        pf("sum:%d\n",sum);
        flag = 1;
        return;
    }

    if(sum > fsum){
        fsum = sum, till = idx;
        for(int i=0; i<idx; i++){
            ans2[i] = ans[i];
        }
    }

    for(int i=0; i<t; i++){
         if(flag) continue;

        if(!taken[i]){
            till = idx;
            int s = sum + arr[i];
            if(s <= n){
               taken[i] = 1;
               ans[idx] = arr[i];
               backTrack(idx+1, n, t, s);
            }
            taken[i] = false;
        }
    }



}


int main(){

////    freopen("input.txt", "rt", stdin);
////    freopen("output.txt", "wt", stdout);

    int n,t;
    while( sf("%d %d",&n, &t) == 2){
        int tsum = 0 ;
        for(int i=0; i<=t; i++){
            arr[i] = ans[i] = ans2[i] = taken[i] = 0;
            flag=fsum=0;
        }

        for(int i=0; i<t; i++){
            sf("%d",arr+i);
            tsum += arr[i];
        }

        if(tsum < n) {
            for(int i=0; i<t; i++)pf("%d ",arr[i]);
            pf("sum:%d\n",tsum);
            continue;
        }

        backTrack(0,n,t,0);

        if(!flag){
            for(int i=0; i<till; i++){
                pf("%d ",ans2[i]);
            }
            pf("sum:%d\n",fsum);
        }


    }


    return 0;
}

