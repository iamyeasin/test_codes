void backtrack(int idx, int prev){
 if(idx == len){
  //print the combination
  for(int i = 0; i < len; i++){
   printf("%c",ans[i]);
  }
  puts("");
  return;
 }
 
 for(int x = 0; str[x]; x++) if( !taken[x] && x > prev){
  ans[idx] = str[x]; //save the combination here
  
  taken[x] = true;
  backtrack( idx+1, x );
  taken[x] = false;
  
  while( str[x] == str[x+1] ) x++;
 }
}

call backtrack(0, -1);









 /*******************/
///Permutation

#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

unsigned long long fact[25];

char str[123]={'0','0','1','1'},ans[123],len=4;
bool taken[55];

void backtrack(int idx)
{
    if(idx == 4){
        //print the combination
        for(int i = 0; i < len; i++){
            printf("%c",ans[i]);
        }
        puts("");
        return;
    }

    for(int x = 0; str[x]; x++)
        if( !taken[x]){
        ans[idx] = str[x]; //save the combination here

        taken[x] = true;
        backtrack( idx+1, x );
        taken[x] = false;

        while( str[x] == str[x+1] ) x++;
        }
}


int main(){

    memset(taken,0,sizeof(taken));
    backtrack(0,-1);



    return 0;
}
