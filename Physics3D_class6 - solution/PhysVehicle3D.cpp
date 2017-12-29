#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;

	wheel.color = Black;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());

	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();


	chassis.Render();
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Bababooey()
{
	float connection_height = 1.2f;
	float wheel_radius = 0.3f;
	float wheel_width = 0.3f;
	float suspensionRestLength = 0.9f;

	float half_width = info.chassis_size.x*0.5f;
	float half_length = info.chassis_size.z*0.5f;

	vec3 direction(0, -1, 0);
	vec3 axis(-1, 0, 0);

	// FRONT-LEFT ------------------------
	info.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	info.wheels[0].direction = direction;
	info.wheels[0].axis = axis;
	info.wheels[0].suspensionRestLength = suspensionRestLength;
	info.wheels[0].radius = wheel_radius;
	info.wheels[0].width = wheel_width;
	info.wheels[0].front = false;
	info.wheels[0].drive = false;
	info.wheels[0].brake = true;
	info.wheels[0].steering = false;

	// FRONT-RIGHT ------------------------
	info.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	info.wheels[1].direction = direction;
	info.wheels[1].axis = axis;
	info.wheels[1].suspensionRestLength = suspensionRestLength;
	info.wheels[1].radius = wheel_radius;
	info.wheels[1].width = wheel_width;
	info.wheels[1].front = false;
	info.wheels[1].drive = false;
	info.wheels[1].brake = true;
	info.wheels[1].steering = false;

	// REAR-LEFT ------------------------
	info.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	info.wheels[2].direction = direction;
	info.wheels[2].axis = axis;
	info.wheels[2].suspensionRestLength = suspensionRestLength;
	info.wheels[2].radius = wheel_radius;
	info.wheels[2].width = wheel_width;
	info.wheels[2].front = true;
	info.wheels[2].drive = true;
	info.wheels[2].brake = false;
	info.wheels[2].steering = true;

	// REAR-RIGHT ------------------------
	info.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	info.wheels[3].direction = direction;
	info.wheels[3].axis = axis;
	info.wheels[3].suspensionRestLength = suspensionRestLength;
	info.wheels[3].radius = wheel_radius;
	info.wheels[3].width = wheel_width;
	info.wheels[3].front = true;
	info.wheels[3].drive = true;
	info.wheels[3].brake = false;
	info.wheels[3].steering = true;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Bababooey2()
{
	float connection_height = 1.2f;
	float wheel_radius = 0.3f;
	float wheel_width = 0.3f;
	float suspensionRestLength = 0.9f;

	float half_width = info.chassis_size.x*0.5f;
	float half_length = info.chassis_size.z*0.5f;

	vec3 direction(0, -1, 0);
	vec3 axis(-1, 0, 0);

	info.num_wheels = 4;
	info.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	info.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	info.wheels[0].direction = direction;
	info.wheels[0].axis = axis;
	info.wheels[0].suspensionRestLength = suspensionRestLength;
	info.wheels[0].radius = wheel_radius;
	info.wheels[0].width = wheel_width;
	info.wheels[0].front = true;
	info.wheels[0].drive = true;
	info.wheels[0].brake = false;
	info.wheels[0].steering = true;
	
	// FRONT-RIGHT ------------------------
	info.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	info.wheels[1].direction = direction;
	info.wheels[1].axis = axis;
	info.wheels[1].suspensionRestLength = suspensionRestLength;
	info.wheels[1].radius = wheel_radius;
	info.wheels[1].width = wheel_width;
	info.wheels[1].front = true;
	info.wheels[1].drive = true;
	info.wheels[1].brake = false;
	info.wheels[1].steering = true;
	
	// REAR-LEFT ------------------------
	info.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	info.wheels[2].direction = direction;
	info.wheels[2].axis = axis;
	info.wheels[2].suspensionRestLength = suspensionRestLength;
	info.wheels[2].radius = wheel_radius;
	info.wheels[2].width = wheel_width;
	info.wheels[2].front = false;
	info.wheels[2].drive = false;
	info.wheels[2].brake = true;
	info.wheels[2].steering = false;
	
	// REAR-RIGHT ------------------------
	info.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	info.wheels[3].direction = direction;
	info.wheels[3].axis = axis;
	info.wheels[3].suspensionRestLength = suspensionRestLength;
	info.wheels[3].radius = wheel_radius;
	info.wheels[3].width = wheel_width;
	info.wheels[3].front = false;
	info.wheels[3].drive = false;
	info.wheels[3].brake = true;
	info.wheels[3].steering = false;
}