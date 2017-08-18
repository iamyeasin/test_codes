#include<bits/stdc++.h>
#define sf scanf
#define pf printf
#define mx 1000005

using namespace std;

int main(){

    long kase;
    sf("%ld",&kase);

    static int p[ 1000050 ],l[500],s[500];

    while(kase--){

        memset(p,0,sizeof(p));
        long player,howls,ndies;
        cin >> player >> howls >> ndies;

        for(int i=1; i<=howls; i++){
            int x,y;
            cin >> x >> y;
            l[x] = y;
        }

//        for(int i=1; i<=100; i++){
//            cout << "i = " <<i << " " << l[i] << endl;
//        }

        long n;
        for(int i=1; i<=ndies; i++){
            cin >> n;
            int x=i;
            if(x > player) {x %= player; if(!x) x=player;}

            if(i<=player){
                if(l[n+1]){
                    p[x] = l[n+1];
                }
                else p[x] = n+1;
            }
            else{
                if(l[p[x]]){
                    p[x] = l[p[x]];
//                    cout << "p[x] " << l[p[x]] <<endl;
                }
                else {
//                    cout << x << " cout " << p[x] << endl;

                    if(p[x] >= 100)p[x] = 100;
                    else p[x] += n;
                }
            }

        }

        for(int i=1; i<=player; i++){
            pf("Position of player %d is %d.\n",i,p[i]);
        }


    }


    return 0;
}
