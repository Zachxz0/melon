#ifndef _LINEAR_NEURON_H_
#define _LINEAR_NEURON_H_

#include <melon/neuron.hpp>
#include <vector>
#include <melon/vec.hpp>
#include <melon/mat.hpp>
#include <ostream>
using namespace std;
namespace melon
{

class LinearNeuron:public Neuron
{
public:
	LinearNeuron(){}
	~LinearNeuron(){}
	virtual void initSpec(int in_dim); 	
	virtual Vector<double> forward(Matrix<double> *data);
	virtual Vector<double> backward(Vector<double> *label);
	virtual void updateWeight();
	virtual void print(ostream &out);
	inline virtual string getType(){ return "LinearNeuron";}
};

}

#endif