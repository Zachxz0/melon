#ifndef _LOGREGRES_H_
#define _LOGREGRES_H_
#include <melon/neuron.hpp>
#include <vector>
#include <melon/vec.hpp>
#include <melon/mat.hpp>
namespace melon
{

class LogNeuron:public Neuron
{
public:
	LogNeuron(){}
	~LogNeuron(){}
	virtual void init();
	virtual double forward(const Matrix<double> &data);
	virtual double forward(const Vector<double> &);
	virtual double backwark(double f_loss);
	void update();
};

}

#endif