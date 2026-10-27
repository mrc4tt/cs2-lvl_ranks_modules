/* Hand-written for the AMBuild build (upstream generates it with configure/CMake). */
#ifndef MAXMINDDB_CONFIG_H
#define MAXMINDDB_CONFIG_H

#define MMDB_UINT128_USING_MODE 0
#if defined(_MSC_VER)
/* MSVC has no unsigned __int128 */
#define MMDB_UINT128_IS_BYTE_ARRAY 1
#else
#define MMDB_UINT128_IS_BYTE_ARRAY 0
#endif

#endif /* MAXMINDDB_CONFIG_H */
