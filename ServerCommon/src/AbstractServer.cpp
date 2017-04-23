#include "stdafx.h"
#include "AbstractServer.h"

#include "NetworkClient.h"
#include "FGServer.h"
#include "Timer.h"

AbstractServer::AbstractServer() : server(new FG::Server)
{

}

AbstractServer::~AbstractServer()
{

}

void AbstractServer::Init(int port)
{
	server->Bind(port);
	server->Listen();
	server->SetAcceptHandler(std::bind(&AbstractServer::OnAccept, this, std::placeholders::_1));
}

void AbstractServer::Update(int dt)
{
	for (auto& pair : taskList)
	{
		auto& timer = pair.second;
		bool done = timer->Update();
		if (done == true)
		{
			taskList.erase(pair.first);
		}
	}
}

void AbstractServer::AddTask(__int64 delayMs, std::function<void(void)> task)
{
	auto* timer = new Timer();
	timer->Init(delayMs, task);
	timer->Start();

	taskList.emplace(taskID++,timer);
}
