#include<bits/stdc++.h>

using namespace std;

int n,x,y,ans;

int main(){
	cin>>n>>x>>y;
	ans=ceil((float)y/x);
	if (n > ans)
		cout<<n-ans;
	else cout<<0;
	return 0;
}

