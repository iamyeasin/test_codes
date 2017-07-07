#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int dec(char ss)
{
    return ss - '0';
}

int zero(char *sn,int pos)
{
    int n = strlen(sn);
    int xr = 0;
    for(int i=0; i<n; i++)
    {
        if(dec(sn[i]) > 0)
        {
            break;
        }
        else if(sn[i] == '0' )
        {
            xr++;
        }
    }

    return xr;
}

int main()
{
    while(1)
    {
        char s[1024];
        char st[1024];
        gets(s);

        int len = strlen(s);
        int pos=0,neg=0;

        if(s[0] == '-')
        {
            st[0] = '-';
            neg = 1;
        }
        else
        {
            st[0] = '+';
            pos = 1;
        }

        int ok=0,dPos=0,noPoint=0,ind=1,xr,fL;

        for(int i=0; i<=len; i++)
        {
            if(s[i] == '.')
            {
                dPos = i;
                noPoint = 1;
            }

            if(((s[i]-'0') > 0 ) && !ok)
            {
                st[ind++] = s[i];
                ok=1;
                fL = i;
            }
        }

        if(noPoint)
        {
            xr = zero(s,dPos);
        }

        if(!ok)
        {
            pf("%c0000E+00\n",st[0]);
            return 0;
        }
        st[ind++] = '.';
        //If no point found on the string
        if(!noPoint)
        {
            int in = 1;
            int k = (s[0] == '-' || s[0] == '+') ? 2 : 1;
            int zr = zero(s,k);
            k = (zr > 0) ? zr : k;
//            cout << k << endl;


            for(int i=k; i<=4; i++)
            {
                st[ind++] = (i >= len) ? '0' : s[i];
            }
            if(dec(s[5+k]) > 0) {st[6]= (st[6]-'0')+1+'0';}
//            cout << ind << endl;
            if(ind < 6)
            {
                for(int i=ind; i<6; i++)
                {
                    st[i] = '0';
                }
            }


            st[ind++] = 'E';
            st[ind++] = '+';

            int dig=0,flag=0,fuck;

            cout << zr << endl;
            if(!zr)
            {
                if(k==2)dig=(len-2);
                else if(k==1)dig = (len-1);
            }
            else if(zr>0)
            {

            }
            cout << st << " " << dig << endl;
        }

        else // IF there is a point
        {

//            st[ind++] = '.';
            // copying data
            for(int i=fL+1; i<=fL+4; i++)
            {
                if(s[i]=='.')
                {
                    fL++;
                    continue;
                }
                else if(i>=len)
                {
                    st[ind++] = '0';
                }
                else
                {
                    st[ind++] = s[i];
                }
            }

            st[ind++] = 'E';

            if(xr > 0 ) st[ind++] = '-';
            else st[ind++] = '+';

            int posCounter=0,sp;
            sp = (s[0] =='-' || s[0] == '+') ? 2 : 1;

            int k=0;
//            if(sp == 2)
            {
                for(int i=sp-1; i<len; i++)
                {
                    if(s[i] == '.')continue;
                    else if(k == 5)
                    {
                        if(dec(s[i]) >= 5)st[6]=(((st[6]-'0')+1)+'0');
                        break;
                    }
                    else
                    {
                        k++;
                    }
                }
            }


            if(xr > 0)
            {
                for(int i=sp; i<len; i++)
                {
                    if(s[i] == st[1])break;
                    else posCounter++;
                }
            }
            else
            {
                for(int i=sp; i<=dPos; i++)
                {
                    if(s[i] == '.')break;
                    else posCounter++;
                }
            }

            if(posCounter >= 0 && posCounter <= 9) st[ind++] = '0';
            pf("%s%d\n",st,posCounter);

        }

        memset(st,'\0',sizeof(st));

    }

    return 0;
}
