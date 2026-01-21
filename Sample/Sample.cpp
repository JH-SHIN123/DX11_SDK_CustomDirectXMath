#ifdef _DEBUG
#pragma comment(lib, "GMath_d.lib")
#else
#pragma comment(lib, "GMath.lib")
#endif

#include <iostream>
#include "../GMath/GMath.h"

int main()
{
	GMath::FVector3D Start(0.f, 0.f, 0.f);
	GMath::FVector3D End(10.f, 10.f, 10.f);

	GMath::FVector3D Mid = Lerp(Start, End, 0.5f);

	GMath::FMatrix Rotation = GMath::MatrixRotation_AxisZ(45.f);
	GMath::FVector3D RotatedVec = GMath::TransformNormal(Rotation, GMath::FVector3D::Axis[GMath::EAxis::X]);

	std::cout << "Mid Point: " << Mid.x << ", " << Mid.y << ", " << Mid.z << std::endl;
	std::cout << "Rotated X-Axis (45 deg): " << RotatedVec.x << ", " << RotatedVec.y << std::endl;

	if (GMath::IsNormalize(RotatedVec))
	{
		std::cout << "Rotation preserved length!" << std::endl;
	}

	return 0;
}