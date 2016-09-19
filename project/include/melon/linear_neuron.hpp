#ifndef _LINEAR_NEURON_H_
#define _LINEAR_NEURON_H_

#include <melon/neuron.hpp>
#include <melon/vec.hpp>
#include <melon/mat.hpp>
#include <string>
using namespace std;
namespace melon
{

class LinearNeuron:public Neuron
{
public:
	LinearNeuron():m_lr(0.12)
	{
		init();
	}
	LinearNeuron(bool ishidden):Neuron(ishidden)
	{
		init();
	}
	~LinearNeuron()
	{
		delete m_loss;
		delete m_delta;
	}
	virtual void setLearningRate(double lr){m_lr=lr;}
	virtual void initSpec(int in_dim); 	
	virtual Vector<double>* forward(Matrix<double> *data);
	virtual Matrix<double>* backward(Vector<double> *label);
	virtual void updateWeight();
	virtual double test(Vector<double>* test);
	virtual string print();
	virtual inline string toString(){return "LinearNeuron";}
	inline virtual string getType(){ return "LinearNeuron";}
protected:
	virtual void init()
	{
		m_loss = new Vector<double>();
		m_delta = new Matrix<double>();
	}
	Vector<double> m_weight;//weight + bias 
	Vector<double>* m_loss;//loss val
	Matrix<double>* m_delta;//transport to the pre layer
	double m_lr;//learning rate
};

}

#endif