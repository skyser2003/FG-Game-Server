#pragma once

template <class Message>
class PksInfo;

template <class Message>
constexpr int GetPKSID()
{
	return PKSInfo<Message>::enumVal;
}