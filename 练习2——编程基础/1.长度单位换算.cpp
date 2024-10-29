#include<bits/stdc++.h>

using namespace std;

long long in,ft,yd,mi;

int main(){
	cin>>in;
	ft = in/12; in %= 12;
	yd = ft/3; ft %= 3;
	mi = yd/1760; yd %= 1760;
	if (mi != 0)
		cout<<mi<<" mi ";
	if (yd != 0)
		cout<<yd<<" yd ";
	if (ft != 0)
		cout<<ft<<" ft ";
	if (in != 0)
		cout<<in<<" in ";
	return 0;
}

