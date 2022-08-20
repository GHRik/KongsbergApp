#pragma once

#include "../interfaces/iLifeCycleMenager.hpp"
#include "../interfaces/iLogger.hpp"
#include "../interfaces/iStreamMenager.hpp"

namespace common {
	class StreamMenager : public interface::iStreamMenager, public interface::iLifeCycleService
	{
	public:
		StreamMenager(interface::iLogger* logger, interface::iLifeCycleMenager* lifeCycleMenager);
		virtual ~StreamMenager();
		utils::ErrorCode setStatus(utils::Status status);
		utils::Status getStatus();
		utils::ErrorCode run();

		utils::ErrorCode openStream();
		utils::ErrorCode getFromStream();
		utils::ErrorCode closeStream();

	private:
		interface::iLifeCycleMenager* lifeCycleMenager;
		interface::iLogger* logger;
		utils::Status status;
	};
}