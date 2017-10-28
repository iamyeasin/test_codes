#include<bits/stdc++.h>
#define MAX 1000000001
#define pf printf
#define sf scanf

using namespace std;

int ans[1234];
string num = "";
long sq, k =0,c=0, sum = 1232345;
bool flag=0;
long test=1;
long N;

bool isPrime(long n){
    if(n <= 3) return true;
    if( !(n & 1) )return false;

    for(int i=3; i*i <= n; i+=2){
        if(!(n%i))return false;
    }
    return true;
}

void fn(long n ){
    if(n < 10 || isPrime(n)){
        ans[k++] = n;
        long s = 0;
        test *= n;

        if(test != N) {
            cout << test << endl;
        }

        sort(ans, ans+k);
        for(int i=k-1; i>=0; i++){
            s += (ans[i]* pow(10,i));
        }
        if(s < sum ){
            sum = s;
        }
        puts("");

        flag = 1;
        return;
    }
    cout << test << endl;

    if(flag)return;

    for(int i=9; i>=2; i--){
        if(flag) return;
        if(!(n%i)){
            ans[k++] = i;
            test *= i;
            fn(n/i);
            return;
        }
    }
}


int main(){

    while(scanf("%d",&N) != EOF){
        if(!N) { pf("10\n"); continue; }
        if(N < 10){
            pf("%d\n",N);
            continue;
        }

        for(int i=2; i*i<N; i++){
            num = "";
            if(!(N%i)){
                ans[k++] = i;
                test *= i;
                fn(N/i);
            }
            k=0,flag =0,c =0;
//        cout << sum << endl;
        }

    }
    return 0;
}
