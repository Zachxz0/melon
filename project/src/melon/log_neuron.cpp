#include <melon/log_neuron.hpp>
#include <iostream>
#include <sstream>
#include <melon/vec.hpp>
#include <utils/func.hpp>
using namespace std;
namespace melon
{

Vector<double>* LogNeuron::forward(Matrix<double> *data)
{
	LinearNeuron::forward(data);
	*m_out_sig_data = *(m_out_data);
	sigmod<double>(*m_out_sig_data);
	return m_out_sig_data;
}

Matrix<double>* LogNeuron::backward(Vector<double> *delte)
{
	LinearNeuron::backward(delte);
	int cols = m_delta->getRow();
	for(int i=0;i<cols;++i)
	{
		(*m_delta)[i] *= dsigmod<double>(*m_out_sig_data);
	}
	return m_delta;
}

double LogNeuron::test(Vector<double>* test)
{
	double dot = LinearNeuron::test(test);
	if(dot>0.5)
	{
		return 1.0;
	}else{
		return 0.0;
	}
}

}

