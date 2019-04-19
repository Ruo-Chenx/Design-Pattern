//桥接模式4
#include <iostream>
using namespace std;
class AbstractionImp {
	public:
		virtual void Operation() = 0;
		virtual ~ AbstractionImp()
		{
			cout<<"Abstraction 的析构"<<endl;
		}
};

class ConcreteA : public AbstractionImp {
	public:
		void Operation()
		{
			cout<<"ConcreteA 的Operation"<<endl;
		}
		~ ConcreteA()
		{
			cout<<"ConcreateA 的析构"<<endl;
		}
};

class ConcreteB : public AbstractionImp {
	public:
		void Operation()
		{
			cout<<"ConcreteB 的Operation"<<endl;
		}
		~ ConcreteB()
		{
			cout<<"ConcreteB 的析构"<<endl;
		}
};

class Abstraction {
	private:
		AbstractionImp *pb;
	public:
		Abstraction(AbstractionImp *t)
		{
			pb = t;
		}
		virtual void Operation() 
		{
			pb -> Operation();
		}
		virtual ~ Abstraction()
		{
			cout<<"Abstraction 的析构"<<endl;
		}
};

class DefinedAbstractionA : public Abstraction {
	public:
		DefinedAbstractionA(AbstractionImp *t) : Abstraction(t)
		{
			
		}

		~ DefinedAbstractionA()
		{
			cout<<"DefinedAbstractionA 的析构"<<endl;
		}
};

class DefinedAbstractionB : public Abstraction {
	public:
		DefinedAbstractionB(AbstractionImp *t) : Abstraction(t)
		{
			
		}

		~ DefinedAbstractionB()
		{
			cout<<"DefinedAbstractionB 的析构"<<endl;
		}
};

int main(void)
{
	ConcreteB *b = new ConcreteB();
	Abstraction *pa = new DefinedAbstractionA(b);
	pa -> Operation();
	delete b;
	delete pa;
	return 0;
}












