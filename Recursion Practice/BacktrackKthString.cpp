#include<bits/stdc++.h>
#define     pf     printf
#define     sf     scanf

using namespace std;

vector<bool>A(5,0);

/// Complexity O(2T(n-1) + d ), where n >= 0, otherwise O ( C )
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


/// Complexity O( KT(n-1) + d ), where n >= 0, otherwise O ( C )

void kth( int k, int n ){
    if( n<1 ){
        for( int i=0; i<n; i++ ){
            cout << A[i] << " ";
        }
        cout << endl;
    }
    else{
        for( int j=0; j<k; j++ ){
            A[n-1] = j;
            kth(k,n-1);
        }
    }
}

int main(){
     kth(3,5);
  return 0;
}
