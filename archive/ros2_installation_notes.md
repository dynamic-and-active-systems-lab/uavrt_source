# ROS 2 Installation Notes 

ROS 2 is currently supported by on Windows, Linux (Ubuntu and REHL), and macOS (Mojave (10.14)). 
However, all testing thus far has been on Ubuntu. We are currently unsure as to whether the 
first version of UAVRT will be supported on any system other than Linux running Ubuntu. 
As such, the current and published installation notes will contain only the instructions for 
installing on Ubuntu 20.04. The installation notes that are related to all other systems 
will be located here as a reference. 

### Unsupported platforms

- Windows is not supported at this time.
- Linux - REHL (which version? 8? amd64 and arm64?)
- macOS - Mojave (10.14)

### Dependencies

Installation instructions will be supplied for macOS Mojave (10.14).

- [Homebrew](https://brew.sh/) will be used for installation purposes on macOS.

**Note:** Check whether these dependencies are installed prior to running the installation commands below!

#### Python

Python 3.8 is the minimum requirement:

- macOS

```
brew update
brew upgrade
brew install python@3.8
python --version
```

While a Python 3.9 enviroment is required for MATLAB ROS 2 support:

- macOS

```
brew update
brew upgrade
brew install python@3.9
python --version
```

#### CMake

Cmake 3.16.3+:

- macOS

```
brew update
brew upgrade
brew install cmake
cmake --version
```

#### C++ Compilers

- macOS — Xcode 10+

To install Command Line Utilities only:

```
xcode-select --install
gcc --version
```

#### Netcat

- macOS

```
brew update
brew upgrade
brew install netcat
netcat -h
```

#### airspyhf_rx

TBD. The instructions I wrote for this are in the [airspy_channelizer repo](https://github.com/dynamic-and-active-systems-lab/airspyhf_channelize#installing-airspyhf_rx). 

# Installaton 

Assuming MAVSDK C++ and ROS 2 Galactic were installed: 

#### macOS

TBD. Instructions are listed in the ROS 2 documentation but I have not gone through them. I'm leaving this section blank until I go through this installation process on a Mac running Mohave 10.4.
