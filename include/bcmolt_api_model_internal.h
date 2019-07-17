/*
<:copyright-BRCM:2018:DUAL/GPL:standard

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

#ifndef BCMOLT_API_MODEL_INTERNAL_H_
#define BCMOLT_API_MODEL_INTERNAL_H_

#include <bcmos_system.h>
#include <bcm_dev_log.h>

/* Internal macro: Check if a given bit is set in a structure presence mask */
#define _BCMOLT_FIELD_MASK_BIT_IS_SET(_mask, _field_id) \
    ((_mask == 0) || ((_mask & (uint64_t)(1ULL << _field_id))) ? BCMOS_TRUE : BCMOS_FALSE)

/* Internal macro: Set a given bit in a structure presence mask */
#define _BCMOLT_FIELD_MASK_BIT_SET(_mask, _field_id) \
    do {                                             \
        _mask |= (uint64_t)(1ULL << _field_id);      \
    } while(0)

/* Internal macro: Check if a given bit is set in an array index mask */
/* Note: array indices >63 cannot be covered by the index mask and are assumed to always be set. */
#define _BCMOLT_ARRAY_MASK_BIT_IS_SET(_mask, _idx) \
    ((_idx > 63) || (_mask == 0) || ((_mask & (1ULL << _idx)) ? BCMOS_TRUE : BCMOS_FALSE))

/* Internal macro: Check if a given bit is set in a group property mask */
#define _BCMOLT_PROPERTY_MASK_BIT_IS_SET(_mask, _prop_id) \
    ((_mask & (1ULL << (uint64_t)_prop_id)) ? BCMOS_TRUE : BCMOS_FALSE)

/* Internal macro: Log that an unknown field ID was enountered during unpack */
#define _BCMOLT_LOG_UNKNOWN_FIELD_ID(_type_name, _presence_mask, _unsupported_mask) \
    BCM_LOG(ERROR, \
        bcmolt_api_model_log_id_get(), \
        "%s: unsupported field ID %d\n", \
        _type_name, \
        ffsll((_presence_mask) & (_unsupported_mask)) - 1)

dev_log_id bcmolt_api_model_log_id_get(void);
void bcmolt_api_model_init(void);

#endif
