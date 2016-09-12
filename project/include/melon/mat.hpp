#ifndef _DATA_SET_H_
#define _DATA_SET_H_
#include <boost/shared_ptr.hpp>
#include <vector>
#include <iostream>
using namespace std;
namespace melon
{
template<typename t>class Vector;

template<typename DataType>
class Matrix
{
public:
	Matrix(){}
	Matrix(Matrix<DataType>& mat);
	Matrix(Vector<DataType>&);
	Matrix(int i,int ii);
	~Matrix(){}
	virtual string onSerialize();
	virtual void deSerialize(string);
	inline int getRow()const {return this->m_data.size();}
	inline int getCol()const 
	{
		if(this->getRow()>0)
		{
			return this->m_data[0]->getDim();
		}
		return 0;
	}

	Vector<DataType>& operator[](int i);
	Matrix<DataType>& operator=(Matrix<DataType> &mat);
	Matrix<DataType> operator*(Matrix<DataType> &mat);
	Vector<DataType> operator*(Vector<DataType>&vec);
	Matrix<DataType> operator-(Matrix<DataType>&mat);
	Matrix<DataType> operator+(Matrix<DataType>&mat);
    Matrix<DataType> transpose();
    void insertCol(double val=1.0,int index=-1);
    void clear(){m_data.clear();}
	void insertRow(Vector<DataType>& vec);
	void print(ostream &out);
protected:
	bool hasSameSpec(const Matrix<DataType>&);
	vector<boost::shared_ptr<Vector<DataType> > > m_data;
};


}

#endif