#include<iostream>
using namespace std;

int main(){
   int a,b,Multi=1;
   cout<<"Enter a number: ";
   cin>>a;
   while(a!=0){
        b=a%10;
        Multi*=b;
        a/=10;
   }
   cout<<"Multiplication: "<<Multi<<endl;
}