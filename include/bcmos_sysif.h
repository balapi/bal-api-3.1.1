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
 * bcmos_sysif.h
 *
 * This internal header file includes OS-specific services
 * that are referred in OS-independent OS abstraction implementation
 *
 */

#ifndef BCMOS_SYSIF_H_
#define BCMOS_SYSIF_H_

/*
 * OS-specific init
 */

/** Initialize system library
 * Must be called before any other system function
 * \returns 0=OK or error code <0
 */
bcmos_errno bcmos_sys_init(void);

/** Clean-up system library
 */
void bcmos_sys_exit(void);


/*
 * Timer support
 */

/* OS abstraction must define struct bcmos_sys_timer
 */
typedef struct bcmos_sys_timer bcmos_sys_timer;

/* System timer handler. Implemented in common OS abstraction services */
typedef void (*bcmos_sys_timer_handler)(void *data);

/* Create system timer
 * It is expected that only one high-resolution system timer is needed.
 * It is used to "kick" timer pool implemented in OS abstraction
 * \param[in]   timer   System timer
 * \param[in]   handler Timer handler
 * \param[in]   data    Data to be passed to the handler
 * \returns 0 if OK or error < 0
 */
bcmos_errno bcmos_sys_timer_create(bcmos_sys_timer *timer, bcmos_sys_timer_handler handler, void *data);

/* Destroy system timer
 * \param[in]   timer   System timer
 */
void bcmos_sys_timer_destroy(bcmos_sys_timer *timer);

/* Start system timer
 * \param[in]   timer           System timer
 * \param[in]   interval        Interval (us)
 */
void bcmos_sys_timer_start(bcmos_sys_timer *timer, uint32_t interval);

/* Stop system timer
 * \param[in]   timer           System timer
 */
void bcmos_sys_timer_stop(bcmos_sys_timer *timer);

#endif /* BCMOS_SYSIF_H_ */
