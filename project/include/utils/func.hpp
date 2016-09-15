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

template<typename DataType>
Vector<DataType>& dsigmod(Vector<DataType>&vec);

double loge(double val);

template<typename DataType>
DataType dsigmod(DataType x);

double innerProduct(const vector<double>&x,const vector<double>&y);

}

#endif