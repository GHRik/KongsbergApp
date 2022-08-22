#pragma once

namespace utils
{
	enum Status
	{
		INIT = 0,
		START,
		WORK,
		STOP
	};

	inline const char* ToString(Status v)
	{
		switch (v)
		{
		case INIT:   return "INIT";
		case START:   return "START";
		case WORK: return "WORK";
		case STOP:      return "STOP";
		}
	}
}
