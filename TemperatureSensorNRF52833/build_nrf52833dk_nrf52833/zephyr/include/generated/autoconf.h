#define CONFIG_NET_CONFIG_IEEE802154_DEV_NAME "IEEE802154_nrf5"
#define CONFIG_UART_INTERRUPT_DRIVEN 1
#define CONFIG_NET_IPV6 1
#define CONFIG_GPIO_NRF_P1 1
#define CONFIG_BOARD "nrf52833dk_nrf52833"
#define CONFIG_SOC "nRF52833_QIAA"
#define CONFIG_SOC_SERIES "nrf52"
#define CONFIG_NUM_IRQS 48
#define CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC 32768
#define CONFIG_HEAP_MEM_POOL_SIZE 2048
#define CONFIG_GPIO 1
#define CONFIG_PM 1
#define CONFIG_HAS_POWER_STATE_DEEP_SLEEP_1 1
#define CONFIG_SOC_HAS_TIMING_FUNCTIONS 1
#define CONFIG_ARCH_HAS_CUSTOM_BUSY_WAIT 1
#define CONFIG_IEEE802154_NRF5 1
#define CONFIG_CLOCK_CONTROL 1
#define CONFIG_NRF_RTC_TIMER 1
#define CONFIG_SYS_CLOCK_TICKS_PER_SEC 32768
#define CONFIG_BUILD_OUTPUT_HEX 1
#define CONFIG_FPU 1
#define CONFIG_ROM_START_OFFSET 0x0
#define CONFIG_FLASH_SIZE 512
#define CONFIG_FLASH_BASE_ADDRESS 0x0
#define CONFIG_SERIAL 1
#define CONFIG_MAIN_STACK_SIZE 1024
#define CONFIG_PRIVILEGED_STACK_SIZE 1024
#define CONFIG_NCS_SAMPLES_DEFAULTS 1
#define CONFIG_LOG_DEFAULT_LEVEL 1
#define CONFIG_PM_PARTITION_SIZE_PROVISION 0x1000
#define CONFIG_PM_PARTITION_SIZE_B0_IMAGE 0x8000
#define CONFIG_SB_VALIDATION_INFO_MAGIC 0x86518483
#define CONFIG_SB_VALIDATION_POINTER_MAGIC 0x6919b47e
#define CONFIG_SB_VALIDATION_INFO_CRYPTO_ID 1
#define CONFIG_SB_VALIDATION_INFO_VERSION 2
#define CONFIG_SB_VALIDATION_METADATA_OFFSET 0
#define CONFIG_SB_VALIDATE_FW_SIGNATURE 1
#define CONFIG_SYSTEM_WORKQUEUE_STACK_SIZE 2048
#define CONFIG_MPSL_THREAD_COOP_PRIO 8
#define CONFIG_MPSL_SIGNAL_STACK_SIZE 1024
#define CONFIG_MPSL_TIMESLOT_SESSION_COUNT 0
#define CONFIG_MPSL_LOG_LEVEL_INF 1
#define CONFIG_MPSL_LOG_LEVEL 3
#define CONFIG_PARTITION_MANAGER_ENABLED 1
#define CONFIG_SRAM_SIZE 128
#define CONFIG_SRAM_BASE_ADDRESS 0x20000000
#define CONFIG_PM_PARTITION_SIZE_ZBOSS_NVRAM 0x4000
#define CONFIG_PM_PARTITION_SIZE_ZBOSS_PRODUCT_CONFIG 0x1000
#define CONFIG_PM_SINGLE_IMAGE 1
#define CONFIG_PM_SRAM_BASE 0x20000000
#define CONFIG_PM_SRAM_SIZE 0x20000
#define CONFIG_ZIGBEE 1
#define CONFIG_ZIGBEE_APP_UTILS 1
#define CONFIG_ZIGBEE_APP_UTILS_LOG_LEVEL_INF 1
#define CONFIG_ZIGBEE_APP_UTILS_LOG_LEVEL 3
#define CONFIG_ZIGBEE_CHANNEL_SELECTION_MODE_SINGLE 1
#define CONFIG_ZIGBEE_CHANNEL 16
#define CONFIG_ZIGBEE_ROLE_ROUTER 1
#define CONFIG_ZBOSS_DEFAULT_THREAD_PRIORITY 3
#define CONFIG_ZBOSS_DEFAULT_THREAD_STACK_SIZE 2048
#define CONFIG_ZIGBEE_APP_CB_QUEUE_LENGTH 10
#define CONFIG_ZBOSS_ERROR_PRINT_TO_LOG 1
#define CONFIG_ZIGBEE_ERROR_TO_STRING_ENABLED 1
#define CONFIG_ZBOSS_TRACE_LOG_LEVEL_OFF 1
#define CONFIG_ZBOSS_TRACE_LOG_LEVEL 0
#define CONFIG_ZBOSS_TRACE_MASK 0x0000
#define CONFIG_ZIGBEE_SHELL_LOG_LEVEL_INF 1
#define CONFIG_ZIGBEE_SHELL_LOG_LEVEL 3
#define CONFIG_ZBOSS_OSIF_LOG_LEVEL_INF 1
#define CONFIG_ZBOSS_OSIF_LOG_LEVEL 3
#define CONFIG_APP_LINK_WITH_ZIGBEE 1
#define CONFIG_MGMT_FMFU_LOG_LEVEL_INF 1
#define CONFIG_MGMT_FMFU_LOG_LEVEL 3
#define CONFIG_BOOT_SIGNATURE_KEY_FILE ""
#define CONFIG_AGPS_LOG_LEVEL_INF 1
#define CONFIG_AGPS_LOG_LEVEL 3
#define CONFIG_NRF_ACL_FLASH_REGION_SIZE 0x1000
#define CONFIG_FPROTECT_BLOCK_SIZE 0x1000
#define CONFIG_DK_LIBRARY 1
#define CONFIG_DK_LIBRARY_BUTTON_SCAN_INTERVAL 10
#define CONFIG_DK_LIBRARY_INVERT_BUTTONS 1
#define CONFIG_DK_LIBRARY_INVERT_LEDS 1
#define CONFIG_DK_LIBRARY_DYNAMIC_BUTTON_HANDLERS 1
#define CONFIG_DK_LIBRARY_LOG_LEVEL_INF 1
#define CONFIG_DK_LIBRARY_LOG_LEVEL 3
#define CONFIG_MULTITHREADING_LOCK 1
#define CONFIG_RESET_ON_FATAL_ERROR 1
#define CONFIG_FATAL_ERROR_LOG_LEVEL_INF 1
#define CONFIG_FATAL_ERROR_LOG_LEVEL 3
#define CONFIG_CLOCK_CONTROL_MPSL 1
#define CONFIG_SOC_FLASH_NRF_RADIO_SYNC_MPSL 1
#define CONFIG_SOC_FLASH_NRF_RADIO_SYNC_MPSL_TIMESLOT_SESSION_COUNT 1
#define CONFIG_ZEPHYR_NRF_MODULE 1
#define CONFIG_DT_FLASH_WRITE_BLOCK_SIZE 4
#define CONFIG_ZEPHYR_MCUBOOT_MODULE 1
#define CONFIG_NRF_MODEM_SHMEM_CTRL_SIZE 0x4e8
#define CONFIG_MPSL 1
#define CONFIG_ZIGBEE_LIBRARY_PRODUCTION 1
#define CONFIG_APP_LINK_WITH_ZBOSS 1
#define CONFIG_NRF_802154_SL 1
#define CONFIG_ZEPHYR_NRFXLIB_MODULE 1
#define CONFIG_ZEPHYR_HAL_NORDIC_MODULE 1
#define CONFIG_HAS_NORDIC_DRIVERS 1
#define CONFIG_NRF_802154_RADIO_DRIVER 1
#define CONFIG_NRF_802154_MULTIPROTOCOL_SUPPORT 1
#define CONFIG_NRF_802154_CCA_MODE_ED 1
#define CONFIG_NRF_802154_CCA_ED_THRESHOLD 45
#define CONFIG_NRF_802154_CCA_CORR_THRESHOLD 45
#define CONFIG_NRF_802154_CCA_CORR_LIMIT 2
#define CONFIG_NRF_802154_PENDING_SHORT_ADDRESSES 16
#define CONFIG_NRF_802154_PENDING_EXTENDED_ADDRESSES 16
#define CONFIG_NRF_802154_RX_BUFFERS 16
#define CONFIG_HAS_NRFX 1
#define CONFIG_NRFX_GPIOTE 1
#define CONFIG_NRFX_NVMC 1
#define CONFIG_NRFX_PPI 1
#define CONFIG_NRFX_PWM 1
#define CONFIG_NRFX_PWM0 1
#define CONFIG_NRFX_PWM3 1
#define CONFIG_ZEPHYR_CDDL_GEN_MODULE 1
#define CONFIG_ZEPHYR_CONNECTEDHOMEIP_MODULE 1
#define CONFIG_HAS_CMSIS_CORE 1
#define CONFIG_HAS_CMSIS_CORE_M 1
#define CONFIG_NUM_PREEMPT_PRIORITIES 15
#define CONFIG_BOARD_NRF52833DK_NRF52833 1
#define CONFIG_BOARD_ENABLE_DCDC 1
#define CONFIG_SOC_SERIES_NRF52X 1
#define CONFIG_CPU_HAS_ARM_MPU 1
#define CONFIG_SOC_FAMILY "nordic_nrf"
#define CONFIG_SOC_FAMILY_NRF 1
#define CONFIG_HAS_HW_NRF_ACL 1
#define CONFIG_HAS_HW_NRF_CCM 1
#define CONFIG_HAS_HW_NRF_CCM_LFLEN_8BIT 1
#define CONFIG_HAS_HW_NRF_CLOCK 1
#define CONFIG_HAS_HW_NRF_COMP 1
#define CONFIG_HAS_HW_NRF_ECB 1
#define CONFIG_HAS_HW_NRF_EGU0 1
#define CONFIG_HAS_HW_NRF_EGU1 1
#define CONFIG_HAS_HW_NRF_EGU2 1
#define CONFIG_HAS_HW_NRF_EGU3 1
#define CONFIG_HAS_HW_NRF_EGU4 1
#define CONFIG_HAS_HW_NRF_EGU5 1
#define CONFIG_HAS_HW_NRF_GPIO0 1
#define CONFIG_HAS_HW_NRF_GPIO1 1
#define CONFIG_HAS_HW_NRF_GPIOTE 1
#define CONFIG_HAS_HW_NRF_I2S 1
#define CONFIG_HAS_HW_NRF_LPCOMP 1
#define CONFIG_HAS_HW_NRF_MWU 1
#define CONFIG_HAS_HW_NRF_NFCT 1
#define CONFIG_HAS_HW_NRF_NVMC_PE 1
#define CONFIG_HAS_HW_NRF_PDM 1
#define CONFIG_HAS_HW_NRF_POWER 1
#define CONFIG_HAS_HW_NRF_PPI 1
#define CONFIG_HAS_HW_NRF_PWM0 1
#define CONFIG_HAS_HW_NRF_PWM1 1
#define CONFIG_HAS_HW_NRF_PWM2 1
#define CONFIG_HAS_HW_NRF_PWM3 1
#define CONFIG_HAS_HW_NRF_QDEC 1
#define CONFIG_HAS_HW_NRF_RADIO_BLE_2M 1
#define CONFIG_HAS_HW_NRF_RADIO_TX_PWR_HIGH 1
#define CONFIG_HAS_HW_NRF_RADIO_BLE_CODED 1
#define CONFIG_HAS_HW_NRF_RADIO_IEEE802154 1
#define CONFIG_HAS_HW_NRF_RADIO_BLE_DF 1
#define CONFIG_HAS_HW_NRF_RNG 1
#define CONFIG_HAS_HW_NRF_RTC0 1
#define CONFIG_HAS_HW_NRF_RTC1 1
#define CONFIG_HAS_HW_NRF_RTC2 1
#define CONFIG_HAS_HW_NRF_SAADC 1
#define CONFIG_HAS_HW_NRF_SPI0 1
#define CONFIG_HAS_HW_NRF_SPI1 1
#define CONFIG_HAS_HW_NRF_SPI2 1
#define CONFIG_HAS_HW_NRF_SPIM0 1
#define CONFIG_HAS_HW_NRF_SPIM1 1
#define CONFIG_HAS_HW_NRF_SPIM2 1
#define CONFIG_HAS_HW_NRF_SPIM3 1
#define CONFIG_HAS_HW_NRF_SPIS0 1
#define CONFIG_HAS_HW_NRF_SPIS1 1
#define CONFIG_HAS_HW_NRF_SPIS2 1
#define CONFIG_HAS_HW_NRF_SWI0 1
#define CONFIG_HAS_HW_NRF_SWI1 1
#define CONFIG_HAS_HW_NRF_SWI2 1
#define CONFIG_HAS_HW_NRF_SWI3 1
#define CONFIG_HAS_HW_NRF_SWI4 1
#define CONFIG_HAS_HW_NRF_SWI5 1
#define CONFIG_HAS_HW_NRF_TEMP 1
#define CONFIG_HAS_HW_NRF_TIMER0 1
#define CONFIG_HAS_HW_NRF_TIMER1 1
#define CONFIG_HAS_HW_NRF_TIMER2 1
#define CONFIG_HAS_HW_NRF_TIMER3 1
#define CONFIG_HAS_HW_NRF_TIMER4 1
#define CONFIG_HAS_HW_NRF_TWI0 1
#define CONFIG_HAS_HW_NRF_TWI1 1
#define CONFIG_HAS_HW_NRF_TWIM0 1
#define CONFIG_HAS_HW_NRF_TWIM1 1
#define CONFIG_HAS_HW_NRF_TWIS0 1
#define CONFIG_HAS_HW_NRF_TWIS1 1
#define CONFIG_HAS_HW_NRF_UART0 1
#define CONFIG_HAS_HW_NRF_UARTE0 1
#define CONFIG_HAS_HW_NRF_UARTE1 1
#define CONFIG_HAS_HW_NRF_USBD 1
#define CONFIG_HAS_HW_NRF_WDT 1
#define CONFIG_NRF_HW_TIMER1_RESERVED 1
#define CONFIG_NRF_HW_RTC1_RESERVED 1
#define CONFIG_SOC_NRF52833 1
#define CONFIG_SOC_NRF52833_QIAA 1
#define CONFIG_SOC_DCDC_NRF52X 1
#define CONFIG_GPIO_AS_PINRESET 1
#define CONFIG_NRF_ENABLE_ICACHE 1
#define CONFIG_SOC_LOG_LEVEL_INF 1
#define CONFIG_SOC_LOG_LEVEL 3
#define CONFIG_SOC_COMPATIBLE_NRF 1
#define CONFIG_SOC_COMPATIBLE_NRF52X 1
#define CONFIG_ARCH "arm"
#define CONFIG_CPU_CORTEX 1
#define CONFIG_CPU_CORTEX_M 1
#define CONFIG_ISA_THUMB2 1
#define CONFIG_ASSEMBLER_ISA_THUMB2 1
#define CONFIG_COMPILER_ISA_THUMB2 1
#define CONFIG_STACK_ALIGN_DOUBLE_WORD 1
#define CONFIG_PLATFORM_SPECIFIC_INIT 1
#define CONFIG_FAULT_DUMP 2
#define CONFIG_ARM_STACK_PROTECTION 1
#define CONFIG_FP_HARDABI 1
#define CONFIG_CPU_CORTEX_M4 1
#define CONFIG_CPU_CORTEX_M_HAS_SYSTICK 1
#define CONFIG_CPU_CORTEX_M_HAS_DWT 1
#define CONFIG_CPU_CORTEX_M_HAS_BASEPRI 1
#define CONFIG_CPU_CORTEX_M_HAS_VTOR 1
#define CONFIG_CPU_CORTEX_M_HAS_PROGRAMMABLE_FAULT_PRIOS 1
#define CONFIG_ARMV7_M_ARMV8_M_MAINLINE 1
#define CONFIG_ARMV7_M_ARMV8_M_FP 1
#define CONFIG_GEN_ISR_TABLES 1
#define CONFIG_ZERO_LATENCY_IRQS 1
#define CONFIG_ARM_MPU 1
#define CONFIG_ARM_MPU_REGION_MIN_ALIGN_AND_SIZE 32
#define CONFIG_MPU_STACK_GUARD 1
#define CONFIG_MPU_ALLOW_FLASH_WRITE 1
#define CONFIG_CUSTOM_SECTION_MIN_ALIGN_SIZE 32
#define CONFIG_GEN_IRQ_VECTOR_TABLE 1
#define CONFIG_IDLE_STACK_SIZE 320
#define CONFIG_ISR_STACK_SIZE 2048
#define CONFIG_TEST_EXTRA_STACKSIZE 0
#define CONFIG_ARM 1
#define CONFIG_ARCH_IS_SET 1
#define CONFIG_ARCH_LOG_LEVEL_INF 1
#define CONFIG_ARCH_LOG_LEVEL 3
#define CONFIG_MPU_LOG_LEVEL_INF 1
#define CONFIG_MPU_LOG_LEVEL 3
#define CONFIG_HW_STACK_PROTECTION 1
#define CONFIG_KOBJECT_TEXT_AREA 256
#define CONFIG_GEN_PRIV_STACKS 1
#define CONFIG_DYNAMIC_INTERRUPTS 1
#define CONFIG_GEN_SW_ISR_TABLE 1
#define CONFIG_ARCH_SW_ISR_TABLE_ALIGN 0
#define CONFIG_GEN_IRQ_START_VECTOR 0
#define CONFIG_ARCH_HAS_TIMING_FUNCTIONS 1
#define CONFIG_ARCH_HAS_STACK_PROTECTION 1
#define CONFIG_ARCH_HAS_USERSPACE 1
#define CONFIG_ARCH_HAS_EXECUTABLE_PAGE_BIT 1
#define CONFIG_ARCH_HAS_RAMFUNC_SUPPORT 1
#define CONFIG_ARCH_HAS_NESTED_EXCEPTION_DETECTION 1
#define CONFIG_ARCH_SUPPORTS_COREDUMP 1
#define CONFIG_ARCH_SUPPORTS_ARCH_HW_INIT 1
#define CONFIG_ARCH_HAS_EXTRA_EXCEPTION_INFO 1
#define CONFIG_ARCH_HAS_THREAD_LOCAL_STORAGE 1
#define CONFIG_ARCH_HAS_THREAD_ABORT 1
#define CONFIG_CPU_HAS_FPU 1
#define CONFIG_CPU_HAS_MPU 1
#define CONFIG_MPU 1
#define CONFIG_MPU_REQUIRES_POWER_OF_TWO_ALIGNMENT 1
#define CONFIG_SRAM_REGION_PERMISSIONS 1
#define CONFIG_KERNEL_LOG_LEVEL_INF 1
#define CONFIG_KERNEL_LOG_LEVEL 3
#define CONFIG_MULTITHREADING 1
#define CONFIG_NUM_COOP_PRIORITIES 16
#define CONFIG_MAIN_THREAD_PRIORITY 7
#define CONFIG_COOP_ENABLED 1
#define CONFIG_PREEMPT_ENABLED 1
#define CONFIG_PRIORITY_CEILING 0
#define CONFIG_NUM_METAIRQ_PRIORITIES 0
#define CONFIG_THREAD_STACK_INFO 1
#define CONFIG_ERRNO 1
#define CONFIG_SCHED_DUMB 1
#define CONFIG_WAITQ_DUMB 1
#define CONFIG_BOOT_BANNER 1
#define CONFIG_BOOT_DELAY 0
#define CONFIG_SYSTEM_WORKQUEUE_PRIORITY -1
#define CONFIG_ATOMIC_OPERATIONS_BUILTIN 1
#define CONFIG_TIMESLICING 1
#define CONFIG_TIMESLICE_SIZE 0
#define CONFIG_TIMESLICE_PRIORITY 0
#define CONFIG_POLL 1
#define CONFIG_NUM_MBOX_ASYNC_MSGS 10
#define CONFIG_NUM_PIPE_ASYNC_MSGS 10
#define CONFIG_KERNEL_MEM_POOL 1
#define CONFIG_ARCH_HAS_CUSTOM_SWAP_TO_MAIN 1
#define CONFIG_SWAP_NONATOMIC 1
#define CONFIG_SYS_CLOCK_EXISTS 1
#define CONFIG_TIMEOUT_64BIT 1
#define CONFIG_XIP 1
#define CONFIG_KERNEL_INIT_PRIORITY_OBJECTS 30
#define CONFIG_KERNEL_INIT_PRIORITY_DEFAULT 40
#define CONFIG_KERNEL_INIT_PRIORITY_DEVICE 50
#define CONFIG_APPLICATION_INIT_PRIORITY 90
#define CONFIG_STACK_POINTER_RANDOM 0
#define CONFIG_MP_NUM_CPUS 1
#define CONFIG_TICKLESS_IDLE 1
#define CONFIG_TICKLESS_IDLE_THRESH 3
#define CONFIG_TICKLESS_KERNEL 1
#define CONFIG_HAS_DTS 1
#define CONFIG_HAS_DTS_GPIO 1
#define CONFIG_IEEE802154 1
#define CONFIG_IEEE802154_NRF5_DRV_NAME "IEEE802154_nrf5"
#define CONFIG_IEEE802154_NRF5_RX_STACK_SIZE 800
#define CONFIG_IEEE802154_NRF5_INIT_PRIO 80
#define CONFIG_IEEE802154_NRF5_EXT_IRQ_MGMT 1
#define CONFIG_IEEE802154_NRF5_PKT_TXTIME 1
#define CONFIG_IEEE802154_DRIVER_LOG_LEVEL_INF 1
#define CONFIG_IEEE802154_DRIVER_LOG_LEVEL 3
#define CONFIG_UART_CONSOLE_ON_DEV_NAME "UART_0"
#define CONFIG_CONSOLE 1
#define CONFIG_CONSOLE_INPUT_MAX_LINE_LEN 128
#define CONFIG_CONSOLE_HAS_DRIVER 1
#define CONFIG_UART_CONSOLE 1
#define CONFIG_UART_CONSOLE_INIT_PRIORITY 60
#define CONFIG_UART_CONSOLE_LOG_LEVEL_INF 1
#define CONFIG_UART_CONSOLE_LOG_LEVEL 3
#define CONFIG_HAS_SEGGER_RTT 1
#define CONFIG_USE_SEGGER_RTT 1
#define CONFIG_SEGGER_RTT_MAX_NUM_UP_BUFFERS 3
#define CONFIG_SEGGER_RTT_MAX_NUM_DOWN_BUFFERS 3
#define CONFIG_SEGGER_RTT_BUFFER_SIZE_UP 1024
#define CONFIG_SEGGER_RTT_BUFFER_SIZE_DOWN 16
#define CONFIG_SEGGER_RTT_PRINTF_BUFFER_SIZE 64
#define CONFIG_SEGGER_RTT_MODE_NO_BLOCK_SKIP 1
#define CONFIG_SEGGER_RTT_MODE 0
#define CONFIG_SEGGER_RTT_SECTION_NONE 1
#define CONFIG_SERIAL_HAS_DRIVER 1
#define CONFIG_SERIAL_SUPPORT_ASYNC 1
#define CONFIG_SERIAL_SUPPORT_INTERRUPT 1
#define CONFIG_UART_NRFX 1
#define CONFIG_UART_0_NRF_UARTE 1
#define CONFIG_UART_0_ENHANCED_POLL_OUT 1
#define CONFIG_UART_0_INTERRUPT_DRIVEN 1
#define CONFIG_UART_0_NRF_TX_BUFFER_SIZE 32
#define CONFIG_UART_1_NRF_UARTE 1
#define CONFIG_UART_1_INTERRUPT_DRIVEN 1
#define CONFIG_UART_1_ENHANCED_POLL_OUT 1
#define CONFIG_UART_1_NRF_TX_BUFFER_SIZE 32
#define CONFIG_NRF_UARTE_PERIPHERAL 1
#define CONFIG_NRF_RTC_TIMER_USER_CHAN_COUNT 0
#define CONFIG_SYSTEM_CLOCK_WAIT_FOR_STABILITY 1
#define CONFIG_SYSTEM_CLOCK_DISABLE 1
#define CONFIG_SYSTEM_CLOCK_INIT_PRIORITY 0
#define CONFIG_TICKLESS_CAPABLE 1
#define CONFIG_ENTROPY_GENERATOR 1
#define CONFIG_ENTROPY_NRF5_RNG 1
#define CONFIG_ENTROPY_NRF5_THR_POOL_SIZE 8
#define CONFIG_ENTROPY_NRF5_THR_THRESHOLD 4
#define CONFIG_ENTROPY_NRF5_ISR_POOL_SIZE 16
#define CONFIG_ENTROPY_NRF5_ISR_THRESHOLD 12
#define CONFIG_ENTROPY_HAS_DRIVER 1
#define CONFIG_GPIO_LOG_LEVEL_INF 1
#define CONFIG_GPIO_LOG_LEVEL 3
#define CONFIG_GPIO_NRFX 1
#define CONFIG_GPIO_NRF_INIT_PRIORITY 40
#define CONFIG_GPIO_NRF_P0 1
#define CONFIG_PWM 1
#define CONFIG_PWM_LOG_LEVEL_INF 1
#define CONFIG_PWM_LOG_LEVEL 3
#define CONFIG_PWM_NRFX 1
#define CONFIG_CLOCK_CONTROL_LOG_LEVEL_INF 1
#define CONFIG_CLOCK_CONTROL_LOG_LEVEL 3
#define CONFIG_CLOCK_CONTROL_NRF_FORCE_ALT 1
#define CONFIG_CLOCK_CONTROL_NRF 1
#define CONFIG_CLOCK_CONTROL_NRF_K32SRC_XTAL 1
#define CONFIG_CLOCK_CONTROL_NRF_K32SRC_20PPM 1
#define CONFIG_CLOCK_CONTROL_NRF_ACCURACY 20
#define CONFIG_FLASH_HAS_DRIVER_ENABLED 1
#define CONFIG_FLASH_HAS_PAGE_LAYOUT 1
#define CONFIG_FLASH 1
#define CONFIG_FLASH_LOG_LEVEL_INF 1
#define CONFIG_FLASH_LOG_LEVEL 3
#define CONFIG_FLASH_PAGE_LAYOUT 1
#define CONFIG_SOC_FLASH_NRF 1
#define CONFIG_COUNTER 1
#define CONFIG_COUNTER_LOG_LEVEL_INF 1
#define CONFIG_COUNTER_LOG_LEVEL 3
#define CONFIG_COUNTER_NRF_TIMER 1
#define CONFIG_COUNTER_TIMER2 1
#define CONFIG_CRYPTO 1
#define CONFIG_CRYPTO_INIT_PRIORITY 90
#define CONFIG_CRYPTO_LOG_LEVEL_INF 1
#define CONFIG_CRYPTO_LOG_LEVEL 3
#define CONFIG_CRYPTO_NRF_ECB 1
#define CONFIG_MINIMAL_LIBC 1
#define CONFIG_HAS_NEWLIB_LIBC_NANO 1
#define CONFIG_MINIMAL_LIBC_MALLOC 1
#define CONFIG_MINIMAL_LIBC_MALLOC_ARENA_SIZE 0
#define CONFIG_MINIMAL_LIBC_CALLOC 1
#define CONFIG_MINIMAL_LIBC_REALLOCARRAY 1
#define CONFIG_STDOUT_CONSOLE 1
#define CONFIG_SYS_HEAP_ALLOC_LOOPS 3
#define CONFIG_CBPRINTF_COMPLETE 1
#define CONFIG_CBPRINTF_FULL_INTEGRAL 1
#define CONFIG_CBPRINTF_FP_SUPPORT 1
#define CONFIG_CBPRINTF_N_SPECIFIER 1
#define CONFIG_POSIX_MAX_FDS 4
#define CONFIG_MAX_TIMER_COUNT 5
#define CONFIG_PRINTK 1
#define CONFIG_EARLY_CONSOLE 1
#define CONFIG_ASSERT 1
#define CONFIG_ASSERT_LEVEL 2
#define CONFIG_SPIN_VALIDATE 1
#define CONFIG_ASSERT_VERBOSE 1
#define CONFIG_ASSERT_NO_COND_INFO 1
#define CONFIG_ASSERT_NO_MSG_INFO 1
#define CONFIG_LOG 1
#define CONFIG_LOG_MINIMAL 1
#define CONFIG_LOG_OVERRIDE_LEVEL 0
#define CONFIG_LOG_MAX_LEVEL 4
#define CONFIG_NET_BUF 1
#define CONFIG_NET_BUF_USER_DATA_SIZE 4
#define CONFIG_NET_BUF_LOG_LEVEL_INF 1
#define CONFIG_NET_BUF_LOG_LEVEL 3
#define CONFIG_NETWORKING 1
#define CONFIG_NET_L2_ZIGBEE 1
#define CONFIG_NET_NATIVE 1
#define CONFIG_NET_NATIVE_IPV6 1
#define CONFIG_NET_INIT_PRIO 90
#define CONFIG_NET_IF_MAX_IPV6_COUNT 1
#define CONFIG_NET_IF_UNICAST_IPV6_ADDR_COUNT 2
#define CONFIG_NET_IF_MCAST_IPV6_ADDR_COUNT 3
#define CONFIG_NET_IF_IPV6_PREFIX_COUNT 2
#define CONFIG_NET_INITIAL_HOP_LIMIT 64
#define CONFIG_NET_IPV6_MAX_NEIGHBORS 8
#define CONFIG_NET_IPV6_LOG_LEVEL 0
#define CONFIG_NET_ICMPV6_LOG_LEVEL 0
#define CONFIG_NET_IPV6_NBR_CACHE_LOG_LEVEL 0
#define CONFIG_NET_TC_TX_COUNT 1
#define CONFIG_NET_TC_RX_COUNT 1
#define CONFIG_NET_TC_THREAD_COOPERATIVE 1
#define CONFIG_NET_TC_NUM_PRIORITIES 16
#define CONFIG_NET_TC_MAPPING_STRICT 1
#define CONFIG_NET_TX_DEFAULT_PRIORITY 1
#define CONFIG_NET_RX_DEFAULT_PRIORITY 0
#define CONFIG_NET_MAX_ROUTERS 1
#define CONFIG_NET_MAX_CONTEXTS 6
#define CONFIG_NET_CONTEXT_SYNC_RECV 1
#define CONFIG_NET_CONTEXT_CHECK 1
#define CONFIG_NET_PKT_RX_COUNT 4
#define CONFIG_NET_PKT_TX_COUNT 4
#define CONFIG_NET_BUF_RX_COUNT 16
#define CONFIG_NET_BUF_TX_COUNT 16
#define CONFIG_NET_BUF_FIXED_DATA_SIZE 1
#define CONFIG_NET_BUF_DATA_SIZE 128
#define CONFIG_NET_DEFAULT_IF_FIRST 1
#define CONFIG_NET_PKT_TIMESTAMP 1
#define CONFIG_NET_PKT_TXTIME 1
#define CONFIG_NET_TX_STACK_SIZE 1200
#define CONFIG_NET_RX_STACK_SIZE 1500
#define CONFIG_NET_PKT_LOG_LEVEL 0
#define CONFIG_NET_DEBUG_NET_PKT_EXTERNALS 0
#define CONFIG_NET_CORE_LOG_LEVEL 0
#define CONFIG_NET_IF_LOG_LEVEL 0
#define CONFIG_NET_TC_LOG_LEVEL 0
#define CONFIG_NET_UTILS_LOG_LEVEL 0
#define CONFIG_NET_CONTEXT_LOG_LEVEL 0
#define CONFIG_NET_CONN_LOG_LEVEL 0
#define CONFIG_NET_ROUTE_LOG_LEVEL 0
#define CONFIG_NET_HTTP_LOG_LEVEL 0
#define CONFIG_NET_CONFIG_AUTO_INIT 1
#define CONFIG_NET_CONFIG_INIT_PRIO 95
#define CONFIG_NET_CONFIG_INIT_TIMEOUT 30
#define CONFIG_NET_CONFIG_LOG_LEVEL 0
#define CONFIG_PM_POLICY_RESIDENCY 1
#define CONFIG_PM_POLICY_RESIDENCY_DEFAULT 1
#define CONFIG_PM_MIN_RESIDENCY_DEEP_SLEEP_1 60000
#define CONFIG_PM_LOG_LEVEL_INF 1
#define CONFIG_PM_LOG_LEVEL 3
#define CONFIG_ENTROPY_DEVICE_RANDOM_GENERATOR 1
#define CONFIG_CSPRING_ENABLED 1
#define CONFIG_HARDWARE_DEVICE_CS_GENERATOR 1
#define CONFIG_FLASH_MAP 1
#define CONFIG_TEST_ARM_CORTEX_M 1
#define CONFIG_TOOLCHAIN_GNUARMEMB 1
#define CONFIG_LINKER_ORPHAN_SECTION_WARN 1
#define CONFIG_HAS_FLASH_LOAD_OFFSET 1
#define CONFIG_FLASH_LOAD_OFFSET 0x0
#define CONFIG_FLASH_LOAD_SIZE 0x0
#define CONFIG_KERNEL_ENTRY "__start"
#define CONFIG_LINKER_SORT_BY_ALIGNMENT 1
#define CONFIG_SIZE_OPTIMIZATIONS 1
#define CONFIG_COMPILER_OPT ""
#define CONFIG_RUNTIME_ERROR_CHECKS 1
#define CONFIG_KERNEL_BIN_NAME "zephyr"
#define CONFIG_OUTPUT_STAT 1
#define CONFIG_OUTPUT_DISASSEMBLY 1
#define CONFIG_OUTPUT_PRINT_MEMORY_USAGE 1
#define CONFIG_BUILD_OUTPUT_BIN 1
#define CONFIG_REBOOT 1
#define CONFIG_COMPAT_INCLUDES 1
