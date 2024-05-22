#include <iostream>
#include <vector>
using namespace std;

int lBound(vector<long long>v, long long key){
    long long low = 0, high = v.size() - 1;
    int index = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(v[mid] > key)    // Can't be solution
            high = mid - 1;
        else{   // Can be solution
            index = mid;
            low = mid+1;
        }
    }
    return index;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, k, q;
        cin>>n>>k>>q;
        vector<long long> dist;
        dist.push_back(0);
        vector<long long> time;
        time.push_back(0);
        for(int i = 0; i<k; i++){
            long long x;
            cin>>x;
            dist.push_back(x);
        }

        for(int i = 0; i<k; i++){
            long long x;
            cin>>x;
            time.push_back(x);
        }
        
        for(int i = 0; i<q; i++){
            long long query;
            cin>>query;
            long long index = lBound(dist, query);
            if(dist[index] == query)
                cout<<time[index]<<" ";
            else{
                long long T = time[index] + ((query - dist[index]) * (time[index+1] - time[index])) / (dist[index+1] - dist[index]); 
                cout<<T<<" ";
            }
        }
        cout<<endl;

    }    
}