#ifndef _LAYER_H_
#define _LAYER_H_

#include <vector>
#include <boost/shared_ptr.hpp>
#include <melon/vec.hpp>
using namespace std;
namespace melon
{

class Layer
{
public:
	NeuronGroub(){}
	virtual ~NeuronGroub(){}
	inline void push(Neuron *neuron,double weight = 1.0)
	{ 
		if(neuron==null)return;
		shared_ptr<Neuron> sp(neuron);
		m_neuron_s.push_back(sp);
		m_weight.push(weight);
	}
	inline int getNum(){ m_neuron_s.size(); }
	virutal void updateWeight();
	virtual string getType(){ return "Layer"; }
	virtual 
	virtual void print();
protected:
	vector<shared_ptr<Neuron>> m_neuron_s;
	Vector<double> m_weight;
}

}

#endif