#include<iostream>
#include<vector>
using namespace std;

int SingleNumber(vector<int> & nums) { //O(n)
    int result=0;
    for(int i=0; i<nums.size(); i++){
        result^=nums[i];
    }
    return result;
}
void Print_Subarrays(int arr[],int n){ //O(n^3)
    for(int start=0;start<n;start++){
        for(int end=start;end<n;end++){
            for(int i=start;i<=end;i++){
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}
void Maximum_Subarray_Sum_Bruteforce(int arr[],int n){ //O(n^3)
    int max_sum=0;
    for(int Start=0;Start<n;Start++){
        int Current_sum=0;
        for(int End=Start;End<n;End++){
            Current_sum+=arr[End];
            max_sum=max(max_sum,Current_sum);
        }
    }
    cout<<"Maximum Subarray Sum: "<<max_sum<<endl;
}
void Kadanes_Algorithm(int arr[],int n){ //O(n)
    int max_sum=0;
    int current_sum=0;
    for(int i=0; i<n; i++){
        current_sum+=arr[i];
        max_sum=max(max_sum,current_sum);
        if(current_sum<0){
            current_sum=0;
        }
    }
    cout<<"Maximum Subarray Sum: "<<max_sum<<endl;

}
int main(){
    int n;
    cout<<"Enter no of elements of the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the Elements of the array:";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Print_Subarrays(arr, n);
    vector<int> nums={2,2,3,1,6,1,6};
    cout<<"Single Number: "<<SingleNumber(nums)<<endl;
    Maximum_Subarray_Sum_Bruteforce(arr, n);
}
