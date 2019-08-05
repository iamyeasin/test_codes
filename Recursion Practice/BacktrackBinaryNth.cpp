#include<bits/stdc++.h>
#define     pf     printf
#define     sf     scanf

using namespace std;

vector<bool>A(3,1);

void binarys( int n ){
    if( n < 1 ){
        for(bool i: A){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    else{
        A[n-1] = 0;
        binarys(n-1);
        A[n-1]=1;
        binarys(n-1);
    }
}

int main(){
     binarys(3);
  return 0;
}
