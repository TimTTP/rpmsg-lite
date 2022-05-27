/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**************************************************************************
 * FILE NAME
 *
 *       rpmsg_env_specific.h
 *
 * DESCRIPTION
 *
 *       This file contains ThreadX specific constructions.
 *
 **************************************************************************/
#ifndef RPMSG_ENV_SPECIFIC_H_
#define RPMSG_ENV_SPECIFIC_H_

#include <stdint.h>
#include "rpmsg_default_config.h"

typedef struct
{
    uint32_t src;
    void *data;
    uint32_t len;
} rpmsg_queue_rx_cb_data_t;

#if defined(RL_USE_STATIC_API) && (RL_USE_STATIC_API == 1)
#include "tx_api.h"
#include "tx_event_flags.h"

typedef TX_SEMAPHORE LOCK_STATIC_CONTEXT;
typedef TX_QUEUE rpmsg_static_queue_ctxt;
/* Queue object static storage size in bytes, should be defined as (RL_BUFFER_COUNT*sizeof(rpmsg_queue_rx_cb_data_t)) */
#define RL_ENV_QUEUE_STATIC_STORAGE_SIZE (RL_BUFFER_COUNT * sizeof(rpmsg_queue_rx_cb_data_t))
#endif

#endif /* RPMSG_ENV_SPECIFIC_H_ */
