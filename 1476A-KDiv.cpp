#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, k;
        cin>>n>>k;
        // Every element will be a positive integer
        long long a = k * ((n + k - 1) / k);
        long long max = (a + n - 1) / n;
        cout<<max<<endl;
    }
}