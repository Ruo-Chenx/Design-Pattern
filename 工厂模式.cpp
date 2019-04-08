//����ģʽ(�ͻ����˵�ѹ����)
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
			cout<<"����ProductA  Do�ķ���"<<endl;
		}
};

class ProductB : public Product{
	public:
		void Do()
		{
			cout<<"����ProductB  Do�ķ���"<<endl;
		}
};

class ProductC : public Product{
	public:
		void Do()
		{
			cout<<"����ProductC Do�ķ���"<<endl;
		}
};

class Factory{
	private:
		Product *product;
	public:
		Factory(Product *t)
		{
			product = t;
			cout<<"����ĵ���"<<endl;
		}
		void Send()
		{
			product -> Do();
		}
		
		~Factory()
		{
			cout<<"�����ĵ���"<<endl;
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
