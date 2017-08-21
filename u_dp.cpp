#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#define sf scanf
#define pf printf

using namespace std;

int main(){

    char num[16],n[16];
    long long nm;
    memset(num,'0',sizeof(num));

    while(1){

        sf("%s",num);
        if(num[0] == '0' && num[1] == 0) break; // NEXT ONE MAY BE GOT SOMEHOW INTEGER
        int counter=0;

        while(1){
            int z=0,sum=0;
            for(int i=0; i<=3; i++){
                if(num[i] == '0')z++;
                sum += (num[i]-'0');
            }
            counter++;
            if(counter > 111 || sum == 0) break;

            long long f = atol(num);
            long long sq = f*f,x,y;
            char temp[16],fin[16];
            memset(fin,'\0',sizeof(fin));

            x = sq;

            int ii=0;
            while(x>0){
                temp[ii++] = x%10 + '0';
                x /= 10;
            }
            temp[ii] = '\0';
            reverse(temp,temp+ii);

            int k=0,i,ik;
            for(i=0; i<(8-ii)/2; i++)fin[i]='0';
            for(ik = i; ik<=ii; ik++) fin[ik] = temp[k++];
            for(int j = ik; j<8; j++)fin[j] = '0';
            fin[8] = '\0';

            num[0] = fin[2]; num[1] = fin[3];
            num[2] = fin[4]; num[3] = fin[5];
            num[4] = '\0';

            cout << counter << " ";
            puts(num);
        }

        cout << counter << endl;
    }

    return 0;
}
