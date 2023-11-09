#ifndef UAVRT_DETECTION__VISIBILITY_CONTROL_H_
#define UAVRT_DETECTION__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define UAVRT_DETECTION_EXPORT __attribute__ ((dllexport))
    #define UAVRT_DETECTION_IMPORT __attribute__ ((dllimport))
  #else
    #define UAVRT_DETECTION_EXPORT __declspec(dllexport)
    #define UAVRT_DETECTION_IMPORT __declspec(dllimport)
  #endif
  #ifdef UAVRT_DETECTION_BUILDING_LIBRARY
    #define UAVRT_DETECTION_PUBLIC UAVRT_DETECTION_EXPORT
  #else
    #define UAVRT_DETECTION_PUBLIC UAVRT_DETECTION_IMPORT
  #endif
  #define UAVRT_DETECTION_PUBLIC_TYPE UAVRT_DETECTION_PUBLIC
  #define UAVRT_DETECTION_LOCAL
#else
  #define UAVRT_DETECTION_EXPORT __attribute__ ((visibility("default")))
  #define UAVRT_DETECTION_IMPORT
  #if __GNUC__ >= 4
    #define UAVRT_DETECTION_PUBLIC __attribute__ ((visibility("default")))
    #define UAVRT_DETECTION_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define UAVRT_DETECTION_PUBLIC
    #define UAVRT_DETECTION_LOCAL
  #endif
  #define UAVRT_DETECTION_PUBLIC_TYPE
#endif
#endif  // UAVRT_DETECTION__VISIBILITY_CONTROL_H_
// Generated 21-Feb-2023 17:30:38
 