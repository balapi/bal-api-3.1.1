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

/* bcmolt_presence_mask.h:
 * Definitions/utilities related to presence masks.
 */

#ifndef BCMOLT_PRESENCE_MASK_H_
#define BCMOLT_PRESENCE_MASK_H_

#include <bcmos_system.h>

/** Bitmask of fields that are present in a message/struct/array. */
typedef uint64_t bcmolt_presence_mask;

/** Presence mask indicating all fields present. For structures/arrays, 0 also means all fields present. */
#define BCMOLT_PRESENCE_MASK_ALL ((bcmolt_presence_mask)0xFFFFFFFFFFFFFFFF)

#endif
