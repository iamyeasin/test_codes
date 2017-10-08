#include<bits/stdc++.h>
#define pf printf
#define sf scanf

using namespace std;

void printCombination(int idx, char *data , char *arr, int r , int n, int start){
    if(r == idx) {
        data[idx] = '\0';
        puts(data);
        return;
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

        memset(arr,'\0',sizeof(arr));

    }

    return 0;
}
a
