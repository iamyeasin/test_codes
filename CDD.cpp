#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int n,arr[1234],taken[1234], ans[1234], ans2[1234],fsum,till=0;
bool flag;
vector < pair<int,int> > v;

void backTrack(int idx, int j, int t, int sum){
    if(sum == n){
       // for(int i=0; i<idx; i++)pf("%d ",ans[i]);
       // pf("sum:%d\n",sum);
        fsum = sum, till = idx;
        for(int i=0; i<idx; i++){
            ans2[i] = ans[i];
           // pf("%d ",ans[i]);
        }
        flag = 1;
        return;
    }
    if(sum>n)
        return;

    if(sum > fsum && sum<n){
        fsum = sum, till = idx;
        for(int i=0; i<idx; i++){
            ans2[i] = ans[i];
           // pf("%d ",ans[i]);
        }
        //printf("\t%d\n",till);
    }

    for(int i=j; i<t; i++){
         if(flag) return;

        if(!taken[i]){
            int s = sum + v[i].first;
            if(s <= n){
               taken[i] = 1;
               ans[idx] = v[i].second;
               backTrack(idx+1, i+1, t, s);
               taken[i] = false;
            }

        }
    }



}


int main(){

//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);

    int t;
    while( sf("%d %d",&n, &t) == 2){
        int tsum = 0 ;
        for(int i=0; i<=t; i++){
            arr[i] = ans[i] = ans2[i] = taken[i] = 0;
            flag=fsum=0;
        }

        for(int i=0; i<t; i++){
            sf("%d",arr+i);
            v.push_back(make_pair(arr[i],i));
            tsum += arr[i];
        }
        sort(v.begin(),v.end());
        if(tsum < n) {
            for(int i=0; i<t; i++)pf("%d ",arr[i]);
            pf("sum:%d\n",tsum);
            v.clear();
            continue;
        }

        backTrack(0,0,t,0);

       sort(ans2,ans2+till);
        for(int i=0; i<till; i++){
            pf("%d ",arr[ans2[i]]);
        }
        pf("sum:%d\n",fsum);
        v.clear();

    }


    return 0;
}

