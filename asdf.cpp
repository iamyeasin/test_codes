#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

string bigNum;

void bigDiv(){

    int len = bigNum.size();
    string qut;

    int carry = 0;
    for(int i=0; i<len; i++){

        int x = (bigNum[i] - '0') + carry;
        if(x > 0){
            if(x < 2){
                qut += (0 +'0');
                carry = 10;
            }else{

                qut += ((x >> 1) +'0');
                if(((x << 1) - x) == 0){
                    carry = 0;
                }
                else carry = 10;
            }
        }
        else if(x == 0) qut += '0';
    }
    cout << qut << endl;


}



int main(){
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    long kase;

    while(1){
        cin >> bigNum;
    bigDiv();

    }


//
//    for(int i=1; i<=kase; i++){
//        long odP = 0;
//
//    }

    return 0;
}
