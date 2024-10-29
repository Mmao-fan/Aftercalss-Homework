#include <iostream>
using namespace std;

int main(){
    int y, one, two, three, four;     //one    - 表示年份的个位     two    - 表示年份的十位    three - 表示年份的百位    four   - 表示年份的千位 
    cin>>y;
    while(1){
        y++;
       // 以下语句求one、two、three、four     
		one = y / 1000;
		two = y / 100 % 10;
		three = y / 10 % 10;
		four = y % 10;
	    if (one == two || one == three || one == four || two == three || two == four || three == four)   //判断数字是否重复
            continue;    // 继续循环
        else
            break;     // 终止循环
    }
    cout<<y<<endl;
    return 0;
}
