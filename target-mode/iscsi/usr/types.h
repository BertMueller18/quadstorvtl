/*
 * Copyright (C) 2002-2003 Ardis Technolgies <roman@ardistech.com>
 *
 * Released under the terms of the GNU GPL v2.0.
 */

#ifndef TYPES_H
#define TYPES_H

#include <sys/types.h>
#include <stdint.h>
#include <inttypes.h>

#ifdef FREEBSD
#include <sys/endian.h>
#include <sys/uio.h>
#define __BYTE_ORDER		_BYTE_ORDER
#define __LITTLE_ENDIAN		_LITTLE_ENDIAN
#define __BIG_ENDIAN		_BIG_ENDIAN
#define bswap_16		bswap16
#define bswap_32		bswap32
#include "bsddefs.h"
#else
#include <byteswap.h>
#include <endian.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <linux/netlink.h>
#endif

#if __BYTE_ORDER == __BIG_ENDIAN
#define cpu_to_le16(x)		bswap_16(x)
#define le16_to_cpu(x)		bswap_16(x)
#define cpu_to_le32(x)		bswap_32(x)
#define le32_to_cpu(x)		bswap_32(x)
#define cpu_to_be16(x)		(x)
#define be16_to_cpu(x)		(x)
#define cpu_to_be32(x)		(x)
#define be32_to_cpu(x)		(x)
#elif __BYTE_ORDER == __LITTLE_ENDIAN
#define cpu_to_le16(x)		(x)
#define le16_to_cpu(x)		(x)
#define cpu_to_le32(x)		(x)
#define le32_to_cpu(x)		(x)
#define cpu_to_be16(x)		bswap_16(x)
#define be16_to_cpu(x)		bswap_16(x)
#define cpu_to_be32(x)		bswap_32(x)
#define be32_to_cpu(x)		bswap_32(x)
#else
#error "unknown endianess!"
#endif

typedef u_int8_t u8;
typedef u_int16_t u16;
typedef u_int32_t u32;
typedef u_int64_t u64;

#endif	/* TYPES_H */
