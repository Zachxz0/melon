#ifndef _LOGREGRES_H_
#define _LOGREGRES_H_
#include <melon/neuron.hpp>
#include <vector>
#include <melon/vec.hpp>
#include <melon/mat.hpp>
#include <ostream>
#include <string>
using namespace std;
namespace melon
{

class LogNeuron:public Neuron
{
public:
	LogNeuron(){}
	~LogNeuron(){}
	virtual void initSpec(int in_dim); 	
	virtual Vector<double> forward(Matrix<double> *data);
	virtual Vector<double> backward(Vector<double> *label);
	virtual void updateWeight();
	virtual void print(ostream &out);
	inline virtual string getType(){ return "LogNeuron";}
};

}

#endif