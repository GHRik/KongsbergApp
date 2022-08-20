#include "../headers/Listener.hpp"


listenerLayer::Listener::Listener(interface::iListenerMenager* ListenerMenager)
{

}

listenerLayer::Listener::~Listener()
{

}

utils::ErrorCode listenerLayer::Listener::setStatus(utils::Status)
{
	return utils::ErrorCode::NOK;
}

utils::Status listenerLayer::Listener::getStatus()
{
	return utils::Status::START;
}

utils::ErrorCode listenerLayer::Listener::run()
{
	return utils::ErrorCode::NOK;
}