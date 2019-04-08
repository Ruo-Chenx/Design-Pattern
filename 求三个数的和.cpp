//求三个数的和
#include <iostream>
using namespace std;

class My{
	private:
		int x;
		static int sum;
	public:
		My(){
			cout<<"My的无参构造"<<endl; 
		}
		My(int x)
		{
			this->x = x;
			cout<<"My的有参构造"<<endl;
		} 
		static void AddPrint(My t1, My t2, My t3)
		{
			sum = t1.x+t2.x+t3.x;
			cout<<"sum="<<sum<<endl;
		}
}; 
int My::sum = 0;

int main(void)
{
	My my1(3);
	My my2(4);
	My *p1 = new My(7);
	My::AddPrint(my1, my2, *p1);
	return 0;
}
