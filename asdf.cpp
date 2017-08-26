#include<bits/stdc++.h>

using namespace std;

vector < string > s;

int main(){

    long n;
    cin >> n;

    //input taking
    for(int i=0; i<n; i++){
        string token;
        cin >> token;
        s.push_back(token);
    }

    long till; cin >> till;
    for(int k=0; k<till; k++){
        string test;
        cin >> test;
        int f=0;

        //if it exists on the container
        for(int i=0; i<n; i++){
            if(s[i] == test){
                cout << test << " is correct" << endl;
                f=1;
            }
        }
        if(f)continue;
        int ok = 0;

        int l1 = test.size();

        for(int i=0; i<n; i++){
            ok=1;
            int l2 = s[i].size();
            string gini = s[i];
                if(l1 == l2){
                    sort(gini.begin(),gini.end());
                    sort(test.begin(),test.end());

                    if(gini == test){
                        cout << test << " is a misspelling of " << s[i] << endl;ok=1;
                        break;
                    }

        }
//        if(ok)continue;

        int pro = 0;
        for(int m=0; m<n; m++){
            int l2 = s[m].size();
            string ginis = s[m];

            if(l1 >= l2 || (l2-1 == l1) || (l2+1 == l1) ){
                sort(ginis.begin(),ginis.end());
                sort(test.begin(),test.end());
                pro =0;

                for(int x=0; x<(max(l1,l2)); x++){
                    if(ginis[x] != test[x]) pro++;
                }
                cout << pro << endl;
                break;
            }
        }

    }

}

}
