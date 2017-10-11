#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#define pf printf
#define sf scanf
#define mx 100

using namespace std;
vector< string > vs;
vector< string > srs;

bool isPrime(int n, int x){
    int sum = n+x;
    int sz = sqrt(sum);

    if(sum<3) return true;
    if(!(sum&1)) return false;

    for(int i=3; i<= sz; i+=2){
        if(!(sum%i)){
            return false;
        }
    }
    return true;

}

void backTrack(string soFar, string rest, int lim){
    if(soFar.size() == lim){
        int x =  ( soFar[soFar.size()-1] ) - '0' ;
        int y =  ( soFar[0] ) - '0';
        int sz = soFar.size();

        if(soFar[0] != '1' || !isPrime(x, y)) return;
            for(int i=0; i<sz; i++){
                pf("%c ", soFar[i]);
            }
            puts("");

//        string demo = "";
//
//        for( int i=0; i<sz; i++){
//            if(i == 0){
//                demo += soFar[i];
//            }
//            else if(i < sz){
//                demo = (demo + " ") + soFar[i];
//            }
//            else if(i == sz-1){
//                demo += soFar[i];
//            }
//        }
//
//        cout << demo << endl;

        return;
    }

    for(int i=0; i<rest.size(); i++){
        string remaining = rest.substr(0,i) + rest.substr(i+1);
        int x =  ( soFar[soFar.size()-1] ) - '0' ;
        int y =  ( rest[i] ) - '0';
        if(isPrime(x,y))
         backTrack(soFar+ rest[i] , remaining, lim);
    }

}


int main(){

//    freopen("in.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);

    int n,T=0, arr[2342],ans[2343];

    while(sf("%d",&n) == 1){
        string soFar = "";
        string rest = "";
        for(int i=0; i<n; i++) rest += ((i+1) +'0');

        //cout << rest << endl;

        if(T >= 1) puts("");
        pf("Case %d:\n",++T);
        backTrack( soFar,rest ,n);
    }

    return 0;
}
