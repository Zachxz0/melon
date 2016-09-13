#include <melon/stump_neuron.hpp>
#include <utils/func.hpp>
#include <math.h>
#include <sstream>
#include <float.h>
using namespace std;
namespace melon
{

double StumpNeuron::test(Vector<double> *data)
{
	return 0.0;
}

void StumpNeuron::initSpec(int dim)
{}

double StumpNeuron::innerDigest(Matrix<double> *data,Vector<double> *label,Vector<double>* weight)
{
	if(data==NULL||label==NULL)return 0.0;
	int dim = data->getCol();
	int row = data->getRow();
	m_in_data = data;
	Matrix<int> predictedVals(row ,1,1);
	double minError = DBL_MAX;
	for(int i=0;i<dim;++i)
	{
		double max = findMax();
		double min = findMin();
		double step = (max - min)/10;//ten step
		for(int j = -1;j<11;++j)
		{
			for(int k = 0;k<=1;++k)
			{
				double thresh = min + step * j;
				Matrix<int> pv(row,1,1);
				stumpClassify(pv,i,thresh,!((bool)k));
				Matrix<double> errArr(row,1,1);
				for(int i=0;i<row;++i)
				{
					if(pv[i][0]==(int)(*label)[i])
					{
						errArr[i][0] = 0;
					}
				}
				double weightErr = (*weight)*(errArr.transpose()[0]);
				if(weightErr<minError)
				{
					minError = weightErr;
					m_dim = i;
					m_thresh = thresh;
					m_lt = k;
					predictedVals = pv;
				}
			}
		}
	}
	double alpha = 0.5*loge((1.0-minError)/(minError>(1e-16)?minError:1e-16));
	double sum_weight = 0.0;
	for(int i=0;i<row;++i)
	{
		double expon = alpha;
		if(predictedVals[i][0]==(*label)[i])
		{
			expon = -expon;
		}
		(*weight)[i] = ((*weight)[i])*(exp(expon));
		sum_weight += (*weight)[i];
	}
	for(int i=0;i<row;++i)
	{
		(*weight)[i] = (*weight)[i]/sum_weight;
	}
	return alpha;
}

Vector<double>* StumpNeuron::forward(Matrix<double> *data)
{
	return NULL;
}

Vector<double>* StumpNeuron::backward(Vector<double>* label)
{
	return NULL;
}

void StumpNeuron::stumpClassify(Matrix<int> &ret,int dim,double thresh,bool eq)
{
	int row = m_in_data->getRow();
	if(eq){
		for(int i=0;i<row;++i)
		{
			double val = (*m_in_data)[i][dim];
			if(val<=thresh)ret[i][0]=-1;
		}
	}else{
		for(int i=0;i<row;++i)
		{
			double val = (*m_in_data)[i][dim];
			if(val>thresh)ret[i][0]=-1;
		}
	}
}

double StumpNeuron::findMax()
{
	int row = m_in_data->getRow();
	double max = (*m_in_data)[0][m_dim];
	for(int i=1;i<row;++i)
	{
		double curr = (*m_in_data)[i][m_dim];
		if(curr>max)
		{
			max =curr;
		}
	}
	return max;
}

double StumpNeuron::findMin()
{
	int row = m_in_data->getRow();
	double min = (*m_in_data)[0][m_dim];
	for(int i=1;i<row;++i)
	{
		double curr = (*m_in_data)[i][m_dim];
		if(curr<min)
		{
			min =curr;
		}
	}
	return min;
}

string StumpNeuron::print()
{
	stringstream ss;
	ss<<getType()<<"\r\n";
	ss<<"\tdim:"<<m_dim<<"\r\n";
	ss<<"\tthresh:"<<m_thresh<<"\r\n";
	ss<<"\tless than:"<<m_lt<<"\r\n";
	return ss.str();
}


}