#include <melon/softmax_neuron.hpp>
#include <sstream>
#include <float.h>
#include <iostream>
#include <utils/func.hpp>
using namespace std;
namespace melon
{

Matrix<double>* SoftMaxNeuron::forward(Matrix<double>*data)
{
	if(data==NULL)return NULL;
	if(data->getCol()!=m_weight.getCol())
	{
		cout<<"dim no same"<<endl;
	}
	m_in_data = data;
	m_out_data->clear();
	int m = data->getRow();
	int row = m_weight.getRow();
	for(int i=0;i<m;++i)
	{
		Vector<double>* vec = new Vector<double>();
		m_out_data->insertRow(*vec);
		for(int j=0;j<row;++j)
		{
			double p = softmax(&(*data)[i],j);
			(*m_out_data)[i].push(p);
		}
	}
	return m_out_data;
}

double SoftMaxNeuron::softmax(Vector<double>* x,int n)
{
	double den = 0;//分母
	int k = m_weight.getRow();
	for(int i=0;i<k;++i)
	{
		den += m_weight[i]*(*x);
	}
	return (m_weight[n]*(*x))/den;
}

Matrix<double>* SoftMaxNeuron::backward(Vector<double>*label)
{
	if(label==NULL)return NULL;
	m_loss->clear();
	int row = label->getDim();
	int k = m_weight.getRow();
	for(int i=0;i<k;++i)
	{
		m_loss->insertRow(*(new Vector<double>()));
		for(int j=0;j<row;++j)
		{		
			double loss = 0;
			if((int)(*label)[j]==i)loss+=1;
			loss += - (*m_out_data)[j][i];
			(*m_loss)[i].push(loss);
		}
	}
	return m_loss;
}

void SoftMaxNeuron::updateWeight()
{
	int k = m_weight.getRow();
	int row = m_in_data->getRow();
	for(int i=0;i<k;++i)
	{
		m_weight[i] = m_weight[i] - (m_in_data->transpose()*((*m_loss)[i])*m_lr)/row;
	}
}

void SoftMaxNeuron::initSpec(int r,int c,double val)
{
	for(int i=0;i<r;++i)
	{
		m_weight.insertRow(*(new Vector<double>()));
		for(int j=0;j<c;++j)
		{
			m_weight[i].push(val);
		}
	}
}

double SoftMaxNeuron::test(Vector<double> *x)
{
	int min_index = 0;
	double min_val = DBL_MAX;
	int k = m_weight.getRow();
	for(int i=0;i<k;++i)
	{
		double out = m_weight[i]*(*x);
		if(out<min_val)
		{
			out = min_val;
			min_val = i;
		}
	}
	return min_index;
}

string SoftMaxNeuron::print()
{
	stringstream ss;
	int row = m_weight.getRow();
	int col = m_weight.getCol();
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<col;++j)
		{
			ss<<m_weight[i][j]<<" ";
		}
		ss<<"\r\n";
	}
	ss<<"\r\n";
	return ss.str();
}


}