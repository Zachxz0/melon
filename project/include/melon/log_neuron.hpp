#ifndef _LOGREGRES_H_
#define _LOGREGRES_H_
#include <melon/neuron.hpp>
#include <vector>
#include <melon/vec.hpp>
#include <melon/mat.hpp>
#include <ostream>
using namespace std;
namespace melon
{

class LogNeuron:public Neuron
{
public:
	LogNeuron(){}
	~LogNeuron(){}
	virtual void initSpec(int in_dim); 	
	virtual Vector<double> forward(Matrix<double> &data);
	virtual double forward(Vector<double> &);
	virtual Vector<double> backward(Vector<double> &out,Vector<double> &label);
	virtual double backward(double out,double label);
	virtual void updateWeight(Matrix<double>& mat,Vector<double>&diff);
	virtual void updateWeight(Vector<double> &vec,double diff);
	virtual void print(ostream &out);
};

}

#endif