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
    for(int i=pos; i<n; i++)
    {
        if(sn[i] != '0')break;
        else if(sn[i] ==0)xr++;
    }

    return xr;
}

int main()
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

    int ok=0,dPos=0,noPoint=0,ind=1,xr;

    for(int i=0; i<=len; i++)
    {
        if(s[i] == '.')
        {
            dPos = i;
            noPoint = 1;
            break;
        }

        if(((s[i]-'0') > 0 ) && !ok)
        {
            st[ind++] = s[i];
            ok=1;
        }
    }

    if(noPoint)
    {
        xr = zero(s,dPos);
    }

    if(!ok)
    {
        pf("%c0000E00\n",st[0]);
        return 0;
    }

    //If no point found on the string
    if(!noPoint)
    {
//		cout << len << endl;
        if(s[0] == '-' || s[0] == '+')
        {
            char chs = (dec(st[6])) >= 5 ? dec(st[5])+1+'0' : st[5];
            if(len>=1 && len<=9)
            {
                pf("%c%c.%c%c%c%cE0%d\n",st[0],s[1],s[2],s[3],s[4],s[5],chs,len);
            }
            else
            {
                pf("%c%c.%c%c%c%cE%d\n",st[0],s[1],s[2],s[3],s[4],s[5],chs,len);
            }

        }
        else
        {
            char chs = (dec(st[5])) >= 5 ? dec(st[4])+1+'0' : st[4];
            if(len>=1 && len<=9)
            {
                pf("%c%c.%c%c%c%cE0%d\n",st[0],s[0],s[1],s[2],s[3],s[4],chs,len);
            }
            else
            {
                pf("%c%c.%c%c%c%cE%d\n",st[0],s[0],s[1],s[2],s[3],s[5],chs,len);
            }

        }

    }

    else // IF there is a point
    {
        // copying data

        cout << st << endl;

    }




     return 0;
}
