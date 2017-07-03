#include<bits/stdc++.h>
#define sf scanf 
#define pf printf

using namespace std;

int main()
{
	int mat[256][256];
	int n;
	
	while(sf("%d",&n) != EOF)
	{
		int x=0,y=n-1;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				mat[i][j] = 0;
				mat[i][x] = 2;
				mat[i][y] =3;
			}
			x++;y--;
		}
		
		int res = n/3,half = res+2;
		//~ cout << res << " " << half << endl;
		for(int i=res; i<=half; i++)
		{
			for(int j=res; j<=half; j++)
			{
				mat[i][j] = 1;
				//~ cout << mat[i][j] << " ";
		
			}
			//~ cout<< endl;
		}
		mat[n/2][n/2] = 4;
		
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(j<n-1)
				{
					pf("%d ",mat[i][j]);
				}
				else if(j==n-1)
				{
					pf("%d\n",mat[i][j]);
				}
			}
		}
		
		pf("\n");
	}
	
	
	return 0;
}

