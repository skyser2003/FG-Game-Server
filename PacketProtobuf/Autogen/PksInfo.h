#pragma once

#include "enum/enum_cm.pb.h"
#include "enum/enum_mc.pb.h"
#include "enum/enum_cz.pb.h"
#include "enum/enum_zc.pb.h"

#include "struct/struct_cm.pb.h"
#include "struct/struct_mc.pb.h"
#include "struct/struct_cz.pb.h"
#include "struct/struct_zc.pb.h"

// Declaration only
template <class PKS>
class PKSInfo;

template <>
class PKSInfo<PKS::CM_JOIN_MEMBER>
{
public:
	static const PKENUM::CMPacketEnum enumVal = PKENUM::CMPacketEnum::CM_JOIN_MEMBER;
};

template <>
class PKSInfo<PKS::CM_LOGIN>
{
public:
	static const PKENUM::CMPacketEnum enumVal = PKENUM::CMPacketEnum::CM_LOGIN;
};

template <>
class PKSInfo<PKS::CM_SET_FAMILY_NAME>
{
public:
	static const PKENUM::CMPacketEnum enumVal = PKENUM::CMPacketEnum::CM_SET_FAMILY_NAME;
};

template <>
class PKSInfo<PKS::CZ_MOVE>
{
public:
	static const PKENUM::CZPacketEnum enumVal = PKENUM::CZPacketEnum::CZ_MOVE;
};

template <>
class PKSInfo<PKS::CZ_STOP>
{
public:
	static const PKENUM::CZPacketEnum enumVal = PKENUM::CZPacketEnum::CZ_STOP;
};

template <>
class PKSInfo<PKS::CZ_EVADE>
{
public:
	static const PKENUM::CZPacketEnum enumVal = PKENUM::CZPacketEnum::CZ_EVADE;
};

template <>
class PKSInfo<PKS::CZ_ENTER_GAME>
{
public:
	static const PKENUM::CZPacketEnum enumVal = PKENUM::CZPacketEnum::CZ_ENTER_GAME;
};

template <>
class PKSInfo<PKS::CZ_ATTACK>
{
public:
	static const PKENUM::CZPacketEnum enumVal = PKENUM::CZPacketEnum::CZ_ATTACK;
};

template <>
class PKSInfo<PKS::CZ_ATTACK_HIT>
{
public:
	static const PKENUM::CZPacketEnum enumVal = PKENUM::CZPacketEnum::CZ_ATTACK_HIT;
};

template <>
class PKSInfo<PKS::CZ_REVIVE>
{
public:
	static const PKENUM::CZPacketEnum enumVal = PKENUM::CZPacketEnum::CZ_REVIVE;
};

template <>
class PKSInfo<PKS::CZ_USE_HP_POTION>
{
public:
	static const PKENUM::CZPacketEnum enumVal = PKENUM::CZPacketEnum::CZ_USE_HP_POTION;
};

template <>
class PKSInfo<PKS::CZ_PING>
{
public:
	static const PKENUM::CZPacketEnum enumVal = PKENUM::CZPacketEnum::CZ_PING;
};

template <>
class PKSInfo<PKS::MC_JOIN_MEMBER_RESULT>
{
public:
	static const PKENUM::MCPacketEnum enumVal = PKENUM::MCPacketEnum::MC_JOIN_MEMBER_RESULT;
};

template <>
class PKSInfo<PKS::MC_LOGIN_RESULT>
{
public:
	static const PKENUM::MCPacketEnum enumVal = PKENUM::MCPacketEnum::MC_LOGIN_RESULT;
};

template <>
class PKSInfo<PKS::MC_SET_FAMILY_NAME_RESULT>
{
public:
	static const PKENUM::MCPacketEnum enumVal = PKENUM::MCPacketEnum::MC_SET_FAMILY_NAME_RESULT;
};

template <>
class PKSInfo<PKS::ZC_ME_CONNECTED>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_ME_CONNECTED;
};

template <>
class PKSInfo<PKS::ZC_OTHER_USER_CONNECTED>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_OTHER_USER_CONNECTED;
};

template <>
class PKSInfo<PKS::ZC_EXIST_USER_INFORMATION>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_EXIST_USER_INFORMATION;
};

template <>
class PKSInfo<PKS::ZC_USER_DISCONNECTED>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_USER_DISCONNECTED;
};

template <>
class PKSInfo<PKS::ZC_MONSTER_APPEARED>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_MONSTER_APPEARED;
};

template <>
class PKSInfo<PKS::ZC_MOVE>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_MOVE;
};

template <>
class PKSInfo<PKS::ZC_STOP>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_STOP;
};

template <>
class PKSInfo<PKS::ZC_EVADE>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_EVADE;
};

template <>
class PKSInfo<PKS::ZC_DIED>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_DIED;
};

template <>
class PKSInfo<PKS::ZC_REVIVE>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_REVIVE;
};

template <>
class PKSInfo<PKS::ZC_USE_HP_POTION>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_USE_HP_POTION;
};

template <>
class PKSInfo<PKS::ZC_MOVE_DEST>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_MOVE_DEST;
};

template <>
class PKSInfo<PKS::ZC_ENTER_FIELD>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_ENTER_FIELD;
};

template <>
class PKSInfo<PKS::ZC_ATTACK>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_ATTACK;
};

template <>
class PKSInfo<PKS::ZC_GET_HIT>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_GET_HIT;
};

template <>
class PKSInfo<PKS::ZC_DEAD>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_DEAD;
};

template <>
class PKSInfo<PKS::ZC_PING>
{
public:
	static const PKENUM::ZCPacketEnum enumVal = PKENUM::ZCPacketEnum::ZC_PING;
};
