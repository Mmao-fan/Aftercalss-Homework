#include<bits/stdc++.h>

using namespace std;

char c;

int main(){
	cin >> c;
	if (islower(c)) cout << (char)toupper(c);
		else cout <<(char)tolower(c);
	return 0;
}
