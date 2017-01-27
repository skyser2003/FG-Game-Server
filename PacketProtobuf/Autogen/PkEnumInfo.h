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
template <int ENUM>
class PKENUMInfo;

template <>
class PKENUMInfo<static_cast<int>(PKENUM::CMPacketEnum::CM_JOIN_MEMBER)>
{
public:
	using PKS = PKS::CM_JOIN_MEMBER;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::CMPacketEnum::CM_LOGIN)>
{
public:
	using PKS = PKS::CM_LOGIN;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::CMPacketEnum::CM_SET_FAMILY_NAME)>
{
public:
	using PKS = PKS::CM_SET_FAMILY_NAME;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::CZPacketEnum::CZ_MOVE)>
{
public:
	using PKS = PKS::CZ_MOVE;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::CZPacketEnum::CZ_STOP)>
{
public:
	using PKS = PKS::CZ_STOP;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::CZPacketEnum::CZ_EVADE)>
{
public:
	using PKS = PKS::CZ_EVADE;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::CZPacketEnum::CZ_ENTER_GAME)>
{
public:
	using PKS = PKS::CZ_ENTER_GAME;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::CZPacketEnum::CZ_ATTACK)>
{
public:
	using PKS = PKS::CZ_ATTACK;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::CZPacketEnum::CZ_ATTACK_HIT)>
{
public:
	using PKS = PKS::CZ_ATTACK_HIT;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::CZPacketEnum::CZ_REVIVE)>
{
public:
	using PKS = PKS::CZ_REVIVE;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::CZPacketEnum::CZ_USE_HP_POTION)>
{
public:
	using PKS = PKS::CZ_USE_HP_POTION;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::CZPacketEnum::CZ_PING)>
{
public:
	using PKS = PKS::CZ_PING;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::MCPacketEnum::MC_JOIN_MEMBER_RESULT)>
{
public:
	using PKS = PKS::MC_JOIN_MEMBER_RESULT;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::MCPacketEnum::MC_LOGIN_RESULT)>
{
public:
	using PKS = PKS::MC_LOGIN_RESULT;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::MCPacketEnum::MC_SET_FAMILY_NAME_RESULT)>
{
public:
	using PKS = PKS::MC_SET_FAMILY_NAME_RESULT;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_ME_CONNECTED)>
{
public:
	using PKS = PKS::ZC_ME_CONNECTED;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_OTHER_USER_CONNECTED)>
{
public:
	using PKS = PKS::ZC_OTHER_USER_CONNECTED;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_EXIST_USER_INFORMATION)>
{
public:
	using PKS = PKS::ZC_EXIST_USER_INFORMATION;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_USER_DISCONNECTED)>
{
public:
	using PKS = PKS::ZC_USER_DISCONNECTED;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_MONSTER_APPEARED)>
{
public:
	using PKS = PKS::ZC_MONSTER_APPEARED;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_MOVE)>
{
public:
	using PKS = PKS::ZC_MOVE;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_STOP)>
{
public:
	using PKS = PKS::ZC_STOP;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_EVADE)>
{
public:
	using PKS = PKS::ZC_EVADE;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_DIED)>
{
public:
	using PKS = PKS::ZC_DIED;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_REVIVE)>
{
public:
	using PKS = PKS::ZC_REVIVE;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_USE_HP_POTION)>
{
public:
	using PKS = PKS::ZC_USE_HP_POTION;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_MOVE_DEST)>
{
public:
	using PKS = PKS::ZC_MOVE_DEST;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_ENTER_FIELD)>
{
public:
	using PKS = PKS::ZC_ENTER_FIELD;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_ATTACK)>
{
public:
	using PKS = PKS::ZC_ATTACK;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_GET_HIT)>
{
public:
	using PKS = PKS::ZC_GET_HIT;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_DEAD)>
{
public:
	using PKS = PKS::ZC_DEAD;
};

template <>
class PKENUMInfo<static_cast<int>(PKENUM::ZCPacketEnum::ZC_PING)>
{
public:
	using PKS = PKS::ZC_PING;
};
