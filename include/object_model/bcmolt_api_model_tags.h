/*
<:copyright-BRCM:2018:proprietary:standard

   Broadcom Proprietary and Confidential.(c) 2018 Broadcom
   All Rights Reserved

This program is the proprietary software of Broadcom Corporation and/or its
licensors, and may only be used, duplicated, modified or distributed pursuant
to the terms and conditions of a separate, written license agreement executed
between you and Broadcom (an "Authorized License").  Except as set forth in
an Authorized License, Broadcom grants no license (express or implied), right
to use, or waiver of any kind with respect to the Software, and Broadcom
expressly reserves all rights in and to the Software and all intellectual
property rights therein.  IF YOU HAVE NO AUTHORIZED LICENSE, THEN YOU HAVE
NO RIGHT TO USE THIS SOFTWARE IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY
BROADCOM AND DISCONTINUE ALL USE OF THE SOFTWARE.

Except as expressly set forth in the Authorized License,

1. This program, including its structure, sequence and organization,
    constitutes the valuable trade secrets of Broadcom, and you shall use
    all reasonable efforts to protect the confidentiality thereof, and to
    use this information only in connection with your use of Broadcom
    integrated circuit products.

2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
    AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
    WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
    RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND
    ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT,
    FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR
    COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE
    TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR
    PERFORMANCE OF THE SOFTWARE.

3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR
    ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL,
    INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY
    WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
    IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES;
    OR (ii) ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE
    SOFTWARE ITSELF OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS
    SHALL APPLY NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY
    LIMITED REMEDY.
:>
*/

#ifndef BCMOLT_API_MODEL_TAGS_H_
#define BCMOLT_API_MODEL_TAGS_H_

#include <bcmos_system.h>


typedef enum
{
    BCMOLT_TAG__NONE = 0,
    BCMOLT_TAG_DEVICE = 1ULL << 0,
    BCMOLT_TAG_GPON = 1ULL << 1,
    BCMOLT_TAG_NGPON2 = 1ULL << 2,
    BCMOLT_TAG_SYSTEM = 1ULL << 3,
    BCMOLT_TAG_XGPON = 1ULL << 4,
    BCMOLT_TAG_XGS = 1ULL << 5,
} bcmolt_tag;


#define BCMOLT_CONFIG_MODE_DEVICE 1
#define BCMOLT_CONFIG_MODE_GPON 1
#define BCMOLT_CONFIG_MODE_NGPON2 1
#define BCMOLT_CONFIG_MODE_SYSTEM 1
#define BCMOLT_CONFIG_MODE_XGPON 1
#define BCMOLT_CONFIG_MODE_XGS 1


bcmolt_tag bcmolt_device_get_active_tags(const bcmolt_device_key *key);


bcmolt_tag bcmolt_erps_interface_get_active_tags(const bcmolt_erps_interface_key *key);


bcmolt_tag bcmolt_eth_oam_get_active_tags(const bcmolt_eth_oam_key *key);


bcmolt_tag bcmolt_flow_get_active_tags(const bcmolt_flow_key *key);


bcmolt_tag bcmolt_gpio_get_active_tags(const bcmolt_gpio_key *key);


bcmolt_tag bcmolt_group_get_active_tags(const bcmolt_group_key *key);


bcmolt_tag bcmolt_inband_mgmt_channel_get_active_tags(const bcmolt_inband_mgmt_channel_key *key);


bcmolt_tag bcmolt_internal_nni_get_active_tags(const bcmolt_internal_nni_key *key);


bcmolt_tag bcmolt_itupon_alloc_get_active_tags(const bcmolt_itupon_alloc_key *key);


bcmolt_tag bcmolt_itupon_gem_get_active_tags(const bcmolt_itupon_gem_key *key);


bcmolt_tag bcmolt_log_get_active_tags(const bcmolt_log_key *key);


bcmolt_tag bcmolt_log_file_get_active_tags(const bcmolt_log_file_key *key);


bcmolt_tag bcmolt_ngpon2_channel_get_active_tags(const bcmolt_ngpon2_channel_key *key);


bcmolt_tag bcmolt_nni_interface_get_active_tags(const bcmolt_nni_interface_key *key);


bcmolt_tag bcmolt_olt_get_active_tags(const bcmolt_olt_key *key);


bcmolt_tag bcmolt_onu_get_active_tags(const bcmolt_onu_key *key);


bcmolt_tag bcmolt_pbit_to_tc_get_active_tags(const bcmolt_pbit_to_tc_key *key);


bcmolt_tag bcmolt_pon_interface_get_active_tags(const bcmolt_pon_interface_key *key);


bcmolt_tag bcmolt_protection_interface_get_active_tags(const bcmolt_protection_interface_key *key);


bcmolt_tag bcmolt_software_error_get_active_tags(const bcmolt_software_error_key *key);


bcmolt_tag bcmolt_tc_to_queue_get_active_tags(const bcmolt_tc_to_queue_key *key);


bcmolt_tag bcmolt_tm_qmp_get_active_tags(const bcmolt_tm_qmp_key *key);


bcmolt_tag bcmolt_tm_queue_get_active_tags(const bcmolt_tm_queue_key *key);


bcmolt_tag bcmolt_tm_sched_get_active_tags(const bcmolt_tm_sched_key *key);



#endif
