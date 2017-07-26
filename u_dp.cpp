#include<bits/stdc++.h>

using namespace std;

bool isLeap(long year)
{
    if((!(year%4) || !(year%400)) && (year%100))
        return true;
    else
        return false;
}

int date[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
int l_date[13] = {0, 31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);

    long kase;
    int cnt, ans, extra;
    while(scanf("%d",&kase),kase)
    {
        cnt = ans = 0;
        int day[3], month[3], year[3], bill[3];



        cin >> day[1] >> month[1] >> year[1] >> bill[1];

        for(int i=1; i<kase; i++)
        {

            cin >> day[2] >> month[2] >> year[2] >> bill[2];
            if(month[1] == month[2] && year[1] == year[2]){
                if(day[1] == day[2]-1){
                        ans += abs(bill[1]-bill[2]);
                        cnt++;
                }
            }
            else if(month[1] == month[2]-1 && year[1] == year[2]){
                if(day[2]==1){

                    int date = isLeap(year[1]) ? 28 : 29;
                    if( (isLeap(year[1]) && day[1] == l_date[ month[1] ] ) || (!(isLeap(year[1]) && day[1] == date[ month[1] ] ) ) ){
                           ans += abs(bill[1]-bill[2]);
                            cnt++;
                       }
                }

            }
            else if(year[2]-1 == year[1] ){
                if( day[1]==31 && month[1]==12 && day[2]==1 && month[2]==1){
                    ans += abs(bill[1]-bill[2]);
                            cnt++;
                }
            }


            day[1] = day[2], month[1] = month[2], year[1] = year[2], bill[1] = bill[2];
        }

    cout << cnt << " " << ans << endl;

    }





    return 0;
}
