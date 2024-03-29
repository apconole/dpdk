/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2020 Intel Corporation
 */

#ifndef _RTE_PMD_FPGA_5GNR_FEC_H_
#define _RTE_PMD_FPGA_5GNR_FEC_H_

#include <stdint.h>
#include <stdbool.h>

#include <rte_compat.h>

/**
 * @file rte_pmd_fpga_5gnr_fec.h
 *
 * Functions for configuring VC 5GNR and AGX100 HW, exposed directly to applications.
 * Configuration related to encoding/decoding is done through the
 * librte_bbdev library.
 *
 * @warning
 * @b EXPERIMENTAL: this API may change without prior notice
 */

#ifdef __cplusplus
extern "C" {
#endif

/** Number of Virtual Functions FPGA 5GNR FEC supports */
#define FPGA_5GNR_FEC_NUM_VFS 8

/**
 * Structure to pass FPGA 5GNR FEC configuration.
 */
struct rte_fpga_5gnr_fec_conf {
	/** 1 if PF is used for dataplane, 0 for VFs */
	bool pf_mode_en;
	/** Number of UL queues per VF */
	uint8_t vf_ul_queues_number[FPGA_5GNR_FEC_NUM_VFS];
	/** Number of DL queues per VF */
	uint8_t vf_dl_queues_number[FPGA_5GNR_FEC_NUM_VFS];
	/** UL bandwidth. Needed only for VC schedule algorithm */
	uint8_t ul_bandwidth;
	/** DL bandwidth. Needed only for VC schedule algorithm */
	uint8_t dl_bandwidth;
	/** UL Load Balance */
	uint8_t ul_load_balance;
	/** DL Load Balance */
	uint8_t dl_load_balance;
};

/**
 * Configure a FPGA 5GNR device in PF mode notably for bbdev-test
 *
 * @param dev_name
 *   The name of the device. This is the short form of PCI BDF, e.g. 00:01.0.
 *   It can also be retrieved for a bbdev device from the dev_name field in the
 *   rte_bbdev_info structure returned by rte_bbdev_info_get().
 * @param conf
 *   Configuration to apply to FPGA 5GNR FEC.
 *
 * @return
 *   Zero on success, negative value on failure.
 */
__rte_experimental
int
rte_fpga_5gnr_fec_configure(const char *dev_name,
		const struct rte_fpga_5gnr_fec_conf *conf);

#ifdef __cplusplus
}
#endif

#endif /* _RTE_PMD_FPGA_5GNR_FEC_H_ */
