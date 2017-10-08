#include<bits/stdc++.h>
#define pf printf
#define sf scanf

using namespace std;

map < string , int > mp;
set < string > st;
map <string , int > ::iterator it;

void printCombination(int idx, char *data , char *arr, int r , int n, int start){
    if(r == idx) {

        string ss = "";
        for(int i=0; i<idx; i++){
            ss += data[i];
        }
        // cout << ss << endl; return ;
       string cpy = ss;
       sort(cpy.begin(), cpy.end());

       if(!mp[cpy]){
        mp[cpy] ++;
//        cout << ss << endl;
        st.insert( ss );
        return;
       }
    }

    for(int j=start; j<n; j++){
        data[idx] = arr[j];
        printCombination(idx+1, data, arr, r, n, j+1);
    }

}


int main(){
    char arr[34], data[23];

    while( sf("%s",arr) ,arr){
        int n,r;
        scanf("%d",&r);
        n = strlen(arr);
        printCombination(0, data, arr, r, n, 0);

        sort (st.begin(), st.end() );
        while(!st.empty()){
            cout << st.front() << endl;
            st.pop();
        }

        mp.clear();
        st.clear();

        memset(arr,'\0',sizeof(arr));


    }

    return 0;
}

