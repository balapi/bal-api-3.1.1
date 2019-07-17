/******************************************************************************
 *
 *  <:copyright-BRCM:2016:DUAL/GPL:standard
 *
 *     Copyright (c) 2016 Broadcom
 *     All Rights Reserved
 *
 *  Unless you and Broadcom execute a separate written software license
 *  agreement governing use of this software, this software is licensed
 *  to you under the terms of the GNU General Public License version 2
 *  (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
 *  with the following added to such license:
 *
 *     As a special exception, the copyright holders of this software give
 *     you permission to link this software with independent modules, and
 *     to copy and distribute the resulting executable under terms of your
 *     choice, provided that you also meet, for each linked independent
 *     module, the terms and conditions of the license of that module.
 *     An independent module is a module which is not derived from this
 *     software.  The special exception does not apply to any modifications
 *     of the software.
 *
 *  Not withstanding the above, under no circumstances may you combine
 *  this software in any way with any other Broadcom software provided
 *  under a license other than the GPL, without Broadcom's express prior
 *  written consent.
 *
 *  :>
 *
 *****************************************************************************/

/**
 * @file bcmos_system.h
 * @brief The file provides a FAKE stub for bcmos_system.h
 *
 */
#ifndef BCMOS_SYSTEM_H_
#define BCMOS_SYSTEM_H_

#include <pthread.h>
#include <semaphore.h>
#include <inttypes.h>
#include <bcmos_common.h>

#ifdef __cplusplus
typedef bool bcmos_bool;
#define BCMOS_FALSE false
#define BCMOS_TRUE true
#else
typedef _Bool bcmos_bool;
#define BCMOS_FALSE 0
#define BCMOS_TRUE 1
#endif

#include "bcmos_queue.h"

typedef uint16_t bcmos_msg_instance;

#include "bcmos_types.h"
#include "bcmos_endian.h"

#endif /* BCMOS_SYSTEM_H_ */
