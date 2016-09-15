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

Vector<double>* LogNeuron::backward(Vector<double> *delte)
{
	LinearNeuron::backward(delte);
	*m_delta *= dsigmod<double>(*m_out_sig_data);
	return delte;
}

double LogNeuron::test(Vector<double>* test)
{
	double dot = LinearNeuron::test(test);
	if(dot>0.5){
		return 1.0;
	}else{
		return 0.0;
	}
}

}

