# Install script for directory: C:/nRF/v1.5.1/zephyr

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Zephyr-Kernel")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/zephyr/arch/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/zephyr/lib/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/zephyr/soc/arm/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/zephyr/boards/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/zephyr/subsys/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/zephyr/drivers/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/nrf/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/mcuboot/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/nrfxlib/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/hal_nordic/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/tfm/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/cddl-gen/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/cmsis/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/canopennode/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/civetweb/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/fatfs/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/st/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/libmetal/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/lvgl/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/mbedtls/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/mcumgr/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/open-amp/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/loramac-node/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/openthread/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/segger/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/tinycbor/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/tinycrypt/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/littlefs/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/mipi-sys-t/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/nrf_hw_models/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/modules/connectedhomeip/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/zephyr/kernel/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/zephyr/cmake/flash/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/zephyr/cmake/usage/cmake_install.cmake")
  include("C:/nRF/v1.5.1/nrf/samples/zigbee/TemperatureSensorNRF52833/build_nrf52833dk_nrf52833/zephyr/cmake/reports/cmake_install.cmake")

endif()

