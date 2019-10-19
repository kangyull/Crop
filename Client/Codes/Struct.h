#pragma once

typedef struct vector2 : public D3DXVECTOR2
{
	vector2()
		: D3DXVECTOR2(0.f, 0.f) {}

	vector2(const vector2& v)
		: D3DXVECTOR2(v) {}

	vector2(const float* pVal)
		: D3DXVECTOR2(pVal) {}

	vector2(float x, float y)
		: D3DXVECTOR2(x, y) {}

	float length()					{ return D3DXVec2Length(this); }
	float dot(const vector2* pIn)	{ return D3DXVec2Dot(this, pIn); }

	vector2* normalize(vector2* pOut)	{ return static_cast<vector2*>(D3DXVec2Normalize(pOut, this)); }
} _vec2;

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

	vector3* normalize(vector3* pOut)								{ return static_cast<vector3*>(D3DXVec3Normalize(pOut, this)); }
	vector3* cross(vector3* pOut, const vector3* pIn)				{ return static_cast<vector3*>(D3DXVec3Cross(pOut, this, pIn)); }
	vector3* transformCoord(const D3DXMATRIX* pM)					{ return static_cast<vector3*>(D3DXVec3TransformCoord(this, this, pM)); }
	vector3* transformCoord(vector3* pOut, const D3DXMATRIX* pM)	{ return static_cast<vector3*>(D3DXVec3TransformCoord(pOut, this, pM)); }
	vector3* transformNormal(const D3DXMATRIX* pM)					{ return static_cast<vector3*>(D3DXVec3TransformNormal(this, this, pM)); }
	vector3* transformNormal(vector3* pOut, const D3DXMATRIX* pM)	{ return static_cast<vector3*>(D3DXVec3TransformNormal(pOut, this, pM)); }
} _vec3;

typedef struct vector4 : public D3DXVECTOR4
{
	vector4()
		: D3DXVECTOR4(0.f, 0.f, 0.f, 0.f) {}

	vector4(const vector4& v)
		: D3DXVECTOR4(v) {}

	vector4(const float* pVal)
		: D3DXVECTOR4(pVal) {}

	vector4(float x, float y, float z, float w)
		: D3DXVECTOR4(x, y, z, w) {}

	vector4(const vector3& v, float w)
		: D3DXVECTOR4(v.x, v.y, v.z, w) {}

	float length()					{ return D3DXVec4Length(this); }
	float dot(const vector4* pIn)	{ return D3DXVec4Dot(this, pIn); }
	
	vector4* normalize(vector4* pOut)										{ return static_cast<vector4*>(D3DXVec4Normalize(pOut, this)); }
	vector4* cross(vector4* pOut, const vector4* pIn1, const vector4* pIn2) { return static_cast<vector4*>(D3DXVec4Cross(pOut, this, pIn1, pIn2)); }
} _vec4;