project(Construct_Streamlines)

cmake_minimum_required(VERSION 2.8.10)

set(CMAKE_C_COMPILER /usr/local/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/local/bin/g++)
set(CMAKE_C_FLAGS "-g -fopenmp -Ofast")
set(CMAKE_CXX_STANDARD 14)

SET(VTKm_DIR /home/sci/ssane/projects/uncertainty_vis/VTKM/install/lib/cmake/vtkm-1.5)
find_package(VTKm REQUIRED QUIET)

add_executable(Construct_Streamlines main.cxx)

  target_include_directories(Construct_Streamlines PRIVATE ${VTKm_INCLUDE_DIRS})
  target_link_libraries(Construct_Streamlines PRIVATE vtkm_cont ${VTKm_LIBRARIES})
#  target_compile_definitions(Construct_Streamlines PRIVATE "VTKM_DEVICE_ADAPTER=VTKM_DEVICE_ADAPTER_SERIAL")
  target_compile_options(Construct_Streamlines PRIVATE ${VTKm_COMPILE_OPTIONS})
