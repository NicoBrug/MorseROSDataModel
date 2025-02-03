<h1 align="center">ROS Data Model</h1>
<h3 align="center">The ROS Data Model Inside Unreal Engine</h3>

<p align="center">
  <a href="" target="_blank"><img alt="Badge showing project license type" src="https://img.shields.io/badge/License-MIT-green.svg"></a>
  <a href=""><img src="https://img.shields.io/badge/Windows-Supported-blue?logo=windows" alt="Windows Supported OS"></a>
  <a href=""><img src="https://img.shields.io/badge/Linux-Supported-blue?logo=linux" alt="Linux Supported OS"></a>
</p>


## 🚀 Overview
MorseRosDataModel is an Unreal Engine plugin that implements the ROS Data Model.

It does not contain a direct dependency on ROS and uses the Morse Core, based on Cyclone DDS, as the communication layer. You need [Morse Core](https://github.com/NicoBrug/Morse) in you're project for using the ROS Data Model. With the With the MorseRosDataModel and Morse Core, you can distribute your Unreal simulation data into the ROS framework (see examples in Morse Core).

Here is a list of the implemented ROS data model:


| Module           	| Data Type            	| Implementation 	|
|------------------	|---------------------------	|----------------	|
| BuiltinInterface 	| Duration                  	| ✅              	|
| BuiltinInterface 	| Time                      	| ✅              	|
| Std              	| Header                    	| ✅              	|
| RclInterface     	| Log                       	| ✅              	|
| RosGraph         	| Clock                     	| ✅              	|
| Geometry         	| Accel                     	| ✅              	|
| Geometry         	| Point                     	| ✅              	|
| Geometry         	| Point32                   	| ✅              	|
| Geometry         	| PointStamped              	| ✅              	|
| Geometry         	| Pose                      	| ✅              	|
| Geometry         	| PoseStamped               	| ✅              	|
| Geometry         	| PoseWithCovariance        	| ✅              	|
| Geometry         	| PoseWithCovarianceStamped 	| ✅              	|
| Geometry         	| Quaternion                	| ✅              	|
| Geometry         	| Vector3                   	| ✅              	|
| Geometry         	| Transform                 	| ✅              	|
| Geometry         	| TransformStamped          	| ✅              	|
| Tf2              	| TfMessage                 	| ✅              	|
| Sensor           	| CameraInfo                	| ✅              	|
| Sensor           	| ChannelFloat32            	| ✅              	|
| Sensor           	| Image                     	| ✅              	|
| Sensor           	| Imu                       	| ✅              	|
| Sensor           	| JointState                	| ✅              	|
| Sensor           	| LaserScan                 	| ✅              	|
| Sensor           	| NavSatFix                 	| ✅              	|
| Sensor           	| NavSatStatus              	| ✅              	|
| Sensor           	| PointCloud                	| ✅              	|
| Sensor           	| PointCloud2               	| ✅              	|
| Sensor           	| PointField                	| ✅              	|
| Sensor           	| RegionOfInterest          	| ✅              	|
| Sensor           	| FluidPressure             	| 🔜              	|
| Sensor           	| LaserEcho                 	| 🔜              	|
| Sensor           	| MagneticField             	| 🔜              	|
| Sensor           	| BatteryState              	| 🔜              	|


## 📫 Contact

If you have any questions, feedback, or inquiries about this project, feel free to reach out via the following methods:

- **Email**: [nicolasbrugie@gmail.com](mailto:nicolasbrugie@gmail.com)
- **LinkedIn**: [Brugie Nicolas](https://www.linkedin.com/in/nicolas-brugie/)
- **GitHub Issues**: [Open an Issue](https://github.com/NicoBrug/MorseROSDataModel/issues)
