//����ģʽ
#include <iostream>
using namespace std;

class Base{
	public:
		Base(){
			cout<<"Base �Ĺ���"<<endl;
		}
		virtual void method() = 0;
		virtual ~ Base(){
			cout<<"Base ������"<<endl;
		}
};

class Source : public Base{
	public:
		Source() {
			cout<<"Source �Ĺ���"<<endl;
		}
		void method()
		{
			cout<<"Source ��method����"<<endl;
		}
		~ Source() {
			cout<<"Source ������"<<endl;
		}
}; 

class Proxy : public Base{
	private:
		Base *pb;
	public:
		Proxy (Base *t) {
			pb = t;
			cout<<"Proxy �Ĺ���"<<endl; 
		}
		void method() 
		{
			pb -> method(); 
		} 
		~ Proxy() {
			
			cout<<"Proxy ������"<<endl;
		}
}; 

int main(void) 
{
	Source *ps = new Source();
	Proxy *pp = new Proxy(ps);
	
	pp ->method();
	delete ps;
	delete pp;
	return 0;
}
