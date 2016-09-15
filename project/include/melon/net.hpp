#ifndef _NET_WORLD_H_
#define _NET_WORLD_H_

#include <zoson/object.hpp>
#include <melon/layer.hpp>
#include <melon/mat.hpp>
#include <melon/vec.hpp>
#include <string>
using namespace std;
namespace melon
{

class NeuronNet:public zoson::Object
{
public:
	NeuronNet()
	{
		m_out_data = new Matrix<double>();
	}
	virtual ~NeuronNet()
	{
		delete m_out_data;
	}
	virtual void updateLayer();
	virtual Matrix<double>* forward(Matrix<double> *data);
	virtual Matrix<double>* backward(Matrix<double> *delta);
	virtual string print();
	inline virtual int getNum(){return m_layer_s.size();}
	void push(Layer* layer);
protected:
	vector<boost::shared_ptr<Layer> > m_layer_s;
	Matrix<double>* m_out_data;
	Matrix<double>* m_in_data;
}

}

#endif