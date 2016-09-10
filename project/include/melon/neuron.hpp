#ifndef _PERCEPTRON_H_
#define _PERCEPTRON_H_
#include <melon/vec.hpp>
#include <melon/mat.hpp>
#include <ostream>
using namespace std;

namespace melon
{

class Neuron
{
public:
	Neuron():m_lr(0.12){}
	virtual ~Neuron(){}
	virtual Vector<double> forward(Matrix<double> &data)=0;
	virtual double forward(Vector<double>&)=0;
	virtual Vector<double> backward(Vector<double> &out,Vector<double> &label)=0;
	virtual double backward(double out,double label) =0 ;
	virtual void updateWeight(Matrix<double>& mat,Vector<double>&diff)=0;
	virtual void updateWeight(Vector<double>& vec,double diff)=0;
	inline void setLearnRate(double rate){m_lr = rate;};
	virtual void initSpec(int in_dim)= 0;
	virtual void print(ostream &out)=0;

protected:
	Vector<double> m_out_data; // store out_data
	Matrix<double> m_in_data; //store in_data
	double m_lr;//learning rate
	Vector<double> m_weight;//weight + bias 
};

class NeuronParam
{

};

}

#endif