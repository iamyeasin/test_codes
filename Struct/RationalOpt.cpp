#include<bits/stdc++.h>
#define     pf     printf
#define     sf     scanf
#define     dbg(x) cout << #x << " " << x << endl;

using namespace std;

const int dr[] = { 0,  1,  0, -1,   -1,  1,  1, -1,   -2, -2,  2,  2, -1, -1,  1,  1};
const int dc[] = { 1,  0, -1,  0,    1,  1, -1, -1,   -1,  1, -1,  1, -2,  2, -2,  2};


typedef struct {
      int p;
      int q;
} rational;

long long lcm( int a, int b){
  return a * (b/__gcd(a,b));
}


void add( rational *x , rational *y, rational *ans ){
    int lc = lcm( x->q , y->q );
    ans->q = lc;
    ans->p = ( (lc / x->q) * ( x->p) ) + ( ( (lc / y->q) * ( y->p) ) );
}

void sub( rational *x , rational *y, rational *ans ){
    int lc = lcm( x->q , y->q );
    ans->q = lc;
    ans->p = ( (lc / x->q) * ( x->p) ) - ( ( (lc / y->q) * ( y->p) ) );
}

void mul( rational *x , rational *y, rational *ans ){
    int lc = lcm( x->q , y->q );
    ans->q = lc;
    ans->p = ( (lc / x->q) * ( x->p) ) * ( ( (lc / y->q) * ( y->p) ) );
}

void div( rational *x , rational *y, rational *ans ){
    int lc = lcm( x->q , y->q );
    ans->q = lc;
    ans->p = ( (lc / x->q) * ( x->p) ) / ( ( (lc / y->q) * ( y->p) ) );
}



int main(){


    rational a,b,adds;
    a.p = 1, a.q = 2;
    b.p = 1, b.q = 2;

    add( &a , &b, &adds);
    cout << adds.p << " " << adds.q << endl;

    sub( &a , &b, &adds);
    cout << adds.p << " " << adds.q << endl;

    mul( &a , &b, &adds);
    cout << adds.p << " " << adds.q << endl;

    div( &a , &b, &adds);
    cout << adds.p << " " << adds.q << endl;







  return 0;
}
