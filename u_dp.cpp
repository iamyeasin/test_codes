/*Get a suitable solution idiot! */

#include<bits/stdc++.h>
#define sf scanf 
#define pf printf

using namespace std;


int ranks(string s,string ss)
{
	
	if(s == "pedra" && ss == "lagarto")
		return 1;
	else if(ss == "pedra" && s == "lagarto")
		return 2;
	
	if(s == "tesoura" && ss == "papel")
		return 1;
	else if(ss == "tesoura" && s == "papel")
		return 2;
	
	if(s == "papel" && ss == "pedra")
		return 1;
	else if(ss == "papel" && s == "pedra")
		return 2;
	
	if(s == "lagarto" && ss == "Spock")
		return 1;
	else if(s == "lagarto" && ss == "Spock")
		return 2;
		
	if(s == "Spock" && ss == "tesoura")
		return 1;
	else if(ss == "Spock" && s == "tesoura")
		return 2;	
	
	if(s == "tesoura" && ss == "lagarto")
		return 1;
	else if(ss == "tesoura" && s == "lagarto")
		return 2;
		
	if(s == "lagarto" && ss == "papel")
		return 1;
	else if(ss== "lagarto" && s == "papel")
		return 2;
		
	if(s == "papel" && ss == "Spock")
		return 1;
	else if(ss == "papel" && s == "Spock")
		return 2;
		
	if(s == "Spock" && ss == "pedra") 
		return 1;
	else if(ss == "Spock" && s == "pedra")
		return 2;
	
	if(s == "pedra" && ss == "tesoura")
		return 1;
	else if(ss == "pedra" && s == "tesoura")
		return 2;
		
		
	return 0;
}

int main()
{
	//freopen("in.txt","rt",stdin);
	// freopen("out.txt","wt",stdout);
	
	int n;
	string s3,ss;
	sf("%d",&n);
	
	for(int i=1; i<=n; i++)
	{
		cin >> s3 >> ss;
		
		if(s3 == ss)
		{
			pf("Caso #%d: De novo!\n",i);
			continue;
		}
		
		// cout << s3 << " " << ss << endl;
		
		int nn = ranks(s3,ss);
		if(nn==1)
		{
			pf("Caso #%d: Bazinga!\n",i);
		}
		else if(nn==2)
		{
			pf("Caso #%d: Raj trapaceou!\n",i);
		}

	}

	
	
	
	return 0;
}
