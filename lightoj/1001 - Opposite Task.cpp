#include<iostream>

using namespace std;


int main(){
    int test,a,i=1;
    cin>>test;
    while(i<=test){
        cin>>a;
        if(a<=10)cout<<a<<" "<<"0"<<endl;
        else cout<<a-10<<" "<<"10"<<endl;
        i++;
    }
return 0;
}
