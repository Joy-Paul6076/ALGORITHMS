#include<iostream>
#include<vector>
using namespace std;

vector<int> pair_Target_sum(vector<int>nums,int target){//O(n^2)
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
//Sorted array approach O(n)
vector<int> pair_Target_sum_sorted(vector<int>nums,int target){
    vector<int> result;
    int left=0;
    int right=nums.size()-1;
    while(left<right){
        int sum=nums[left]+nums[right];
        if(sum==target){
            result.push_back(left);
            result.push_back(right);
            return result;
        }
        else if(sum<target){
            left++;
        }
        else{
            right--;
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
    vector<int> result_sorted=pair_Target_sum_sorted(nums,target);
    if(result.size()==0){
        cout<<"No pair found with the given target sum."<<endl;
    }
    else{
        cout<<"Pair found at indices: "<<result[0]<<" and "<<result[1]<<endl;
    }
    if(result_sorted.size()==0){
        cout<<"No pair found with the given target sum in the sorted array."<<endl;
    }
    else{
        cout<<"Pair found at indices: "<<result_sorted[0]<<" and "<<result_sorted[1]<<endl;
    }
}
    
