#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <math.h>
namespace melon
{

double sigmod(double x)
{
	return 1.0/(1+exp(-x));
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


}

#endif