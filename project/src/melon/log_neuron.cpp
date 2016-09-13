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
	sigmod<double>(*m_out_data);
	return m_out_data;
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

