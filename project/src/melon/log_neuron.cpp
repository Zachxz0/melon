#include <melon/log_neuron.hpp>
#include <vector>
#include <melon/vec.hpp>
#include <utils/func.hpp>
namespace melon
{
double LogNeuron::forward(const Vector<double> &data)
{
	return 1.0;
}

double LogNeuron::forward(const Matrix<double> &data)
{
	return 1.0;
}

double LogNeuron::backwark(double f_loss)
{
	return f_loss;
}

void LogNeuron::update()
{
	return ;
}

void LogNeuron::init()
{

}


}

