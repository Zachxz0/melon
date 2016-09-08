#include <melon/logregres.hpp>
namespace melon
{

template<typename DataType>
DataType Logregres<DataType>::forwardProcess(const vector<DataType> &data)
{
	return data[0];
}

template<typename DataType>
DataType Logregres<DataType>::backwarkProcess(DataType f_loss)
{
	return f_loss;
}

template<typename DataType>
void Logregres<DataType>::updateWeight()
{
	return ;
}

template<typename DataType>
double Logregres<DataType>::test()
{
	return 1.032;
}

}

