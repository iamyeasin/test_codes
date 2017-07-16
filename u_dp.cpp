#include<bits/stdc++.h>
#define sf scanf
#define pf printf
#define mx 100090

using namespace std;

char ok[mx];

int main()
{
    int n;
    cin >> n;

    sf("%s",ok);

    int arr[mx];
    int i=0,sum=0,f=0,zero=0;
    while(i < n)
    {
        sum = 0;
        if(ok[i] == '1')
        {
            i++;sum++;

            while(ok[i] == '1')
            {
                sum++;
                i++;
            }
            arr[f++] = sum;
            sum = 0;
        }

        if(ok[i] == '0')
        {
            i++; sum++;
            while(ok[i] == '0')
            {
                sum++;
                i++;
            }
            if(sum > 1) arr[f++] = 0;
        }
    }

    for(int k=0; k<f; k++)
    {
        pf("%d",arr[k]);
    }
    pf("\n");


    return 0;

}
