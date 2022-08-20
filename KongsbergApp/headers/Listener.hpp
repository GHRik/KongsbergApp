#pragma once

#include "../interfaces/iListenerService.hpp"

namespace listenerLayer
{
	class Listener : public interface::iListenerService
	{
	public:
		Listener(interface::iListenerMenager* ListenerMenager);
		virtual  ~Listener();
		utils::ErrorCode run();
		utils::ErrorCode setStatus(utils::Status status);
	private:
		interface::iListenerMenager* ListenerMenager;
		utils::Status status;
	};
}
