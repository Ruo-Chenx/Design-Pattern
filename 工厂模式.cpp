//工厂模式(客户发端的压力大)
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
		Factory(Product *t)
		{
			product = t;
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
	Factory *factory = new Factory(new ProductB());
	factory -> Send();
	delete factory; 
	return 0 ;
} 
