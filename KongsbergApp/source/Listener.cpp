#include "../headers/Listener.hpp"


listenerLayer::Listener::Listener(interface::iListenerMenager* listenerMenager, std::string name, int maxValue, int minValue, int frequency)
{
	this->ListenerMenager = listenerMenager;
	this->name = name;
	this->maxValue = maxValue;
	this->minValue = minValue;
	this->frequency = frequency;
	listenerMenager->registerListener(this);
}

listenerLayer::Listener::~Listener()
{

}

utils::ErrorCode listenerLayer::Listener::run()
{
	std::chrono::seconds timespan(this->frequency);
	this->status = utils::Status::WORK;
	while (this->status == utils::Status::WORK)
	{
		std::cout << this->name;
		std::this_thread::sleep_for(timespan);
	}
	return utils::ErrorCode::OK;
}

utils::ErrorCode listenerLayer::Listener::setStatus(utils::Status status)
{
	switch (status)
	{
	case utils::Status::INIT:
		this->status = utils::Status::INIT;
		break;
	case utils::Status::START:
		this->status = utils::Status::START;
		break;
	case utils::Status::WORK:
		this->thread = std::thread(&listenerLayer::Listener::run, this);
		this->status = utils::Status::WORK;
		break;
	case utils::Status::STOP:
		this->status = utils::Status::STOP;
		this->thread.join();

		break;

	}
	return utils::ErrorCode::OK;
}