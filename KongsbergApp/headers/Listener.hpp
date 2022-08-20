#pragma once

#include "../interfaces/iListenerService.hpp"

namespace listenerLayer
{
	class Listener : public interface::iListenerService
	{
	public:
		Listener(interface::iListenerMenager* ListenerMenager);
		virtual  ~Listener();
		utils::ErrorCode setStatus(utils::Status status);
		utils::Status getStatus();
		utils::ErrorCode run();
	private:
		interface::iListenerMenager* ListenerMenager;
		utils::Status status;
	};
}
