#pragma once


 
class DriveController
{
private:
    void update();
    /* data */
public:
    DriveController(/* args */); //Constructor
    
    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();


};

