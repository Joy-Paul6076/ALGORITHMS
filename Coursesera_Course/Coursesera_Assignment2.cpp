#include<cstdlib>
#include <iostream>
#include<vector>
using namespace std;

long long Maxpairwiseproduct(vector<int> & numbers){
    long long result =0;
    int n = numbers.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((long long)numbers[i]*numbers[j]>result){
                result=(long long)numbers[i]*numbers[j];
            }
        }
    }
    return result;
}
long long Maxpairwiseproductfast(vector<int> & numbers){
    int n = numbers.size();
    int max_index1=-1;
    for(int i=0; i<n; i++){
        if(max_index1==-1 || numbers[i]>numbers[max_index1]){
            max_index1=i;
        }
    }
    int max_index2=-1;
    for(int j=0; j<n; j++){
        if(j!=max_index1 && (max_index2==-1 || numbers[j]>numbers[max_index2])){
            max_index2=j;
        }
    }
    return (long long)numbers[max_index1]*numbers[max_index2];
}
int main(){
   /* while(true){
        int n = rand()%10+2;
        cout<<n<<endl;
        vector<int> numbers;
        for(int i=0; i<n; i++){
            numbers.push_back(rand()%100000);
        }
        for(int i=0; i<n; i++){
            cout<<numbers[i]<<" ";
        }
        long long result1=Maxpairwiseproduct(numbers);
        long long result2=Maxpairwiseproductfast(numbers);
        if(result1!=result2){
            cout<<"Wrong answer: "<<result1<<" "<<result2<<endl;
            break;
        }
        else{
            cout<<"OK"<<endl;
        }
    }*/
    int n;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0; i<n; i++){
        cin>>numbers[i];
    }
    cout<<Maxpairwiseproductfast(numbers)<<endl;
    return 0;
}
