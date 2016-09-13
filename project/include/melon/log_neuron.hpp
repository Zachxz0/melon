#ifndef _LOGREGRES_H_
#define _LOGREGRES_H_
#include <vector>
#include <melon/vec.hpp>
#include <melon/mat.hpp>
#include <string>
#include <melon/linear_neuron.hpp>
using namespace std;
namespace melon
{

class LogNeuron:public LinearNeuron
{
public:
	LogNeuron(){}
	~LogNeuron(){}
	virtual Vector<double>* forward(Matrix<double> *data);
	virtual double test(Vector<double>* test);
	virtual inline string toString(){return "LogNeuron";}
	inline virtual string getType(){ return "LogNeuron";}
};

}

#endif