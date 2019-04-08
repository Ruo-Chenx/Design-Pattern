//创建链表
#include <iostream>
using namespace std;

class A{
	private :
		int data;
		A *next;
	public :
		A()
		{
			data=0;
		} 
		A(int data)
		{
			this->data=data;
		}
		void set(A *t)
		{
			this->next=t;
		}
		void Print()
		{
			A *p;
			for(p=this;p;p=p->next)
			{
				cout<<p->data<<endl;
			} 
		}
		~A()
		{
			cout<<"Des"<<endl;
		} 
};

int main(void)
{
	int i,x;
	A *p,*h=NULL;
	for(i=0;i<4;i++)
	{
		cout<<"请输入链表的"<<i+1<<"个结点:";
		cin>>x;
		p=new A(x);
		p->set(h);
		h=p;
	} 
	h->Print();
	return 0;
} 
