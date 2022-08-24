#include "../headers/Listener.hpp"


listenerLayer::Listener::Listener(interface::iListenerMenager* listenerMenager, int id , std::string name, int maxValue, int minValue, int frequency)
	: ListenerMenager(listenerMenager), id(id), name(name), maxValue(maxValue), minValue(minValue), frequency(frequency)
{
	listenerMenager->registerListener(this);
}

utils::ErrorCode listenerLayer::Listener::run()
{
	std::chrono::milliseconds timespan(utils::logSleepMilisec);
	this->status = utils::Status::WORK;
	while (this->status == utils::Status::WORK)
	{
		wrappAndLog(this->ListenerMenager->popNotPreparedMessage(this->id));
		std::this_thread::sleep_for(timespan);
	}
	return utils::ErrorCode::OK;
}

void listenerLayer::Listener::wrappAndLog(int message)
{
	std::string prepareMessage = utils::PREFIX_MESSAGE;
	prepareMessage += ", " + std::to_string(this->id) + " ," + this->name + ", " + std::to_string(message) + ", ";

	std::string quality;

	float alarmPercent = utils::alarmPercent;
	float alarmMinValueStart = this->minValue;
	float alarmMinValueStop = alarmMinValueStart + this->maxValue * alarmPercent;
	float alarmMaxValueStop = this->maxValue;
	float alarmMaxValueStart = alarmMaxValueStop - (this->maxValue * alarmPercent);

	float warnPercent = utils::warnPercent;
	float warnMinValueStart = alarmMinValueStop;
	float warnMinValueStop = warnMinValueStart + (this->maxValue * warnPercent);
	float warnMaxValueStop = alarmMaxValueStart;
	float warnMaxValueStart = warnMaxValueStop - (this->maxValue * warnPercent);

	float normalPercent = 100-(alarmPercent * 2 + warnPercent * 2);
	float normalMinValue = this->minValue + (this->minValue * normalPercent);
	float normalMaxValue = this->maxValue + (this->maxValue * normalPercent);

	if ( (message <= alarmMinValueStop) || (message >= alarmMaxValueStart) )
	{
		quality = "ALARM*";
		
	}
	else if ( message > alarmMinValueStop && message <= warnMinValueStop || message > warnMaxValueStart && message < warnMaxValueStop)
	{
		quality = "WARN*";
	}
	else
	{
		quality = "Normal*";
	}
	this->ListenerMenager->logOutput(prepareMessage+quality+"\n");

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