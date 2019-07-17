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

#ifndef BCMOLT_HOST_API_H_
#define BCMOLT_HOST_API_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <bcmos_system.h>
#include <bcmolt_api.h>
#include <bcm_dev_log.h>

/** IP (UDP) parameters */
typedef struct
{
    bcmos_ipv4_address ip;      /**< IP address in host format */
    uint16_t port;              /**< UDP port in host format */
} addr_ip_port;
   
typedef enum
{

    BCM_HOST_API_CONN_REMOTE,
    BCM_HOST_API_CONN_LOCAL

}bcm_host_api_conn;
    
/** Host subsystem initialization parameters */
typedef struct bcmolt_host_init_parms
{
    /** Transport initialization parameters */
    struct
    {
        /** Connection parameters with device management daemon */
        bcm_host_api_conn type;       /**< Connection type. Supported types are
                                         BCM_HOST_API_CONN_REMOTE - Network connection manager based transport
                                         BCM_HOST_API_CONN_LOCAL - Unix domain socket (linux only)
                                      */
        addr_ip_port addr;            /**< Device management daemon address (and port). Must be set if type==BCM_HOST_API_CONN_REMOTE */
        uint16_t listen_port;         /**< UDP port to listen on. 0=auto-assign */
        bcmos_bool disable_ka;        /**< Disable keep alive between application and device management daemon. This is a debug option */
    } transport;

    bcmos_bool use_default_logging; /**< TRUE when the user doesn't build with logging enabled, but wants the attached host api module to be able to log */
    

    dev_log_init_parms log;

} bcmolt_host_init_parms;

/**
 * @brief  Initialize host subsystem
 * @note This function must be called first
 * @param  *init_parms: initialization parameters
 * @retval BCM_ERR_OK (0) if successful or error < 0
 */
bcmos_errno bcmolt_host_init(const bcmolt_host_init_parms *init_parms);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef BCMOLT_HOST_API_H_ */
