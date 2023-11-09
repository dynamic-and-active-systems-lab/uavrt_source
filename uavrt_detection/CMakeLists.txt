cmake_minimum_required(VERSION 3.5)
project(uavrt_detection)
set(CMAKE_VERBOSE_MAKEFILE ON)
# Set CMAKE_BUILD_TYPE
set(CMAKE_BUILD_TYPE Release)
# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()
# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(ALIAS_ROS2_TF2)
  add_definitions(-Dtf2=ros2_tf2)
  add_definitions(-Dtf2_ros=ros2_tf2_ros)
  add_definitions(-Dmessage_filters=ros2_message_filters)
endif()
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package( builtin_interfaces REQUIRED)
find_package( rclcpp REQUIRED)
find_package( uavrt_interfaces REQUIRED)
include_directories("/codegen/exe")
include_directories("include/uavrt_detection")
set (CMAKE_SKIP_BUILD_RPATH false)
set (CMAKE_BUILD_WITH_INSTALL_RPATH true)
set (CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set (CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
# Node
add_executable(uavrt_detection 
src/DAHostLib_Network.c
src/DAHostLib_rtw.c
src/AsyncBuffer.cpp
src/AsyncBuffercgHelper.cpp
src/CoderTimeAPI.cpp
src/DetectorConfig.cpp
src/FFTImplementationCallback.cpp
src/UDPReceiver.cpp
src/UDPSender.cpp
src/abs.cpp
src/all.cpp
src/allOrAny.cpp
src/any1.cpp
src/assembleWq.cpp
src/assertCompatibleDims.cpp
src/assertValidSizeArg.cpp
src/bigProduct.cpp
src/buildtimecorrelatormatrix.cpp
src/builtin_interfaces_TimeStruct.cpp
src/channelreceiver.cpp
src/circshift.cpp
src/coder_fileops.c
src/coder_posix_time.c
src/colon.cpp
src/combineVectorElements.cpp
src/controlreceiver.cpp
src/datetime.cpp
src/dec2bin.cpp
src/dec2hex.cpp
src/diff.cpp
src/div.cpp
src/eml_int_forloop_overflow_check.cpp
src/eml_rand.cpp
src/eml_rand_mcg16807_stateful.cpp
src/eml_rand_mt19937ar.cpp
src/eml_rand_mt19937ar_stateful.cpp
src/eml_rand_shr3cong.cpp
src/eml_rand_shr3cong_stateful.cpp
src/eml_randn.cpp
src/evfit.cpp
src/feof.cpp
src/fft.cpp
src/fftshift.cpp
src/fgetl.cpp
src/fileManager.cpp
src/find.cpp
src/formatSTFTOutput.cpp
src/fseek.cpp
src/ftell.cpp
src/function_handle.cpp
src/fwrite.cpp
src/fzero.cpp
src/getLocalTime.cpp
src/heapsort.cpp
src/horzcatStructList.cpp
src/ifWhileCond.cpp
src/imresize.cpp
src/incohsumtoeplitz.cpp
src/ind2sub.cpp
src/indexShapeCheck.cpp
src/insertionsort.cpp
src/interp1.cpp
src/introsort.cpp
src/iseven.cpp
src/locBsearch.cpp
src/log10.cpp
src/lower.cpp
src/main.cpp
src/makepulsestruc.cpp
src/mean.cpp
src/minOrMax.cpp
src/mod.cpp
src/mtimes.cpp
src/nextpow2.cpp
src/norm.cpp
src/nullAssignment.cpp
src/pause.cpp
src/plus.cpp
src/psdfreqvec.cpp
src/pulseOut.cpp
src/pulsestats.cpp
src/quickselect.cpp
src/randn.cpp
src/rectwin.cpp
src/repmat.cpp
src/ros2_structmsg_conversion.cpp
src/ros2node.cpp
src/ros2publisher.cpp
src/rtGetInf.cpp
src/rtGetNaN.cpp
src/rt_nonfinite.cpp
src/sort.cpp
src/sortIdx.cpp
src/sortLE.cpp
src/sparse.cpp
src/sparse1.cpp
src/speye.cpp
src/sqrt.cpp
src/stft.cpp
src/str2double.cpp
src/str2matrix.cpp
src/strcmp.cpp
src/string1.cpp
src/strtok.cpp
src/sub2ind.cpp
src/sum.cpp
src/threshold.cpp
src/tic.cpp
src/timeKeeper.cpp
src/toc.cpp
src/uavrt_detection.cpp
src/uavrt_detection_data.cpp
src/uavrt_detection_initialize.cpp
src/uavrt_detection_rtwutil.cpp
src/uavrt_detection_terminate.cpp
src/uavrt_interfaces_PulseStruct.cpp
src/unaryMinOrMax.cpp
src/unique.cpp
src/validateNumericIndex.cpp
src/validate_print_arguments.cpp
src/validateattributes.cpp
src/validator_check_size.cpp
src/vecfind.cpp
src/waveform.cpp
src/waveformcopy.cpp
src/weightingmatrix.cpp
src/wfmstft.cpp
src/wgn.cpp
src/xaxpy.cpp
src/xdotc.cpp
src/xnrm2.cpp
src/xrotg.cpp
src/xscal.cpp
src/xzsvdc.cpp
)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
target_compile_options(uavrt_detection PUBLIC 
  $<$<OR:$<COMPILE_LANGUAGE:CXX>,$<COMPILE_LANGUAGE:C>>:
  -Wall -Wextra -Wpedantic
  >)
endif()
target_compile_options(uavrt_detection PRIVATE
  $<$<OR:$<COMPILE_LANGUAGE:CXX>,$<COMPILE_LANGUAGE:C>>:
  -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
  -DROS2_PROJECT
  -DSTACK_SIZE=200000
  -DMODEL=uavrt_detection
  >
  )
ament_target_dependencies(
  uavrt_detection
  "builtin_interfaces"
  "rclcpp"
  "uavrt_interfaces"
)
target_include_directories(uavrt_detection PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(uavrt_detection 
    dl m
	${CMAKE_DL_LIBS}
    )
install(TARGETS uavrt_detection
  EXPORT export_${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME})
ament_export_include_directories(
  include
)
foreach(file_i ${CUDA_BINS})
add_custom_command(
                   TARGET uavrt_detection
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy ${PROJECT_SOURCE_DIR}/src/${file_i} ${CMAKE_INSTALL_PREFIX}/uavrt_detection_ert_rtw/${file_i}
				   )
add_custom_command(
                   TARGET uavrt_detection
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy ${PROJECT_SOURCE_DIR}/src/${file_i} ${CMAKE_INSTALL_PREFIX}/codegen/exe/uavrt_detection/${file_i}
				   )				   
endforeach(file_i)
ament_package()
# Generated on Tue Feb 21 17:30:38 2023
