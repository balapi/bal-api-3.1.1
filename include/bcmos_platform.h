/*
   <:copyright-BRCM:2016:DUAL/GPL:standard

   Broadcom Proprietary and Confidential.(c) 2016 Broadcom
   All Rights Reserved

   Unless you and Broadcom execute a separate written software license
   agreement governing use of this software, this software is licensed
   to you under the terms of the GNU General Public License version 2
   (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
   with the following added to such license:

   As a special exception, the copyright holders of this software give
   you permission to link this software with independent modules, and
   to copy and distribute the resulting executable under terms of your
   choice, provided that you also meet, for each linked independent
   module, the terms and conditions of the license of that module.
   An independent module is a module which is not derived from this
   software.  The special exception does not apply to any modifications
   of the software.

   Not withstanding the above, under no circumstances may you combine
   this software in any way with any other Broadcom software provided
   under a license other than the GPL, without Broadcom's express prior
   written consent.

   :>
 */

#ifndef BCMOS_PLATFORM_H_
#define BCMOS_PLATFORM_H_

#ifndef BCMOS_SYSTEM_H_
#error Please do not include bcmos_platform.h directly. Include bcmos_system.h
#endif

typedef enum
{
    BCM_MAC_DEVICE_TYPE_UNKNOWN,
    BCM_MAC_DEVICE_TYPE_BCM6862X,       /* Maple family */
    BCM_MAC_DEVICE_TYPE_BCM6865X,       /* Aspen family */
} bcm_mac_device_type;

/** BCM68620 CPU core
 * \ingroup system_task */
typedef enum
{
    BCMOS_CPU_CORE_ANY,                         /**< Any core */

    BCMOS_CPU_CORE__NUM_OF = 1,                 /**< Number of cores */
} bcmos_core;

#define MAX_NUMBER_OF_PONS_ON_ALL_DEVICES (BCMTR_MAX_DEVICES * BCMTR_MAX_INSTANCES)

/** BCM68620 module
 * \ingroup system_module
 */
