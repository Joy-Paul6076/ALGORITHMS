#include<iostream>
#include<vector>
using namespace std;
//Majority Element must be exist in the array & majority element > n/2

int majority_Element(vector<int> &arr){
    int n=arr.size();
    for(int val : arr){
        int count=0;
        for(int i=0; i<n; i++){
            if(arr[i]==val){
                count++;
            }
        }
        if(count>n/2){
            cout<<"Majority Element is: "<<val<<endl;
            return val;
        }
    }
}
int optimized_majority_element(vector<int> &arr){
    int n=arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }   
    int frequency = 1;
    for(int i=1; i<n; i++){
        if(arr[i]==arr[i-1]){
            frequency++;
        }
        else{
            frequency=1;
        }
        if(frequency>n/2){
            cout<<"Majority Element is: "<<arr[i]<<endl;
            return arr[i];
        }
    }
}
int moores_Voting_algorithm(vector<int> &arr){
    int n=arr.size();
    int count=0;
    int candidate=-1;
    for(int i=0; i<n; i++){
        if(count==0){
            candidate=arr[i];
        }
        if(arr[i]==candidate){
            count++;
        }
        else{
            count--;
        }
    }
    cout<<"Majority Element is: "<<candidate<<endl;
    return candidate;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array:";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array:";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int x=majority_Element(arr);
    int y=optimized_majority_element(arr);
    int z=moores_Voting_algorithm(arr);
    cout<<"Majority Element from first approach: "<<x<<endl;
    cout<<"Majority Element from second approach: "<<y<<endl;
    cout<<"Majority Element from third approach: "<<z<<endl;
    return 0;
}