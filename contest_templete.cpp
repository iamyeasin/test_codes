

    #include <bits/stdc++.h>
    #define     sf      scanf
    #define     pf      printf
    #define     inf     INT_MAX
    #define     dbg     cout << "Debug" << endl;
    #define     MAX     10000007
    #define     MOD     1000000009
    #define     eps     1e-6
    #define     INF     1llu<<61    // 2,305,843,009,213,693,952
    #define     PI      acos(-1.0)  // 3.1415926535897932
    #define     block   -1
    #define     white   +0
    #define     noway   -3
    #define     source  -4
    #define     goal    -5
    #define     MP      make_pair
    #define     PB      push_back
    #define     F       first
    #define     S       second
    #define     loop(i,a,b)     for( int i=a; i<=b; i++ )
    #define     pool(i,a,b)     for( int i=a; i>=b; i-- )
    #define     ll long long
     
    using namespace std;
    const int dr[] = { 0,  1,  0, -1,   -1,  1,  1, -1,   -2, -2,  2,  2, -1, -1,  1,  1};
    const int dc[] = { 1,  0, -1,  0,    1,  1, -1, -1,   -1,  1, -1,  1, -2,  2, -2,  2};
     
    #define  LLI  unsigned long long
     
    int main(){
     
        long long s,n,cstrn;
        cin >> s >> n;
     
        vector < pair <long long,long long> >vp;
        for( auto i=1; i<=n; i++ ){
            long long x,y;
            cin >> x >> y; vp.PB(MP(x,y));
        }
     
        sort(vp.begin(),vp.end());
        bool flag[n+10]; memset( flag,0,sizeof flag );
        cstrn = s;
     
        for( auto i=0; i<n; i++ ){
            long long temp = cstrn,ind = 0;
            for( auto j=0; j<n; j++ ){
                if( ( vp[j].first < cstrn && !flag[j] && (cstrn + vp[j].second) >= temp ) ){
                    temp = (cstrn + vp[j].second);
                    ind = j;
                }
                //if( vp[j].first > cstrn )break;
            }
           // cout << endl;
            cstrn = temp; flag[ind] = 1;
            //cout << vp[ind].first << " " << cstrn << endl;
        }
     
        for( auto &x : vp ){
            if( cstrn <= x.first ){
                puts("NO"); return 0;
            }
        }
        puts("YES");
        vp.clear();
     
     
     
        #ifndef ONLINE_JUDGE
            main();
        #endif
     
     
    	return 0;
    }
