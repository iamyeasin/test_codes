/*
Given a matrix, each of which may be 1 or 0. The filled cells that are connected form aregion.
Two cells are said to be connected if they are adjacent to each other horizontally,vertically or diagonally.
There may be several regions in the matrix. How do you find thelargest region (in terms of number of cells) in the matrix?

*/


#include<bits/stdc++.h>
#define     pf     printf
#define     sf     scanf
#define     dbg(x) cout << #x << " " << x << endl;

using namespace std;

const int dr[] = { 0,  1,  0, -1,   -1,  1,  1, -1,   -2, -2,  2,  2, -1, -1,  1,  1};
const int dc[] = { 1,  0, -1,  0,    1,  1, -1, -1,   -1,  1, -1,  1, -2,  2, -2,  2};

int A[50][50]={
        { 1,1,0,0,0 },
        { 0,1,1,0,1 },
        { 0,1,1,1,1 },
        { 1,0,0,1,1 },
        { 0,1,1,1,1 },
    },
    mxsize=0,sz=0,track[50][50];

bool valid(int nx, int ny){
     return nx>=0 && nx<5 && ny>=0 && ny<5;
}

void getmax(int r, int c){
   // dbg(mxsize)
    track[r][c] = true; sz++;
    mxsize = max(sz,mxsize);
    for( int i=0; i<8; i++ ){
        int newi = r + dr[i];
        int newj = c + dc[i];
        if( valid(newi,newj) && track[newi][newj] == false && A[newi][newj] ){
            getmax(newi,newj);
        }
    }
    // track[r][c] = 0;
}

void solve(){
    for( int i=0; i<=4; i++)
    for( int j=0; j<=4; j++ ){
        if( A[i][j] ){
            track[i][j] = true;
            getmax(i,j);
            sz = 0;
        }
    }
}

int main(){

    memset(track,0,sizeof track);
    solve();
    cout << mxsize << endl;

  return 0;
}
