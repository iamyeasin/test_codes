#include<bits/stdc++.h>

using namespace std;

void toh(int n, char from, char topeg, char aux){
    if( n == 1){
        cout << " Move disk1 from " << from << " peg to " << topeg << endl;
        return;
    }
    toh(n-1, from,aux,topeg );
    cout << " Move disk" << n << " from " << from << " peg to " << topeg << endl;
    toh(n-1, aux,topeg,from );
}


int main(){
    toh(3,'1','3','2');

  return 0;
}
