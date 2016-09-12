#include <utils/func.hpp>
#include <math.h>
#include <melon/vec.hpp>
namespace melon
{
template<typename DataType>
DataType sigmod(DataType x)
{
	return 1.0/(1+exp(-x));
}

template<typename DataType>
Vector<DataType>& sigmod(Vector<DataType> &vec)
{
	int dim = vec.getDim();
	for(int i=0;i<dim;++i)
	{
		vec[i] = sigmod<DataType>(vec[i]);
	}
	return vec;
}

double dsigmod(double x)
{
	return sigmod(x)*(1-sigmod(x));
}

double innerProduct(const vector<double>&x,const vector<double>&y)
{
	if(x.size()!=y.size())return -1;
	double result = 0;
	for(int i=0;i<x.size();++i)
	{
		result+= x[i]*y[i];
	}
	return result;
}
template Vector<double>& sigmod(Vector<double> &vec);
template Vector<float>& sigmod(Vector<float> &vec);

}