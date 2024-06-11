#include "FPSCamera.h"

#include "glm_wrapper.h"

#include <QDebug>

FPSCamera::FPSCamera(const Vector3& position, const Vector3& up, double yaw, double pitch)
{
    position_ = position;

    Front = Vector3{0.0f, 0.0f, 5000.0f};
    WorldUp = up;
    Up = up;
    Yaw = yaw;
    Pitch = pitch;

    *transformation += RotationData(Yaw, Pitch, 0);

    updateCameraVectors();
}

// Matrix4 FPSCamera::getProjectionMatrix()  const
// {
//     return perspective(radians(75.0), aspect, zNear, zFar);
// }

Matrix4 FPSCamera::getViewMatrix()
{
    auto Position = transformation->getMoveMatrix() * position_;

    auto gyro = transformation->getRotateData();

    Yaw = std::clamp(gyro[0], MIN_YAW, MAX_YAW);
    Pitch = std::clamp(gyro[1], MIN_PITCH, MAX_PITCH);

    updateCameraVectors();

    return lookAt(Position, Position + Front, Up);
}

void FPSCamera::updateCameraVectors()
{
    Vector3 front(cos(radians(Yaw)) * cos(radians(Pitch)),
                  sin(radians(Pitch)),
                  sin(radians(Yaw)) * cos(radians(Pitch)));
    // Vector3 front(Front.getData().length() * sin(radians(Yaw)),
    //               Front.getData().length() * sin(radians(Yaw)) * sin(radians(Pitch)),
    //               Front.getData().length() * cos(radians(Yaw)) * cos(radians(Pitch)));
    Front = normalize(front);
    Right = normalize(cross(Front, Up));
    Up = normalize(cross(Right, Front));
}
