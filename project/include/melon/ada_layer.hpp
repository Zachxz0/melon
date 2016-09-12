#ifndef _ADA_LAYER_H_
#define _ADA_LAYER_H_

#include <melon/layer.hpp>

namespace melon
{

class AdaLayer:public Layer
{
public:
	AdaLayer(){}
	virtual ~AdaLayer(){}
	void push(Neuron *neuron,double weight);
	inline int getNum(){ return m_neuron_s.size(); }
	virtual void updateNeuron();
	virtual string getType(){ return "AdaLayer"; }
	virtual Matrix<double>* forward(Matrix<double> *data);
	virtual Matrix<double>* backward(Matrix<double>* label);
	virtual void print(ostream &out);
};

}

#endif