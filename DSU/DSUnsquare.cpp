#include<bits/stdc++.h>
#define sf scanf
#define pf printf
//#define dbg(x) cout << #(x) << " " << x << endl

using namespace std;


int arr[1024];

void init(){
    for( int i=0; i<=10; i++ ) arr[i] = i;
}

bool find( int a, int b ){
    return arr[a] == arr[b] ? 1 : 0;
}

void disjoint_union( int a, int b ){
    int tmp = arr[a];
    for( int i=0; i<=10; i++ ) {
        if( arr[i] == tmp )
            arr[i] = arr[b];
    }
}

void print(){
    for( int i=0; i<10; i++ ) cout << arr[i] << " ";
    cout << endl;
}


int main(){
    init();
    disjoint_union(4,5);
    disjoint_union(9,7);
    disjoint_union(3,1);
    disjoint_union(3,2);
    disjoint_union(9,6);
    disjoint_union(5,7);
    print();

    cout << find(6,5) << endl;
    cout << find(1,5) << endl;





    return 0;
}
