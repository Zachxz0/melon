#ifndef _LAYER_H_
#define _LAYER_H_
#include <melon/object.hpp>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <melon/vec.hpp>
#include <ostream>
#include <string>
#include <melon/Neuron.hpp>
using namespace std;
namespace melon
{

class Layer:virtual public Object
{
public:
	Layer()
	{
		m_loss = new Matrix<double>();
		m_out_data = new Matrix<double>();
	}
	virtual ~Layer()
	{
		delete m_loss;
		delete m_out_data;
	}
	void push(Neuron *neuron,double weight = 1.0);
	inline int getNum(){ return m_neuron_s.size(); }
	virtual void updateWeight();
	virtual void updateNeuron();
	virtual string getType(){ return "Layer"; }
	virtual Matrix<double>* forward(Matrix<double> *data);
	virtual Matrix<double>* backward(Matrix<double>* label);
	virtual void print(ostream &out);
protected:
	vector<boost::shared_ptr<Neuron> > m_neuron_s;
	Vector<double> m_weight;
	Matrix<double>* m_out_data;
	Matrix<double>* m_loss;
	Matrix<double>* m_in_data;
};

}

#endif