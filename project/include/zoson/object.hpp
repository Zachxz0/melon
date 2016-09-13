#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <mutex>
#include <string>
#include <queue>
#include <boost/shared_ptr.hpp>
#include <condition_variable>
using namespace std;
namespace zoson
{
//typedef shared_ptr<Object> Spoint;
//typedef weak_ptr<Object> Wpoint;
class Object
{
public:
	Object();
	virtual ~Object();
	inline bool equals(const Object& obj){ return (this==(&obj)); }
	string toString();
	void notify();
	void notifyAll();
	void wait(long time);
	void wait();
private:
	mutex m_mutex;
	condition_variable m_cv;
};

}

#endif