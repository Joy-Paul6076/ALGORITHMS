#include<iostream>
using namespace std;
void insertionsort(int arr[],int n){
    for(int starting_index=1; starting_index<n; starting_index++){
        int element_on_hand=arr[starting_index];
        int current_index=starting_index-1;
        while(current_index>=0 && arr[current_index]>element_on_hand){
            arr[current_index+1]=arr[current_index];
            current_index--;
        }
        arr[current_index+1]=element_on_hand;
    }
}
void selectionsort(int arr[],int n){
    for(int starting_index=0; starting_index<n-1; starting_index++){
        int min_index=starting_index;
        for(int current_index=starting_index+1; current_index<n; current_index++){
            if(arr[current_index]<arr[min_index]){
                min_index=current_index;
            }
        }
        swap(arr[starting_index],arr[min_index]);
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Choose the sorting algorithm: "<<endl;
    cout<<"1. Insertion Sort"<<endl;
    cout<<"2. Selection Sort"<<endl;
    cin>>n;
    switch(n){
        case 1:
            insertionsort(arr,n);
            break;
        case 2:
            selectionsort(arr,n);
            break;    
    }
    
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}