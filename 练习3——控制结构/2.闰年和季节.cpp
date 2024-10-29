#include<bits/stdc++.h>

using namespace std;

int yy, mm;

int main(){
	cin >> yy >> mm;
	if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0){
		cout << "Leap year,";
	} else{
		cout << "Common year,";
	}
	switch (mm){
		case 3:
		case 4:
		case 5:
			cout << "Spring";
			break;
		case 6:
		case 7:
		case 8:
			cout << "Summer";
			break;
		case 9:
		case 10:
		case 11:
			cout << "Fall";
			break;
		case 12:
		case 1:
		case 2:
			cout << "Winter";
			break;
		default:
		break; 
	}
	return 0;
}

