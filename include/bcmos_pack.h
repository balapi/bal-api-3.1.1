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

#ifndef BCMOS_PACK_H_
#define BCMOS_PACK_H_


/*
 * Packing macros
 *
 * Usage:
 * struct __PACKED_ATTR_START__ my_packed_struct
 * {
 *      ...
 * } __PACKED_ATTR_END__ ;
 *
 */

#ifdef __GNUC__

#define __PACKED_ATTR_START__
#define __PACKED_ATTR_END__ __attribute__ ((packed))

#else

#error define __PACKED_ATTR_START__,  __PACKED_ATTR_END__ for this compiler

#endif

/*
 * Macros for bit-field manipulation
 * For each field F requires 2 constants
 * - F_S - field shift
 * - F_W - field width
 */
#define BCM_FIELD_GET(_w, _f)           (((_w)>>_f ## _S) & ((1 << _f ## _W) - 1))
#define BCM_FIELD(_f, _v)               ((_v & ((1 << _f ## _W) - 1)) << _f ## _S)
#define BCM_FIELD_SET(_w, _f, _v)       (_w) |= BCM_FIELD(_f, _v)


#endif /* BCMOS_PACK_H_ */
