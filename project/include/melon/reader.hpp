#ifndef _READ_H_
#define _READ_H_
#include <melon/mat.hpp>
#include <string>
#include <fstream>
namespace melon
{

template<typename Data,typename Label>
class Reader
{
public:
	Reader(string path);
	virtual void getAll(Matrix<Data> &mat,Vector<Label>& label);
	virtual void getOne(Vector<Data>&vec,Label& lable);
protected:
	fstream m_fs;
};


}

#endif