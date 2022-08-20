#pragma once

#include "../utils/ErrorCode.hpp"

namespace interface
{
	class iStreamMenager
	{
	public:
		iStreamMenager(){};
		virtual ~iStreamMenager(){};
		virtual utils::ErrorCode openStream() = 0;
		virtual utils::ErrorCode getFromStream() = 0;
		virtual utils::ErrorCode closeStream() = 0;
	};
};