typedef enum
{
    BCMOS_MODULE_ID_NONE,                       /**< no module */

#ifdef BCMOS_SYS_UNITTEST
    BCMOS_MODULE_ID_TEST1,
    BCMOS_MODULE_ID_TEST2,
#endif
    BCMOS_MODULE_ID_TRANSPORT_IND,

    /* Each Device (BCM6862X) must have its own dedicated Device Control Module at the host */
    BCMOS_MODULE_ID_DEV_AGENT_DEV0,

    /* CLI over PCIe client */
    BCMOS_MODULE_ID_CLI_OVER_PCIE = BCMOS_MODULE_ID_DEV_AGENT_DEV0 + BCMTR_MAX_DEVICES,

    /* Protection switching user application */
    BCMOS_MODULE_ID_USER_APPL_PS,

    /* Remote CLI */
    BCMOS_MODULE_ID_REMOTE_CLI_DEV0 = BCMOS_MODULE_ID_USER_APPL_PS + BCMTR_MAX_DEVICES,

    /* Remote logger application (To support multiple devices we need to add number of devices to previous value) */
    BCMOS_MODULE_ID_USER_APPL_REMOTE_LOGGER_DEV0 = BCMOS_MODULE_ID_REMOTE_CLI_DEV0 + BCMTR_MAX_DEVICES,

    /* OMCI SW download user application (To support multiple devices we need to add number of devices to previous value) */
    BCMOS_MODULE_ID_USER_APPL_OMCI_SWDL_DEV0 = BCMOS_MODULE_ID_USER_APPL_REMOTE_LOGGER_DEV0 + BCMTR_MAX_DEVICES,

    /* ITU mac learning / aging user application (To support multiple devices we need to add number of devices to previous value) */
    BCMOS_MODULE_ID_USER_APPL_ITU_MAC_LEARNING_DEV0 = BCMOS_MODULE_ID_USER_APPL_OMCI_SWDL_DEV0 + BCMTR_MAX_DEVICES,

    /* GPON stress user application (To support multiple devices we need to add number of devices to previous value) */
    BCMOS_MODULE_ID_USER_APPL_ITU_STRESS_DEV0 =  BCMOS_MODULE_ID_USER_APPL_ITU_MAC_LEARNING_DEV0 + BCMTR_MAX_DEVICES,

    /* GPON DS OMCI packets user application (To support multiple devices we need to add number of devices to previous value) */
    BCMOS_MODULE_ID_USER_APPL_ITU_DS_OMCI_DEV0 = BCMOS_MODULE_ID_USER_APPL_ITU_STRESS_DEV0 + BCMTR_MAX_DEVICES,

    /* GPON SN acquisition (To support multiple devices we need to add number of devices multiplied by max PON number to previous value) */
    BCMOS_MODULE_ID_USER_APPL_ITU_SN_DISCOVERY_DEV0 = BCMOS_MODULE_ID_USER_APPL_ITU_DS_OMCI_DEV0 + MAX_NUMBER_OF_PONS_ON_ALL_DEVICES,

    /* GPON cooperative DBA example application (To support multiple devices we need to add number of devices multiplied by max PON number to previous value) */
    BCMOS_MODULE_ID_USER_APPL_GPON_COOP_DBA_EXAMPLE_DEV0 = BCMOS_MODULE_ID_USER_APPL_ITU_SN_DISCOVERY_DEV0 + MAX_NUMBER_OF_PONS_ON_ALL_DEVICES,

    /* GPON statistics (To support multiple devices we need to add number of devices multiplied by max PON number to previous value) */
    BCMOS_MODULE_ID_USER_APPL_ITU_STATISTICS_DEV0 = BCMOS_MODULE_ID_USER_APPL_GPON_COOP_DBA_EXAMPLE_DEV0 + MAX_NUMBER_OF_PONS_ON_ALL_DEVICES,

    /* ITU RSSI user application (To support multiple devices we need to add number of devices multiplied by max PON number to previous value) */
    BCMOS_MODULE_ID_USER_APPL_ITU_RSSI_DEV0 = BCMOS_MODULE_ID_USER_APPL_ITU_STATISTICS_DEV0 + MAX_NUMBER_OF_PONS_ON_ALL_DEVICES,

    /* ITU NG-PON2 Wavelength Handover user application */
    BCMOS_MODULE_ID_USER_APPL_ITU_ONU_TUNING_OLT0 = BCMOS_MODULE_ID_USER_APPL_ITU_RSSI_DEV0 + BCMTR_MAX_DEVICES,

    /* EPON OAM negotiation application (To support multiple devices we need to add number of devices to previous value) */
    BCMOS_MODULE_ID_USER_APPL_EON = BCMOS_MODULE_ID_USER_APPL_ITU_ONU_TUNING_OLT0 + BCMTR_MAX_OLTS,

    /* EPON optical monitoring application */
    BCMOS_MODULE_ID_USER_APPL_OMON = BCMOS_MODULE_ID_USER_APPL_EON + BCMTR_MAX_DEVICES,

    /* EPON Host driven encryption application */
    BCMOS_MODULE_ID_USER_APPL_EPON_HDE,

    BCMOS_MODULE_ID_USER_APPL_EPON_OAM,

    BCMOS_MODULE_ID_USER_APPL_DPOE_SEC,

    BCMOS_MODULE_ID_USER_APPL_IMAGE_TRANSFER0 = BCMOS_MODULE_ID_USER_APPL_DPOE_SEC + BCMTR_MAX_DEVICES,

    BCMOS_MODULE_ID_USER_APPL_ONU_TUNING_DEV0 = BCMOS_MODULE_ID_USER_APPL_IMAGE_TRANSFER0 + BCMTR_MAX_DEVICES,

    BCMOS_MODULE_ID_USER_APPL_TOD_DEV0 = BCMOS_MODULE_ID_USER_APPL_ONU_TUNING_DEV0 + BCMTR_MAX_DEVICES,

    /* OLT Agent */
    BCMOS_MODULE_ID_OLT_AGENT = BCMOS_MODULE_ID_USER_APPL_TOD_DEV0 + BCMTR_MAX_DEVICES,

    /* BALIMPORT BEGIN */
    BCMOS_MODULE_ID_WORKER_MGMT,  /**< Number of modules *//** worker module for MGMT message handling */
    BCMOS_MODULE_ID_WORKER_API_IND,             /** worker module for BAL API INDICATION message handling */
    BCMOS_MODULE_ID_WORKER_BAL_CORE_FOR_AGENT,  /** worker module for the BAL CORE when running as an OF agent */
    /* BALIMPORT TODO: duplicates */
    //  BCMOS_MODULE_ID_USER_APPL_EON,              /** EON module */
    //  BCMOS_MODULE_ID_USER_APPL_EPON_OAM,         /** EPON OAM module */
    BCMOS_MODULE_ID_OFPAL,                      /** OF-PAL module */
    BCMOS_MODULE_ID_OMCI_TRANSPORT,             /** OMCI Transport module */
    BCMOS_MODULE_ID_OMCI_RX_WORKER0,            /** OMCI RX worker module */
#define BCM_OMCI_MAX_RX_WORKER_THREADS  32
    BCMOS_MODULE_ID_DPOE2_TRANSPORT = BCMOS_MODULE_ID_OMCI_RX_WORKER0 + BCM_OMCI_MAX_RX_WORKER_THREADS, /** DPoE2 Transport module */
    BCMOS_MODULE_ID_API_PROXY,                  /** API proxy module */
    BCMOS_MODULE_ID_VOMCI_SERVER,               /** ONU management: VOMCI server module */
    /* BALIMPORT END */

    BCMOS_MODULE_ID__NUM_OF,                    /**< Number of modules */
    BCMOS_MODULE_ID_INVALID = BCMOS_MODULE_ID_NONE
} bcmos_module_id;

