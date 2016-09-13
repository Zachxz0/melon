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
#include <melon/layer.hpp>
#include <melon/stump_neuron.hpp>
#include <zoson/object.hpp>
#include <thread>
using namespace boost;
using namespace melon;
using namespace std;
void change(Vector<double> * vec)
{
	(*vec)[0] = 1.22;
	(*vec)[1] = 23.22;
}

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

	Vector<double>* vec = new Vector<double>(3,1);
	change(vec);
	vec->print(cout);
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
	mat.insertCol();
	LogNeuron log;
	log.initSpec(mat.getCol());
	for(int i=0;i<500;++i)
	{
		try{
			Vector<double>* outs = log.forward(&mat);
			Vector<double>* loss = log.backward(&label);
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
			Vector<double>* outs = lin.forward(&mat);
			Vector<double>* loss = lin.backward(&label);
			lin.updateWeight();
		}catch(...)
		{
			cout<<"cat"<<endl;
		}
		
	}
	lin.print(cout);
}


void testLayer()
{
	Reader<double,double> reader("/Users/Zoson/Desktop/ml/Ch08/ex1.txt");
	Matrix<double> mat;
	Vector<double> label;
	reader.getAll(mat,label);
	Layer layer ;
	LinearNeuron *lin = new LinearNeuron();
	lin->initSpec(mat.getCol());
	layer.push(lin);
	for(int i=0;i<500;++i)
	{
		try{
			Matrix<double>* outs = layer.forward(&mat);
			Matrix<double> mlabel;
			mlabel.insertRow(label);
			Matrix<double>* loss = layer.backward(&mlabel);
			layer.updateNeuron();
		}catch(...)
		{
			cout<<"cat"<<endl;
		}
	}
	layer.print(cout);
}

void testStumpNeuron()
{
	Reader<double,double> reader("/Users/Zoson/Desktop/ml/Ch07/test.txt");
	Matrix<double> mat;
	Vector<double> label;
	reader.getAll(mat,label);
	mat.print(cout);
	label.print(cout);
	Vector<double> *weight = new Vector<double>(mat.getRow(),(double)1.0/mat.getRow());
	for(int i=0;i<3;++i)
	{
		StumpNeuron *stu = new StumpNeuron();
		double a = stu->innerDigest(&mat,&label,weight);
		stu->print(cout);
		cout<<"alpha:"<<a<<endl;
	}
}

zoson::Object obj;
void testCond()
{
	obj.wait();
}

void notifyThread()
{
	obj.notifyAll();
}
void testObject()
{
	std::thread t1(testCond);
	std::thread t2(testCond);		
	for(int i=0;i<100000;i++);	
	notifyThread();
	t1.join();
	t2.join();

}

int main()
{
	//testMatAndVec();
	//testReader();
	//testLogNeuron();
	//testLinearNeuron();
	//testLayer();
	//testStumpNeuron();
	testObject();
}
