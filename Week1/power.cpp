#include <iostream>
using namespace std;

long long pow(int mid, int m, int n){
    long long ans = 1;
    for(int i = 0; i<n; i++){
        ans *= mid;
        if(ans > m)
            return 2;
        }
        if(ans == m)
            return 1;
        else
            return 0; 
}

int NthRoot(int m, int n){
    // We will apply binary search algorithm here to solve in O(n)
    int low = 1, high = m;
    while(low <= high){
        int mid = (low + high) / 2;            
        if(pow(mid, m, n) == 2){    // Answer is to the left
            high = mid - 1;
        }
        else if(pow(mid, m, n) == 0){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int m, n;
    cin>>m>>n;
    cout<<NthRoot(m, n);
}
