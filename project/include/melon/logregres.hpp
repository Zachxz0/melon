#ifndef _LOGREGRES_H_
#define _LOGREGRES_H_

#include <melon/perceptron.hpp>
namespace melon
{

template<typename DataType>
class Logregres:public Perceptron<DataType>
{
public:
	Logregres()
	{

	}
	virtual ~Logregres()
	{

	}
	virtual DataType forwardProcess(const vector<DataType> &data);
	virtual DataType backwarkProcess(DataType f_loss);
	virtual void updateWeight();
	double test();
};



}

#endif