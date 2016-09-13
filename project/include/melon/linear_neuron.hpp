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
		m_loss = new Vector<double>();
	}
	~LinearNeuron()
	{
		delete m_loss;
	}
	virtual void initSpec(int in_dim); 	
	virtual Vector<double>* forward(Matrix<double> *data);
	virtual Vector<double>* backward(Vector<double> *label);
	virtual void updateWeight();
	virtual double test(Vector<double>* test);
	virtual string print();
	virtual inline string toString(){return "LinearNeuron";}
	inline virtual string getType(){ return "LinearNeuron";}
protected:
	Vector<double> m_weight;//weight + bias 
	Vector<double>* m_loss;//loss val
	double m_lr;//learning rate
};

}

#endif