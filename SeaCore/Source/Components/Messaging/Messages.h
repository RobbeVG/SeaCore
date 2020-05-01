#pragma once
namespace sea_core
{
	namespace Messages
	{
		enum class General : unsigned int
		{
			Start = 0,
			Render = 1,
			Update = 2,
			FixedUpdate = 3,
			LateUpdate = 4,
			OnGui = 5,
			OnDisable = 6,
			OnEnable = 7
		};

		//Al other messages should start from 8!
		
		enum class MonoBehaviour : unsigned int
		{
			OnCollisionEnter	= 8,
			OnCollisionExit		= 9
		};
	}
}
