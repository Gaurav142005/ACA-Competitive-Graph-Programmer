#include<bits/stdc++.h>
using namespace std;

vector<int> funGame (vector<int> &arr) {
   // Write your code here
   int a = 0, b = arr.size() - 1;
   int N = arr.size() - 1;
   vector<int>sol;
   while(a <= N && b >= 0){
        if(arr[a] > arr[b]){
            sol.push_back(1);
            b--;
        }
        else if(arr[a] < arr[b]){
            sol.push_back(2);
            a++;
        }
        else{
            sol.push_back(0);
            a++;
            b--;
        }
   }
   return sol;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i_arr=0; i_arr<n; i_arr++)
    {
    	cin >> arr[i_arr];
    }

    vector<int> out_;
    out_ = funGame(arr);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}
