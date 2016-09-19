#include <melon/net.hpp>
#include <sstream>
using namespace std;
namespace melon
{

void NeuronNet::updateLayer()
{
	int num = getNum();
	for(int i=0;i<num;++i)
	{
		m_layer_s[i]->updateNeuron();
	}
}

Matrix<double>* NeuronNet::forward(Matrix<double> *data)
{
	int layer_num = getNum();
	if(layer_num == 0) return NULL;
	Matrix<double>* out = m_layer_s[0]->forward(data);
	for(int i=1;i<getNum();++i)
	{
		out = m_layer_s[i]->forward(data);
	}
	return out;
}

Matrix<double>* NeuronNet::backward(Matrix<double> *delta)
{
	if(delta==NULL)return;
	int num = getNum();
	Matrix<double> post_delta = m_layer_s[num-1]->backward(delta);
 	for(int i=num-2;i>=0;++i)
	{
		post_delta = m_layer_s[i]->backward(post_delta);
	}
	return post_delta;
}

string NeuronNet::print()
{
	int num = getNum();
	stringstream ss;
	for(int i=0;i<num;i++)
	{
		ss<<m_layer_s[i]->print();
		ss<<"\r\n";
	}
}

void NeuronNet::push(Layer* layer)
{
	if(layer==NULL)return;
	boost::shared_ptr<Layer> sp(layer);
	m_layer_s.push_back(sp);
}



}