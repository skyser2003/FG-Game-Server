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
	std::vector<int> doneList;

	for (auto& pair : taskList)
	{
		auto& timer = pair.second;
		if (timer->Update() == true)
		{
			doneList.push_back(pair.first);
		}
	}

	for(auto index : doneList)
	{
		taskList.erase(index);
	}
}

void AbstractServer::AddTask(__int64 delayMs, std::function<void(void)> task)
{
	auto* timer = new Timer();
	timer->Init(delayMs, task);
	timer->Start();

	taskList.emplace(taskID++,timer);
}
