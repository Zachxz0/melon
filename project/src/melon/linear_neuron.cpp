#include <melon/linear_neuron.hpp>
#include <vector>
#include <iostream>
#include <melon/vec.hpp>
#include <utils/func.hpp>
using namespace std;
namespace melon
{

double LinearNeuron::forward(Vector<double> &data)
{
	if(data.getDim()!=m_weight.getDim())
	{
		throw "dim no same";
	}else{
		m_out_data.clear();
		m_in_data.clear();
		m_in_data.push(data);
		double dot = data * m_weight;
		dot = sigmod<double>(dot);
		m_out_data.push(dot);
		return dot;
	}
}

Vector<double> LinearNeuron::forward(Matrix<double> &data)
{
	if(data.getCol()!=m_weight.getDim()){
		throw "dim no same";
	}else{
		m_out_data.clear();
		m_out_data = data*m_weight;
		m_in_data.clear();
		m_in_data = data;
		return m_out_data;
	}
}

Vector<double> LinearNeuron::backward(Vector<double>& label)
{
	m_loss.clear();
	m_loss = m_out_data - label;
	return m_loss;
}

double LinearNeuron::backward(double label)
{
	m_loss.clear();
	double diff = m_out_data[0] - label;
	m_loss.push(diff);
	return diff;
}

void LinearNeuron::updateWeight()
{
	if(m_loss.getDim()<0)return;
	int row = m_in_data.getRow();
	m_weight = m_weight - ((m_in_data.transpose()*m_loss)*m_lr)/row;
}


void LinearNeuron::initSpec(int in_dim)
{
	for(int i=0;i<in_dim;++i)
	{
		m_weight.push(1.0);
	}
}

void LinearNeuron::print(ostream &out)
{
	for(int i=0;i<m_weight.getDim();++i)
	{
		out<<m_weight[i]<<" ";
	}
	out<<endl;
}


}

