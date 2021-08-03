#pragma once
class Vec3
{
	float _x, _y, _z;
public:
	Vec3():_x(0.0f), _y(0.0f), _z(0.0f) {}
	Vec3(float x, float y):_x(x), _y(y), _z(0) {}
	Vec3(const Vec3& x) :_x(x._x), _y(x._y), _z(x._z) {}
	Vec3(float x, float y, float z):_x(x), _y(y), _z(z) {}
	

	float x()const { return  _x; }
	float y()const { return _y; }
	float z()const { return _z; }

	
	Vec3 operator=(Vec3& newVector)
	{
		_x = newVector.x();
		_y = newVector.y();
		_z = newVector.z();
		return Vec3(_x,_y,_z);
	}

	static Vec3 Zero()
	{
		return Vec3(0.0f, 0.0f, 0.0f);
	}

};

