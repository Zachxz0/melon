#include <melon/layer.hpp>
#include <melon/Neuron.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
using namespace std;
namespace melon
{

void Layer::push(Neuron *neuron,double weight)
{ 
	if(neuron==NULL)return;
	boost::shared_ptr<Neuron> sp(neuron);
	m_neuron_s.push_back(sp);
	m_weight.push(weight);
}

Matrix<double>* Layer::forward(Matrix<double>*data)
{
	if(data == NULL||data->getRow()==0||data->getCol()==0||m_neuron_s.size()==0)return NULL;
	int neuron_num = m_neuron_s.size();
	m_in_data = new Matrix<double>;
	for(int i=0;i<neuron_num;++i)
	{
		m_out_data->insertRow(*(m_neuron_s[i]->forward(data)));
	}
	return m_out_data;
}

Matrix<double>* Layer::backward(Matrix<double>*label)
{
	if(label==NULL||label->getRow()==0||label->getCol()==0||m_neuron_s.size()==0)return NULL;
	int neuron_num = m_neuron_s.size();
	for(int i=0;i<neuron_num;++i)
	{
		m_loss->insertRow(*(m_neuron_s[i]->backward(&(*label)[i])));
	}
	return m_loss;
}

void Layer::updateNeuron()
{
	int num = m_neuron_s.size();
	for(int i=0;i<num;++i)
	{
		m_neuron_s[i]->updateWeight();
	}
}

void Layer::updateWeight()
{

}

void Layer::print(ostream &out)
{
	int num = m_neuron_s.size();
	for(int i=0;i<num;++i)
	{
		out<<m_neuron_s[i]->getType()<<endl;
		out<<"\t";
		m_neuron_s[i]->print(out);
	}
	out<<endl;
}

}