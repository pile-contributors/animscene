/**
 * @file animscene.cc
 * @brief Definitions for AnimScene class.
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#include "animmath.h"


// from http://stackoverflow.com/a/717833/1742064
bool parabolaFrom3P (
        const QPointF &point1, const QPointF &point2, const QPointF &point3,
        double * param_a, double * param_b, double * param_c)
{
    double denom = (point1.x () - point2.x ()) * (point1.x () - point3.x ()) *
            (point2.x () - point3.x ());
    if (qFuzzyIsNull (denom)) {
        return false;
    }

    *param_a     = (point3.x () * (point2.y () - point1.y ()) +
                    point2.x () * (point1.y () - point3.y ()) +
                    point1.x () * (point3.y () - point2.y ())) /
            denom;
    *param_b     = (point3.x () * point3.x () * (point1.y () - point2.y ()) +
                    point2.x () * point2.x () * (point3.y () - point1.y ()) +
                    point1.x () * point1.x () * (point2.y () - point3.y ())) /
            denom;
    *param_c     = (point2.x () * point3.x () *
                    (point2.x () - point3.x ()) * point1.y () +
                    point3.x () * point1.x () *
                    (point3.x () - point1.x ()) * point2.y () +
                    point1.x () * point2.x () *
                    (point1.x () - point2.x ()) * point3.y ()) /
            denom;
    return true;
}
