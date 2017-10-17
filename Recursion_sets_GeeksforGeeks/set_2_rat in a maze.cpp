#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int N;
int arr[256][256];
int xMove[] = { 0, -1, 0, 1 };
int yMove[] = { 1, 0, -1, 0 };
int sol[10][10];

void solve(int idx, int x, int y){
    if(idx == N*N) {
        return;
    }

    for(int k=0; k<4; k++){
        int next_move = x + xMove[k];
        int neyt_move = y + yMove[k];


        if(arr[next_move][neyt_move] && next_move>=0 && next_move<N && neyt_move>=0 && neyt_move<N){
//            cout << next_move << " " <<  neyt_move << endl;
            sol[next_move][neyt_move] = 1;
            solve(idx+1,next_move, neyt_move);
           // arr[next_move][neyt_move] = 0;
        }

    }
}


void findSolution( int n, int x, int y, string ans){
    if(x == (n-1) && y == (n-1)){
        cout << "Ans = " << ans << endl;
        return;
    }
//    cout << x << " " << y << endl;

    if(sol[x+1][y] == 1){
//        cout << "D" << endl;
        ans += "D";
        //sol[x][y] = 2;
        findSolution(n, x+1, y, ans);
        sol[x+1][y]=0;
    }

    if(sol[x-1][y] == 1){
//        cout << "U" << endl;
        ans += "U";
        //sol[x][y] = 2;
        findSolution(n, x-1, y, ans);
        sol[x-1][y] = 0;
    }

    if(sol[x][y+1] == 1){
//        cout << " R " << endl;
        ans += "R";
      //  sol[x][y] = 2;
        findSolution(n,x,y+1,ans);
        sol[x][y+1] = 0;
    }

    if(sol[x][y-1] == 1){
//        cout << "L" << endl
        ans += "L";
//        sol[x][y] = 1;
        findSolution(n, x, y-1, ans);
        sol[x][y-1] = 0;
    }
//    sol[x][y] = 0;

}




int main(){
    int kase;
    cin >> kase;

    while(kase--){
        cin >> N;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> arr[i][j];
            }
        }
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                sol[i][j]=0;
            }
        }

        solve(0,0,0);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << sol[i][j];
            }
            cout << endl;

        }

//        cout << sol[1][1] << endl;
//        printSolution(0,0,sol,N, "");
        findSolution(N, 0,0, "");

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << sol[i][j];
            }
            cout << endl;

        }

    }



    return 0;
}
