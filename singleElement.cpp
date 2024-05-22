#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>&nums) {
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if((mid & 1) == 0){     // Mid has even index
            if(mid >0 && (nums[mid-1] == nums[mid])){
                // Single element on the left side
                high = mid - 1;
            }

            else if(mid < nums.size() - 1 && (nums[mid] == nums[mid + 1])){
                // Single element on the right side
                low = mid + 1;
            }
            else
                return nums[mid];
        }

        else{   // Mid has odd index
            if(mid > 0 && (nums[mid-1] == nums[mid])){
                // Single element on the right side
                low = mid + 1;
            }

            else if(mid < nums.size() - 1 && (nums[mid] == nums[mid + 1])){
                // Single element on the left side
                high = mid - 1;
            }
            else
                return nums[mid];
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<singleNonDuplicate(v)<<endl;
}