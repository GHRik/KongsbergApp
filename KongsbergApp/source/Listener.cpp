#include "../headers/Listener.hpp"


listenerLayer::Listener::Listener(interface::iListenerMenager* listenerMenager, int id , std::string name, int maxValue, int minValue, int frequency)
{
	this->ListenerMenager = listenerMenager;
	this->id = id;
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
	std::chrono::milliseconds timespan(10);
	this->status = utils::Status::WORK;
	while (this->status == utils::Status::WORK)
	{
		std::cout << this->ListenerMenager->popNotPreparedMessage(this->id);
		std::this_thread::sleep_for(timespan);
	}
	return utils::ErrorCode::OK;
}

//void wrappAndLog

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
		if (this->status == utils::Status::WORK)
		{
			this->status = utils::Status::STOP;
			this->thread.join();
		}
		this->status = utils::Status::STOP;
		break;

	}
	return utils::ErrorCode::OK;
}