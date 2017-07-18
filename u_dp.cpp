#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int mon[256],cred[256],kk[256],pay[256],koto[256],pos[256];
    int n,b;

    while(sf("%d %d",&b,&n,(b||n)))
    {
        for(int i=1; i<=b; i++)sf("%d",&mon[i]);

        memset(pay,0,sizeof(pay));
        memset(cred,0,sizeof(cred));
        memset(koto,0,sizeof(koto));
        memset(kk,0,sizeof(kk));

        for(int i=1; i<=n; i++)
        {
            int d,c,v;
            sf("%d %d %d",&d,&c,&v);

            if(mon[d] >= v)
            {
                mon[c] += v;
                mon[d] -= v;
                cred[c]++;
            }
            else
            {
                mon[c] += v;
                koto[d] = v- mon[d];
                mon[d] = 0;
                pay[d] = c;
                kk[d] = d;
            }
        }

        for(int i=1; i<=n; i++)
        {
            if(pay[i]>0)
            {
                cout << cred[i] << endl;
            }
            cout << cred[i] << endl;


//            pf("%d number bank %d number bank er kase %d taka pay\n",pay[i],kk[i],koto[i]);
//            pf("Credits = %d\n", mon[i]);
        }


    }



    return 0;
}
