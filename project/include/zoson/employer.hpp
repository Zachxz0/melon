#ifndef _EMPLOYER_H_
#define _EMPLOYER_H_

namespace zoson
{

class Employer:public Object
{
public:
	static Employer& getDefault();
protected:
	static Employer *s_emp ;

}

}

#endif