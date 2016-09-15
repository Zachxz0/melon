#include <melon/vec.hpp>
#include <melon/mat.hpp>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
namespace melon
{
template<typename DataType>
Vector<DataType>::Vector(int num,DataType def)
{
	for(int i=0;i<num;++i)
	{
		m_data.push_back(def);
	}
}

template<typename DataType>
string Vector<DataType>::onSerialize()
{
	return "";
}

template<typename DataType>
void Vector<DataType>::deSerialize(string str)
{

}

template<typename DataType>
void Vector<DataType>::push(DataType data)
{
	this->m_data.push_back(data);
}

template<typename DataType>
Vector<DataType>& Vector<DataType>::operator=(const Vector<DataType>& vec)
{
	this->m_data = vec.m_data;
	return *this;
}

template<typename DataType>
DataType Vector<DataType>::operator*(const Vector<DataType>& vec)
{
	DataType temp;
	if(this->getDim()==vec.getDim())
	{
		for(int i=0;i<vec.getDim();++i)
		{
			temp += this->m_data[i]*vec.m_data[i];
		}
	}
	return temp;
}

template<typename DataType>
DataType Vector<DataType>::operator*(Matrix<DataType>&mat)
{
	DataType temp;
	if(mat.getCol()==1)
	{
		for(int i=0;i<mat.getRow();++i)
		{
			temp += mat[i][0]*this->m_data[i];
		}
	}
	return temp;
}

template<typename DataType>
Vector<DataType> Vector<DataType>::operator*(DataType val)
{
	int dim = this->getDim();
	Vector<DataType> temp(dim);
	for(int i=0;i<dim;++i)
	{
		temp[i] = (*this)[i]*val;
	}
	return temp;
}

template<typename DataType>
Vector<DataType> Vector<DataType>::operator+(const Vector<DataType>&vec)
{
	Vector<DataType> temp;
	const int dim = vec.getDim();
	if(dim!=this->getDim())return *this;
	for(int i=0;i<dim;++i)
	{
		temp.m_data[i] = vec.m_data[i]+this->m_data[i];
	}
	return temp;
}

template<typename DataType>
Vector<DataType> Vector<DataType>::operator-(const Vector<DataType>&vec)
{
	const int dim = vec.getDim();
	if(dim!=this->getDim())return *this;
	Vector<DataType> temp(dim);
	for(int i=0;i<dim;++i)
	{
		temp.m_data[i] = this->m_data[i]-vec.m_data[i];
	}
	return temp;
}

template<typename DataType>
Vector<DataType>& Vector<DataType>::operator*=(const Vector<DataType>& vec)
{
	int dim = this->getDim();
	for(int i=0;i<dim;++i)
	{
		(*this)[i] = (*this)[i]*vec.m_data[i];
	}
	return *this;
}

template<typename DataType>
Vector<DataType>& Vector<DataType>::operator*=(DataType val)
{
	int dim = this->getDim();
	for(int i=0;i<dim;++i)
	{
		(*this)[i] = (*this)[i]*val;
	}
	return *this;
}


template<typename DataType>
DataType& Vector<DataType>::operator[](int index)
{
	return this->m_data[index];
}

template<typename DataType>
string Vector<DataType>::print()
{
	stringstream ss;
	int len = this->getDim();
	for(int i=0;i<len;++i)
	{
		ss<<this->m_data[i]<<" ";
	}
	ss<<"\r\n";
	return ss.str();
}

template<typename DataType>
Vector<DataType> Vector<DataType>::operator/(DataType val)
{
	Vector<DataType> temp ;
	const int dim = this->getDim();
	for(int i=0;i<dim;++i)
	{
		temp.push((*this)[i]/val);
	}
	return temp;
}

template class Vector<double>;
template class Vector<float>;
template class Vector<int>;

}