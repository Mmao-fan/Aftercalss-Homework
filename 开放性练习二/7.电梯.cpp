#include<bits/stdc++.h>

using namespace std;

int n, a, b;
long long t;

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> b;
		t += (b-a) * (b > a?6:-4);
		a = b;
	}
	cout << t + 5*n;
	return 0;
}

