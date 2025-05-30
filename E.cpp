#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

int main(){

    int n,p;
    long long t1,t2;
    cin>>n>>p>>t1>>t2;
    
    vector<long long> d(n);
    for(long long &x:d) cin>>x;
    
    vector<pair<long long,long long>> danger;
    
    for(int i=0;i<p;++i){
        long long x,y;
        cin>>x>>y;
        for(int j=0;j<n;++j){
            long long l=x-d[j];
            long long r=y-d[j];
            l=max(l,t1);
            r=min(r,t2);
            if(l<r){
                danger.push_back(make_pair(l,r));
            }
        }
    }
    
    sort(danger.begin(),danger.end());
    vector<pair<long long,long long>> merged;
    
    for(size_t i=0;i<danger.size();++i){
        long long l=danger[i].first;
        long long r=danger[i].second;
        if(merged.empty() || merged.back().second<l){
            merged.push_back(make_pair(l,r));
        }
        else{
            merged.back().second=max(merged.back().second,r);
        }
    }
    
    long long dangerTime=0;
    for(size_t i=0;i<merged.size();++i){
        dangerTime+=merged[i].second-merged[i].first;
    }
    
    long double total=t2-t1;
    long double safeTime=total-dangerTime;
    long double probability=safeTime/total;
    
    cout<<fixed<<setprecision(10)<<probability<<"\n";
    
    return 0;
}