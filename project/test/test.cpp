#include <melon/logregres.hpp>
#include <iostream>
using namespace melon;
using namespace std;

int main()
{
	Logregres<double> logregres;
	cout<<logregres.test()<<endl;
}
