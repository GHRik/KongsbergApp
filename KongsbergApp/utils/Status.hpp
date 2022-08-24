#pragma once

namespace utils
{
	enum Status
	{
		CREATE,
		INIT,
		START,
		WORK,
		STOP
	};

	inline const char* ToString(Status v)
	{
		switch (v)
		{
		case CREATE:	return "CREATE";
		case INIT:		return "INIT";
		case START:		return "START";
		case WORK:		return "WORK";
		case STOP:		return "STOP";
		default:		return "";
		}
	}
}
