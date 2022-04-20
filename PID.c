#include <iostream>
#include <tuple>
#include <cstblib>

std::tuple<int, int, int, float, float, float> pidController(int, int*, int);
int updateRightSpeed(int, int*);
int updateLeftSpeed(int, int*);

int main(){
   int dist[] = {30, 50, 70, 20, 35, 27, 42, 50, 39, 12, 19, 7, 27, 38, 57, 62, 45, 53, 31, 22, 5, 12, 70, 67, 61, 55, 37, 4, 15, 26, 33, 47};
   int previousError{0};
   int setPoint{30};
   int rightSpeed{100};
   int leftSpeed{100};
   int output0, output1, output2;
   float Kp, Ki, Kd;
   std::string line("==============================================================");
   std::string title("\t  P I D   C O N T R O L L E R");

   std::cout << line << std::endl;
   std::cout << title << std::endl;
   std::cout << line << std::endl;

   std::cout << "    Your robot is following a wall!" << std::endl;
   std::cout << "    It is coming from South to North and the wall \n is at the robot\s left side!" << std::endl;
   std::cout << "      The desired distance to the wall is " << setpoint << " cm." << std::endl;
   std::cout << "      The current distance to it equals ---> " << dists[1] << " cm." << std::endl;
   std::cout << "      The robot speed on both wheels is " << rightSpeed << " cm per second." << std::endl;

   std::tie(output0, output1, output2, Kp, Ki, Kd) = pidController(setPoint, &dist[1], previousError);
   std::cout << "      The current error equals ---> " << output0 << " ." << std::endl;
   std::cout << "      The previous error was: " << output1 << " ." << std::endl;
   std::cout << "      The summed up error is = " << output2 << " ." << std::endl;

   int newRightSpeed = updateRightSpeed(rightSpeed, &output2);
   int newLeftSpeed = updateLeftSpeed(leftSpeed, &output2);

   std::cout << "\t  The updated robot speed is: \n\t new right speed = "
    << newRightSpeed << "\n\t new left speed = " << newLeftSpeed << std::endl;

   std::cout << "\t The value of the PID constants used was: \n\t Ki = " << Ki << "\n\t Kp = "
   << Kp << "\n\t Kd = " << Kd << std::endl;

    previousError = output0;
    rightSpeed = newRightSpeed;
    leftSpeed = newLeftSpeed;

    std::cout << line << std::endl;
    std::cout << title << std::endl;
    std::cout << line << std::endl;
   return 0;
}

std::tuple<int, int, int, float, float, float> pidController(int setPoint, int* input, int prevError){

  float kp{4.0};
}
