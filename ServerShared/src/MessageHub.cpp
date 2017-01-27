#include "stdafx.h"
#include "MessageHub.h"

#include "AbstractMessageNode.h"

void MessageHub::AddNode(std::shared_ptr<AbstractMessageNode> node)
{
	nodeList.push_back(node);
}

void MessageHub::Send(int id, const MessageArgument& arg1, const MessageArgument& arg2, const MessageArgument& arg3)
{
	for (auto& node : nodeList)
	{
		node->Receive(id, arg1, arg2, arg3);
	}
}