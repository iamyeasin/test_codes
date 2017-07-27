#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

//vector < int > x[81];

int x[12][12];
int pos1[] = {2,5,7};
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};

bool cRow()
{
    int row[10];
    for(int i=1; i<=9; i++)
    {
        for(int i=0; i<10; i++)row[i]=0;

        for(int j=1; j<=9;j++)
        {
            if(!row[x[i][j]])row[x[i][j]] = 1;
            else return false;
        }
    }
    return true;
}



bool cCol()
{
    int row[10];
    for(int i=1; i<=9; i++)
    {
        for(int i=0; i<10; i++)row[i]=0;

        for(int j=1; j<=9;j++)
        {
            if(!row[x[j][i]])row[x[j][i]] = 1;
            else return false;
        }
    }
    return true;
}

bool isSub()
{
    int arr[11] = {0,0,0,0,0,0,0,0,0,0};

    for(int i=0; i<3; i++)
    {
        memset(arr,0,sizeof(arr));
        for(int j=0; j<=3; j++)
        {
            arr[pos1[j]] = 1;
           for(int k=0; k<=3; k++)
           {
                int nx = pos1[i] + fx[k];
                int ny = pos1[j] + fx[k];

                if(!arr[x[nx][ny]])arr[x[nx][ny]] = 1;
                else return false;
           }
        }
    }

    return true;
}

int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    int kase,y;
    scanf("%d",&kase);

    for(int i=1; i<=kase; i++)
    {
        for(int j=1; j<=9; j++)
        {
            for(int k=1; k<=9; k++)
            {
                int mm;
                sf("%d",&mm);
                if(mm >=1 && mm <=9)
                {
                    x[j][k] = mm;
                }
            }
        }

        if(cRow() && cCol())pf("Instancia %d\nSIM\n\n",i);
        else pf("Instancia %d\nNAO\n\n",i);

        cout << isSub() << endl;
    }


    return 0;
}
