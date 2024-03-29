/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright (c) 2023 NVIDIA Corporation & Affiliates
 */

#include "mlx5dr_internal.h"

uint32_t dr_ste_crc_tab32[] = {
	0x0, 0x77073096, 0xee0e612c, 0x990951ba, 0x76dc419, 0x706af48f,
	0xe963a535, 0x9e6495a3, 0xedb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
	0x9b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
	0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
	0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
	0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
	0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c,
	0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
	0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
	0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
	0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x1db7106,
	0x98d220bc, 0xefd5102a, 0x71b18589, 0x6b6b51f, 0x9fbfe4a5, 0xe8b8d433,
	0x7807c9a2, 0xf00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x86d3d2d,
	0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
	0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
	0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
	0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
	0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
	0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
	0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
	0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
	0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x3b6e20c, 0x74b1d29a,
	0xead54739, 0x9dd277af, 0x4db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
	0xd6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0xa00ae27, 0x7d079eb1,
	0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
	0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
	0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
	0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
	0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
	0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
	0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
	0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
	0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x26d930a, 0x9c0906a9, 0xeb0e363f,
	0x72076785, 0x5005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0xcb61b38,
	0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0xbdbdf21, 0x86d3d2d4, 0xf1d4e242,
	0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
	0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
	0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
	0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
	0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
	0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
	0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
	0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

/* CRC table for the CRC-16, the polynome is 0x100b */
uint16_t dr_crc_inner_crc_tab16[] = {
	0x0000, 0x100B, 0x2016, 0x301D, 0x402C, 0x5027, 0x603A, 0x7031,
	0x8058, 0x9053, 0xA04E, 0xB045, 0xC074, 0xD07F, 0xE062, 0xF069,
	0x10BB, 0x00B0, 0x30AD, 0x20A6, 0x5097, 0x409C, 0x7081, 0x608A,
	0x90E3, 0x80E8, 0xB0F5, 0xA0FE, 0xD0CF, 0xC0C4, 0xF0D9, 0xE0D2,
	0x2176, 0x317D, 0x0160, 0x116B, 0x615A, 0x7151, 0x414C, 0x5147,
	0xA12E, 0xB125, 0x8138, 0x9133, 0xE102, 0xF109, 0xC114, 0xD11F,
	0x31CD, 0x21C6, 0x11DB, 0x01D0, 0x71E1, 0x61EA, 0x51F7, 0x41FC,
	0xB195, 0xA19E, 0x9183, 0x8188, 0xF1B9, 0xE1B2, 0xD1AF, 0xC1A4,
	0x42EC, 0x52E7, 0x62FA, 0x72F1, 0x02C0, 0x12CB, 0x22D6, 0x32DD,
	0xC2B4, 0xD2BF, 0xE2A2, 0xF2A9, 0x8298, 0x9293, 0xA28E, 0xB285,
	0x5257, 0x425C, 0x7241, 0x624A, 0x127B, 0x0270, 0x326D, 0x2266,
	0xD20F, 0xC204, 0xF219, 0xE212, 0x9223, 0x8228, 0xB235, 0xA23E,
	0x639A, 0x7391, 0x438C, 0x5387, 0x23B6, 0x33BD, 0x03A0, 0x13AB,
	0xE3C2, 0xF3C9, 0xC3D4, 0xD3DF, 0xA3EE, 0xB3E5, 0x83F8, 0x93F3,
	0x7321, 0x632A, 0x5337, 0x433C, 0x330D, 0x2306, 0x131B, 0x0310,
	0xF379, 0xE372, 0xD36F, 0xC364, 0xB355, 0xA35E, 0x9343, 0x8348,
	0x85D8, 0x95D3, 0xA5CE, 0xB5C5, 0xC5F4, 0xD5FF, 0xE5E2, 0xF5E9,
	0x0580, 0x158B, 0x2596, 0x359D, 0x45AC, 0x55A7, 0x65BA, 0x75B1,
	0x9563, 0x8568, 0xB575, 0xA57E, 0xD54F, 0xC544, 0xF559, 0xE552,
	0x153B, 0x0530, 0x352D, 0x2526, 0x5517, 0x451C, 0x7501, 0x650A,
	0xA4AE, 0xB4A5, 0x84B8, 0x94B3, 0xE482, 0xF489, 0xC494, 0xD49F,
	0x24F6, 0x34FD, 0x04E0, 0x14EB, 0x64DA, 0x74D1, 0x44CC, 0x54C7,
	0xB415, 0xA41E, 0x9403, 0x8408, 0xF439, 0xE432, 0xD42F, 0xC424,
	0x344D, 0x2446, 0x145B, 0x0450, 0x7461, 0x646A, 0x5477, 0x447C,
	0xC734, 0xD73F, 0xE722, 0xF729, 0x8718, 0x9713, 0xA70E, 0xB705,
	0x476C, 0x5767, 0x677A, 0x7771, 0x0740, 0x174B, 0x2756, 0x375D,
	0xD78F, 0xC784, 0xF799, 0xE792, 0x97A3, 0x87A8, 0xB7B5, 0xA7BE,
	0x57D7, 0x47DC, 0x77C1, 0x67CA, 0x17FB, 0x07F0, 0x37ED, 0x27E6,
	0xE642, 0xF649, 0xC654, 0xD65F, 0xA66E, 0xB665, 0x8678, 0x9673,
	0x661A, 0x7611, 0x460C, 0x5607, 0x2636, 0x363D, 0x0620, 0x162B,
	0xF6F9, 0xE6F2, 0xD6EF, 0xC6E4, 0xB6D5, 0xA6DE, 0x96C3, 0x86C8,
	0x76A1, 0x66AA, 0x56B7, 0x46BC, 0x368D, 0x2686, 0x169B, 0x0690
};

uint32_t mlx5dr_crc32_calc(uint8_t *p, size_t len)
{
	uint32_t crc = 0;

	while (len--)
		crc = (crc >> 8) ^ dr_ste_crc_tab32[(crc ^ *p++) & 255];

	return rte_be_to_cpu_32(crc);
}

uint16_t mlx5dr_crc16_calc(uint8_t *p, size_t len, uint16_t crc_tab16[])
{
	uint16_t crc = 0;

	while (len--)
		crc = (crc << 8) ^ crc_tab16[((crc >> 8) ^ *p++) & 0xff];

	return crc;
}

int mlx5dr_crc_encap_entropy_hash_calc(struct mlx5dr_context *ctx,
				       struct mlx5dr_crc_encap_entropy_hash_fields *data,
				       uint8_t entropy_res[],
				       enum mlx5dr_crc_encap_entropy_hash_size res_size)
{
	struct mlx5dr_cmd_query_caps *caps = ctx->caps;
	uint16_t max_hash, min_hash, res;

	if (caps->encap_entropy_hash_type) {
		DR_LOG(ERR, "calculation of encap_entropy_hash_type 0x%x not supported",
		       caps->encap_entropy_hash_type);
		rte_errno = ENOTSUP;
		return rte_errno;
	}

	max_hash = caps->roce_max_src_udp_port;
	min_hash = caps->roce_min_src_udp_port;

	res = mlx5dr_crc16_calc((uint8_t *)data, sizeof(*data), dr_crc_inner_crc_tab16);

	if (res_size == MLX5DR_CRC_ENCAP_ENTROPY_HASH_SIZE_16) {
		*(uint16_t *)entropy_res = rte_cpu_to_be_16((min_hash | res) & max_hash);
	} else if (res_size == MLX5DR_CRC_ENCAP_ENTROPY_HASH_SIZE_8) {
		*entropy_res = (uint8_t)(res & 0xff);
	} else {
		rte_errno = ENOTSUP;
		return rte_errno;
	}

	return 0;
}
