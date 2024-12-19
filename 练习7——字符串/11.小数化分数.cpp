#include <bits/stdc++.h>
#include <iostream>

using namespace std;

char c;

long long gcd(long long a, long long b){
	long long r=1;
	if (a < b) swap(a, b);
	while(r){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int T;
//	cout <<gcd(20,25);
	cin >> T;
	cin.ignore();
	for(int k = 1; k <= T; k++) {
		bool b=0;
		string nre="", re="";
		getchar(),getchar();
		while(1) {
			c = getchar();
			if(c == '\n') break;
			if(c == ')'){
				getchar();
				break;
			}
			if(c == '(') {
				b=1;
				continue;
			}
			if(b) {
				re += c;
			} else {
				nre += c;
			}
		}
//		cout << nre<<re;
		long long fz, fm, g;
		if(re.empty()) {
			fz = stoll(nre);
			fm = pow(10,nre.size());
		} else {
			fz = stoll(nre + re);
			if(!nre.empty()) {
				fz -= stoll(nre);
			}
			string sfm="";
			for(int i = 1; i <= re.size(); i++) {
				sfm += '9';
			}
			for(int i = 1; i <= nre.size(); i++) {
				sfm += '0';
			}
			fm = stoll(sfm);
		}
		g = gcd(fz, fm);
		cout << fz/g << '/' << fm/g << endl;
	}
	return 0;
}

