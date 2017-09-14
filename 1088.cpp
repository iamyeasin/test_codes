#include<stdio.h>

int arr[123456];
int hi,lo;
int flag = 0;


int get_ind(int n){ // 0 based index will return
    int l = 0;
    int h = hi-1;

    flag = 0    ;
    if(arr[l] == n ) { return l; }
    if(arr[h] <= n ) { return h; }

    while(l < h){
        int mid = (l+h)/2;
        int ne = (l-h) < 0 ? (h-l) : (l-h) ;
        if( ne == 1 && arr[mid] != n){
            if(arr[l] < arr[h]) return mid;
        }

        if( arr[mid] == n ){return mid;}
        else if( arr[mid] < n) l = mid;
        else h = mid;
    }

}


int main(){
//    freopen("in.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);

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

            if(x <= arr[pos1]) minR += 1;
            if(y >= arr[pos2]) minR += 1;
            if(minR > 0 && (pos1 == pos2)) minR--;

            printf("%d\n",minR);
            minR = 0;
        }

    }


    return 0;

}
