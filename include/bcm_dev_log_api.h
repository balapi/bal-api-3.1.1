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

#ifndef __BCM_DEV_LOG_API_H_
#define __BCM_DEV_LOG_API_H_

#include <bcmos_system.h>

/* Log file type */
typedef enum
{
    BCM_DEV_LOG_FILE_MEMORY,    /**< Memory file */
#ifdef BCM_OS_POSIX
    BCM_DEV_LOG_FILE_REGULAR,   /**< Regular file */
#endif
#ifdef DEV_LOG_SYSLOG
    BCM_DEV_LOG_FILE_SYSLOG,    /**< syslog "file" */
#endif
    BCM_DEV_LOG_FILE_UDEF       /**< User-defined file */
} bcm_dev_log_file_type;


/** Logger initialization parameters */
typedef struct dev_log_init_parms
{
    bcm_dev_log_file_type type;   /**< Log file type */
    uint32_t queue_size;          /**< Max number of entries that can be waiting on dev_log task queue. 0=use default */
#define BCM_DEV_LOG_DEFAULT_QUEUE_SIZE   4096

    union /* Log parameters per log_type */
    {
        uint32_t mem_size;        /**< Memory size for log_type == BCMOLT_LOG_TYPE_MEMORY. 0=use default */
#define BCM_DEV_LOG_DEFAULT_MEM_SIZE     (1024 * 1024)
#ifdef BCM_OS_POSIX
        const char *filename;     /**< For log_type == BCMOLT_LOG_TYPE_FILE */
#endif
    };

    /**< Optional callback to call after common log initialization.
         It can be used to set default log levels, timestamp format, etc.
    */
    bcmos_errno (*post_init_cb)(void);
} dev_log_init_parms;



#endif /* __BCM_DEV_LOG_API_H_ */
