#pragma once

#ifdef CYCLONE_ROS_API
  #define CYCLONE_ROS_EXPORT CYCLONE_ROS_API
#else
  #if PLATFORM_WINDOWS
  #define CYCLONE_ROS_EXPORT __declspec(dllexport)  // Windows
  #elif PLATFORM_LINUX || PLATFORM_MAC
  #define CYCLONE_ROS_EXPORT __attribute__((visibility("default")))  // Linux/Mac
  #else
  #define CYCLONE_ROS_EXPORT
  #endif
#endif