/** BCM68620 event group. Each group supports up to 32 events.
 * \ingroup system_event
 */
typedef enum
{
#ifdef BCMOS_SYS_UNITTEST
    BCMOS_EVENT_ID_TEST1,
    BCMOS_EVENT_ID_TEST2,
#else
    BCMOS_EVENT_ID_DUMMY,                       /* Currently OS s/w doesn't use events.
                                                   Remove this constant when adding real events */
#endif

    BCMOS_EVENT_ID__NUM_OF,                     /**< Number of event groups */
} bcmos_event_id;

/** Message hash size
 * \ingroup system_msg
 */
#define BCMOS_MSG_HASH_SIZE     512

/** Maple OS message
 * \ingroup system_msg
 */
typedef enum
{
    BCMOS_MSG_ID__BEGIN,

    /* Internal messages */
    BCMOS_MSG_ID_INTERNAL_TIMER = BCMOS_MSG_ID__BEGIN, /**< Internal "timer message" type */
    BCMOS_MSG_ID_INTERNAL_EVENT,                       /**< Internal "event message" type */
    BCMOS_MSG_ID_INTERNAL_IPC,

    BCMOS_MSG_ID_INITIATE_RX_POWER,
    BCMOS_MSG_ID_INITIATE_TRX_STATUS,
    BCMOS_MSG_ID_INITIATE_ROGUE_SCAN,
    BCMOS_MSG_ID_INITIATE_RSSI_READ,

    BCMOS_MSG_ID_ITU_STRESS_START,
    BCMOS_MSG_ID_ITU_STRESS_TIMEOUT,
    BCMOS_MSG_ID_ITU_STRESS_ONU_DISCOVERED,
    BCMOS_MSG_ID_ITU_STRESS_PON_DEACTIVATION_COMPLETED,
    BCMOS_MSG_ID_ITU_STRESS_PON_ACTIVATION_COMPLETED,
    BCMOS_MSG_ID_ITU_STRESS_ALL_ONUS_DEACTIVATION_COMPLETED,
    BCMOS_MSG_ID_ITU_STRESS_ALL_ONUS_ACTIVATION_COMPLETED,
    BCMOS_MSG_ID_ITU_STRESS_ONU_DEACTIVATION_COMPLETED,
    BCMOS_MSG_ID_ITU_STRESS_ONU_ACTIVATION_COMPLETED,

    BCMOS_MSG_ID_ITU_DS_OMCI_START,
    BCMOS_MSG_ID_ITU_DS_OMCI_TIMEOUT,
    BCMOS_MSG_ID_ITU_DS_OMCI_STOP,
    BCMOS_MSG_ID_ITU_DS_OMCI_DEVICE_CONNECTED,
    BCMOS_MSG_ID_ITU_DS_OMCI_DEVICE_DISCONNECTED,

    BCMOS_MSG_ID_ITU_RSSI_START,

    BCMOS_MSG_ID_ITU_STATISTICS_START,
    BCMOS_MSG_ID_ITU_STATISTICS_TIMEOUT,
    BCMOS_MSG_ID_ITU_STATISTICS_STOP,

    BCMOS_MSG_ID_EON_START,
    BCMOS_MSG_ID_EON_STOP,
    BCMOS_MSG_ID_EON_PROXY_RX,

    BCMOS_MSG_ID_EPON_OAM_PROXY_RX,
    BCMOS_MSG_ID_EPON_OAM_TIMEOUT,

    BCMOS_MSG_ID_DPOE_SEC_START,
    BCMOS_MSG_ID_DPOE_SEC_RX_OAM,
    BCMOS_MSG_ID_DPOE_SEC_RX_EAPOL,

    BCMOS_MSG_ID_ONU_TUNING_START,
    BCMOS_MSG_ID_ONU_TUNING_STOP,

    BCMOS_MSG_ID_OLT_AGENT_BAL_STATE_CHANGED, /* BAL reports state change to OLT Agent */

    BCMOS_MSG_ID_SW_UTIL_NNI_STATE_CHANGED,
    BCMOS_MSG_ID_SW_UTIL_RING_PORT_CONTROL,

    /******************************************************************************/
    /* BALIMPORT BEGIN */
    /* Application messages */
    BCMOS_MSG_ID_IPC_PING,                  /*** Inter-process communication ping */

    /* Core/Switch util messages */
    BCMBAL_SWITCH_UTIL_MSG,

    /* Core/Mac util messages */
    BCMBAL_MAC_UTIL_MSG,

    /* Core->Public API indication messages (both auto and "normal") */
    BCMBAL_MGMT_API_IND_MSG,

    BCMOS_MSG_ID_OMCI_TRANSPORT_SEND,

    BCMOS_MSG_ID_DPOE2_TRANSPORT_SEND,
    /* BALIMPORT END */
    /******************************************************************************/

    /* Device Agent Internal Messages BEGIN */
    BCMOS_MSG_ID_DA_INT_TIMEOUT,
    BCMOS_MSG_ID_DA_INT_KA_FAIL,
    BCMOS_MSG_ID_DA_INT_DISCONNECT_REQ,
    BCMOS_MSG_ID_DA_INT_RESET_REQ,
    BCMOS_MSG_ID_DA_INT_DDR_TEST_TIMEOUT,
    BCMOS_MSG_ID_DA_INT_DDR_TEST_COMPLETE,
    BCMOS_MSG_ID_DA_INT_INBAND_CONN_ESTD,
    BCMOS_MSG_ID_DA_IND_DISCONNECT,
    BCMOS_MSG_ID_DA_IND_CONN_FAIL,
    BCMOS_MSG_ID_DA_IND_DDR_TEST_FAIL,
    /* Device Agent Internal Messages END */

    /* TOD APPL Messages */
    BCMOS_MSG_ID_TOD_APPL_START,
    /* PS APPL Messages */
    BCMOS_MSG_ID_PS_APPL_START,

    BCMOS_MSG_ID__NONE,
    BCMOS_MSG_ID__END,
    BCMOS_MSG_ID__FORCE16 = 0x7fff
} bcmos_msg_id;

