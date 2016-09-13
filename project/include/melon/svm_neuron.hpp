#ifndef _SVM_NEURON_H_
#define _SVM_NEURON_H_

#include <melon/neuron.hpp>
namespace melon
{

class SvmNeuron:Neuron
{
public:
	SvmNeuron():m_alpha(m_weight){}
	~SvmNeuron(){}
	virtual void initSpec(int in_dim); 	
	virtual Vector<double> forward(Matrix<double> *data);
	virtual Vector<double> backward(Vector<double> *label);
	
	virtual void updateWeight();
	virtual void print(ostream &out);
	virtual inline string getType(){return "SvmNeuron";}
protected:
	Vector<double> &m_alpha;
};

}

#endif