//简单工厂(违背了开闭原则)
#include <iostream>
using namespace std;

class Product{
	public:
		virtual void Do() = 0;
};

class ProductA : public Product{
	public:
		void Do()
		{
			cout<<"这是ProductA  Do的方法"<<endl;
		}
};

class ProductB : public Product{
	public:
		void Do()
		{
			cout<<"这是ProductB  Do的方法"<<endl;
		}
};

class ProductC : public Product{
	public:
		void Do()
		{
			cout<<"这是ProductC Do的方法"<<endl;
		}
};

class Factory{
	private:
		Product *product;
	public:
		Factory(int n)
		{
			switch(n)
			{
				case 1:
					product = new ProductA();
					break;
				case 2:
					product = new ProductB();
					break;
				case 3:
					product = new ProductC();
					break;
			}
			cout<<"构造的调用"<<endl;
		}
		void Send()
		{
			product -> Do();
		}
		
		~Factory()
		{
			cout<<"析构的调用"<<endl;
			delete product;
		}
};

int main(void)
{
	Factory *factory = new Factory(2);
	factory -> Send();
	delete factory; 
	return 0 ;
} 
