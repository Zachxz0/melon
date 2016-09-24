#ifndef _SOFT_MAX_H_
#define _SOFT_MAX_H_

#include <melon/neuron.hpp>
#include <string>
namespace melon
{

class SoftMaxNeuron
{
public:
	SoftMaxNeuron():m_lr(10.0){init();}
	~SoftMaxNeuron()
	{
		delete m_out_data;
		delete m_loss;
	}
	virtual Matrix<double>*forward(Matrix<double>*data);
	virtual Matrix<double>*forward(Matrix<double>*data,Matrix<double>*data_t);
	virtual Matrix<double>* backward(Vector<double>*label);
	virtual void updateWeight();
	virtual inline string getType(){return "SoftMaxNeuron";}
	virtual string print();
	void setLearningRate(double lr){m_lr = lr;}
	virtual inline string toString(){return "SoftMaxNeuron";}
	virtual void initSpec(int r,int c,double val = 1.0);
	virtual double test(Vector<double> *x);
protected:
	double softmax(Vector<double>* x,int n);
	virtual void init()
	{
		m_out_data = new Matrix<double>();
		m_loss = new Matrix<double>();
	}
	Matrix<double> m_weight;
	Matrix<double>* m_loss;
	Matrix<double>* m_in_data;
	Matrix<double>* m_out_data;
	Matrix<double>* m_in_data_t;
	double m_lr;
};

}

#endif