#include<iostream>

using namespace std;

int main(){

    int t;
    cin>>t;
    
    while(t--){
        long long n;
        cin>>n;
        
        long long ans=0;
        bool check=true;
        
        while(check){
            if(n%4==0 && n!=4){
                ans+=1;
                n-=1;
            }
            else if((n%4!=0 && n%2==0) || (n==4)){
                long long temp1=n/2;
                n/=2;
                ans+=temp1;
            }
            else if(n%2!=0){
                ans+=1;
                n-=1;
            }
            
            if(n==0) check=false;
            
            if(n%4==0 && n!=4){
                n-=1;
            }
            else if((n%4!=0 && n%2==0) || (n==4)){
                n/=2;
            }
            else if(n%2!=0){
                n-=1;
            }
            
            if(n==0) check=false;
        }
        
        cout<<ans<<'\n';
    }
    
    return 0;
}