#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <math.h>
#include <melon/vec.hpp>

namespace melon
{
template<typename DataType>
DataType sigmod(DataType x);

template<typename DataType>
Vector<DataType>& sigmod(Vector<DataType> &vec);

double loge(double val);

double dsigmod(double x);

double innerProduct(const vector<double>&x,const vector<double>&y);

}

#endif