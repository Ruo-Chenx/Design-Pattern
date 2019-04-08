//抽象工厂模式 
#include <iostream>
using namespace std;

class Product{
	public:
		virtual void Do() = 0;
		Product()
		{
			cout<<"Product的构造"<<endl;
		}
		~ Product()
		{
			cout<<"Product的析构"<<endl;
		}
};

class ProductA : public Product{
	public:
		ProductA()
		{
			cout<<"ProductA的构造"<<endl;
		}
		void Do()
		{
			cout<<"这是ProductA  Do的方法"<<endl;
		}
		~ ProductA()
		{
			cout<<"ProductA的析构"<<endl;
		}
};

class ProductB : public Product{
	public:
		ProductB()
		{
			cout<<"ProductA的构造"<<endl;
		}
		void Do()
		{
			cout<<"这是ProductB  Do的方法"<<endl;
		}
};

class ProductC : public Product{
	public:
		ProductC()
		{
			cout<<"ProductA的构造"<<endl;
		}
		void Do()
		{
			cout<<"这是ProductC Do的方法"<<endl;
		}
};

class Factory{
	protected:
		Product *product; 
	public:
		virtual void Send() = 0;
		Factory()
		{
			cout<<"Factory构造的调用"<<endl;
		}
		virtual ~ Factory() 
		{
			//delete product; 
			cout<<"Factory析构的调用"<<endl;
		}
};

class FactoryA : public Factory{
	public:
		FactoryA(Product *t)
		{
			product = t;
			cout<<"FactoryA构造的调用"<<endl;
		}
		void Send()
		{
			product -> Do();
		}
		~ FactoryA() 
		{
			cout<<"FactoryA析构的调用"<<endl;
		}
}; 

class FactoryB : public Factory{
	public:
		FactoryB(Product *t)
		{
			product = t;
			cout<<"FactoryB构造的调用"<<endl;
		}
		void Send()
		{
			product -> Do();
		}
}; 

class FactoryC : public Factory{
	public:
		FactoryC(Product *t)
		{
			product = t;
			cout<<"FactoryC构造的调用"<<endl;
		}
		void Send()
		{
			product -> Do();
		}
};

int main(void)
{
	Factory *factory = new FactoryA(new ProductA());
	factory -> Send();
	delete factory; 
	return 0 ;
} 
