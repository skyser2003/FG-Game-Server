#pragma once

#include <vector>
#include <memory>
#include <functional>

class AbstractMessageNode;
class MessageArgument;

class MessageHub
{
public:
	void AddNode(std::shared_ptr<AbstractMessageNode> node);

	void Send(int id, const MessageArgument& arg1, const MessageArgument& arg2, const MessageArgument& arg3);

private:
	std::vector<std::shared_ptr<AbstractMessageNode>> nodeList;
};