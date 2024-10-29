#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
	cin >> n;
	if (n > 89)
		cout << 'A';
	else if (n >79)
			cout << 'B';
		else if (n > 69)
				cout << 'C';
			else if (n > 59)
					cout << 'D';
				else 
					cout << 'E';
	return 0;
}

