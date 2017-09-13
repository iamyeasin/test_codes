#include<bits/stdc++.h>

using namespace std;

int arr[123456];
int hi,lo;
int flag = 0;


int get_ind(int n){ // 0 based index will return
    int l = 0;
    int h = hi-1;

    flag = 0    ;
    if(arr[l] == n ) { flag = 1 ; return l; }
    if(arr[h] <= n ) { if(arr[h] == n)flag = 1;  return h; }

    while(l < h){
        int mid = (l+h)/2;
        if(arr[mid] )
        if(abs(l-h) == 1 && arr[mid] != n){

            if(arr[l] < arr[h]) return mid;
        }

        if( arr[mid] == n ){flag = 1; return mid;}
        else if( arr[mid] < n) l = mid;
        else h = mid;
    }

}


int main(){
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);

    int kase,minR;
    scanf("%d",&kase);

    for(int i=1; i<=kase; i++){
        int n,q;
        scanf("%d %d",&hi,&q);

        for(int m=0; m<hi; m++){
            scanf("%d",&arr[m]);
        }
        printf("Case %d:\n",i);
        for(int j=1; j<=q; j++){
            int x,y;
            scanf("%d %d",&x,&y);
            int pos1 = get_ind(x);
            int pos2 = get_ind(y);

            minR = (pos2-pos1);
            if(minR > 0) minR -= 1;
            if(arr[pos2] >= x) minR += 1;
            if(arr[pos1] == x || pos1 <= 0) minR += 1;

            printf("%d\n",minR);
            minR = 0;
        }


    }

    return 0;

}
