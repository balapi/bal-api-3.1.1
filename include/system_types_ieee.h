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

/* system_types_ieee.h: platform agnostic data types for the IEEE stack */

#ifndef SYSTEM_TYPES_IEEE_H_
#define SYSTEM_TYPES_IEEE_H_

#include <bcmos_system.h>

typedef uint32_t mpcp_timestamp;

typedef uint32_t bandwidth_tqps;

#define LINE_RATE_1G_KBPS 1000000
#define LINE_RATE_10G_KBPS 10000000
#define LINE_RATE_25G_KBPS 25000000

#define RPT_LEN_1G_NO_FEC_TQ    42
#define RPT_LEN_1G_FEC_TQ       58
#define RPT_LEN_10G_TQ          5
#define RPT_LEN_25G_TQ          2

#define NS_PER_TQ 16

#endif /* SYSTEM_TYPES_IEEE_H_ */
