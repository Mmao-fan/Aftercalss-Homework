#include<bits/stdc++.h>

using namespace std;

string result;
int a, b, n, rem;

int main(){
	cin >> a >> b >> n;//b!=0 && 1<=n <=200
	//high_precision_division(a, b, n);
	result = to_string(a/b) + '.';
	rem = a % b;
	for (int i = 1; i <= n; i++){
		rem *= 10;
		result += to_string(rem/b);
		rem %= b;
		if (rem == 0){
			for (int j = i; j <= n; j++){
				result += '0';
			}
			break;
		}
	}
	cout << result;
	return 0;
}

