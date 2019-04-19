//声明triangle函数
#include<iostream>
#include<math.h>
using namespace std;
class Triangle{
	private:
		int a,b,c;
	public:
		Triangle()
		{
			a=1;
			b=1;
			c=1;
		}
		Triangle(int i,int j,int k)
		{
			a=i;
			b=j;
			c=k;
		}
	int judge()
	{
		int i=0;
		if(a+b>c&&a+c>b&&b+c>a)
			i=1;
		return i;
	}
	double area()
	{
		double s;
		s=(a+b+c)/2;
		return sqrt(s*(s-a)*(s-b)*(s-c));
	}
}; 
int main(void)
{
	int a,b,c,x,y;
	cout<<"请输入三角形三边长"<<endl;
	cin>>a>>b>>c;
	Triangle tri(a,b,c);
	if(tri.judge())
		cout<<"area="<<tri.area()<<endl;
	else
		cout<<"不能构成三角形"<<endl;
}
