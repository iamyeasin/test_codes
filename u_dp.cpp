#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

int bits[] = {0,32,16,8,4,2,1};
bool h[64],m[64];

void print(){
    pf(" ____________________________________________\n");
    pf("|                                            |\n");
    pf("|    ____________________________________    |_\n");
    pf("|   |                                    |   |_)\n");
    pf("|   |   8         4         2         1  |   |\n");
    pf("|   |                                    |   |\n");
    pf("|   |  ");


    for(int i=3; i<=7; i++){
        if(h[i]){
            pf("o");
        }
        else pf(" ");

        if(i < 6 && i>2)pf("         ");
    }

    pf("  |   |\n");
    pf("|   |                                    |   |\n");
    pf("|   |  ");


    for(int i=1; i<=7; i++){
        if(i<=2){
            if(m[i]){
                 pf(" o");

            }
            else pf("  ");
        }
        else{
            if(m[i]){
                pf("o");

            }
            else pf(" ");
        }

        if(i>=1 && i<7)pf("    ");
    }


    pf("  |   |\n");

     pf("|   |                                    |   |\n");
     pf("|   |   32    16    8     4     2     1  |   |_\n");
     pf("|   |____________________________________|   |_)\n");
     pf("|                                            |\n");
     pf("|____________________________________________|\n");





}


int main(){

    long hh,mm;
    while(sf("%d:%d",&hh,&mm) != EOF){
        memset(m,0,sizeof(m));
        memset(h,0,sizeof(h));

        for(int i=1; i<=7; i++){
            if(hh >= bits[i]){
                h[i] = 1; hh %= bits[i];
            }
            if(mm >= bits[i]){
                m[i] = 1; mm %= bits[i];
            }
        }
//
//        for(int i=1; i<=6; i++){
//            cout << pow(2,i) << "= " << m[i] <<endl;
//        }

        print();
        puts("");

    }



    return 0;
}
