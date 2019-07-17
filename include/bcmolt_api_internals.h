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

#ifndef BCMOLT_API_INTERNALS_H_
#define BCMOLT_API_INTERNALS_H_

#include <bcm_dev_log.h>

/** Default log ID for API error reporting */
extern dev_log_id bcmolt_api_log_id;

#ifdef BCMOLT_API_INTERNAL

/* The following internal functions are available to SDK components,
   but not to SDK application
*/

/** Get indication configuration
 *
 * This function is internal
 *
 * \param[in]   olt     OLT ID
 * \param[out]  cfg     Indication configuration structure
 * \returns error code
 * The error code can indicate local or remote failure
 */
bcmos_errno bcmolt_auto_cfg_get(bcmolt_oltid olt, bcmolt_auto_cfg *cfg);

/** Set indication configuration
 *
 * This function is internal
 *
 * \param[in]   olt     OLT ID
 * \param[in]   cfg     Indication configuration structure
 * \returns error code
 * The error code can indicate local or remote failure
 */
bcmos_errno bcmolt_auto_cfg_set(bcmolt_oltid olt, bcmolt_auto_cfg *cfg);

#endif /* #ifdef BCMOLT_API_INTERNAL */

#endif /* #ifdef BCMOLT_API_INTERNALS_H */
