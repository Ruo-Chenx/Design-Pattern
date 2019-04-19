//�Ž�ģʽ4
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
			cout<<"Abstraction ������"<<endl;
		}
};

class DefinedAbstractionA : public Abstraction {
	public:
		DefinedAbstractionA(AbstractionImp *t) : Abstraction(t)
		{
			
		}

		~ DefinedAbstractionA()
		{
			cout<<"DefinedAbstractionA ������"<<endl;
		}
};

class DefinedAbstractionB : public Abstraction {
	public:
		DefinedAbstractionB(AbstractionImp *t) : Abstraction(t)
		{
			
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












