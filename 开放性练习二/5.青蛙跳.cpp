#include<bits/stdc++.h>

using namespace std;

long long n, a, b, k;

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a >> b >> k;
		cout << (k/2)*(a-b)+(k%2)*a << endl;
	}
	return 0;
}

