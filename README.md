# UAV-RT Source directory

This repository acts as the source in which all UAV-RT repositories/packages can be cloned into to be built using the version of [colcon](https://colcon.readthedocs.io/en/released/) packaged with [ROS 2 galactic](https://docs.ros.org/en/galactic/index.html).

The development of this code was funded via National Science Foundation grant no. 2104570.

# Basic operation

TBD

# Documentation

The supporting documentation for this project can be found here. (TBD)

TBD

# System requirements

### Supported platforms

- Linux - Ubuntu 20.04 (amd64)

### Hardware

- [PX4 autopilot](https://docs.px4.io/master/en/flight_controller/pixhawk4.html)
- [Airspy HF+ Discovery](https://airspy.com/airspy-hf-discovery/)
- Companion computer
  - This project was developed and deployed on the [UDOO x86 II Ultra](https://shop.udoo.org/en/udoo-x86-ii-ultra.html)

### Dependencies

Installation instructions will be supplied for Ubuntu 20.04. The standard Debian/Ubuntu package manager `apt` will be used for installation purposes.

**Note:** Check whether these dependencies are installed prior to running the installation commands below!

#### Python

Python 3.8 is the minimum requirement:

- Ubuntu

```
sudo apt update && sudo apt upgrade
sudo apt install python3.8
python --version
```

While a Python 3.9 enviroment is required for MATLAB ROS 2 support:

- Ubuntu

```
sudo apt update && sudo apt upgrade
sudo apt install python3.9
python --version
```

#### CMake

Cmake 3.16.3+:

- Ubuntu

```
sudo apt update && sudo apt upgrade
sudo apt install cmake
cmake --version
```

#### Git 

- Ubuntu 

```
sudo apt update && sudo apt upgrade
sudo apt install git
git --version
```

#### C++ Compilers

- Ubuntu — GNU Compiler Collection (GCC) 6.3+

```
sudo apt update && sudo apt upgrade
sudo apt install build-essential
sudo apt install manpages-dev
gcc --version
```

#### Netcat

Ubuntu

```
sudo apt update && sudo apt upgrade
apt install netcat
dpkg -L netcat
```

#### Boost

This codebase utilizes Boost when necessary. 

The following commands are to install all Boost 1.71.0 libraries: 

```
sudo apt update
sudo apt upgrade
sudo apt install libboost-all-dev
```
Note: Narrow down the exact Boost libraries that are required. 

#### airspyhf_rx

TBD. The instructions I wrote for this are in the [airspy_channelizer repo](https://github.com/dynamic-and-active-systems-lab/airspyhf_channelize#installing-airspyhf_rx). Ultimately, the dependencies for the UAV-RT need to be on a centralized site. 

#### ROS 2

The UAV-RT codebase supports the Galactic Geochelone distributions of ROS 2:

- [ROS 2 Galactic Geochelone](https://docs.ros.org/en/galactic/Releases/Release-Galactic-Geochelone.html)

The instructions for installing ROS 2 Galactic Geochelone can be found here: 

- [ROS 2 Galactic Geochelone Installation](https://docs.ros.org/en/galactic/Installation/Ubuntu-Install-Debians.html)

Follow from the beginning of the instrunctions to the end, as it can be difficult to troubleshoot errors later on unless ROS 2 is correctly installed. 
Run the [Examples](https://docs.ros.org/en/galactic/Installation/Ubuntu-Install-Debians.html#id7) that are listed at the bottom of the installation 
instructions to ensure that ROS 2 is correctly installed on your machine.  

#### Ros2dep

ROS 2 packages are built on frequently updated Ubuntu systems. It is always recommended that you ensure your system is up to date before installing new packages.

```
sudo apt update && sudo apt upgrade
sudo apt install python3-rosdep2
```

You will then need to update rosdep. [From the ROS 2 galactic isntructions](https://docs.ros.org/en/galactic/Installation/Alternatives/Ubuntu-Development-Setup.html#install-dependencies-using-rosdep). 

```
rosdep update 
```

#### Colcon 

colcon is an iteration on the ROS build tools catkin_make, catkin_make_isolated, catkin_tools and ament_tools. For more information on the design of colcon see this [document](https://design.ros2.org/articles/build_tool.html).

The source code can be found in the [colcon GitHub organization](https://github.com/colcon).

```
sudo apt update && sudo apt upgrade
sudo apt install python3-colcon-common-extensions
```

#### MAVLink and MAVSDK C++

This codebase supports [MAVLink V2](https://mavlink.io/en/guide/mavlink_2.html).

We use MAVSDK C++ as the interface to the MAVLink protocol:

- [MAVSDK C++](https://mavsdk.mavlink.io/main/en/cpp/)

Note: The installation version listed on the MAVSDK site is out-of-date! 

Use the following instructions for installing the version of MAVSDK that was used during development. 

```
cd ~
wget https://github.com/mavlink/MAVSDK/releases/download/v1.4.2/libmavsdk-dev_1.4.2_ubuntu20.04_amd64.deb
sudo dpkg -i libmavsdk-dev_1.4.2_ubuntu20.04_amd64.deb
```

#### MATLAB

MATLAB 2022a+ is recommended but it is not required:

- [MATLAB R2022a](https://www.mathworks.com/support/requirements/matlab-system-requirements.html)

# Installaton

For installing this package, it is required that you have a functional ROS 2 workspace. Below is a set of instructions to create a ROS2 workspace. These instructions will fail unless the previous dependencies have been met.

- These instructions were adapted from [ROS 2 documentation](https://docs.ros.org/).
- For more details on creating a workspace using [Galactic](https://docs.ros.org/en/galactic/Tutorials.html).

### Linux

Within a terminal window, run the following commands:

[//]: # ('source ~/ros2_galactic/ros2-linux/setup.bash' run this command if the first command doesn't work)  
[//]: # ('source ~/ros2_galactic/ros2-linux/setup.bash' run this command if the last above doesn't work)  

```
source /opt/ros/galactic/setup.bash
mkdir -p ~/uavrt_workspace/
cd ~/uavrt_workspace/
```

You must be a member of the Dynamic and Active Systems Lab organization on Github. Authentication is currently required for the following command: 

```
git clone https://github.com/dynamic-and-active-systems-lab/uavrt_source/
```

"All required rosdeps installed successfully" should be returned after the following command: 

```
rosdep install -i --from-path uavrt_source --rosdistro galactic -y
```

There should be "build  install  log  uavrt_source" directories in the workspace root (~/uavrt_workspace) after the following command: 

```
colcon build
source /opt/ros/galactic/setup.bash
. install/local_setup.bash
```

If these commands didn't fail, then your installation of uavrt_source should be complete. 

## Installating uavrt_packages

You will need to populate uavrt_source with the different uavrt_packages in order to begin using the system. The instructions for installing these individual packages are found in the installation section of each package's README. 

Once all of the necessary uavrt_packages have been cloned into uavrt_source, you will need to run the following commands again within a terminal window: 

```
cd ~/uavrt_workspace/
source /opt/ros/galactic/setup.bash
```

"All required rosdeps installed successfully" should be returned after the following command: 

```
rosdep install -i --from-path uavrt_source --rosdistro galactic -y
```

After this next command, you will see something akin to... 

Starting >>> uavrt_PACKAGE

Finished <<< uavrt_PACKAGE [Time(s)]

Summary: 1 package finished [Time(s)]

```
colcon build
source /opt/ros/galactic/setup.bash
. install/local_setup.bash
```

If these commands didn't fail, then your installation of the UAV-RT codebase should be complete. 

# Troubleshooting

Troubleshooting tips can be found here. (TBD)

# License

This codebase is released under the GNU Lesser General Public License v3 or later.
