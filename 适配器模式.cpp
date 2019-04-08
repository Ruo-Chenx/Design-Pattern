//������ģʽ
#include <iostream>
using namespace std;

class Adaptee{
	public:
		void method(int x)
		{
			cout<<"Adaptee x="<<x<<endl;
		}
};

class AdapterBase{
	public:
		virtual void method() = 0;
		virtual ~ AdapterBase()
		{
			cout<<"AdapterBase �����ĵ���"<<endl;
		}
};

class AdapterA : public AdapterBase{
	public:
		void method()
		{
			cout<<"AdapterA ��method����"<<endl;
		}
}; 


class AdapterB : public AdapterBase{
	private:
		Adaptee * ptea;
	public:
		AdapterB()
		{
			ptea = new Adaptee();
		}
		void method()
		{
			ptea ->method(3);
		}
		~ AdapterB()
		{
			delete ptea;
		}
}; 


int main(void)
{
	AdapterBase *pbase = new AdapterB();
	pbase ->method();
	delete pbase;
	return 0;
} 
