#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,h[200010],x[200010];
vector<pair<int,int>>v; 
bool check(int t){
	v.clear();
	for(int i=1;i<=n;i++){
		int val=(h[i]+t-1)/t;
		if(val<=m){
			v.push_back({x[i]-m+val,1});
			v.push_back({x[i]+m-val+1,-1});
		}
	}
	sort(v.begin(),v.end());
	int sum=0;
	for(auto i:v){
        cout << i.first << " " << i.second << endl;
		sum+=i.second;
		if(sum>=k)return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++){
			cin>>h[i];
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int l=1,r=1e9,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
            cout << mid << endl;
			if(check(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		if(ans==0)cout<<"-1\n";
		else cout<<ans<<"\n";
	}
}