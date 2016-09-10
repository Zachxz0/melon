#include <melon/log_neuron.hpp>
#include <vector>
#include <iostream>
#include <melon/vec.hpp>
#include <utils/func.hpp>
using namespace std;
namespace melon
{
double LogNeuron::forward(Vector<double> &data)
{
	if(data.getDim()!=m_weight.getDim())
	{
		throw "dim no same";
	}else{
		m_out_data.clear();
		m_in_data.clear();
		m_in_data = data;
		double dot = data * m_weight;
		dot = sigmod<double>(dot);
		m_out_data.push(dot);
		return dot;
	}
}

Vector<double> LogNeuron::forward(Matrix<double> &data)
{
	if(data.getCol()!=m_weight.getDim()){
		throw "dim no same";
	}else{
		m_out_data.clear();
		m_out_data = data*m_weight;
		sigmod<double>(m_out_data);
		return m_out_data;
	}
}

Vector<double> LogNeuron::backward(Vector<double> &out,Vector<double>& label)
{
	return (out-label);
}

double LogNeuron::backward(double out,double label)
{
	double diff = out - label;
	return diff;
}

void LogNeuron::updateWeight(Matrix<double>& mat,Vector<double>& diff)
{
	int row = mat.getRow();
	m_weight = m_weight - ((mat.transpose()*diff)*m_lr)/row;
}

void LogNeuron::updateWeight(Vector<double> &vec,double diff)
{

}

void LogNeuron::initSpec(int in_dim)
{
	for(int i=0;i<in_dim;++i)
	{
		m_weight.push(1.0);
	}
}

void LogNeuron::print(ostream &out)
{
	for(int i=0;i<m_weight.getDim();++i)
	{
		out<<m_weight[i]<<" ";
	}
	out<<endl;
}


}

