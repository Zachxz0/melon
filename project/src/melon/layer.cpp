#include <melon/layer.hpp>
#include <melon/Neuron.hpp>
#include <boost/shared_ptr.hpp>
#include <sstream>
using namespace std;
namespace melon
{

void Layer::push(Neuron *neuron)
{ 
	if(neuron==NULL)return;
	boost::shared_ptr<Neuron> sp(neuron);
	m_neuron_s.push_back(sp);
}

Matrix<double>* Layer::forward(Matrix<double>*data)
{
	if(data == NULL||data->getRow()==0||data->getCol()==0||m_neuron_s.size()==0)return NULL;
	int neuron_num = m_neuron_s.size();
	m_in_data = data;
	for(int i=0;i<neuron_num;++i)
	{
		m_out_data->insertRow(*(m_neuron_s[i]->forward(data)));
	}
	return m_out_data;
}

Matrix<double>* Layer::backward(Matrix<double>* delta)
{
	if(delta==NULL||delta->getRow()||delta->getCol()||m_neuron_s.size()==0)return NULL;
	m_delta->clear();
	int neuron_num = m_neuron_s.size();
	int neuron_dim = m_in_data->getCol();
	(*m_delta) = *(m_neuron_s[0]->backward(&(*delta)[0]));
	for(int i=1;i<neuron_num;++i)
	{
		(*m_delta)+=*(m_neuron_s[i]->backward(&(*delta)[i]));
	}
	return m_delta;
}

void Layer::updateNeuron()
{
	int num = m_neuron_s.size();
	for(int i=0;i<num;++i)
	{
		m_neuron_s[i]->updateWeight();
	}
}

string Layer::print()
{
	stringstream ss;
	int num = m_neuron_s.size();
	for(int i=0;i<num;++i)
	{
		ss<<m_neuron_s[i]->getType()<<"\r\n";
		ss<<"\t";
		ss<<m_neuron_s[i]->print();
	}
	return ss.str();
}

}