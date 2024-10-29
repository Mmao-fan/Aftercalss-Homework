#include<bits/stdc++.h>

using namespace std;

long long n;
bool t,f,s;

int main(){
	cin >> n;
	t = !(n % 3);
	f = !(n % 5);
	s = !(n % 7);
	//cout << t<<f<<s;	
	if (!t && !f && !s)
		cout << "null";
	else {
		cout << "It's divisible by ";
		if (t) {
			if (f && s) {
				cout << "3,5,7";
			}else{
				if (f) 
					cout <<"3,5";
				else if (s) 
						cout <<"3,7";
					else 
						cout << '3';
			}			
		}else
			if (f) {
				if (s) {
					cout << "5,7";
				}else{
					cout << '5';
				}	
			}else{
				if (s) cout << '7';
			}
	} 
	return 0;
}

