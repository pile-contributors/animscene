/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/*!
\file         animeasing.h
\date         December 2015
\author       Nicu Tofan

\brief        Contains the definition for AnimEasing class.

*//*

 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Please read COPYING and README files in root folder
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
#ifndef PILE_ANIM_EASING_H
#define PILE_ANIM_EASING_H
//
//
//
//
/*  INCLUDES    ------------------------------------------------------------ */

#include <animscene/animitem.h>
#include <QEasingCurve>

/*  INCLUDES    ============================================================ */
//
//
//
//
/*  DEFINITIONS    --------------------------------------------------------- */

class AnimScene;

QT_BEGIN_NAMESPACE
class QEasingCurve;
QT_END_NAMESPACE

/*  DEFINITIONS    ========================================================= */
//
//
//
//
/*  CLASS    --------------------------------------------------------------- */

//! Animation item that also packs an easing curve.
class ANIMSCENE_EXPORT AnimEasing : public AnimItem {
    //
    //
    //
    //
    /*  DEFINITIONS    ----------------------------------------------------- */


public:

    QEasingCurve * easing_; /**< the easing */

    /*  DEFINITIONS    ===================================================== */
    //
    //
    //
    //
    /*  DATA    ------------------------------------------------------------ */

private:

    /*  DATA    ============================================================ */
    //
    //
    //
    //
    /*  FUNCTIONS    ------------------------------------------------------- */

public:

    //! Constructor.
    AnimEasing (
            QEasingCurve::Type easing = QEasingCurve::Linear,
            unsigned duration = 0,
            KbAnimItem kb_tik = NULL,
            KbAnimItem kb_end = NULL,
            void * user_data = NULL,
            unsigned flags = DEFAULT_ANIM_FLAGS);

    //! Constructor.
    AnimEasing (
            QEasingCurve * easing,
            unsigned duration = 0,
            KbAnimItem kb_tik = NULL,
            KbAnimItem kb_end = NULL,
            void * user_data = NULL,
            unsigned flags = DEFAULT_ANIM_FLAGS);


    //! destructor
    virtual ~AnimEasing ();

    //! Take ownership of the easing.
    QEasingCurve *
    takeEasing () {
        QEasingCurve * result = easing_;
        easing_ = NULL;
        return result;
    }

    //! Change the easing.
    void
    setEasing (
            QEasingCurve * value) {
        if (easing_ != NULL) {
            delete easing_;
        }
        easing_ = value;
    }

    //! Get the easing.
    QEasingCurve *
    easing () const {
        return easing_;
    }

    //! The proportion that passed from the total (a value between 0 and 1)
    virtual double
    fractionDone () const;

    /*  FUNCTIONS    ======================================================= */
    //
    //
    //
    //
}; /* class AnimEasing */

/*  CLASS    =============================================================== */
//
//
//
//

#endif // PILE_ANIM_EASING_H
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
