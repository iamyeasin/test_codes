#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s1;
    getline(cin,s1);


    char st[123];
    int len = s1.length();

    if(s1[0] == '-') st[0] = '-';
    else st[0] = '+';

    int flag=0,dot=-5,fz=0;
    bool fs=0,dt=false;


    for(int i=0; i<len; i++)
    {

        if((s1[i]-'0') > 0 && !fs)
        {
            st[1] = s1[i];
            fs = true;

            st[2] = '.';dt=true;
        }
        else if(s1[i] == '.' && !dt)
        {
            st[2] = '.';dt = true;
        }

        if(s1[i] == '.'){ dot=i;dt=true; }
    }
    dot = (dot==-5) ? 0 : dot;
//    cout << dot << endl;

    int sk = 3;

    for(int i=dot; i<=dot+3; i++)
    {
        st[sk++] = s1[i+1];
    }
    st[sk++] = (s1[dot+3]-'0' > 5) ? (s1[dot+3]-'0' +1 ) + '0' : s1[dot+3];




    cout << st<< endl;



    return 0;
}
