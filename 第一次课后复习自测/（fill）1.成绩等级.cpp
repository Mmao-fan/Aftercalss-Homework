#include<bits/stdc++.h>
#include <iostream>          //包含输入输出头文件
using namespace std;         //使用标准命名空间

int main(){
    int a;
    cin>>a;  
    if(a<0||a>100) {
        cout<<"This is not a valid number"<<endl;
        return 0;        
    } 
    switch(a/10){       
		case 6:
			cout << 'D';
			break;
		case 7:
			cout << 'C';
			break;
		case 8:
			cout << 'B';
			break;
		case 9:
			cout << 'A';
			break;
		case 10:
			cout << 'S';
			break;
        default: cout <<"E"<<endl;
    }
    return 0; 
}
