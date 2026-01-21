#pragma once

#include <DirectXMath.h>
#include <DirectXPackedVector.h>

/*
Vector2D, 3D, 4D Declaration
Add operator override only, handle other related mathematical functions separately

Vector2D, 3D, 4D 선언
연산자 재정의만 추가, 기타 관련된 수학기능 함수는 따로 처리

GameInfo_Math 헤더 확인
*/

namespace GMath
{
	namespace EAxis
	{
		enum Type : char
		{
			None = -1,
			X, Y, Z,
			End
		};
	}

	struct FVector2D
	{
		static FVector2D ZeroVector;
		static FVector2D OneVector;

		float	x = 0.f;
		float	y = 0.f;

#pragma region Construction

		FVector2D();
		FVector2D(float _x, float _y);
		FVector2D(const FVector2D& v);
		FVector2D(const struct FVector3D& v);
		FVector2D(FVector2D&& v) noexcept;

#pragma endregion Construction

#pragma region Equal

		const FVector2D& operator = (const FVector2D& v);
		const FVector2D& operator = (float Value);
		const FVector2D& operator = (double Value);
		const FVector2D& operator = (int Value);

		bool operator == (const FVector2D& v);
		bool operator != (const FVector2D& v);

		float& operator [] (int Index);

#pragma endregion Equal

#pragma region Plus
		// +
		FVector2D operator + (const FVector2D& v) const;
		FVector2D operator + (float Value) const;
		FVector2D operator + (double Value)	const;
		FVector2D operator + (int Value) const;

		// +=
		const FVector2D& operator += (const FVector2D& v);
		const FVector2D& operator += (float Value);
		const FVector2D& operator += (double Value);
		const FVector2D& operator += (int Value);

		// ++
		const FVector2D& operator ++ ();
		const FVector2D& operator ++ (int);

#pragma endregion Plus

#pragma region Minus
		// -
		FVector2D operator - (const FVector2D& v)	const;
		FVector2D operator - (float Value)	const;
		FVector2D operator - (double Value)	const;
		FVector2D operator - (int Value)	const;
		// -=
		const FVector2D& operator -= (const FVector2D& v);
		const FVector2D& operator -= (float Value);
		const FVector2D& operator -= (double Value);
		const FVector2D& operator -= (int Value);

		// --
		const FVector2D& operator -- ();
		const FVector2D& operator -- (int);

#pragma endregion Minus

#pragma region Multiply

		// *
		FVector2D operator * (const FVector2D& v)	const;
		FVector2D operator * (float Value)	const;
		FVector2D operator * (double Value)	const;
		FVector2D operator * (int Value)	const;

		// *=
		const FVector2D& operator *= (const FVector2D& v);
		const FVector2D& operator *= (float Value);
		const FVector2D& operator *= (double Value);
		const FVector2D& operator *= (int Value);

#pragma endregion Multiply

#pragma region Divide

		// /
		FVector2D operator / (const FVector2D& v) const;
		FVector2D operator / (float Value) const;
		FVector2D operator / (double Value)	const;
		FVector2D operator / (int Value) const;

		// /=
		const FVector2D& operator /= (const FVector2D& v);
		const FVector2D& operator /= (float Value);
		const FVector2D& operator /= (double Value);
		const FVector2D& operator /= (int Value);

#pragma endregion Divide
	};

	struct FVector3D
	{
		static FVector3D ZeroVector;
		static FVector3D OneVector;
		static FVector3D Axis[EAxis::End];

		float	x = 0.f;
		float	y = 0.f;
		float	z = 0.f;

#pragma region Construction

		FVector3D();
		FVector3D(float _x, float _y, float _z);
		FVector3D(const FVector3D& v);
		FVector3D(FVector3D&& v) noexcept;
		FVector3D(const FVector2D& v);
		FVector3D(const DirectX::XMVECTOR& v);

#pragma endregion Construction

#pragma region Equal

		const FVector3D& operator = (const FVector3D& v);
		const FVector3D& operator = (const DirectX::XMVECTOR& v);
		const FVector3D& operator = (float Value);
		const FVector3D& operator = (double Value);
		const FVector3D& operator = (int Value);

		bool operator == (const FVector3D& v);
		bool operator != (const FVector3D& v);

		float& operator [] (int Index);

#pragma endregion Equal

#pragma region Plus
		// +
		FVector3D operator + (const FVector3D& v)	const;
		FVector3D operator + (float Value)	const;
		FVector3D operator + (double Value)	const;
		FVector3D operator + (int Value)	const;

		// +=
		const FVector3D& operator += (const FVector3D& v);
		const FVector3D& operator += (float Value);
		const FVector3D& operator += (double Value);
		const FVector3D& operator += (int Value);

