#include <iostream>
#include <vector>
#include <string>
#include <melon/mat.hpp>
#include <melon/vec.hpp>
#include <melon/reader.hpp>
#include <boost/shared_ptr.hpp>
using namespace melon;
using namespace std;
void testMatAndVec()
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

void testReader()
{
	Reader<double,int> reader("/Users/Zoson/Desktop/ml/Ch05/testSet.txt");
	Matrix<double> mat;
	Vector<int> vec;
	reader.getAll(mat,vec);
	mat.print(cout);
	vec.print(cout);
}
int main()
{
	//testMatAndVec();
	testReader();
}
