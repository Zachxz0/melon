#ifndef _LOGREGRES_H_
#define _LOGREGRES_H_
#include <vector>
#include <melon/vec.hpp>
#include <melon/mat.hpp>
#include <string>
#include <melon/linear_neuron.hpp>
using namespace std;
namespace melon
{

class LogNeuron:public LinearNeuron
{
public:
	LogNeuron()
	{
		m_out_sig_data = new Vector<double>();
	}
	~LogNeuron()
	{
		delete m_out_sig_data ;
	}
	virtual Vector<double>* forward(Matrix<double> *data);
	virtual Vector<double>* backward(Vector<double>*delte);
	virtual double test(Vector<double>* test);
	virtual inline string toString(){return "LogNeuron";}
	inline virtual string getType(){ return "LogNeuron";}

protected:
	Vector<double>* m_out_sig_data;
};

}

#endif