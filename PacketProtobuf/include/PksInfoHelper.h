#pragma once

template <class Message>
class PKSInfo;

template <class Message>
constexpr int GetPKSID()
{
	return PKSInfo<Message>::enumVal;
}