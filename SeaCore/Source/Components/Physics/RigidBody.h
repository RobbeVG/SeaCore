#pragma once
#include <Box2D/Dynamics/b2Body.h>
#include "PhysicsComponent.h"

namespace sea_core
{
	//Needs a transform component!
    struct RigidBodyDesc;

	/**
	 * @note Adding a rigidbody disables the setter functions on the Transform Component.
	 * -> Still want to move? Use a movementComponent or a Monobehaviour
	 */
    class RigidBody : public PhysicsComponent
    {
    public:
        enum Type
        {
            Static,
            Kinematic,
            Dynamic
        };

		void FixedUpdate() override;
    	
        RigidBody(Transform* pTransform, const RigidBodyDesc& desc);
		b2Body* GetBody() const { return m_pBody; };

    private:
        Transform* m_pTransform; //---> DISGUSTING
        b2Body* m_pBody;
    };

	struct RigidBodyDesc
	{	
		/// The body type: static, kinematic, or dynamic.
		/// Note: if a dynamic body would have zero mass, the mass is set to one.
        RigidBody::Type type = RigidBody::Static;

		/// The linear velocity of the body's origin in world co-ordinates.
		b2Vec2 linearVelocity = b2Vec2(0.0f, 0.0f);
		

		/// The angular velocity of the body.
		float angularVelocity = 0.0f;

		/// Linear damping is use to reduce the linear velocity. The damping parameter
		/// can be larger than 1.0f but the damping effect becomes sensitive to the
		/// time step when the damping parameter is large.
		float linearDamping = 0.0f;

		/// Angular damping is use to reduce the angular velocity. The damping parameter
		/// can be larger than 1.0f but the damping effect becomes sensitive to the
		/// time step when the damping parameter is large.
		float angularDamping = 0.0f;

		/// Set this flag to false if this body should never fall asleep. Note that
		/// this increases CPU usage.
		bool allowSleep = true;

		/// Is this body initially awake or sleeping?
		bool awake = true;

		/// Should this body be prevented from rotating? Useful for characters.
		bool fixedRotation = false;

		/// Is this a fast moving body that should be prevented from tunneling through
		/// other moving bodies? Note that all bodies are prevented from tunneling through
		/// kinematic and static bodies. This setting is only considered on dynamic bodies.
		/// @warning You should use this flag sparingly since it increases processing time.
		bool bullet = false;

		/// Does this body start out active?
		bool active = true;

		/// Scale the gravity applied to this body.
		float gravityScale = 1.0f;
	};
}