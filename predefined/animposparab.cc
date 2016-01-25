/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/*!
  file         animposparab.cc
  date         December 2015
  author       Nicu Tofan

  brief        Contains the implementation for AnimPosParab class.

*//*

 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Please read COPYING and README files in root folder
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
//
//
//
//
/*  INCLUDES    ------------------------------------------------------------ */

#include "animposparab.h"
#include "../animscene-private.h"
#include "../animmath.h"

#include <QGraphicsItem>

/*  INCLUDES    ============================================================ */
//
//
//
//
/*  DEFINITIONS    --------------------------------------------------------- */

/*  DEFINITIONS    ========================================================= */
//
//
//
//
/*  CLASS    --------------------------------------------------------------- */

/**
 * @class AnimPosParab
 *
 * .
 */

/* ------------------------------------------------------------------------- */
AnimPosParab::AnimPosParab (
        const QPointF &point1, const QPointF &point2, const QPointF &point3,
        QEasingCurve::Type easing, unsigned duration, unsigned flags) :
    AnimEasing(easing, duration, NULL, NULL, NULL, flags),
    param_a_(),
    param_b_(),
    param_c_(),
    x_init_pos_(point1.x ()),
    x_len_(point3.x ()),
    item_(NULL)
{
    if (!parabolaFrom3P (
                point1, point2, point3, &param_a_, &param_b_, &param_c_)) {
        ANIMSCENE_DEBUGM("Can't determine the parabola "
                         "from these three points\n");
        param_a_ = -1.0;
        param_b_ = -1.0;
        param_c_ = -1.0;
    }
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
AnimPosParab::AnimPosParab (
        double param_a, double param_b, double param_c,
        double initial_x, double end_x,
        QEasingCurve::Type easing, unsigned duration, unsigned flags) :
    AnimEasing(easing, duration, NULL, NULL, NULL, flags),
    param_a_(param_a),
    param_b_(param_b),
    param_c_(param_c),
    x_init_pos_(initial_x),
    x_len_(end_x),
    item_(NULL)
{
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
AnimPosParab::~AnimPosParab ()
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool AnimPosParab::isParabolaValid ()
{
    return !(
                param_a_ == -1.0 &&
                param_b_ == -1.0 &&
                param_c_ == -1.0);
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void AnimPosParab::animationTick (unsigned interval)
{
    AnimItem::animationTick (interval);
    if (skipMe ())
        return;
    if (atEnd ())
        return;
    double frac = fractionDone ();
    double pos_x = x_init_pos_ + x_len_ * frac;
    double pos_y = param_a_ * pos_x * pos_x + param_b_ * pos_x + param_c_;
    item_->setPos (pos_x, pos_y);
}
/* ========================================================================= */

/*  CLASS    =============================================================== */
//
//
//
//

/* ------------------------------------------------------------------------- */
/* ========================================================================= */

