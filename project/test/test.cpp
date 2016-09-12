#include <iostream>
#include <vector>
#include <melon/log_neuron.hpp>
#include <string>
#include <melon/mat.hpp>
#include <melon/vec.hpp>
#include <melon/reader.hpp>
#include <utils/timer.hpp>
#include <boost/shared_ptr.hpp>
#include <melon/linear_neuron.hpp>
using namespace melon;
using namespace std;
void testMatAndVec()
{
	Matrix<double> mat(3,2) ;
	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[1][0] = 3;
	mat[1][1] = 4;
	mat[2][0] = 5;
	mat[2][1] = 6;
	mat.print(cout);
	cout<<"mat transpose"<<endl;
	mat.transpose().print(cout);
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

void testLogNeuron()
{
	//Timer t(Timer::AUTO);
	//boost::progress_timer t;
	Reader<double,double> reader("/Users/Zoson/Desktop/ml/Ch05/testSet.txt");
	Matrix<double> mat;
	Vector<double> label;
	reader.getAll(mat,label);
	LogNeuron log;
	log.initSpec(mat.getCol());
	for(int i=0;i<500;++i)
	{
		try{
			Vector<double> outs = log.forward(&mat);
			Vector<double> loss = log.backward(&label);
			log.updateWeight();
		}catch(...)
		{
			cout<<"cat"<<endl;
		}
		
	}
	log.print(cout);
}

void testLinearNeuron()
{
	Reader<double,double> reader("/Users/Zoson/Desktop/ml/Ch08/ex1.txt");
	Matrix<double> mat;
	Vector<double> label;
	reader.getAll(mat,label);
	LinearNeuron lin;
	lin.initSpec(mat.getCol());
	for(int i=0;i<500;++i)
	{
		try{
			Vector<double> outs = lin.forward(&mat);
			Vector<double> loss = lin.backward(&label);
			lin.updateWeight();
		}catch(...)
		{
			cout<<"cat"<<endl;
		}
		
	}
	lin.print(cout);
}

int main()
{
	//testMatAndVec();
	//testReader();
	//testLogNeuron();
	testLinearNeuron();
}
