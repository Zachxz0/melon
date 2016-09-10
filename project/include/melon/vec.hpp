#ifndef _DATA_H_
#define _DATA_H_
#include <vector>
#include <iostream>
#include <string>
using namespace std;

namespace melon
{
template<typename t>class Matrix;

template<typename DataType>
class Vector
{
public:
	Vector():m_data(){}
	explicit Vector(int num);
	virtual ~Vector(){}
	virtual string onSerialize();
	virtual void deSerialize(string);
	inline int getDim()const {return this->m_data.size();}

	Vector<DataType>& operator=(const Vector<DataType>& vec);
	DataType operator*(const Vector<DataType>& vec);
	DataType operator*(Matrix<DataType>& mat);
	Vector<DataType> operator-(const Vector<DataType>& vec);
	Vector<DataType> operator+(const Vector<DataType>& vec);
	DataType& operator[](int index);

	void push(DataType data);
	void print(ostream &out);
protected:
	vector<DataType> m_data;
};

}

#endif