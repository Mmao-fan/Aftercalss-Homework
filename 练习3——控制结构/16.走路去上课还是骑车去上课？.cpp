#include<bits/stdc++.h>

using namespace std;

double A, B, dis;

int main(){
	cin >> dis;
	B = 50 + dis / 3.0;
	A = dis / 1.2;
	if (B > A){
		cout << "Walk";
	} else {
		if (B == A){
			cout << "All";
		} else {
			cout << "Bike";
		}
	}
	return 0;
}

