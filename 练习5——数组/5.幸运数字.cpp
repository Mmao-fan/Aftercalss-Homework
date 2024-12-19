#include<bits/stdc++.h>

using namespace std;

int n, a, sum;

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a;
		if (a % 4 == 0 || a % 7 == 0){
			sum += a;
		}
	}
	cout << sum;
	return 0;
}