#define BCMOS_MSG_ID__NUM_OF (BCMOS_MSG_ID__END - BCMOS_MSG_ID__BEGIN)
/*
 * Task priorities
 */

#define TASK_PRIORITY_COOP_DBA                        BCMOS_TASK_PRIORITY_1
#define TASK_PRIORITY_TRMUX_RX                        BCMOS_TASK_PRIORITY_2
#define TASK_PRIORITY_TRANSPORT_RX                    BCMOS_TASK_PRIORITY_7
#define TASK_PRIORITY_TRANSPORT_TIMEOUT               BCMOS_TASK_PRIORITY_8
#define TASK_PRIORITY_TRANSPORT_PROXY                 BCMOS_TASK_PRIORITY_9
#define TASK_PRIORITY_TRANSPORT_REMOTE_CLI            BCMOS_TASK_PRIORITY_9
#define TASK_PRIORITY_DEVICE_CONTROL                  BCMOS_TASK_PRIORITY_10
#define TASK_PRIORITY_TRANSPORT_IND                   BCMOS_TASK_PRIORITY_11
#define TASK_PRIORITY_USER_APPL_PS                    BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_USER_APPL_EON                   BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_USER_APPL_OMON                  BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_USER_APPL_EPON_HDE              BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_USER_APPL_DPOE_SEC              BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_USER_APPL_ITU_MAC_LEARNING      BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_USER_APPL_ITU_STRESS           BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_USER_APPL_ITU_SN_DISCOVERY      BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_USER_APPL_ITU_DS_OMCI           BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_USER_APPL_ITU_STATISTICS        BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_USER_APPL_ITU_ONU_TUNING        BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_USER_APPL_ITU_RSSI             BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_USER_APPL_GPON_COOP_DBA_EXAMPLE BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_USER_APPL_TOD                   BCMOS_TASK_PRIORITY_12
#define TASK_PRIORITY_CLI                             BCMOS_TASK_PRIORITY_15
#define TASK_PRIORITY_USER_APPL_OMCI_SWDL             BCMOS_TASK_PRIORITY_17
#define TASK_PRIORITY_USER_APPL_IMAGE_TRANSFER        BCMOS_TASK_PRIORITY_17
#define TASK_PRIORITY_DEV_LOG_KERNEL                  BCMOS_TASK_PRIORITY_20
#define TASK_PRIORITY_DEV_LOG                         BCMOS_TASK_PRIORITY_30
#define TASK_PRIORITY_USER_APPL_REMOTE_LOGGER         BCMOS_TASK_PRIORITY_30

