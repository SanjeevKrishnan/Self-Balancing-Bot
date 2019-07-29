# Self-Balancing Bot

## Abstract

The aim of this project was to make a self-balancing bot to learn about:
 * The basics and tuning of PID system
 * Working and Drift Correction of Gyroscope
 * Debugging of algorithms, etc. 

This self-balancing bot is a two-wheeled robot that balances vertically using a closed-loop algorithm.

## Components

| **Item**               | **Quantity** |
|------------------------|----------|
| Johnson Motor(400 rpm) | 2        |
| Differential Wheel     | 2        |
| Arduino Mega           | 1        |
| Cytron Motor Driver    | 1        |
| MPU9250                | 1        |
| LiPo Battery 12V       | 1        |
 
## PHASE 1

![Phase1](https://github.com/SanjeevKrishnan/Self-Balancing-Bot/blob/master/Images%20and%20Videos/Images/Phase%201-View.jpg)

### Mechanical Aspect

#### Drive
It is a two-wheeled differential drive driven by two Johnson motors of 400rpm.

#### Body
The body has two levels where battery and motor drive is placed at the bottom level, and microcontroller with gyroscope(MPU9205) placed at the top level.

#### Material
The frame of the bot was made with aluminum channels to reduce weight and the bases for different levels were made of cardboard since it's an electric insulator and also weightless in nature.

### Electronics Aspect

#### Main Algorithm
Gyroscope records any tilt in the vertical orientation of the bot and feeds it into the PID closed-control loop to produce an acceleration in the opposite direction. This algorithm is iterated to maintain the vertical stability of the bot.
To move the bot in forward direction, appropriate velocities are given to the motors. When they tend to lose their vertical stability, gyroscope records it and feeds it into the PID system and velocities are altered accordingly to bring it back to the stable position without affecting its forward motion.

#### Other Algorithms
Data Averaging algorithm is used for gyroscope’s drift correction.     

#### Microcontroller
Arduino Mega 2560 R3 is used as the microcontroller board.

#### Sensors
* MPU9250 - Gyroscope.

#### Actuators
* Johnson 400rpm motors.

#### Other Controllers
* Cytron Motor Driver - For controlling motors.

#### Power
* 12V LiPo battery is used as the power source.

### Conclusion
* Basic concepts of PID were studied properly and a properly tuned PID system was obtained using the hit-and-trial method.
* Data Average algorithm for gyroscope drift correction did not give expected output.
* Placing gyroscope on the top-level did not give expected readings.
* Placing heavy objects on the bottom level was making it tough to balance the bot.

## PHASE 2

![Phase2](https://github.com/SanjeevKrishnan/Self-Balancing-Bot/blob/master/Images%20and%20Videos/Images/Phase%202-Front%20View.jpg)

### Mechanical Aspect

#### Drive
It is a two-wheeled differential drive driven by two johnson motors of 400rpm.

#### Body
The body has two levels where the microcontroller with gyroscope(MPU9205) was placed at the bottom level and, battery and motor drive placed at the top level.
Also, the height of the top level was increased to make the bot work like an inverted pendulum. And since the gyroscope was placed at the bottom level of the bot, even the smallest change in the bot’s vertical orientation was accurately recorded.

#### Material
The frame of the bot was made with aluminum channels to reduce the weight and the bases for different levels were made of cardboard, since it's an electric insulator and also weightless in nature.

### Electronics Aspect

#### Main Algorithm
Gyroscope records any tilt in the vertical orientation of the bot and feeds it into the PID closed-control loop to produce an acceleration in the opposite direction. This algorithm is iterated to maintain the vertical stability of the bot.
To move the bot in forward direction, appropriate velocities are given to the motors. When they tend to lose their vertical stability, the gyroscope records it and feeds it to the PID system, and velocities are altered accordingly to bring it back to the stable position without affecting its forward motion.

#### Other Algorithms
Kalman filter is applied along with Data Averaging algorithm to correct gyroscope’s drift.

#### Microcontroller
Arduino Mega 2560 R3 is used as the microcontroller board.

#### Sensors
* MPU9250 - Gyroscope

#### Actuators
* Johnson 400rpm motors

#### Other Controllers
* Cytron Motor Driver - For controlling motors

#### Power
12V LiPo battery is used as the power source

### Conclusion
* Kalman filter is found to be very effective in gyroscope drift correction.
* Inverted Pendulum concept (moving center of mass of the bot to topmost point) made it easy to balance the bot.
* Code and algorithm debugging were practiced in depth.
* Bot was able to move forward along with self-balancing.

## Reference
<https://www.instructables.com/id/Guide-to-gyro-and-accelerometer-with-Arduino-inclu/>

<https://create.arduino.cc/projecthub/30503/using-the-mpu9250-to-get-real-time-motion-data-08f011>

<https://circuitdigest.com/microcontroller-projects/arduino-based-self-balancing-robot>