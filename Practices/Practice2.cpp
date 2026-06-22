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
     cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
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
     cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}
void Bubble_Sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped){
            break;
        }
    }
     cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}
void Binary_Search(int arr[], int n, int key){
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == key){
            cout << "Element Found at index: " << mid << endl;
            return;
        } else if(arr[mid] < key){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Element Not Found!" << endl;





}
int main(){
    int n,key,m;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
     cout<<"Enter The Element You Want to Search: ";
    cin>>key;
    Binary_Search(arr, n, key);
   
    cout<<"Choose the sorting algorithm: "<<endl;
    cout<<"1. Insertion Sort"<<endl;
    cout<<"2. Selection Sort"<<endl;
    cout<<"3. Bubble Sort"<<endl;
    cin>>m;
    switch(m){
        case 1:
            insertionsort(arr,n);
            break;
        case 2:
            selectionsort(arr,n);
            break;  
        case 3:
            Bubble_Sort(arr,n);
            break;
        default:
            cout<<"Invalid choice!"<<endl;
            return 0;      
    }
   
    return 0;
}