#include <melon/vec.hpp>
#include <melon/mat.hpp>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
namespace melon
{
template<typename DataType>
Vector<DataType>::Vector(int num)
{
	for(int i=0;i<num;++i)
	{
		DataType n;
		m_data.push_back(n);
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
	Vector<DataType> temp;
	const int dim = vec.getDim();
	if(dim!=this->getDim())return *this;
	for(int i=0;i<dim;++i)
	{
		temp.m_data[i] = this->m_data[i]-vec.m_data[i];
	}
	return temp;
}

template<typename DataType>
DataType& Vector<DataType>::operator[](int index)
{
	return this->m_data[index];
}

template<typename DataType>
void Vector<DataType>::print(ostream &out)
{
	int len = this->getDim();
	for(int i=0;i<len;++i)
	{
		out<<this->m_data[i]<<" ";
	}
	out<<endl;
}

template class Vector<double>;
template class Vector<float>;
template class Vector<int>;

}