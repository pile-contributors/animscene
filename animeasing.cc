/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/*!
  file         animeasing.cc
  date         December 2015
  author       Nicu Tofan

  brief        Contains the implementation for AnimEasing class.

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

#include "animeasing.h"
#include "animscene-private.h"

#include <QPainter>
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
 * @class AnimEasing
 *
 * The easing object inside is owned by this instance; the destructor
 * deletes it.
 */

/* ------------------------------------------------------------------------- */
AnimEasing::AnimEasing (
        QEasingCurve::Type easing, unsigned duration,
        AnimItem::KbAnimItem kb_tik, AnimItem::KbAnimItem kb_end,
        void * user_data, unsigned flags) :
    AnimItem(duration, kb_tik, kb_end, user_data, flags),
    easing_(new QEasingCurve (easing))
{
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
AnimEasing::AnimEasing (
        QEasingCurve * easing, unsigned duration,
        AnimItem::KbAnimItem kb_tik, AnimItem::KbAnimItem kb_end,
        void * user_data, unsigned flags) :
    AnimItem(duration, kb_tik, kb_end, user_data, flags),
    easing_(easing)
{
}
/* ========================================================================= */

/* ------------------------------------------------------------------   `   `   ``------- */
AnimEasing::~AnimEasing ()
{
    if (easing_ != NULL) {
        delete easing_;
    }
}
/* ========================================================================= */

/* ------------------------------------------------------------------   `   `   ``------- */
double AnimEasing::fractionDone () const
{
    double result = AnimItem::fractionDone ();
    if (easing_ != NULL) {
        result = easing_->valueForProgress (result);
    }
    return result;
}
/* ========================================================================= */

/*  CLASS    =============================================================== */
//
//
//
//

/* ------------------------------------------------------------------------- */
/* ========================================================================= */

