//װ��ģʽ2
#include <iostream>
using namespace std;
class Base {
	protected:
		Base *next;
	public:
		Base(Base *t)
		{
			next = t; 
		}
		
		virtual void fun() = 0;
		virtual ~ Base()
		{
			cout<<"Base ����������"<<endl;
		}
}; 

class ProductA : public Base {
	public:
		ProductA(Base *t) : Base(t) 
		{
			
		}
		
		void fun()
		{
			cout<<"ProductA �ķ�����"<<endl;
			if(next)
			{
				next -> fun();
			} 
		}
		~ ProductA()
		{
			cout<<"ProductA ������"<<endl;
		}
};

class Decorator : public Base {
	public:
		Decorator(Base *t) : Base(t)
		{
			
		}
		
		virtual void fun() = 0;
		virtual ~ Decorator()
		{
			cout<<"Decorator ��������"<<endl;
		}
};

class DecoratorA : public Decorator {
	public:
		DecoratorA(Base *t) : Decorator(t)
		{
			
		}
		
		void fun()
		{
			cout<<"DecoratorA �ķ�����"<<endl;
			if(next)
				next -> fun();
		}
		~ DecoratorA()
		{
			cout<<"DecoratorA ��������"<<endl;
		}
}; 

class DecoratorB : public Decorator {
	public:
		DecoratorB(Base *t) : Decorator(t)
		{
			
		}
		
		void fun()
		{
			cout<<"DecoratorB �ķ�����"<<endl;
			if(next)
				next -> fun();
		}
		~ DecoratorB()
		{
			cout<<"DecoratorB ��������"<<endl;
		}
}; 

int main(void)
{
	DecoratorB *pdb = new DecoratorB(NULL);
	DecoratorA *pda = new DecoratorA(pdb);
	Base *head = new ProductA(pda);
	
	head -> fun();
	
	delete pdb;
	delete pda;
	delete head;
	return 0;
}

