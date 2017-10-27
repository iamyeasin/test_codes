#include<bits/stdc++.h>
#include<stdio.h>
#define pf printf
#define sf scanf

using namespace std;

vector  <string> codes, names;

void generate_idx( string nm){
        string code = "";
        code += nm[0];
        int len = nm.size();
        string num = "";

        for( int i =0; i < len ; i++){
            if(nm [i] == 'A' || nm[i] == 'E' ||
            nm [i] == 'Y' || nm[i] == 'I'  ||
            nm [i] == 'U' || nm[i] == 'O' ||
            nm [i] == 'W' || nm[i] == 'H' || nm[i] == nm[i-1]) continue;

            if((nm [i] == 'B' || nm[i] == 'P' || nm [i] == 'F' || nm[i] == 'V' )) num += '1';
            else if(nm [i] == 'C' || nm[i] == 'S' || nm [i] == 'K' || nm[i] == 'G'  || nm [i] == 'J' || nm[i] == 'Q' || nm [i] == 'X' || nm[i] == 'Z') num += '2';
            else if(nm[i] == 'D' || nm[i] == 'T') num += '3';
            else if(nm[i] == 'L') num += '4';
            else if(nm [i] == 'M' || nm[i] == 'N') num += '5';
            else if(nm [i] == 'R') num += '6';
        }

        int sz = num.size();
        if(num.empty()) num += "000";
        else{
            for(int i=sz; i<3; i++){
                num += '0';
            }
//            num[3] = '\0';
        }
        code += num;
        cout << code << endl;

}


int main(){

    generate_idx("KUHNE");
    generate_idx("LEE");
    generate_idx("EBELL");
    generate_idx("EBELSON");
    generate_idx("SCHAEFER");
    generate_idx("SCHAAK");

    return 0;
}
