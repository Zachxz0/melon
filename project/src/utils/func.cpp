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

template<typename DataType>
Vector<DataType>& dsigmod(Vector<DataType>&vec)
{
	int dim = vec.getDim();
	for(int i=0;i<dim;++i)
	{
		vec[i] = dsigmod<DataType>(vec[i]);
	}
	return vec;
}

template<typename DataType>
DataType dsigmod(DataType x)
{
	return sigmod<DataType>(x)*(1-sigmod<DataType>(x));
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

double exp(double val)
{
	return exp(val);
}

double loge(double val)
{
	return log(val);
}

double logn(double val,double di)
{
	return log(val)/log(di);
}

template double sigmod(double x);
template float sigmod(float x);
template double dsigmod(double x);
template float dsigmod(float x);
template Vector<double>& sigmod(Vector<double> &vec);
template Vector<float>& sigmod(Vector<float> &vec);
template Vector<double>& dsigmod(Vector<double>&vec);
template Vector<float>& dsigmod(Vector<float>&vec);

}