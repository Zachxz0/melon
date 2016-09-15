#include <melon/linear_neuron.hpp>
#include <vector>
#include <sstream>
#include <melon/vec.hpp>
#include <utils/func.hpp>
using namespace std;
namespace melon
{

Vector<double>* LinearNeuron::forward(Matrix<double> *data)
{
	if(data->getCol()!=m_weight.getDim()){
		throw "dim no same";
	}else{
		m_out_data->clear();
		*m_out_data = (*data)*m_weight;
		m_in_data = data;
		return m_out_data;
	}
}

Vector<double>* LinearNeuron::backward(Vector<double>* delta)
{
	m_loss->clear();
	*m_loss = *delta;
	m_delta->clear();
	for(int i=0;i<m_weight.getDim();++i)
	{
		m_delta->push((*delta)[i]*m_weight[i]);
	}
	return m_delta;
}

void LinearNeuron::updateWeight()
{
	if(m_loss->getDim()<0)return;
	int row = m_in_data->getRow();
	m_weight = m_weight - (m_in_data->transpose()*(*m_loss)*m_lr)/row;
}


void LinearNeuron::initSpec(int in_dim)
{
	for(int i=0;i<in_dim;++i)
	{
		m_weight.push(1.0);
	}
}

string LinearNeuron::print()
{
	stringstream ss;
	for(int i=0;i<m_weight.getDim();++i)
	{
		ss<<m_weight[i]<<" ";
	}
	ss<<"\r\n";
	return ss.str();
}

double LinearNeuron::test(Vector<double>* test)
{
	if(test==NULL||test->getDim()!=m_weight.getDim())
	{
		throw "params illegal";
	}else{
		return (*test)*m_weight;
	}
}

}

