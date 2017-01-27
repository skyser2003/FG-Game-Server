#include "stdafx.h"
#include "MessageArgument.h"

MessageArgument::MessageArgument(int val)
{
	this->val.i = val;
}

MessageArgument::MessageArgument(float val)
{
	this->val.f = val;
}

MessageArgument::MessageArgument(void* val)
{
	this->val.v = val;
}

int MessageArgument::Int() const
{
	return val.i;
}

float MessageArgument::Float() const
{
	return val.f;
}

void * MessageArgument::VoidPointer() const
{
	return val.v;
}