#include <melon/mat.hpp>
#include <melon/vec.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
using namespace std;
namespace melon
{

template<typename DataType>
Matrix<DataType>::Matrix(int i,int ii)
{
	for(int n=0;n<i;++n)
	{
		Vector<DataType> *vec = new Vector<DataType>();
		for(int m = 0;m<ii;++m)
		{
			DataType d;
			vec->push(d);
		}
	 	boost::shared_ptr<Vector<DataType> > sp(vec);
	 	m_data.push_back(sp);
	}	
}

template<typename DataType>
Matrix<DataType>::Matrix(Vector<DataType> &vec)
{
	m_data.clear();
	Vector<DataType> *newVec = new Vector<DataType>(vec);
	boost::shared_ptr<Vector<DataType> > sp(newVec);
	m_data.push_back(sp);
}

template<typename DataType>
string Matrix<DataType>::onSerialize()
{
	return "";
}

template<typename DataType>
void Matrix<DataType>::deSerialize(string)
{

}


template<typename DataType>
Matrix<DataType>& Matrix<DataType>::operator=(const Matrix<DataType>&mat)
{
	return *this;
}

template<typename DataType>
Matrix<DataType> Matrix<DataType>::operator*(Matrix<DataType>&mat)
{
	int l_row = this->getRow();
	int l_col = this->getCol();
	int r_row = mat.getRow();
	int r_col = mat.getCol();
	Matrix<DataType> temp(l_row,r_col);
	if(l_col==r_row)
	{
		for(int i=0;i<l_row;++i)
		{
			for(int j=0;j<r_col;++j)
			{
				DataType item=0;
				for(int k=0;k<l_col;++k)
				{
					item +=(*this)[i][k] * mat[k][j];
				}
				temp[i][j] = item;
			}
		}
	}else{
		throw "mat x mat error";
	}
	return temp;
}

template<typename DataType>
Vector<DataType> Matrix<DataType>::operator*(Vector<DataType>&vec)
{
	int l_row = this->getRow();
	int l_col = this->getCol();
	int dim = vec.getDim();
	Vector<DataType> temp(dim);
	if(l_col==dim)
	{
		for(int i=0;i<l_row;++i)
		{
			DataType item=0;
			for(int k=0;k<l_col;++k)
				item +=(*this)[i][k] * vec[k];
			temp[i] = item;
		}
				
	}else{
		throw "mat x vec error";
	}
	return temp;
}

template<typename DataType>
Matrix<DataType> Matrix<DataType>::operator+(Matrix<DataType>&mat)
{
	Matrix<DataType> temp(this->getRow(),this->getCol());
	if(this->hasSameSpec(mat))
	{
		int row = this->getRow();
		int col = this->getCol();
		for(int i=0;i<row;++i)
			for(int j=0;j<col;++j)
				temp[i][j] = (*this)[i][j] + mat[i][j];
	}else{
		throw false;
	}
	return temp;
}

template<typename DataType>
Matrix<DataType> Matrix<DataType>::operator-(Matrix<DataType>&mat)
{
	Matrix<DataType> temp(this->getRow(),this->getCol());
	if(this->hasSameSpec(mat))
	{
		int row = this->getRow();
		int col = this->getCol();
		for(int i=0;i<row;++i)
			for(int j=0;j<col;++j)
				temp[i][j] = (*this)[i][j] - mat[i][j];
	}else{
		throw false;
	}
	return temp;
}

template<typename DataType>
Vector<DataType>& Matrix<DataType>::operator[](int index)
{
	return *(this->m_data[index]);
}

template<typename DataType>
bool Matrix<DataType>::hasSameSpec(const Matrix<DataType>&mat)
{
	return (this->getRow()==mat.getRow())&&(this->getCol()==mat.getCol());
}

template<typename DataType>
void Matrix<DataType>::print(ostream& out)
{
	int row = getRow();
	int col = getCol();
	if(row>0&&col>0)
	{
		cout<<"- - - -"<<endl;
		for(int i=0;i<row;++i)
		{
			for(int j=0;j<col;++j)
				out<<(*this)[i][j]<<"\t";
			out<<endl;
		}
		cout<<"- - - -"<<endl;
	}
}

template<typename DataType>
void Matrix<DataType>::push(Vector<DataType>& vec)
{
	Vector<DataType> *newVec = new Vector<DataType>(vec);
	boost::shared_ptr<Vector<DataType> > sp(newVec);
	m_data.push_back(sp);
}

template class Matrix<double>;

}