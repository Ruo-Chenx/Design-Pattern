//���󹤳�ģʽ 
#include <iostream>
using namespace std;

class Product{
	public:
		virtual void Do() = 0;
		Product()
		{
			cout<<"Product�Ĺ���"<<endl;
		}
		~ Product()
		{
			cout<<"Product������"<<endl;
		}
};

class ProductA : public Product{
	public:
		ProductA()
		{
			cout<<"ProductA�Ĺ���"<<endl;
		}
		void Do()
		{
			cout<<"����ProductA  Do�ķ���"<<endl;
		}
		~ ProductA()
		{
			cout<<"ProductA������"<<endl;
		}
};

class ProductB : public Product{
	public:
		ProductB()
		{
			cout<<"ProductA�Ĺ���"<<endl;
		}
		void Do()
		{
			cout<<"����ProductB  Do�ķ���"<<endl;
		}
};

class ProductC : public Product{
	public:
		ProductC()
		{
			cout<<"ProductA�Ĺ���"<<endl;
		}
		void Do()
		{
			cout<<"����ProductC Do�ķ���"<<endl;
		}
};

class Factory{
	protected:
		Product *product; 
	public:
		virtual void Send() = 0;
		Factory()
		{
			cout<<"Factory����ĵ���"<<endl;
		}
		virtual ~ Factory() 
		{
			//delete product; 
			cout<<"Factory�����ĵ���"<<endl;
		}
};

class FactoryA : public Factory{
	public:
		FactoryA(Product *t)
		{
			product = t;
			cout<<"FactoryA����ĵ���"<<endl;
		}
		void Send()
		{
			product -> Do();
		}
		~ FactoryA() 
		{
			cout<<"FactoryA�����ĵ���"<<endl;
		}
}; 

class FactoryB : public Factory{
	public:
		FactoryB(Product *t)
		{
			product = t;
			cout<<"FactoryB����ĵ���"<<endl;
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
			cout<<"FactoryC����ĵ���"<<endl;
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
