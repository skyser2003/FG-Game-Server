#pragma once

#include <memory>
#include <functional>
#include <unordered_map>

#include "FGConnection.h"

namespace FG
{
	class Server;
}

class Timer;

class AbstractServer
{
public:
	AbstractServer();
	virtual ~AbstractServer();

	virtual void Init(int port) = 0;
	virtual void Destroy() = 0;

	void Update(int dt);

	void AddTask(__int64 delayMs, std::function<void(void)> task);

protected:
	virtual void OnAccept(FG::ConnectionPointer& conn) = 0;

	std::unique_ptr<FG::Server> server;

	int taskID = 0;
	std::unordered_map<int, std::unique_ptr<Timer>> taskList;
};