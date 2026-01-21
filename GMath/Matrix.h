#pragma once

#include <memory.h>
#include <assert.h>
#include "Vector.h"

//__declspec(align(16)) 메모리 정렬을 16바이트로

namespace GMath
{
	__declspec(align(16)) union FMatrix
	{
		static FMatrix Identity;

		DirectX::XMMATRIX	m;

		struct
		{
			float	_11, _12, _13, _14;
			float	_21, _22, _23, _24;
			float	_31, _32, _33, _34;
			float	_41, _42, _43, _44;
		};

		FVector4D	v[4];

		FMatrix()
		{
			m = DirectX::XMMatrixIdentity();
		}

		FMatrix(const FMatrix& _m)
		{
			m = _m.m;
		}

		FMatrix(FMatrix&& _m) noexcept
		{
			m = _m.m;
		}

		FMatrix(const DirectX::XMMATRIX& _m)
		{
			m = _m;
		}

		FMatrix(const FVector4D _v[4])
		{
			memcpy(v, _v, sizeof(FVector4D) * 4);
		}

		FVector4D& operator [] (int Index)
		{
			assert(0 <= Index && Index <= 3);

			return v[Index];
		}

		const FMatrix& operator = (const FMatrix& _m)
		{
			m = _m.m;
			return *this;
		}

		const FMatrix& operator = (const DirectX::XMMATRIX& _m)
		{
			m = _m;
			return *this;
		}

		const FMatrix& operator = (const FVector4D _v[4])
		{
			memcpy(v, _v, sizeof(FVector4D) * 4);
			return *this;
		}

		FMatrix operator * (const FMatrix& _m)	const
		{
			return FMatrix(m * _m.m);
		}

		FMatrix operator * (const DirectX::XMMATRIX& _m)	const
		{
			return FMatrix(m * _m);
		}

		const FMatrix& operator *= (const FMatrix& _m)
		{
			*this = m * _m.m;
			return *this;
		}

		FMatrix operator *= (const DirectX::XMMATRIX& _m)
		{
			*this = m * _m;
			return *this;
		}
	};
}

/*
* 
	����� ��ȯ��Ģ�� �������� ����
	�ַ� ����� ������ ������� �����
	A��� ��� ��Ŀ� �׵������ ���� ��� A����� ��µȴ�. (�����ϰ� ��ȯ��Ģ�� �����Ѵ�.)


	�׵����
	1 0 0 0
	0 1 0 0
	0 0 1 0
	0 0 0 1

	�Ϲ����
	4x4 * 4x4�� ���
	1 2 3 4		1 2 3 4
	5 6 7 8		5 6 7 8
	9 0 1 2	 *	9 0 1 2
	3 4 5 6		3 4 5 6

	����� ��:
		������ ��(����)�� ������ ��(����)�� ��ġ�ؾ���
		����� ������ ��(����)�� ������ ��(����)�� ������ ����� ����

	�����: ������� ���� ȿ��
		A��Ŀ� A������� ���ϸ� �׵�(����)����� ����.
		�����̽� ��ȯ �� ������� �̿��� ���� �����̽��� ����� ������ �� �ִ�.

	�����̽��� �����ϱ� ���� ���


SIMD2 ��������: 16Byets ������ �ѹ��� �����Ѵ�.

���� ��� ���� ���
�� �� �� �� ��

ũ�� ���
x 0 0 0
0 y 0 0
0 0 z 0
0 0 0 1

ȸ�� ���Ϸ� ȸ�� �̿�(��ȸ��) ������ ����
���ʹϾ��� ���Ϸ��� �޸� �ѹ��� �� �࿡ ���� ������ ���ϱ� ������ �������� �ؼ��� �� �ִ�.
�ﰢ �Լ��� ���� ������ �̿��� ȸ���� �Ѵ�.

���� ȸ����� = X�� ȸ����� * Y�� ȸ����� * Z�� ȸ�����

*/


