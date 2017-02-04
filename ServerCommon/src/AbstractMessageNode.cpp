#include "stdafx.h"
#include "AbstractMessageNode.h"

void AbstractMessageNode::Init(MessageHub* hub)
{
	this->hub = hub;
}