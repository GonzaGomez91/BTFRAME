#include <Arduino.h>
#include "DriveController.h"

DriveController::DriveController(Motor &leftMotor, Motor &rightMotor)
    : leftMotor(leftMotor), rightMotor(rightMotor), linearSpeed(0), angularSpeed(0), leftTrim(1.0f), rightTrim(1.0f)
{
}

void DriveController::setLinearSpeed(int speed)
{
    linearSpeed = speed;
}

void DriveController::setAngularSpeed(int speed)
{
    angularSpeed = speed;
}

void DriveController::stop()
{
    linearSpeed = 0;
    angularSpeed = 0;
    leftMotor.setSpeed(0);
    rightMotor.setSpeed(0);
}

void DriveController::setTrim(float leftTrim, float rightTrim)
{
    this->leftTrim = leftTrim;
    this->rightTrim = rightTrim;
}

int DriveController::applyTrim(int speed, float trim)
{
    return speed * trim;
}

void DriveController::update()
{
    int leftSpeed = linearSpeed - angularSpeed;
    int rightSpeed = linearSpeed + angularSpeed;

    leftSpeed = applyTrim(leftSpeed, leftTrim);
    rightSpeed = applyTrim(rightSpeed, rightTrim);

    leftSpeed = constrain(leftSpeed, -255, 255);
    rightSpeed = constrain(rightSpeed, -255, 255);

    leftMotor.setSpeed(leftSpeed);
    rightMotor.setSpeed(rightSpeed);


}
