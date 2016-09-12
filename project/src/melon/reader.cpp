#include <melon/reader.hpp>
#include <melon/vec.hpp>
#include <melon/mat.hpp>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
namespace melon
{

template<typename Data,typename Label>
Reader<Data,Label>::Reader(string path):m_fs(path.data())
{}

template<typename Data,typename Label>
void Reader<Data,Label>::getAll(Matrix<Data> &mat,Vector<Label>& label)
{
	while(!m_fs.eof())
	{
		Data d1;
		Data d2;
		Label l1;
		m_fs>>d1>>d2>>l1;
		Vector<Data> vec;
		vec.push(d1);
		vec.push(d2);
		mat.insertRow(vec);
		label.push(l1);
	}
}

template<typename Data,typename Label>
void Reader<Data,Label>::getOne(Vector<Data>&vec,Label& lable)
{

}

template class Reader<double,double>;
template class Reader<double,int>;
template class Reader<double,float>;

template class Reader<int,double>;
template class Reader<int,int>;
template class Reader<int,float>;

template class Reader<float,double>;
template class Reader<float,int>;
template class Reader<float,float>;


}