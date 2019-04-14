//�Ž�ģʽ1
#include <iostream>
using namespace std;
class AbstractionImp {
	public:
		virtual void Operation() = 0;
		virtual ~ AbstractionImp()
		{
			cout<<"Abstraction ������"<<endl;
		}
};

class ConcreteA : public AbstractionImp {
	public:
		void Operation()
		{
			cout<<"ConcreteA ��Operation"<<endl;
		}
		~ ConcreteA()
		{
			cout<<"ConcreateA ������"<<endl;
		}
};

class ConcreteB : public AbstractionImp {
	public:
		void Operation()
		{
			cout<<"ConcreteB ��Operation"<<endl;
		}
		~ ConcreteB()
		{
			cout<<"ConcreteB ������"<<endl;
		}
};

class Abstraction {
	protected:
		AbstractionImp *pb;
	public:
		virtual void Operation() = 0;
		virtual ~ Abstraction()
		{
			cout<<"Abstraction ������"<<endl;
		}
};

class DefinedAbstractionA : public Abstraction {
	public:
		DefinedAbstractionA(AbstractionImp *t)
		{
			pb = t;
		} 
		void Operation()
		{
			pb -> Operation();
		}
		~ DefinedAbstractionA()
		{
			cout<<"DefinedAbstractionA ������"<<endl;
		}
};

class DefinedAbstractionB : public Abstraction {
	public:
		DefinedAbstractionB(AbstractionImp *t)
		{
			pb = t;
		} 
		void Operation()
		{
			pb -> Operation();
		}
		~ DefinedAbstractionB()
		{
			cout<<"DefinedAbstractionB ������"<<endl;
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












