/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/*!
  file         animgroup.cc
  date         December 2015
  author       Nicu Tofan

  brief        Contains the implementation for AnimGroup class.

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

#include "animgroup.h"
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
 * @class AnimGroup
 *
 * The group object inside is owned by this instance; the destructor
 * deletes it.
 */

/* ------------------------------------------------------------------------- */
AnimGroup::AnimGroup (
        unsigned duration, unsigned flags) :
    AnimItem(duration, NULL, NULL, this, flags),
    animations_()
{
}
/* ========================================================================= */

/* ------------------------------------------------------------------   `   `   ``------- */
AnimGroup::~AnimGroup ()
{
    qDeleteAll (animations_);
    animations_.clear ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------   `   `   ``------- */
void AnimGroup::animInstalled (AnimScene *scene)
{
    unsigned max_duration = 0;
    foreach(AnimItem * item, animations_) {
        item->animInstalled (scene);
        if (item->totalDuration () > max_duration) {
            max_duration = item->totalDuration ();
        }
    }
    if (totalDuration () == 0) {
        setTotalDuration (max_duration);
    }
    AnimItem::animInstalled (scene);
}
/* ========================================================================= */

/* ------------------------------------------------------------------   `   `   ``------- */
void AnimGroup::animUninstalled()
{
    foreach(AnimItem * item, animations_) {
        item->animUninstalled ();
    }
    AnimItem::animUninstalled ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool AnimGroup::addAnimationItem (AnimItem *item)
{
    bool b_ret = false;
    for (;;) {

        if (animations_.contains (item)) {
            ANIMSCENE_DEBUGM("The animation is already part of this list\n");
            break;
        }

        animations_.append (item);

        b_ret = true;
        break;
    }
    return b_ret;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool AnimGroup::remAnimationItem (AnimItem *item)
{
    bool b_ret = false;
    for (;;) {

        int i = animations_.indexOf (item);
        if (i == -1) {
            ANIMSCENE_DEBUGM("The animation is not part of this list\n");
            break;
        }

        b_ret = remAnimationItem (i);
        break;
    }
    return b_ret;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool AnimGroup::remAnimationItem (int i)
{
    bool b_ret = false;
    for (;;) {

        if ((i < 0) || (i >= animations_.count ())) {
            ANIMSCENE_DEBUGM("Index %d outside valid range\n", i);
            break;
        }

        AnimItem * item = animations_.at (i);
        animations_.removeAt (i);
        delete item;

        b_ret = true;
        break;
    }
    return b_ret;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
AnimItem * AnimGroup::takeAnimationItem (int i)
{
    AnimItem * item = NULL;
    for (;;) {

        if ((i < 0) || (i >= animations_.count ())) {
            ANIMSCENE_DEBUGM("Index %d outside valid range\n", i);
            break;
        }

        AnimItem * item = animations_.at (i);
        animations_.removeAt (i);

        break;
    }
    return item;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void AnimGroup::animationTick (unsigned interval)
{
    if (skipMe ())
        return;
    if (atEnd ())
        return;
    AnimItem::animationTick (interval);
    foreach(AnimItem * item, animations_) {
        item->animationTick (interval);
    }
}
/* ========================================================================= */

/*  CLASS    =============================================================== */
//
//
//
//

/* ------------------------------------------------------------------------- */
/* ========================================================================= */

