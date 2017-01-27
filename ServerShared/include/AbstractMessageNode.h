#pragma once

class MessageHub;
class MessageArgument;

class AbstractMessageNode
{
public:
	virtual void Receive(int id, const MessageArgument& arg1, const MessageArgument& arg2, const MessageArgument& arg3) = 0;

	void Init(MessageHub* hub);

private:
	MessageHub* hub;
};