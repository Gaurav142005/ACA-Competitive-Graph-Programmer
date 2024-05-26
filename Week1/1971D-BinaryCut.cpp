#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int state = -1;
        int flag = 1;
        int cuts = 1;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '1'){
                if(state == 0){
                    if(flag == 0)
                        cuts++;
                    else
                        flag = 0;
                }
                state = 1;
            }

            if(s[i] == '0'){
                if(state == 1){
                    cuts++;
                }
                state = 0;
            }
        }
        cout<<cuts<<endl;
    }
}
