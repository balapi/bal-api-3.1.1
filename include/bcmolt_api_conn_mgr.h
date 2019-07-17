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

/*
 * Application side connection manager.
 * This module monitors application connection with Device Managhement Daemon(s)
 */

#ifndef BCMOLT_API_CONN_MGR_
#define BCMOLT_API_CONN_MGR_

#include <bcmos_system.h>
#include <bcmolt_msg.h>
#include <bcmtr_interface.h>
#include <bcmolt_api_topology.h>

/** Connection manager flags */
typedef enum
{
    BCMOLT_API_CONN_MGR_FLAGS_NONE          = 0,
    BCMOLT_API_CONN_MGR_FLAGS_DISABLE_KA    = 0x1,   /**< Disable keep alive (for debugging) */
} bcmolt_api_conn_mgr_flags;

bcmos_errno bcmolt_api_conn_mgr_start(bcmolt_goid olt, bcmolt_loid loid,
    const bcmtr_conn_parms *tr_conn_parms, bcmolt_api_conn_mgr_flags flags);

bcmos_bool bcmolt_api_conn_mgr_is_connected(bcmolt_goid olt);

void bcmolt_api_conn_mgr_stop(bcmolt_goid olt);

void bcmolt_api_conn_mgr_stop_all(void);

#endif /* BCMOLT_API_CONN_MGR_H_ */
