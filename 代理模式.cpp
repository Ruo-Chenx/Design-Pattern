//代理模式
#include <iostream>
using namespace std;

class Base{
	public:
		Base(){
			cout<<"Base 的构造"<<endl;
		}
		virtual void method() = 0;
		virtual ~ Base(){
			cout<<"Base 的析构"<<endl;
		}
};

class Source : public Base{
	public:
		Source() {
			cout<<"Source 的构造"<<endl;
		}
		void method()
		{
			cout<<"Source 的method方法"<<endl;
		}
		~ Source() {
			cout<<"Source 的析构"<<endl;
		}
}; 

class Proxy : public Base{
	private:
		Base *pb;
	public:
		Proxy (Base *t) {
			pb = t;
			cout<<"Proxy 的构造"<<endl; 
		}
		void method() 
		{
			pb -> method(); 
		} 
		~ Proxy() {
			
			cout<<"Proxy 的析构"<<endl;
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
