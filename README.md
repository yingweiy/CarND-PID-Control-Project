# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## PID Controllers

### Steering PID Controller

* P component: control how quickly the car can adapt to turns. Too small this value, the car is less adaptive, and became hard to 
take turns. Too large this value, the car is more stable, but appears too stiff. Empirically, with many round manual tests, 
I set this value to 0.16.  
* I component: related to correct the alignment error. I started with a quite small value, 0.0001, and observe that the care does 
not displays an alignment-type error. Hence I keep this value as is.
* D component: make the control stable. This value is more correlate with the P component. I set this value manually through 
many experiments. The larger the value can make the vehicle stablized and reduce the side effect of larger P component. 
Once I set the P component 0.16, I make the P component fixed, and search for the D value. Finally I set it to be 3.0, which
yeilds my current best results.
    
In summary, for the steering controller: P = 0.16, I = 0.0001, D = 3.0. These parameters are set empirically.

### Throttle Controller  

Throttle PID controller is set to P=0.2, I = 0.0001, D=0.3. The value choice is similiar to the steering PID controller. 
They are obtained through manual experiments. I intentionally set the I component small, since no alignment errors observed,
and I used a P and D components values close to my steering values. The initial trial P=0.2, D=0.3 works well. 

For throttle controller, I did a trick to control the target speed based on the CTE. The target speed for throttle 
controller is shown below:

```python
target_speed = 30*exp(-abs(cte)*1.5)+5.0;
```

The the speed is set to the current target_speed:
```python
pid_throttle.UpdateError(speed-target_speed);
```

It behaves slowing down at turns. I found this is very useful to keep the car drive safe.

### Video Clip

[![Alt Video Result on YouTube](https://img.youtube.com/vi/Ht5YHX6-yko/0.jpg)](https://youtu.be/Ht5YHX6-yko)

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)
