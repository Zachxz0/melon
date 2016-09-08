#ifndef _PERCEPTRON_H_
#define _PERCEPTRON_H_
#include <vector>
using namespace std;
namespace melon
{

template<typename DataType>
class Perceptron
{
public:
	virtual ~Perceptron(){}
	virtual DataType forwardProcess(const vector<DataType> &data)=0;
	virtual DataType backwarkProcess(DataType f_loss)=0;
	virtual void updateWeight()=0;
protected:
	DataType m_loss;
	DataType m_out;
	vector<double> m_weight;//权重
};

}

#endif