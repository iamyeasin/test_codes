#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define mx 100
#define N 8

using namespace std;

bool issafe(int x, int y, int sol[N][N]){
    return (x >= 0 && x < N && y >=0 && y<8 && sol[x][y] == -1);
}

void clr(int sol[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            sol[i][j] = -1;
        }
    }
}

void printSolution(int sol[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            pf(" %2d ",sol[i][j]);
        }
        pf("\n");
    }
}

int solve(int idx, int x, int y, int x_move[N], int y_move[N], int sol[N][N]){
    if(idx == N*N){
        return true;
    }

    for(int i=0; i<8; i++){
        int next_x = x + x_move[i];
        int next_y = y + y_move[i];

        if(issafe(next_x, next_y,sol)){
            sol[next_x][next_y] = idx;

            if(solve(idx+1, next_x, next_y, x_move, y_move, sol)) return true;
            else sol[next_x][next_y] = -1;
        }

    }
    return false;
}


int main(){

//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sol[N][N];
    clr(sol);

//    int x_move[] = {+1, -1, +2, +2, -2, -2, +1, -1};
//    int y_move[] = {+2, +2, +1, -1, +1, -1, -2, -2};

    int x_move[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int y_move[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    sol[0][0] = 0;
    int ans = solve(1, 0, 0, x_move, y_move, sol);
   // cout << ans << endl;

    if(ans){
        printSolution(sol);
    }
    else pf("No solution found!");


    return 0;
}
