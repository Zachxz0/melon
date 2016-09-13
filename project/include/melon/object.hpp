#ifndef _OBJECT__H_
#define _OBJECT__H_

#include <string>
using namespace std;
namespace melon
{

class Object
{
public:
	Object(){}
	virtual ~Object(){}
	inline virtual string getType(){return "Object";}
protected:

};

}

#endif