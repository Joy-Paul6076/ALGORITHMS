#include<iostream>
#include<vector>
using namespace std;

vector<int> pair_Target_sum(vector<int>nums,int target){
    vector<int> result;
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]+nums[j]==target){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}
int main(){
    int n;
    cout<<"Enter the number of elements in the array:";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array:";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int target;
    cout<<"Enter the target sum:";
    cin>>target;
    vector<int> result=pair_Target_sum(nums,target);
    if(result.size()==0){
        cout<<"No pair found with the given target sum."<<endl;
    }
    else{
        cout<<"Pair found at indices: "<<result[0]<<" and "<<result[1]<<endl;
    }
}