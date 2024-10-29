#include<bits/stdc++.h>

using namespace std;

string coord;
char a;

int main(){	
	cin>>coord;
	for(char &c : coord){
		switch (c){
			case '(' :
				cout<<'[';
				break;
			case ')' :
				cout<<']'<<'\n';
				break;
			case ',' :
				if (a != ')')
					cout<<c;
				break;
			default:
				cout<<(char)c;
				break;
		}
		a = c;		
	}
	return 0;
}

