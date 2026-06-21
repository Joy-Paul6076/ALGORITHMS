#include<iostream>
#include<vector>
using namespace std;

int SingleNumber(vector<int> & nums) {
    int result=0;
    for(int i=0; i<nums.size(); i++){
        result^=nums[i];
    }
    return result;
}
void Print_Subarrays(int arr[],int n){
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

}
