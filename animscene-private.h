/**
 * @file animscene-private.h
 * @brief Declarations for AnimScene class
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_ANIMSCENE_PRIVATE_H_INCLUDE
#define GUARD_ANIMSCENE_PRIVATE_H_INCLUDE

#include <animscene/animscene-config.h>

#if 0
#    define ANIMSCENE_DEBUGM printf
#else
#    define ANIMSCENE_DEBUGM black_hole
#endif

#if 0
#    define ANIMSCENE_TRACE_ENTRY printf("ANIMSCENE ENTRY %s in %s[%d]\n", __func__, __FILE__, __LINE__)
#else
#    define ANIMSCENE_TRACE_ENTRY
#endif

#if 0
#    define ANIMSCENE_TRACE_EXIT printf("ANIMSCENE EXIT %s in %s[%d]\n", __func__, __FILE__, __LINE__)
#else
#    define ANIMSCENE_TRACE_EXIT
#endif


static inline void black_hole (...)
{}

#endif // GUARD_ANIMSCENE_PRIVATE_H_INCLUDE
