#pragma once

typedef struct vector3 : public D3DXVECTOR3
{
	vector3()
		: D3DXVECTOR3(0.f, 0.f, 0.f) {}

	vector3(const vector3& v)
		: D3DXVECTOR3(v) {}

	vector3(const float* pVal)
		: D3DXVECTOR3(pVal) {}
	
	vector3(float x, float y, float z)
		: D3DXVECTOR3(x, y, z) {}

	float length()									{ return D3DXVec3Length(this); }
	float dot(const vector3* pIn)					{ return D3DXVec3Dot(this, pIn); }

	vector3* normalize(vector3* pOut)					{ return static_cast<vector3*>(D3DXVec3Normalize(pOut, this)); }
	vector3* cross(vector3* pOut, const vector3* pIn)	{ return static_cast<vector3*>(D3DXVec3Cross(pOut, this, pIn)); }
} _vec3;