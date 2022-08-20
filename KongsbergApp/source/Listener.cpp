#include "../headers/Listener.hpp"


listenerLayer::Listener::Listener(interface::iListenerMenager* ListenerMenager)
{

}

listenerLayer::Listener::~Listener()
{

}

utils::ErrorCode listenerLayer::Listener::run()
{
	return utils::ErrorCode::NOK;
}