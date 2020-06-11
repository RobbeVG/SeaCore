#pragma once
#include "Helpers/EnumHelpers.h"

namespace sea_core
{
	namespace Messages
	{
		enum class MonoBehaviour : unsigned int
		{
			OnStart,
			OnGui,
			OnDisable,
			OnEnable,
			OnCollisionEnter,
			OnCollisionExit
		};

		ENUM_CONVERT(MonoBehaviour)
		
	}
}
