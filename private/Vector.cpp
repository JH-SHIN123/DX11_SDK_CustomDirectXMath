#pragma once 

#include "../GMath/Vector.h"

using namespace GMath;

FVector2D FVector2D::ZeroVector = { 0.f, 0.f };
FVector2D FVector2D::OneVector	= { 1.f, 1.f };

FVector3D FVector3D::ZeroVector = { 0.f, 0.f, 0.f };
FVector3D FVector3D::OneVector	= { 1.f, 1.f, 1.f };

FVector4D FVector4D::ZeroVector = { 0.f, 0.f, 0.f, 0.f };
FVector4D FVector4D::OneVector	= { 1.f, 1.f, 1.f, 1.f };

FVector3D FVector3D::Axis[EAxis::End] = {
	{ 1.f, 0.f, 0.f },
	{ 0.f, 1.f, 0.f },
	{ 0.f, 0.f, 1.f }};

FVector4D FVector4D::RGBA_Black		= { 0.f, 0.f, 0.f, 1.f };
FVector4D FVector4D::RGBA_White		= { 1.f, 1.f, 1.f, 1.f };
FVector4D FVector4D::RGBA_Red		= { 1.f, 0.f, 0.f, 1.f };
FVector4D FVector4D::RGBA_Green		= { 0.f, 1.f, 0.f, 1.f };
FVector4D FVector4D::RGBA_Blue		= { 0.f, 0.f, 1.f, 1.f };
FVector4D FVector4D::RGBA_Cyan		= { 0.f, 1.f, 1.f, 1.f };
FVector4D FVector4D::RGBA_Magenta	= { 1.f, 0.f, 1.f, 1.f };
FVector4D FVector4D::RGBA_Yellow	= { 1.f, 1.f, 0.f, 1.f };

#pragma region Vector2D

FVector2D::FVector2D()
{
}

FVector2D::FVector2D(float _x, float _y)
	: x(_x), y(_y)
{
}

FVector2D::FVector2D(const FVector2D& v)
	: x(v.x), y(v.y)
{
}

FVector2D::FVector2D(const FVector3D& v)
	: x(v.x), y(v.y)
{
}

FVector2D::FVector2D(FVector2D&& v) noexcept
	: x(v.x), y(v.y)
{
}

