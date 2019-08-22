#include<bits/stdc++.h>
#define     pf     printf
#define     sf     scanf
#define     dbg(x) cout << #x << " " << x << endl;

using namespace std;

const int dr[] = { 0,  1,  0, -1,   -1,  1,  1, -1,   -2, -2,  2,  2, -1, -1,  1,  1};
const int dc[] = { 1,  0, -1,  0,    1,  1, -1, -1,   -1,  1, -1,  1, -2,  2, -2,  2};

int main(){
    int **s,num[12];

    puts("How many class : ");
    int n; cin >> n;

    s = (int ** ) malloc( sizeof(int*) * n );

    for( int i=0; i<n; i++ ){
        puts("How many students: ");int m; cin>>m;
        num[i] = m;
        s[i] = (int*) malloc( sizeof(int) * m );

        cout << "Enter " << m << " students numbers" << endl;

        for( int j=0; j<m; j++ ){
            cin >> s[i][j];
        }
    }


    for( int i=0; i<n; i++ ){
        for( int j=0; j<num[i]; j++ ){
            cout << s[i][j] << " ";
        }
        cout << endl;
    }


  return 0;
}
