#pragma once

#include "MathVector.h"

namespace PKS
{
	class Vec2;
	class Vec3;
}

namespace ServerShared
{
	PKS::Vec2* Convert(const FTL::Vector2f& vec);

	PKS::Vec2* Convert2XY(const FTL::Vector3f& vec);
	PKS::Vec2* Convert2XZ(const FTL::Vector3f& vec);
	PKS::Vec3* Convert3(const FTL::Vector3f& vec);
}