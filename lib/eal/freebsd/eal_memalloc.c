/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2017-2018 Intel Corporation
 */

#include <inttypes.h>

#include <rte_errno.h>
#include <rte_log.h>
#include <rte_memory.h>

#include "eal_memalloc.h"
#include "eal_private.h"

int
eal_memalloc_alloc_seg_bulk(struct rte_memseg **ms __rte_unused,
		int __rte_unused n_segs, size_t __rte_unused page_sz,
		int __rte_unused socket, bool __rte_unused exact)
{
	EAL_LOG(ERR, "Memory hotplug not supported on FreeBSD");
	return -1;
}

struct rte_memseg *
eal_memalloc_alloc_seg(size_t __rte_unused page_sz, int __rte_unused socket)
{
	EAL_LOG(ERR, "Memory hotplug not supported on FreeBSD");
	return NULL;
}

int
eal_memalloc_free_seg(struct rte_memseg *ms __rte_unused)
{
	EAL_LOG(ERR, "Memory hotplug not supported on FreeBSD");
	return -1;
}

int
eal_memalloc_free_seg_bulk(struct rte_memseg **ms __rte_unused,
		int n_segs __rte_unused)
{
	EAL_LOG(ERR, "Memory hotplug not supported on FreeBSD");
	return -1;
}

int
eal_memalloc_sync_with_primary(void)
{
	EAL_LOG(ERR, "Memory hotplug not supported on FreeBSD");
	return -1;
}

int
eal_memalloc_get_seg_fd(int list_idx __rte_unused, int seg_idx __rte_unused)
{
	return -ENOTSUP;
}

int
eal_memalloc_set_seg_fd(int list_idx __rte_unused, int seg_idx __rte_unused,
		int fd __rte_unused)
{
	return -ENOTSUP;
}

int
eal_memalloc_set_seg_list_fd(int list_idx __rte_unused, int fd __rte_unused)
{
	return -ENOTSUP;
}

int
eal_memalloc_get_seg_fd_offset(int list_idx __rte_unused,
		int seg_idx __rte_unused, size_t *offset __rte_unused)
{
	return -ENOTSUP;
}

int eal_memalloc_cleanup(void)
{
	return 0;
}

int
eal_memalloc_init(void)
{
	return 0;
}
