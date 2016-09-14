#ifndef _LAYER_H_
#define _LAYER_H_
#include <zoson/object.hpp>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <melon/vec.hpp>
#include <string>
#include <melon/Neuron.hpp>
using namespace std;
namespace melon
{

class Layer:virtual public zoson::Object
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
	void push(Neuron *neuron);
	inline int getNum(){ return m_neuron_s.size(); }
	virtual void updateNeuron();
	virtual string getType(){ return "Layer"; }
	virtual Matrix<double>* forward(Matrix<double> *data);
	virtual Matrix<double>* backward(Vector<double>* label);
	virtual string print();
protected:
	vector<boost::shared_ptr<Neuron> > m_neuron_s;
	Matrix<double>* m_out_data;
	Matrix<double>* m_loss;
	Matrix<double>* m_in_data;
};

}

#endif