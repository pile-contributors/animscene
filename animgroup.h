/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/*!
\file         animgroup.h
\date         December 2015
\author       Nicu Tofan

\brief        Contains the definition for AnimGroup class.

*//*

 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Please read COPYING and README files in root folder
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
#ifndef PILE_ANIM_GROUP_H
#define PILE_ANIM_GROUP_H
//
//
//
//
/*  INCLUDES    ------------------------------------------------------------ */

#include <animscene/animitem.h>
#include <QList>

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

//! Animation item that stores a number of sub-animations.
class ANIMSCENE_EXPORT AnimGroup : public AnimItem {
    //
    //
    //
    //
    /*  DEFINITIONS    ----------------------------------------------------- */


public:

    QList<AnimItem*> animations_; /**< the list of animations */

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
    AnimGroup (
            unsigned duration = 0,
            unsigned flags = DEFAULT_ANIM_FLAGS);

    //! destructor
    virtual ~AnimGroup ();


    //! This item was installed in a scene.
    virtual void
    animInstalled (
            AnimScene * scene);

    //! This item was removed from the scene.
    virtual void
    animUninstalled ();

    //! The list of animations running right now.
    const QList<AnimItem*> &
    animations () const {
        return animations_;
    }

    //! Add an animation item to the list.
    bool
    addAnimationItem (
            AnimItem * item);

    //! Remove an animation item from the list.
    bool
    remAnimationItem (
            AnimItem * item);

    //! Remove an animation item from the list.
    bool
    remAnimationItem (
            int i);

    //! Take ownership of an animation item.
    AnimItem *
    takeAnimationItem (
            int i);

protected:

    //! We're informed that some time has passed.
    void
    animationTick (
            unsigned interval);

    /*  FUNCTIONS    ======================================================= */
    //
    //
    //
    //
}; /* class AnimGroup */

/*  CLASS    =============================================================== */
//
//
//
//

#endif // PILE_ANIM_GROUP_H
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
