#include<bits/stdc++.h>

using namespace std;

bool isSorted(int A[], int n){
    if( n == 1 ) return 1;
    return (A[n-1]<A[n-2])?0:isSorted(A,n-1);
}

int main(){
    int A[] = {1,23,42,52,61,222};
    cout << isSorted(A,6) << endl;

  return 0;
}
