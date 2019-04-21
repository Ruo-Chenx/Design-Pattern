//装饰模式1
#include <iostream>
using namespace std;
class Base {
	protected:
		Base *next;
	public:
		virtual void fun() = 0;
		virtual ~ Base()
		{
			cout<<"Base 的析构函数"<<endl;
		}
}; 

class ProductA : public Base {
	public:
		ProductA(Base *t)
		{
			next = t;
		}
		void fun()
		{
			cout<<"ProductA 的方法。"<<endl;
			if(next)
			{
				next -> fun();
			} 
		}
		~ ProductA()
		{
			cout<<"ProductA 的析构"<<endl;
		}
};

class Decorator : public Base {
	public:
		virtual void fun() = 0;
		virtual ~ Decorator()
		{
			cout<<"Decorator 的析构。"<<endl;
		}
};

class DecoratorA : public Decorator {
	public:
		DecoratorA(Base *t)
		{
			next = t;
		}
		void fun()
		{
			cout<<"DecoratorA 的方法。"<<endl;
			if(next)
				next -> fun();
		}
		~ DecoratorA()
		{
			cout<<"DecoratorA 的析构。"<<endl;
		}
}; 

class DecoratorB : public Decorator {
	public:
		DecoratorB(Base *t)
		{
			next = t;
		}
		void fun()
		{
			cout<<"DecoratorB 的方法。"<<endl;
			if(next)
				next -> fun();
		}
		~ DecoratorB()
		{
			cout<<"DecoratorB 的析构。"<<endl;
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

