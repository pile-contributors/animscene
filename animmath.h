/**
 * @file animscene.h
 * @brief Declarations for AnimScene class
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_ANIMMATH_H_INCLUDE
#define GUARD_ANIMSCENE_H_INCLUDE

#include <animscene/animscene-config.h>
#include <qmath.h>

QT_BEGIN_NAMESPACE
class QPointF;
QT_END_NAMESPACE

//! Compute a parabola parameters from three points.
ANIMSCENE_EXPORT bool
parabolaFrom3P (
        const QPointF &point1,
        const QPointF &point2,
        const QPointF &point3,
        double * param_a,
        double * param_b,
        double * param_c);


#endif // GUARD_ANIMSCENE_H_INCLUDE