/* BALIMPORT BEGIN */
#define TASK_PRIORITY_KEEP_ALIVE                BCMOS_TASK_PRIORITY_2
#define TASK_PRIORITY_IPC_RX                    BCMOS_TASK_PRIORITY_3
#define TASK_PRIORITY_API_PROXY_RX              BCMOS_TASK_PRIORITY_4
#define TASK_PRIORITY_API_PROXY_INVOKE          BCMOS_TASK_PRIORITY_5
#define TASK_PRIORITY_CORE_CONN_MGR             BCMOS_TASK_PRIORITY_6
#define TASK_PRIORITY_CLI                       BCMOS_TASK_PRIORITY_15
#define TASK_PRIORITY_OLT_AGENT                 BCMOS_TASK_PRIORITY_16
#define TASK_PRIORITY_WORKER                    BCMOS_TASK_PRIORITY_16
#define TASK_PRIORITY_OFPAL                     BCMOS_TASK_PRIORITY_18
#define TASK_PRIORITY_VOMCI_SERVER              BCMOS_TASK_PRIORITY_18
#define TASK_PRIORITY_VOMCI_DOLT_CLIENT         BCMOS_TASK_PRIORITY_19
#define TASK_PRIORITY_OMCI_TRANSPORT            BCMOS_TASK_PRIORITY_20
#define TASK_PRIORITY_OMCI_RX_WORKER            BCMOS_TASK_PRIORITY_20
#define TASK_PRIORITY_DPOE2_TRANSPORT           BCMOS_TASK_PRIORITY_20
#define TASK_PRIORITY_DEV_LOG                   BCMOS_TASK_PRIORITY_30
/* BALIMPORT END */

#endif /* BCMOS_PLATFORM_H_ */
