#ifndef _TIMER_H_
#define _TIMER_H_
#include <boost/timer.hpp>
#include <boost/progress.hpp>
using namespace boost;
namespace melon
{

class Timer
{
public:
	Timer(int flag = 0)
	{
		switch (flag)
		{
			case 0x0:
				m_t = new timer();break;
			case 0x1:
				m_t = new progress_timer();break;
		    default:
		    	m_t = new timer();				
		}
	};
	~Timer()
	{
		delete m_t;
	}
private:
	timer *m_t;

public:
	static int AUTO;
};

int Timer::AUTO = 0x1;

}

#endif