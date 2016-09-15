#ifndef _DATA_H_
#define _DATA_H_
#include <vector>
#include <string>
#include <zoson/object.hpp>
using namespace std;

namespace melon
{
template<typename t>class Matrix;

template<typename DataType>
class Vector//:virtual public zoson::Object
{
public:
	Vector():m_data(){}
	explicit Vector(int num,DataType def = 0);
	virtual ~Vector(){}
	virtual string onSerialize();
	virtual void deSerialize(string);
	inline int getDim()const {return this->m_data.size();}

	Vector<DataType>& operator=(const Vector<DataType>& vec);
	DataType operator*(const Vector<DataType>& vec);
	DataType operator*(Matrix<DataType>& mat);
	Vector<DataType> operator*(DataType val);
	Vector<DataType> operator-(const Vector<DataType>& vec);
	Vector<DataType> operator+(const Vector<DataType>& vec);
	Vector<DataType>& operator*=(const Vector<DataType>& vec);
	Vector<DataType>& operator*=(DataType val);
	Vector<DataType> operator/(DataType val);
	DataType& operator[](int index);
	inline void clear(){m_data.clear();}
	void push(DataType data);
	string print();
protected:
	mutable vector<DataType> m_data;
};

}

#endif