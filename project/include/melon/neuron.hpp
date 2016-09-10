#ifndef _PERCEPTRON_H_
#define _PERCEPTRON_H_
#include <melon/vec.hpp>
#include <melon/mat.hpp>
namespace melon
{

class Neuron
{
public:
	virtual ~Neuron(){}
	virtual void initWeight() = 0;
	virtual double forward(const Matrix<double> &data)=0;
	virtual double forward(const Vector<double>&)=0;
	virtual double backwark(double f_loss)=0;
	virtual void updateWeight()=0;
protected:
	double m_loss;
	double m_out;
	Vector<double> m_weight;//权重
};

class NeuronParam
{

};

}

#endif