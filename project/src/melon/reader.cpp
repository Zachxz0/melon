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
void Reader<Data,Label>::getAll(Matrix<Data> &mat,Vector<Label>& label,int dim )
{
	while(!m_fs.eof())
	{
		Vector<Data> vec;
		for(int i=0;i<dim-1;++i)
		{
			Data d;
			m_fs>>d;
			vec.push(d);
		}
		mat.insertRow(vec);
		Label l;
		m_fs>>l;
		label.push(l);
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