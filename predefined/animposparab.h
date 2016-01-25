/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/*!
\file         animposparab.h
\date         December 2015
\author       Nicu Tofan

\brief        Contains the definition for AnimPosParab class.

*//*

 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Please read COPYING and README files in root folder
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
#ifndef PILE_ANIM_POSPARAB_H
#define PILE_ANIM_POSPARAB_H
//
//
//
//
/*  INCLUDES    ------------------------------------------------------------ */

#include <animscene/animeasing.h>

/*  INCLUDES    ============================================================ */
//
//
//
//
/*  DEFINITIONS    --------------------------------------------------------- */

class AnimScene;

QT_BEGIN_NAMESPACE
class QGraphicsItem;
QT_END_NAMESPACE

/*  DEFINITIONS    ========================================================= */
//
//
//
//
/*  CLASS    --------------------------------------------------------------- */

//! Animation item that also packs an posparab curve.
class ANIMSCENE_EXPORT AnimPosParab : public AnimEasing {
    //
    //
    //
    //
    /*  DEFINITIONS    ----------------------------------------------------- */

public:

    /*  DEFINITIONS    ===================================================== */
    //
    //
    //
    //
    /*  DATA    ------------------------------------------------------------ */

private:

    double param_a_;
    double param_b_;
    double param_c_;
    double x_init_pos_;
    double x_len_;
    QGraphicsItem * item_;

    /*  DATA    ============================================================ */
    //
    //
    //
    //
    /*  FUNCTIONS    ------------------------------------------------------- */

public:

    //! Constructor that uses three points to compute the parabola.
    AnimPosParab (
            const QPointF & point1,
            const QPointF & point2,
            const QPointF & point3,
            QEasingCurve::Type easing = QEasingCurve::Linear,
            unsigned duration = 0,
            unsigned flags = DEFAULT_ANIM_FLAGS);

    //! Constructor.
    AnimPosParab (
            double param_a,
            double param_b,
            double param_c,
            double initial_x,
            double end_x,
            QEasingCurve::Type easing = QEasingCurve::Linear,
            unsigned duration = 0,
            unsigned flags = DEFAULT_ANIM_FLAGS);

    //! destructor
    virtual ~AnimPosParab ();

    //! Can we really use this?
    bool
    isParabolaValid ();

    //! We're informed that some time has passed.
    virtual void
    animationTick (
            unsigned interval);

    //! Retreive Item.
    inline QGraphicsItem *
    getItem () const {
        return item_;
    }

    //! Set Item.
    inline void
    setItem (
            QGraphicsItem * value) {
        item_ = value;
    }


    /*  FUNCTIONS    ======================================================= */
    //
    //
    //
    //
}; /* class AnimPosParab */

/*  CLASS    =============================================================== */
//
//
//
//

#endif // PILE_ANIM_POSPARAB_H
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
