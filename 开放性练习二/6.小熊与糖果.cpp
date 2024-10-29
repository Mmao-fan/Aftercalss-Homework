#include<bits/stdc++.h>

using namespace std;

long long A, B, a, b, T;

int main(){
	cin >> T;
	for (int i = 1; i <= T; i++){
		cin >> A >> B;
		if (B < 2){
			cout << "Limak";
			continue;
		}
		a = (int)sqrt(A);
		b = (int)sqrt(B);
		if (b*(b+1) > B) b--;
		if (a <= b) {
			cout << "Bob\n";
		}else {
			cout << "Limak\n";
		}
	}
	return 0;
}

