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

#ifndef BCMOS_ENDIAN_H_
#define BCMOS_ENDIAN_H_

#ifndef BCMOS_SYSTEM_H_
#error Please do not include bcmos_endian.h directly. Include bcmos_system.h
#endif


/** \addtogroup system_endian
 * @{
 */
#ifndef BCMOS_ARCH_ENDIAN_SWAP

/** Swaps the endianness of a 16-bit integer
 * \param[in] n the original number
 * \return number with swapped endianness
 */
static inline uint16_t bcmos_endian_swap_u16(uint16_t n)
{
    return ((n << 8 ) & 0xFF00U)|((n >> 8) & 0x00FFU);
}

/** Swaps the endianness of a 24-bit integer
 * \param[in] n the original number
 * \return number with swapped endianness
 */
static inline uint24_t bcmos_endian_swap_u24(uint24_t n)
{
    uint24_t u8;
    u8.u8[0] = n.u8[2];
    u8.u8[1] = n.u8[1];
    u8.u8[2] = n.u8[0];
    return u8;
}

/** Swaps the endianness of a 32-bit integer
 * \param[in] n the original number
 * \return number with swapped endianness
 */
static inline uint32_t bcmos_endian_swap_u32(uint32_t n)
{
    return ((n << 24) & 0xFF000000U)|((n << 8 ) & 0x00FF0000U)|((n >> 8) & 0x0000FF00U)|((n >> 24) & 0x000000FFU);
}

/** Swaps the endianness of a 64-bit integer
 * \param[in] n the original number
 * \return number with swapped endianness
 */
static inline uint64_t bcmos_endian_swap_u64(uint64_t n)
{
    return (((uint64_t)bcmos_endian_swap_u32(n & 0xFFFFFFFFU) << 32) | bcmos_endian_swap_u32((n >> 32) & 0xFFFFFFFFU));
}

#endif /* BCMOS_ARCH_ENDIAN_SWAP */

#if (BCM_CPU_ENDIAN == BCMOS_ENDIAN_BIG)

#define BCMOS_ENDIAN_CPU_TO_BIG_U16(n) (n)
#define BCMOS_ENDIAN_CPU_TO_BIG_U24(n) (n)
#define BCMOS_ENDIAN_CPU_TO_BIG_U32(n) (n)
#define BCMOS_ENDIAN_CPU_TO_BIG_U64(n) (n)
#define BCMOS_ENDIAN_BIG_TO_CPU_U16(n) (n)
#define BCMOS_ENDIAN_BIG_TO_CPU_U24(n) (n)
#define BCMOS_ENDIAN_BIG_TO_CPU_U32(n) (n)
#define BCMOS_ENDIAN_BIG_TO_CPU_U64(n) (n)

#define BCMOS_ENDIAN_CPU_TO_LITTLE_U16(n) (bcmos_endian_swap_u16(n))
#define BCMOS_ENDIAN_CPU_TO_LITTLE_U24(n) (bcmos_endian_swap_u24(n))
#define BCMOS_ENDIAN_CPU_TO_LITTLE_U32(n) (bcmos_endian_swap_u32(n))
#define BCMOS_ENDIAN_CPU_TO_LITTLE_U64(n) (bcmos_endian_swap_u64(n))
#define BCMOS_ENDIAN_LITTLE_TO_CPU_U16(n) (bcmos_endian_swap_u16(n))
#define BCMOS_ENDIAN_LITTLE_TO_CPU_U24(n) (bcmos_endian_swap_u24(n))
#define BCMOS_ENDIAN_LITTLE_TO_CPU_U32(n) (bcmos_endian_swap_u32(n))
#define BCMOS_ENDIAN_LITTLE_TO_CPU_U64(n) (bcmos_endian_swap_u64(n))

#elif (BCM_CPU_ENDIAN == BCMOS_ENDIAN_LITTLE)

#define BCMOS_ENDIAN_CPU_TO_BIG_U16(n) (bcmos_endian_swap_u16(n))
#define BCMOS_ENDIAN_CPU_TO_BIG_U24(n) (bcmos_endian_swap_u24(n))
#define BCMOS_ENDIAN_CPU_TO_BIG_U32(n) (bcmos_endian_swap_u32(n))
#define BCMOS_ENDIAN_CPU_TO_BIG_U64(n) (bcmos_endian_swap_u64(n))
#define BCMOS_ENDIAN_BIG_TO_CPU_U16(n) (bcmos_endian_swap_u16(n))
#define BCMOS_ENDIAN_BIG_TO_CPU_U24(n) (bcmos_endian_swap_u24(n))
#define BCMOS_ENDIAN_BIG_TO_CPU_U32(n) (bcmos_endian_swap_u32(n))
#define BCMOS_ENDIAN_BIG_TO_CPU_U64(n) (bcmos_endian_swap_u64(n))

#define BCMOS_ENDIAN_CPU_TO_LITTLE_U16(n) (n)
#define BCMOS_ENDIAN_CPU_TO_LITTLE_U24(n) (n)
#define BCMOS_ENDIAN_CPU_TO_LITTLE_U32(n) (n)
#define BCMOS_ENDIAN_CPU_TO_LITTLE_U64(n) (n)
#define BCMOS_ENDIAN_LITTLE_TO_CPU_U16(n) (n)
#define BCMOS_ENDIAN_LITTLE_TO_CPU_U24(n) (n)
#define BCMOS_ENDIAN_LITTLE_TO_CPU_U32(n) (n)
#define BCMOS_ENDIAN_LITTLE_TO_CPU_U64(n) (n)

#else
#error BCM_CPU_ENDIAN must be BCMOS_ENDIAN_BIG or _LITTLE
#endif

/** @} system_endian */

#endif /* BCMOS_COMMON2_H_ */
