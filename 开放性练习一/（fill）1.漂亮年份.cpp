#include <iostream>
using namespace std;

int main(){
    int y, one, two, three, four;     //one    - ��ʾ��ݵĸ�λ     two    - ��ʾ��ݵ�ʮλ    three - ��ʾ��ݵİ�λ    four   - ��ʾ��ݵ�ǧλ 
    cin>>y;
    while(1){
        y++;
       // ���������one��two��three��four     
		one = y / 1000;
		two = y / 100 % 10;
		three = y / 10 % 10;
		four = y % 10;
	    if (one == two || one == three || one == four || two == three || two == four || three == four)   //�ж������Ƿ��ظ�
            continue;    // ����ѭ��
        else
            break;     // ��ֹѭ��
    }
    cout<<y<<endl;
    return 0;
}
