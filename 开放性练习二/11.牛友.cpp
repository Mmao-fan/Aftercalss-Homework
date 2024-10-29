#include<bits/stdc++.h>

using namespace std;

int n, sum1, sum2;

int main(){
	cin >> n;
	do{
		sum1 = sum2 = 1;
		for (int i = 2; i <= sqrt(n); i++){
			if (n % i == 0) sum1 += i + n/i;
		}
		for (int i = 2; i <= sqrt(sum1); i++){
			if (sum1 % i == 0) sum2 += i + sum1/i;
		}
		if (sum2 == n) break;
	}while (n++);
	cout << n << ' ' << sum1;
	return 0;
}

