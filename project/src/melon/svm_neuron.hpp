#ifndef _SVM_NEURON_H_
#define _SVM_NEURON_H_

#include <melon/neuron.hpp>
namespace melon
{

class SvmNeuron:Neuron
{
public:
	SvmNeuron(){}
	~SvmNeuron(){}
	virtual void initSpec(int in_dim); 	
	virtual Vector<double> forward(Matrix<double> *data);
	virtual Vector<double> backward(Vector<double> *label);
	virtual void updateWeight();
	virtual void print(ostream &out);
};

}

#endif