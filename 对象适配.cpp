//适配器模式(对象适配) 
#include <iostream>
using namespace std;

class Adaptee{
	public:
		void AdapteePro()
		{
			cout<<"AdapteePro的方法"<<endl;
		}
};

/*class Adapter{
	private:
		//子对象实现 
		Adaptee objAdaptee;
	public:
		void AdapterPro()
		{
			objAdaptee.AdapteePro();
		}
};*/

class Adapter{
	private:
		Adaptee * pAdaptee;
	public:
		Adapter()
		{
			pAdaptee = new Adaptee();
		}
		void AdapterPro()
		{
			pAdaptee -> AdapteePro();
		}
		~ Adapter()
		{
			delete pAdaptee;
		}
}; 

int main(void)
{
	/*Adapter objAdapter;
	objAdapter.AdapterPro(); */
	Adapter *pAdapter = new Adapter();
	pAdapter -> AdapterPro();
	delete pAdapter;
	return 0;
} 
