/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2020 Intel Corporation
 */

#ifndef _RTE_POWER_PMD_MGMT_H
#define _RTE_POWER_PMD_MGMT_H

/**
 * @file
 * RTE PMD Power Management
 */

#include <stdint.h>
#include <stdbool.h>

#include <rte_common.h>
#include <rte_byteorder.h>
#include <rte_log.h>
#include <rte_power.h>
#include <rte_atomic.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * PMD Power Management Type
 */
enum rte_power_pmd_mgmt_type {
	/** Use power-optimized monitoring to wait for incoming traffic */
	RTE_POWER_MGMT_TYPE_MONITOR = 1,
	/** Use power-optimized sleep to avoid busy polling */
	RTE_POWER_MGMT_TYPE_PAUSE,
	/** Use frequency scaling when traffic is low */
	RTE_POWER_MGMT_TYPE_SCALE,
};

/**
 * @warning
 * @b EXPERIMENTAL: this API may change, or be removed, without prior notice.
 *
 * Enable power management on a specified Ethernet device Rx queue and lcore.
 *
 * @note This function is not thread-safe.
 *
 * @warning This function must be called when all affected Ethernet queues are
 *   stopped and no Rx/Tx is in progress!
 *
 * @param lcore_id
 *   The lcore the Rx queue will be polled from.
 * @param port_id
 *   The port identifier of the Ethernet device.
 * @param queue_id
 *   The queue identifier of the Ethernet device.
 * @param mode
 *   The power management scheme to use for specified Rx queue.
 * @return
 *   0 on success
 *   <0 on error
 */
__rte_experimental
int
rte_power_ethdev_pmgmt_queue_enable(unsigned int lcore_id,
		uint16_t port_id, uint16_t queue_id,
		enum rte_power_pmd_mgmt_type mode);

/**
 * @warning
 * @b EXPERIMENTAL: this API may change, or be removed, without prior notice.
 *
 * Disable power management on a specified Ethernet device Rx queue and lcore.
 *
 * @note This function is not thread-safe.
 *
 * @warning This function must be called when all affected Ethernet queues are
 *   stopped and no Rx/Tx is in progress!
 *
 * @param lcore_id
 *   The lcore the Rx queue is polled from.
 * @param port_id
 *   The port identifier of the Ethernet device.
 * @param queue_id
 *   The queue identifier of the Ethernet device.
 * @return
 *   0 on success
 *   <0 on error
 */
__rte_experimental
int
rte_power_ethdev_pmgmt_queue_disable(unsigned int lcore_id,
		uint16_t port_id, uint16_t queue_id);

/**
 * @warning
 * @b EXPERIMENTAL: this API may change, or be removed, without prior notice.
 *
 * Set a emptypoll_max to specified value. Used to specify the number of empty
 * polls to wait before entering sleep state.
 *
 * @param max
 *   The value to set emptypoll_max to.
 */
__rte_experimental
void
rte_power_pmd_mgmt_set_emptypoll_max(unsigned int max);

/**
 * @warning
 * @b EXPERIMENTAL: this API may change, or be removed, without prior notice.
 *
 * Get the current value of emptypoll_max.
 *
 * @return
 *   The current emptypoll_max value
 */
__rte_experimental
unsigned int
rte_power_pmd_mgmt_get_emptypoll_max(void);

/**
 * @warning
 * @b EXPERIMENTAL: this API may change, or be removed, without prior notice.
 *
 * Set the pause_duration. Used to adjust the pause mode callback duration.
 *
 * @note Duration must be greater than zero.
 *
 * @param duration
 *   The value to set pause_duration to.
 * @return
 *   0 on success
 *   <0 on error
 */
__rte_experimental
int
rte_power_pmd_mgmt_set_pause_duration(unsigned int duration);

/**
 * @warning
 * @b EXPERIMENTAL: this API may change, or be removed, without prior notice.
 *
 * Get the current value of pause_duration.
 *
 * @return
 *   The current pause_duration value.
 */
__rte_experimental
unsigned int
rte_power_pmd_mgmt_get_pause_duration(void);

#ifdef __cplusplus
}
#endif

#endif
