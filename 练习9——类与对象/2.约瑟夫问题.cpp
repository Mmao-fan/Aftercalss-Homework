/*
������������
        n ���ˣ���Ŵ�1~n��Χ��һȦ���ӵ� k ���˿�ʼ���������� m ���˳�Ȧ��Ȼ�������δ���е���һ���˿�ʼ���������� m ���˳�Ȧ���ظ��������̣�ֱ��Ȧ�н�ʣ��һ�ˡ�
��������ʽ��
        ����Ϊһ��������������n��k��m��
�������ʽ��
        ���Ϊһ������������ʾ���ʣ�µ��˵ı�š�
���������롿
100 1 5
�����������
47
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class person {
	private:
		int no;      /* �˵ı�� */
		person *next;   /* ָ�����ڵ���һ���� */
	public:
		person(int num) {
			no=num;
			next=NULL;
		}
		void setNext(person *p) {
			next=p;
		}
		int getNo() {
			return no;
		}
		person *getNext() {
			return next;
		}
};

class cycle {
	private:
		person *start;    /* ��ʼ������λ�� */
		int out;          /* ���������� */
		int inQueue;      /* �������������� */
	public:
		cycle(int num, int from, int whoOut) {
			inQueue=num, out=whoOut;
			person *prv=NULL, *first=NULL;
			for(int i=1; i<=num; i++) {
				person *p=new person(i);
				if (i==1)
					first=p;
				if (i==from)
					start=p;
				if (i>1)
					prv->setNext(p);
				prv=p;
			}
			prv->setNext(first);
		}
		int getInQueue() {
			return inQueue;
		}
		void cnt() { /* ������ĿҪ��������ȷ�����е��ˣ������˴�Ȧ���޳� */
			person *current = start;
			person *prv = NULL;
//			while (inQueue > 1) {
				for (int i = 2; i < out; i++) {
					current = current->getNext();
				}
				prv = current;
//				cout << current->getNo()<<start->getNo()<<endl;
//				cout << current->getNext()<<start->getNext()<<endl<<endl;
				inQueue--;
				if (out == 1) {
					prv->setNext(current->getNext());
					start = prv->getNext();
				}else{
					current = current->getNext();
//					cout << current->getNo()<<endl;
					prv->setNext(current->getNext());
					start = current->getNext();
				}
//			}
			
			
//			for (int i = 2; i <= out; i++) {
//				prv = current;
//				current = current->getNext();
//			}
//			cout << current->getNo()<<endl;
//			prv->setNext(current->getNext());
//			inQueue--;
//			if (current == start) {
//				start = prv->getNext();
//			}else{
//				start = current->getNext();
//			}
////			delete current;
		}
		person *getStart() {
			return start;
		}
		~cycle() {
			delete start;
		}
};
int main() {
	int n,k, m ;   /* n Ȧ������  k ��ʼ���� m �������� */
	cin>>n>>k>>m;
	cycle *p=new cycle(n,k,m);
	while(p->getInQueue()>1)
		p->cnt();
	person *winer=p->getStart();
	cout<<winer->getNo()<<endl;
	delete p;
	return 0;
}
