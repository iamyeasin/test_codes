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
