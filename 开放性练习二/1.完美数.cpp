#include<bits/stdc++.h>

using namespace std;

long long n, a;

int main(){
	cin >> n;
	a = 1;
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0){
			a += i + n / i;
		}
	}
	if (n == a) cout << "true";
		else cout << "false";
	return 0;
}

