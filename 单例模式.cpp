//����ģʽ
#include <iostream>
using namespace std;

class Singleton{
	private:
		static Singleton * instance;
		Singleton(){
			cout<<"Singleton ����"<<endl;
		}
	public:
		static Singleton * Create(){
			if(!instance)
			{
				instance = new Singleton();
			}
			return instance;
		}
}; 
Singleton * Singleton::instance = NULL;

int main(void)
{
	Singleton *p;
	p = Singleton::Create();
	return 0;
}
