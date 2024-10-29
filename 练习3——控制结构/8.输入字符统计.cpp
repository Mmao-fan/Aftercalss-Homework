#include<bits/stdc++.h>

using namespace std;

int n, A, a, num, sum, other;
char c;

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> c;
		if ('A' <= c && c <= 'Z') A++;
		else if ('a' <= c && c <= 'z') a++;
			else if ('0' <= c && c <= '9') {
					num++;
					sum += c - '0';	
				}else
					other++;
	}
	cout << A << ' ' << a << ' ' << num << ' ' << other;
	if (num) cout << endl << sum; 
	return 0;
}

