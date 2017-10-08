 bool conflict(int r, int c){ 
     if(check row; // optimize the technique
     check column;
     check LD, Check RD;
     ) return true;
     else return false;
   }

    void backtrack(int c){
     if(c == n){
          print bound;
          return;
     }    
     
     for(int r=0; r<n; r++){
          if(board [r][c] != 'Q' && !conflict(r,c)){
               board[r][c] = 'Q';
               backtrack(c+1);
               board[r][c] = '*';
          }
     }
    
    }


