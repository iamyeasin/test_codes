#include<bits/stdc++.h>
#define MAX 1000000001
#define pf printf
#define sf scanf

using namespace std;

long long ans[1234];
string num = "";
long long sq, k =0,c=0, sum = 1232345;
bool flag=0;
long long N;

bool isPrime(long long n){
    if(n <= 3) return true;
    if( !(n & 1) )return false;

    for(long long i=3; i*i <= n; i+=2){
        if(!(n%i))return false;
    }
    return true;
}

void fn(long long n ){
    if(n < 10 || isPrime(n)){
        ans[k++] = n;
        if(n > 10) return;
        sort(ans, ans+k);
        long long s=0,m=0;

        for (long i=k-1; i>=0; i--){
            s += (ans[m++] * pow ( 10 , i));
        }
        if(s < sum) sum = s;

        flag = 1;
        return;
    }

    if(flag)return;

    for(int i=9; i>=2; i--){
        if(flag) return;
        if(!(n%i)){
            ans[k++] = i;
            fn(n/i);
            return;
        }
    }
}


int main(){

    while(scanf("%lld",&N) != EOF){
        if(!N) { pf("10\n"); continue; }
        if(N < 10){
            pf("%lld\n",N);
            continue;
        }
        if(isPrime(N)){
            pf("-1\n");
            continue;
        }


        for(long long i=2; i*i<=N; i++){
            if(!(N%i)){
                ans[k++] = i;
                fn(N/i);
            }
            k=0,flag =0,c =0;
        }
        if(sum != 1232345) pf("%lld\n",sum);
        else pf("-1\n");
        sum = 1232345;

    }
    return 0;
}
