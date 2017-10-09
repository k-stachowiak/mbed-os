/* mbed Microcontroller Library
 * Copyright (c) 2015-2016 Nuvoton
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MBEDTLS_SHA256_ALT_H
#define MBEDTLS_SHA256_ALT_H

#if !defined(MBEDTLS_CONFIG_FILE)
#include "config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#if defined(MBEDTLS_SHA256_C)
#if defined(MBEDTLS_SHA256_ALT)

#include "sha_alt_hw.h"
#include "sha256_alt_sw.h"

#ifdef __cplusplus
extern "C" {
#endif

struct mbedtls_sha256_context_s;

/**
 * \brief          SHA-256 context structure
 */
typedef struct mbedtls_sha256_context_s
{
    int ishw;
    crypto_sha_context hw_ctx;
    mbedtls_sha256_sw_context sw_ctx;
}
mbedtls_sha256_context;

/**
 * \brief          Initialize SHA-256 context
 *
 * \param ctx      SHA-256 context to be initialized
 */
void mbedtls_sha256_init( mbedtls_sha256_context *ctx );

/**
 * \brief          Clear SHA-256 context
 *
 * \param ctx      SHA-256 context to be cleared
 */
void mbedtls_sha256_free( mbedtls_sha256_context *ctx );

/**
 * \brief          Clone (the state of) a SHA-256 context
 *
 * \param dst      The destination context
 * \param src      The context to be cloned
 */
void mbedtls_sha256_clone( mbedtls_sha256_context *dst,
                           const mbedtls_sha256_context *src );

/**
 * \brief          SHA-256 context setup
 *
 * \param ctx      context to be initialized
 * \param is224    0 = use SHA256, 1 = use SHA224
 *
 * \return         0 if successful
 */
int mbedtls_sha256_starts_ext( mbedtls_sha256_context *ctx, int is224 );

/**
 * \brief          SHA-256 process buffer
 *
 * \param ctx      SHA-256 context
 * \param input    buffer holding the data
 * \param ilen     length of the input data
 *
 * \return         0 if successful
 */
int mbedtls_sha256_update_ext( mbedtls_sha256_context *ctx,
                               const unsigned char *input,
                               size_t ilen );

/**
 * \brief          SHA-256 final digest
 *
 * \param ctx      SHA-256 context
 * \param output   SHA-224/256 checksum result
 *
 * \return         0 if successful
 */
int mbedtls_sha256_finish_ext( mbedtls_sha256_context *ctx,
                               unsigned char output[32] );

/**
 * \brief          SHA-256 process data block (internal use only)
 *
 * \param ctx      SHA-256 context
 * \param data     buffer holding one block of data
 *
 * \return         0 if successful
 */
int mbedtls_internal_sha256_process( mbedtls_sha256_context *ctx,
                                     const unsigned char data[64] );

#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#if defined(MBEDTLS_DEPRECATED_WARNING)
#define MBEDTLS_DEPRECATED      __attribute__((deprecated))
#else
#define MBEDTLS_DEPRECATED
#endif
/**
 * \brief          SHA-256 context setup
 *
 * \deprecated     Superseded by mbedtls_sha256_starts_ext() in 2.5.0
 *
 * \param ctx      context to be initialized
 * \param is224    0 = use SHA256, 1 = use SHA224
 */
MBEDTLS_DEPRECATED static inline void mbedtls_sha256_starts(
                                                mbedtls_sha256_context *ctx,
                                                int is224 )
{
    mbedtls_sha256_starts_ext( ctx, is224 );
}

/**
 * \brief          SHA-256 process buffer
 *
 * \deprecated     Superseded by mbedtls_sha256_update_ext() in 2.5.0
 *
 * \param ctx      SHA-256 context
 * \param input    buffer holding the data
 * \param ilen     length of the input data
 */
MBEDTLS_DEPRECATED static inline void mbedtls_sha256_update(
                                                mbedtls_sha256_context *ctx,
                                                const unsigned char *input,
                                                size_t ilen )
{
    mbedtls_sha256_update_ext( ctx, input, ilen );
}

/**
 * \brief          SHA-256 final digest
 *
 * \deprecated     Superseded by mbedtls_sha256_finish_ext() in 2.5.0
 *
 * \param ctx      SHA-256 context
 * \param output   SHA-224/256 checksum result
 */
MBEDTLS_DEPRECATED static inline void mbedtls_sha256_finish(
                                                mbedtls_sha256_context *ctx,
                                                unsigned char output[32] )
{
    mbedtls_sha256_finish_ext( ctx, output );
}

/**
 * \brief          SHA-256 process data block (internal use only)
 *
 * \deprecated     Superseded by mbedtls_internal_sha256_process() in 2.5.0
 *
 * \param ctx      SHA-256 context
 * \param data     buffer holding one block of data
 */
MBEDTLS_DEPRECATED static inline void mbedtls_sha256_process(
                                                mbedtls_sha256_context *ctx,
                                                const unsigned char data[64] )
{
    mbedtls_internal_sha256_process( ctx, data );
}

#undef MBEDTLS_DEPRECATED
#endif /* !MBEDTLS_DEPRECATED_REMOVED */

#ifdef __cplusplus
}
#endif

#else  /* MBEDTLS_SHA256_ALT */
#include "sha256_alt.h"
#endif /* MBEDTLS_SHA256_ALT */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief          Output = SHA-256( input buffer )
 *
 * \param input    buffer holding the data
 * \param ilen     length of the input data
 * \param output   SHA-224/256 checksum result
 * \param is224    0 = use SHA256, 1 = use SHA224
 *
 * \return         0 if successful
 */
int mbedtls_sha256_ext( const unsigned char *input,
                        size_t ilen,
                        unsigned char output[32],
                        int is224 );

#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#if defined(MBEDTLS_DEPRECATED_WARNING)
#define MBEDTLS_DEPRECATED      __attribute__((deprecated))
#else
#define MBEDTLS_DEPRECATED
#endif
/**
 * \brief          Output = SHA-256( input buffer )
 *
 * \deprecated     Superseded by mbedtls_sha256_ext() in 2.5.0
 *
 * \param input    buffer holding the data
 * \param ilen     length of the input data
 * \param output   SHA-224/256 checksum result
 * \param is224    0 = use SHA256, 1 = use SHA224
 */
MBEDTLS_DEPRECATED static inline void mbedtls_sha256(
                                                    const unsigned char *input,
                                                    size_t ilen,
                                                    unsigned char output[32],
                                                    int is224 )
{
    mbedtls_sha256_ext( input, ilen, output, is224 );
}

#undef MBEDTLS_DEPRECATED
#endif /* !MBEDTLS_DEPRECATED_REMOVED */

/**
 * \brief          Checkup routine
 *
 * \return         0 if successful, or 1 if the test failed
 */
int mbedtls_sha256_self_test( int verbose );

#ifdef __cplusplus
}
#endif

#endif /* MBEDTLS_SHA256_ALT */
#endif /* MBEDTLS_SHA256_C */

#endif /* sha256_alt.h */
