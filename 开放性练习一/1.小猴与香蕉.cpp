#include<bits/stdc++.h>

using namespace std;

long long k, n, w;

int main(){
	cin >> k >> n >> w;
	k *= w*(w+1)/2;
	if (k > n) cout << k-n;
		else cout << 0; 
	return 0;
}
