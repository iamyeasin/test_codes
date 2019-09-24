/*
    Disjoint union set
    Based on finding the root of a node
    arr[root( a) ] =  root(b)

*/

#include<bits/stdc++.h>
#define sf scanf
#define pf printf
//#define dbg(x) cout << #(x) << " " << x << endl

using namespace std;


int arr[1024];

inline void init(){
    for( int i=0; i<=10; i++ ) arr[i] = i;
}

inline int root( int a ){
    if( arr[a] == a ) return a;
    return root(arr[a]);
}

inline void disjoint_union( int a, int b ){
    int roota = root(a);
    int rootb = root(b);
    arr[roota] = rootb;
}

inline bool find( int a, int b ){
    return root(a) == root(b);
}

inline void print(){
    for( int i=0; i<10; i++ ) cout << arr[i] << " ";
    cout << endl;
}


int main(){
    init();
    disjoint_union(2,5);
    disjoint_union(3,6);
    disjoint_union(2,1);
    disjoint_union(3,7);
    disjoint_union(4,7);
    print();

    cout << find(2,3) << endl;
    cout << find(1,2) << endl;





    return 0;
}
