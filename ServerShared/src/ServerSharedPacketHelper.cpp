#include "stdafx.h"
#include "ServerSharedPacketHelper.h"

#include "etc/struct_etc.pb.h"

namespace ServerShared
{
	PKS::Vec2* Convert(const FTL::Vector2f& vec)
	{
		auto* ret = new PKS::Vec2();
		ret->set_x(vec.X.get());
		ret->set_y(vec.Y.get());

		return ret;
	}

	PKS::Vec2* Convert2XY(const FTL::Vector3f& vec)
	{
		auto* ret = new PKS::Vec2();
		ret->set_x(vec.X.get());
		ret->set_y(vec.Y.get());

		return ret;
	}

	PKS::Vec2* Convert2XZ(const FTL::Vector3f& vec)
	{
		auto* ret = new PKS::Vec2();
		ret->set_x(vec.X.get());
		ret->set_y(vec.Z.get());

		return ret;
	}

	PKS::Vec3* Convert3(const FTL::Vector3f& vec)
	{
		auto* ret = new PKS::Vec3();
		ret->set_x(vec.X.get());
		ret->set_y(vec.Y.get());
		ret->set_z(vec.Z.get());

		return ret;
	}
}