const FVector2D& FVector2D:: operator = (const FVector2D& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

const FVector2D& FVector2D:: operator = (float Value)
{
	x = Value;
	y = Value;
	return *this;
}

const FVector2D& FVector2D:: operator = (double Value)
{
	x = (float)Value;
	y = (float)Value;
	return *this;
}

const FVector2D& FVector2D:: operator = (int Value)
{
	x = (float)Value;
	y = (float)Value;
	return *this;
}

bool FVector2D:: operator == (const FVector2D& v)
{
	return fabs(x - v.x) < FLT_EPSILON && fabs(y - v.y) < FLT_EPSILON;
}

bool FVector2D:: operator != (const FVector2D& v)
{
	return fabs(x - v.x) > FLT_EPSILON || fabs(y - v.y) > FLT_EPSILON;
}

float& FVector2D::operator [] (int Index)
{
	assert(0 <= Index && Index <= 1);
	return Index == 0 ? x : y;
}

FVector2D FVector2D::operator + (const FVector2D& v) const
{
	FVector2D	result;
	result.x = x + v.x;
	result.y = y + v.y;
	return result;
}

FVector2D FVector2D::operator + (float Value)	const
{
	FVector2D	result;
	result.x = x + Value;
	result.y = y + Value;
	return result;
}

FVector2D FVector2D::operator + (double Value)	const
{
	FVector2D	result;
	result.x = x + (float)Value;
	result.y = y + (float)Value;
	return result;
}

FVector2D FVector2D::operator + (int Value)	const
{
	FVector2D	result;
	result.x = x + (float)Value;
	result.y = y + (float)Value;
	return result;
}

const FVector2D& FVector2D::operator += (const FVector2D& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

const FVector2D& FVector2D::operator += (float Value)
{
	x += Value;
	y += Value;
	return *this;
}

const FVector2D& FVector2D::operator += (double Value)
{
	x += (float)Value;
	y += (float)Value;
	return *this;
}

const FVector2D& FVector2D::operator += (int Value)
{
	x += (float)Value;
	y += (float)Value;
	return *this;
}

const FVector2D& FVector2D::operator ++ ()
{
	x += 1.f;
	y += 1.f;
	return *this;
}

const FVector2D& FVector2D::operator ++ (int)
{
	x += 1.f;
	y += 1.f;
	return *this;
}

FVector2D FVector2D::operator - (const FVector2D& v) const
{
	FVector2D	result;
	result.x = x - v.x;
	result.y = y - v.y;
	return result;
}

FVector2D FVector2D::operator - (float Value)	const
{
	FVector2D	result;
	result.x = x - Value;
	result.y = y - Value;
	return result;
}

FVector2D FVector2D::operator - (double Value)	const
{
	FVector2D	result;
	result.x = x - (float)Value;
	result.y = y - (float)Value;
	return result;
}

FVector2D FVector2D::operator - (int Value)	const
{
	FVector2D	result;
	result.x = x - (float)Value;
	result.y = y - (float)Value;
	return result;
}

const FVector2D& FVector2D::operator -= (const FVector2D& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

const FVector2D& FVector2D::operator -= (float Value)
{
	x -= Value;
	y -= Value;
	return *this;
}

const FVector2D& FVector2D::operator -= (double Value)
{
	x -= (float)Value;
	y -= (float)Value;
	return *this;
}

const FVector2D& FVector2D::operator -= (int Value)
{
	x -= (float)Value;
	y -= (float)Value;
	return *this;
}

const FVector2D& FVector2D::operator -- ()
{
	x -= 1.f;
	y -= 1.f;
	return *this;
}

const FVector2D& FVector2D::operator -- (int)
{
	x -= 1.f;
	y -= 1.f;
	return *this;
}


FVector2D FVector2D::operator * (const FVector2D& v) const
{
	FVector2D	result;
	result.x = x * v.x;
	result.y = y * v.y;
	return result;
}

FVector2D FVector2D::operator * (float Value)	const
{
	FVector2D	result;
	result.x = x * Value;
	result.y = y * Value;
	return result;
}

FVector2D FVector2D::operator * (double Value)	const
{
	FVector2D	result;
	result.x = x * (float)Value;
	result.y = y * (float)Value;
	return result;
}

FVector2D FVector2D::operator * (int Value)	const
{
	FVector2D	result;
	result.x = x * (float)Value;
	result.y = y * (float)Value;
	return result;
}

const FVector2D& FVector2D::operator *= (const FVector2D& v)
{
	x *= v.x;
	y *= v.y;
	return *this;
}

const FVector2D& FVector2D::operator *= (float Value)
{
	x *= Value;
	y *= Value;
	return *this;
}

const FVector2D& FVector2D::operator *= (double Value)
{
	x *= (float)Value;
	y *= (float)Value;
	return *this;
}

const FVector2D& FVector2D::operator *= (int Value)
{
	x *= (float)Value;
	y *= (float)Value;
	return *this;
}

FVector2D FVector2D::operator / (const FVector2D& v) const
{
	FVector2D	result;
	result.x = x / v.x;
	result.y = y / v.y;
	return result;
}

FVector2D FVector2D::operator / (float Value)	const
{
	FVector2D	result;
	result.x = x / Value;
	result.y = y / Value;
	return result;
}

FVector2D FVector2D::operator / (double Value)	const
{
	FVector2D	result;
	result.x = x / (float)Value;
	result.y = y / (float)Value;
	return result;
}

FVector2D FVector2D::operator / (int Value)	const
{
	FVector2D	result;
	result.x = x / (float)Value;
	result.y = y / (float)Value;
	return result;
}

const FVector2D& FVector2D::operator /= (const FVector2D& v)
{
	x /= v.x;
	y /= v.y;
	return *this;
}

const FVector2D& FVector2D::operator /= (float Value)
{
	x /= Value;
	y /= Value;
	return *this;
}

const FVector2D& FVector2D::operator /= (double Value)
{
	x /= (float)Value;
	y /= (float)Value;
	return *this;
}

const FVector2D& FVector2D::operator /= (int Value)
{
	x /= (float)Value;
	y /= (float)Value;
	return *this;
}

#pragma endregion Vector2D


#pragma region Vector3D

FVector3D::FVector3D()
{
}

FVector3D::FVector3D(float _x, float _y, float _z)
	: x(_x), y(_y), z(_z)
{
}

FVector3D::FVector3D(const FVector3D& v)
	: x(v.x), y(v.y), z(v.z)
{
}

FVector3D::FVector3D(FVector3D&& v) noexcept
	: x(v.x), y(v.y), z(v.z)
{
}

FVector3D::FVector3D(const FVector2D& v)
	: x(v.x), y(v.y), z(0.f)
{
}

FVector3D::FVector3D(const DirectX::XMVECTOR& v)
{
	// XMVECTOR�� XMFLOAT3�� ������ش�.
	DirectX::XMStoreFloat3((DirectX::XMFLOAT3*)this, v);
}

const FVector3D& FVector3D::operator = (const FVector3D& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

const FVector3D& FVector3D::operator = (const DirectX::XMVECTOR& v)
{
	DirectX::XMStoreFloat3((DirectX::XMFLOAT3*)this, v);
	return *this;
}

const FVector3D& FVector3D::operator = (float Value)
{
	x = Value;
	y = Value;
	z = Value;
	return *this;
}

const FVector3D& FVector3D::operator = (double Value)
{
	x = (float)Value;
	y = (float)Value;
	z = (float)Value;
	return *this;
}

const FVector3D& FVector3D::operator = (int Value)
{
	x = (float)Value;
	y = (float)Value;
	z = (float)Value;
	return *this;
}

bool FVector3D::operator == (const FVector3D& v)
{
	return fabs(x - v.x) < FLT_EPSILON &&
		fabs(y - v.y) < FLT_EPSILON &&
		fabs(z - v.z) < FLT_EPSILON;
}

bool FVector3D:: operator != (const FVector3D& v)
{
	return fabs(x - v.x) > FLT_EPSILON ||
		fabs(y - v.y) > FLT_EPSILON ||
		fabs(z - v.z) > FLT_EPSILON;
}

float& FVector3D::operator [] (int Index)
{
	assert(0 <= Index && Index <= 2);

	switch (Index)
	{
	case 0:
		return x;
	case 1:
		return y;
	}

	return z;
}

FVector3D FVector3D::operator + (const FVector3D& v)	const
{
	FVector3D	result;
	result.x = x + v.x;
	result.y = y + v.y;
	result.z = z + v.z;
	return result;
}

FVector3D FVector3D::operator + (float Value)	const
{
	FVector3D	result;
	result.x = x + Value;
	result.y = y + Value;
	result.z = z + Value;
	return result;
}

FVector3D FVector3D::operator + (double Value)	const
{
	FVector3D	result;
	result.x = x + (float)Value;
	result.y = y + (float)Value;
	result.z = z + (float)Value;
	return result;
}

FVector3D FVector3D::operator + (int Value)	const
{
	FVector3D	result;
	result.x = x + (float)Value;
	result.y = y + (float)Value;
	result.z = z + (float)Value;
	return result;
}

const FVector3D& FVector3D::operator += (const FVector3D& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

const FVector3D& FVector3D::operator += (float Value)
{
	x += Value;
	y += Value;
	z += Value;
	return *this;
}

const FVector3D& FVector3D::operator += (double Value)
{
	x += (float)Value;
	y += (float)Value;
	z += (float)Value;
	return *this;
}

const FVector3D& FVector3D::operator += (int Value)
{
	x += (float)Value;
	y += (float)Value;
	z += (float)Value;
	return *this;
}

const FVector3D& FVector3D::operator ++ ()
{
	x += 1.f;
	y += 1.f;
	z += 1.f;
	return *this;
}

const FVector3D& FVector3D::operator ++ (int)
{
	x += 1.f;
	y += 1.f;
	z += 1.f;
	return *this;
}

FVector3D FVector3D::operator - (const FVector3D& v)	const
{
	FVector3D	result;
	result.x = x - v.x;
	result.y = y - v.y;
	result.z = z - v.z;
	return result;
}

FVector3D FVector3D::operator - (float Value)	const
{
	FVector3D	result;
	result.x = x - Value;
	result.y = y - Value;
	result.z = z - Value;
	return result;
}

FVector3D FVector3D::operator - (double Value)	const
{
	FVector3D	result;
	result.x = x - (float)Value;
	result.y = y - (float)Value;
	result.z = z - (float)Value;
	return result;
}

FVector3D FVector3D::operator - (int Value)	const
{
	FVector3D	result;
	result.x = x - (float)Value;
	result.y = y - (float)Value;
	result.z = z - (float)Value;
	return result;
}

FVector3D FVector3D::operator - ()	const
{
	FVector3D	result;
	result.x = -x;
	result.y = -y;
	result.z = -z;
	return result;
}

const FVector3D& FVector3D::operator -= (const FVector3D& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

const FVector3D& FVector3D::operator -= (float Value)
{
	x -= Value;
	y -= Value;
	z -= Value;
	return *this;
}

const FVector3D& FVector3D::operator -= (double Value)
{
	x -= (float)Value;
	y -= (float)Value;
	z -= (float)Value;
	return *this;
}

const FVector3D& FVector3D::operator -= (int Value)
{
	x -= (float)Value;
	y -= (float)Value;
	z -= (float)Value;
	return *this;
}

// --
const FVector3D& FVector3D::operator -- ()
{
	x -= 1.f;
	y -= 1.f;
	z -= 1.f;
	return *this;
}

const FVector3D& FVector3D::operator -- (int)
{
	x -= 1.f;
	y -= 1.f;
	z -= 1.f;
	return *this;
}

FVector3D FVector3D::operator * (const FVector3D& v)	const
{
	FVector3D	result;
	result.x = x * v.x;
	result.y = y * v.y;
	result.z = z * v.z;
	return result;
}

FVector3D FVector3D::operator * (float Value)	const
{
	FVector3D	result;
	result.x = x * Value;
	result.y = y * Value;
	result.z = z * Value;
	return result;
}

FVector3D FVector3D::operator * (double Value)	const
{
	FVector3D	result;
	result.x = x * (float)Value;
	result.y = y * (float)Value;
	result.z = z * (float)Value;
	return result;
}

FVector3D FVector3D::operator * (int Value)	const
{
	FVector3D	result;
	result.x = x * (float)Value;
	result.y = y * (float)Value;
	result.z = z * (float)Value;
	return result;
}

const FVector3D& FVector3D::operator *= (const FVector3D& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

const FVector3D& FVector3D::operator *= (float Value)
{
	x *= Value;
	y *= Value;
	z *= Value;
	return *this;
}

const FVector3D& FVector3D::operator *= (double Value)
{
	x *= (float)Value;
	y *= (float)Value;
	z *= (float)Value;
	return *this;
}

const FVector3D& FVector3D::operator *= (int Value)
{
	x *= (float)Value;
	y *= (float)Value;
	z *= (float)Value;
	return *this;
}

FVector3D FVector3D::operator / (const FVector3D& v)	const
{
	FVector3D	result;
	result.x = x / v.x;
	result.y = y / v.y;
	result.z = z / v.z;
	return result;
}

FVector3D FVector3D::operator / (float Value)	const
{
	FVector3D	result;
	result.x = x / Value;
	result.y = y / Value;
	result.z = z / Value;
	return result;
}

FVector3D FVector3D::operator / (double Value)	const
{
	FVector3D	result;
	result.x = x / (float)Value;
	result.y = y / (float)Value;
	result.z = z / (float)Value;
	return result;
}

FVector3D FVector3D::operator / (int Value)	const
{
	FVector3D	result;
	result.x = x / (float)Value;
	result.y = y / (float)Value;
	result.z = z / (float)Value;
	return result;
}

const FVector3D& FVector3D::operator /= (const FVector3D& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}

const FVector3D& FVector3D::operator /= (float Value)
{
	x /= Value;
	y /= Value;
	z /= Value;
	return *this;
}

const FVector3D& FVector3D::operator /= (double Value)
{
	x /= (float)Value;
	y /= (float)Value;
	z /= (float)Value;
	return *this;
}

const FVector3D& FVector3D::operator /= (int Value)
{
	x /= (float)Value;
	y /= (float)Value;
	z /= (float)Value;
	return *this;
}

#pragma endregion Vector3D


#pragma region Vector4D

FVector4D::FVector4D() 
{
}

FVector4D::FVector4D(float _x, float _y, float _z, float _w)
	: x(_x), y(_y), z(_z), w(_w)
{
}

FVector4D::FVector4D(const FVector4D& v)
	: x(v.x), y(v.y), z(v.z), w(v.w)
{
}
FVector4D::FVector4D(FVector4D&& v) noexcept
	: x(v.x), y(v.y), z(v.z), w(v.w)
{
}
FVector4D::FVector4D(const DirectX::XMVECTOR v)
{
	DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)this, v);
}

const FVector4D& FVector4D::operator = (const FVector4D& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	return *this;
}

const FVector4D& FVector4D::operator = (float Value)
{
	x = Value;
	y = Value;
	z = Value;
	w = Value;
	return *this;
}

const FVector4D& FVector4D::operator = (double Value)
{
	x = (float)Value;
	y = (float)Value;
	z = (float)Value;
	w = (float)Value;
	return *this;
}

const FVector4D& FVector4D::operator = (int Value)
{
	x = (float)Value;
	y = (float)Value;
	z = (float)Value;
	w = (float)Value;
	return *this;
}

bool FVector4D::operator == (const FVector4D& v)
{
	return fabs(x - v.x) < FLT_EPSILON &&
		fabs(y - v.y) < FLT_EPSILON &&
		fabs(z - v.z) < FLT_EPSILON &&
		fabs(w - v.w) < FLT_EPSILON;
}

bool FVector4D::operator != (const FVector4D& v)
{
	return fabs(x - v.x) > FLT_EPSILON ||
		fabs(y - v.y) > FLT_EPSILON ||
		fabs(z - v.z) > FLT_EPSILON ||
		fabs(w - v.w) > FLT_EPSILON;
}

float& FVector4D::operator [] (int Index)
{
	assert(0 <= Index && Index <= 3);

	switch (Index)
	{
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	}

	return w;
}

FVector4D FVector4D::operator + (const FVector4D& v)	const
{
	FVector4D	result;
	result.x = x + v.x;
	result.y = y + v.y;
	result.z = z + v.z;
	result.w = w + v.w;
	return result;
}

FVector4D FVector4D::operator + (float Value)	const
{
	FVector4D	result;
	result.x = x + Value;
	result.y = y + Value;
	result.z = z + Value;
	result.w = w + Value;
	return result;
}

FVector4D FVector4D::operator + (double Value)	const
{
	FVector4D	result;
	result.x = x + (float)Value;
	result.y = y + (float)Value;
	result.z = z + (float)Value;
	result.w = w + (float)Value;
	return result;
}

FVector4D FVector4D::operator + (int Value)	const
{
	FVector4D	result;
	result.x = x + (float)Value;
	result.y = y + (float)Value;
	result.z = z + (float)Value;
	result.w = w + (float)Value;
	return result;
}

const FVector4D& FVector4D::operator += (const FVector4D& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

const FVector4D& FVector4D::operator += (float Value)
{
	x += Value;
	y += Value;
	z += Value;
	w += Value;
	return *this;
}

const FVector4D& FVector4D::operator += (double Value)
{
	x += (float)Value;
	y += (float)Value;
	z += (float)Value;
	w += (float)Value;
	return *this;
}

const FVector4D& FVector4D::operator += (int Value)
{
	x += (float)Value;
	y += (float)Value;
	z += (float)Value;
	w += (float)Value;
	return *this;
}

const FVector4D& FVector4D::operator ++ ()
{
	x += 1.f;
	y += 1.f;
	z += 1.f;
	w += 1.f;
	return *this;
}

const FVector4D& FVector4D::operator ++ (int)
{
	x += 1.f;
	y += 1.f;
	z += 1.f;
	w += 1.f;
	return *this;
}

FVector4D FVector4D::operator - (const FVector4D& v)	const
{
	FVector4D	result;
	result.x = x - v.x;
	result.y = y - v.y;
	result.z = z - v.z;
	result.w = w - v.w;
	return result;
}

FVector4D FVector4D::operator - (float Value)	const
{
	FVector4D	result;
	result.x = x - Value;
	result.y = y - Value;
	result.z = z - Value;
	result.w = w - Value;
	return result;
}

FVector4D FVector4D::operator - (double Value)	const
{
	FVector4D	result;
	result.x = x - (float)Value;
	result.y = y - (float)Value;
	result.z = z - (float)Value;
	result.w = w - (float)Value;
	return result;
}

FVector4D FVector4D::operator - (int Value)	const
{
	FVector4D	result;
	result.x = x - (float)Value;
	result.y = y - (float)Value;
	result.z = z - (float)Value;
	result.w = w - (float)Value;
	return result;
}

const FVector4D& FVector4D::operator -= (const FVector4D& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}

const FVector4D& FVector4D::operator -= (float Value)
{
	x -= Value;
	y -= Value;
	z -= Value;
	w -= Value;
	return *this;
}

const FVector4D& FVector4D::operator -= (double Value)
{
	x -= (float)Value;
	y -= (float)Value;
	z -= (float)Value;
	w -= (float)Value;
	return *this;
}

const FVector4D& FVector4D::operator -= (int Value)
{
	x -= (float)Value;
	y -= (float)Value;
	z -= (float)Value;
	w -= (float)Value;
	return *this;
}

// --
const FVector4D& FVector4D::operator -- ()
{
	x -= 1.f;
	y -= 1.f;
	z -= 1.f;
	w -= 1.f;
	return *this;
}

const FVector4D& FVector4D::operator -- (int)
{
	x -= 1.f;
	y -= 1.f;
	z -= 1.f;
	w -= 1.f;
	return *this;
}

FVector4D FVector4D::operator * (const FVector4D& v)	const
{
	FVector4D	result;
	result.x = x * v.x;
	result.y = y * v.y;
	result.z = z * v.z;
	result.w = w * v.w;
	return result;
}

FVector4D FVector4D::operator * (float Value)	const
{
	FVector4D	result;
	result.x = x * Value;
	result.y = y * Value;
	result.z = z * Value;
	result.w = w * Value;
	return result;
}

FVector4D FVector4D::operator * (double Value)	const
{
	FVector4D	result;
	result.x = x * (float)Value;
	result.y = y * (float)Value;
	result.z = z * (float)Value;
	result.w = w * (float)Value;
	return result;
}

FVector4D FVector4D::operator * (int Value)	const
{
	FVector4D	result;
	result.x = x * (float)Value;
	result.y = y * (float)Value;
	result.z = z * (float)Value;
	result.w = w * (float)Value;
	return result;
}

const FVector4D& FVector4D::operator *= (const FVector4D& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;
	return *this;
}

const FVector4D& FVector4D::operator *= (float Value)
{
	x *= Value;
	y *= Value;
	z *= Value;
	w *= Value;
	return *this;
}

const FVector4D& FVector4D::operator *= (double Value)
{
	x *= (float)Value;
	y *= (float)Value;
	z *= (float)Value;
	w *= (float)Value;
	return *this;
}

const FVector4D& FVector4D::operator *= (int Value)
{
	x *= (float)Value;
	y *= (float)Value;
	z *= (float)Value;
	w *= (float)Value;
	return *this;
}

FVector4D FVector4D::operator / (const FVector4D& v)	const
{
	FVector4D	result;
	result.x = x / v.x;
	result.y = y / v.y;
	result.z = z / v.z;
	result.w = w / v.w;
	return result;
}

FVector4D FVector4D::operator / (float Value)	const
{
	FVector4D	result;
	result.x = x / Value;
	result.y = y / Value;
	result.z = z / Value;
	result.w = w / Value;
	return result;
}

FVector4D FVector4D::operator / (double Value)	const
{
	FVector4D	result;
	result.x = x / (float)Value;
	result.y = y / (float)Value;
	result.z = z / (float)Value;
	result.w = w / (float)Value;
	return result;
}

FVector4D FVector4D::operator / (int Value)	const
{
	FVector4D	result;
	result.x = x / (float)Value;
	result.y = y / (float)Value;
	result.z = z / (float)Value;
	result.w = w / (float)Value;
	return result;
}

const FVector4D& FVector4D::operator /= (const FVector4D& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;
	return *this;
}

const FVector4D& FVector4D::operator /= (float Value)
{
	x /= Value;
	y /= Value;
	z /= Value;
	w /= Value;
	return *this;
}

const FVector4D& FVector4D::operator /= (double Value)
{
	x /= (float)Value;
	y /= (float)Value;
	z /= (float)Value;
	w /= (float)Value;
	return *this;
}

const FVector4D& FVector4D::operator /= (int Value)
{
	x /= (float)Value;
	y /= (float)Value;
	z /= (float)Value;
	w /= (float)Value;
	return *this;
}

#pragma endregion Vector4D