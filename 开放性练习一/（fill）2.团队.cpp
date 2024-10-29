#include <iostream>
using namespace std;

int main(){
    unsigned int n, cnt=0;
    cin>>n;  
    short a, b, c;
    while(n--){
        cin>>a>>b>>c;     // ÊäÈëÃ¿ÐÐ
        if (a+b+c >= 2) cnt++;
    }   
    cout<<cnt<<endl;
    return 0;
}
