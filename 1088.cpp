#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

long n;
long long ans[12345678];
int gcd(int a, int b){
	if(!b) return a;
	else return gcd(b, a % b);
}

void make_answer(){
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;

    for(int i=3; i<= 100001; i++){
        ans[i] = ((ans[i-1] * i) )/ gcd(ans[i-1] , i);
    }
}


int main(){
    make_answer();
    while( sf("%d",&n) ){
    }

    return 0;
}
