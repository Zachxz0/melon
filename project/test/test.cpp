#include <iostream>
using namespace std;
#include <vector>
#include <melon/mat.hpp>
#include <melon/vec.hpp>
using namespace melon;
#include <boost/shared_ptr.hpp>
void test()
{
	Matrix<double> mat(2,2) ;
	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[1][0] = 3;
	mat[1][1] = 4;
	mat.print(cout);
	Vector<double> vec(2);
	vec[0] = 2;
	vec[1] = 3; 
	vec.print(cout);
    Vector<double> vec2 = mat*vec;
    vec2.print(cout);
}
int main()
{
	test();
}
