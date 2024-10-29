#include<bits/stdc++.h>

using namespace std;



int main(){
	int n;
	cin >> n;
	int t = floor(sqrt(2*n));
	while (t*(t+1)>2*n)t--;
	cout << (int)((t+1)*(n-t*(t+2)/6.0));
	return 0;
}

