#ifndef _PERCEPTRON_H_
#define _PERCEPTRON_H_
#include <melon/vec.hpp>
#include <melon/mat.hpp>
#include <ostream>
#include <melon/object.hpp>
using namespace std;

namespace melon
{

class Neuron:virtual public Object
{
public:
	Neuron():m_lr(0.12)
	{
		m_loss = new Vector<double>();
		m_out_data = new Vector<double>();
	}
	virtual ~Neuron()
	{
		delete m_loss;
		delete m_out_data;
	}
	virtual Vector<double>* forward(Matrix<double> *data)=0;
	virtual Vector<double>* backward(Vector<double> *label)=0;
	virtual double test(Vector<double>* test)=0;
	virtual void updateWeight()=0;
	inline void setLearnRate(double rate){m_lr = rate;};
	virtual void initSpec(int in_dim)= 0;
	virtual inline string getType(){return "Neuron"; }
	virtual void print(ostream &out)=0;
protected:
	Vector<double>* m_loss;//loss val
	Vector<double>* m_out_data; // store out_data
	Matrix<double>* m_in_data; //store in_data
	double m_lr;//learning rate
	Vector<double> m_weight;//weight + bias 
};

class NeuronParam
{

};

}

#endif