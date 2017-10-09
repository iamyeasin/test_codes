#include<bits/stdc++.h>

using namespace std;
vector< string > vs;

void recPermute(string soFar, string rest), string start{

    if(rest.empty()){
        int vsz = vs.size(), flag = 0;
        for(int i=0; i<vsz; i++){
            if(vs[i] == soFar){
                flag = 1;
                break;
            }
        }
        if(!flag){
            vs.push_back((soFar));
            cout << vs.size() << " " << soFar << endl;
        }else return;

    }
    else {
        for(int i = 0; i < rest.length(); i++){
            string remaining = rest.substr(0,i) + rest.substr(i+1);
//            cout << "i= "<< i << " " << soFar+rest[i]<< "  " << rest.substr(0,i) << " p=" << rest.substr(i+1)  << " tmp = " << remaining << endl;
            recPermute(soFar+rest[i], remaining);

        }
    }

}


int main(){

    recPermute("","abaaagh");


    return 0;
}
