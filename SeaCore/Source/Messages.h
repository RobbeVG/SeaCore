#pragma once
#include "Helpers/EnumHelpers.h"

namespace sea_core
{
	namespace EventMessages
	{
		enum class Types : unsigned short int
		{
			MonoBehaviour
		};
		
		enum class MonoBehaviour : unsigned short int
		{
			OnStart,
			OnGui,
			OnDisable,
			OnEnable,
			OnCollisionEnter,
			OnCollisionExit
		};		
	}
}