		// ++
		const FVector3D& operator ++ ();
		const FVector3D& operator ++ (int);

#pragma endregion Plus

#pragma region Minus
		// -
		FVector3D operator - (const FVector3D& v)	const;
		FVector3D operator - (float Value)	const;
		FVector3D operator - (double Value)	const;
		FVector3D operator - (int Value)	const;
		FVector3D operator - ()	const;

		// -=
		const FVector3D& operator -= (const FVector3D& v);
		const FVector3D& operator -= (float Value);
		const FVector3D& operator -= (double Value);
		const FVector3D& operator -= (int Value);

		// --
		const FVector3D& operator -- ();
		const FVector3D& operator -- (int);

#pragma endregion Minus

#pragma region Multiply

		// *
		FVector3D operator * (const FVector3D& v)	const;
		FVector3D operator * (float Value)	const;
		FVector3D operator * (double Value)	const;
		FVector3D operator * (int Value)	const;

		// *=
		const FVector3D& operator *= (const FVector3D& v);
		const FVector3D& operator *= (float Value);
		const FVector3D& operator *= (double Value);
		const FVector3D& operator *= (int Value);

#pragma endregion Multiply

#pragma region Divide

		// /
		FVector3D operator / (const FVector3D& v)	const;
		FVector3D operator / (float Value)	const;
		FVector3D operator / (double Value)	const;
		FVector3D operator / (int Value)	const;

		// /=
		const FVector3D& operator /= (const FVector3D& v);
		const FVector3D& operator /= (float Value);
		const FVector3D& operator /= (double Value);
		const FVector3D& operator /= (int Value);

#pragma endregion Divide
	};

	struct FVector4D
	{
		static FVector4D ZeroVector;
		static FVector4D OneVector;

		static FVector4D RGBA_Black;
		static FVector4D RGBA_White;
		static FVector4D RGBA_Red;
		static FVector4D RGBA_Blue;
		static FVector4D RGBA_Green;
		static FVector4D RGBA_Cyan;
		static FVector4D RGBA_Magenta;
		static FVector4D RGBA_Yellow;

		float	x = 0.f;
		float	y = 0.f;
		float	z = 0.f;
		float	w = 0.f;

#pragma region Construction

		FVector4D();
		FVector4D(float _x, float _y, float _z, float _w);
		FVector4D(const FVector4D& v);
		FVector4D(FVector4D&& v) noexcept;
		FVector4D(const DirectX::XMVECTOR v);

#pragma endregion Construction

#pragma region Equal

		const FVector4D& operator = (const FVector4D& v);
		const FVector4D& operator = (float Value);
		const FVector4D& operator = (double Value);
		const FVector4D& operator = (int Value);

		bool operator == (const FVector4D& v);
		bool operator != (const FVector4D& v);

		float& operator [] (int Index);

#pragma endregion Equal

#pragma region Plus
		// +
		FVector4D operator + (const FVector4D& v)	const;
		FVector4D operator + (float Value)	const;
		FVector4D operator + (double Value)	const;
		FVector4D operator + (int Value)	const;

		// +=
		const FVector4D& operator += (const FVector4D& v);
		const FVector4D& operator += (float Value);
		const FVector4D& operator += (double Value);
		const FVector4D& operator += (int Value);

		// ++
		const FVector4D& operator ++ ();
		const FVector4D& operator ++ (int);

#pragma endregion Plus

#pragma region Minus
		// -
		FVector4D operator - (const FVector4D& v)	const;
		FVector4D operator - (float Value)	const;
		FVector4D operator - (double Value)	const;
		FVector4D operator - (int Value)	const;

		// -=
		const FVector4D& operator -= (const FVector4D& v);
		const FVector4D& operator -= (float Value);
		const FVector4D& operator -= (double Value);
		const FVector4D& operator -= (int Value);

		// --
		const FVector4D& operator -- ();
		const FVector4D& operator -- (int);

#pragma endregion Minus

#pragma region Multiply

		// *
		FVector4D operator * (const FVector4D& v)	const;
		FVector4D operator * (float Value)	const;
		FVector4D operator * (double Value)	const;
		FVector4D operator * (int Value)	const;

		// *=
		const FVector4D& operator *= (const FVector4D& v);
		const FVector4D& operator *= (float Value);
		const FVector4D& operator *= (double Value);
		const FVector4D& operator *= (int Value);

#pragma endregion Multiply

#pragma region Divide

		// /
		FVector4D operator / (const FVector4D& v)	const;
		FVector4D operator / (float Value)	const;
		FVector4D operator / (double Value)	const;
		FVector4D operator / (int Value)	const;

		// /=
		const FVector4D& operator /= (const FVector4D& v);
		const FVector4D& operator /= (float Value);
		const FVector4D& operator /= (double Value);
		const FVector4D& operator /= (int Value);

#pragma endregion Divide
	};
}