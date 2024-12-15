/*
【问题描述】
        n 个人（编号从1~n）围成一圈，从第 k 个人开始数数，数到 m 的人出圈，然后继续从未出列的下一个人开始数数，数到 m 的人出圈，重复上述过程，直到圈中仅剩下一人。
【输入形式】
        输入为一行三个正整数，n、k、m。
【输出形式】
        输出为一个正整数，表示最后剩下的人的编号。
【样例输入】
100 1 5
【样例输出】
47
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class person {
	private:
		int no;      /* 人的编号 */
		person *next;   /* 指向相邻的下一个人 */
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
		person *start;    /* 开始数数的位置 */
		int out;          /* 数到几出列 */
		int inQueue;      /* 队伍中现有人数 */
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
		void cnt() { /* 根据题目要求数数，确定出列的人，将该人从圈中剔除 */
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
	int n,k, m ;   /* n 圈内人数  k 开始数数 m 可数出列 */
	cin>>n>>k>>m;
	cycle *p=new cycle(n,k,m);
	while(p->getInQueue()>1)
		p->cnt();
	person *winer=p->getStart();
	cout<<winer->getNo()<<endl;
	delete p;
	return 0;
}
