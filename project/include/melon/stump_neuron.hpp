#ifndef _STUMP_NEURON_H_
#define _STUMP_NEURON_H_

#include <melon/neuron.hpp>
#include <melon/vec.hpp>
#include <melon/mat.hpp>
#include <string>
using namespace std;
namespace melon
{

class StumpNeuron:public Neuron
{
public:
	StumpNeuron(){}
	virtual ~StumpNeuron(){}
	virtual void initSpec(int in_dim); 	
	virtual void updateWeight(){};
	virtual string print();
	virtual double innerDigest(Matrix<double> *data,Vector<double> *label,Vector<double>*weight);
	inline virtual string getType(){ return "StumpNeuron";}
	virtual double test(Vector<double>*);
	inline virtual string toString(){ return "StumpNeuron";}
protected:
	virtual Vector<double>* forward(Matrix<double> *data);
	virtual Vector<double>* backward(Vector<double> *label);
	void stumpClassify(Matrix<int> &ret,int dim,double thresh,bool eq);
	double findMax();
	double findMin();
	int m_dim;
	double m_thresh;
	bool m_lt;//true is lt ,false is gt
};

}

#endif