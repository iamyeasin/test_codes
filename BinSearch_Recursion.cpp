#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int binSearch(int *arr, int n, int lo, int hi){
    if(n > arr[hi-1] || n < arr[lo]) return -1;

    if(lo < hi){
        int mid = ( (lo + hi)/2 );
        if(arr[mid] == n) return mid;
        else if(arr[mid] < n) binSearch(arr, n, mid , hi);
        else binSearch(arr, n , lo , mid);
    }else return -1;
}


int main(){
    int n;
    sf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++) sf("%d",&arr[i]);

    int q,x;
    sf("%d",&q);
    for(int i=0; i<q; i++){
        sf("%d",&x);
        int m = binSearch(arr, x, 0, n);
        if(m < 0)pf("Not Found!\n");
        else pf("%d \n",m);
    }


    return 0;
}
