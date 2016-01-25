/**
 * @file animscene.cc
 * @brief Definitions for AnimScene class.
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#include "animscene.h"
#include "animitem.h"
#include "animscene-private.h"
#include <QGraphicsScene>

/**
 * @class AnimScene
 *
 * Detailed description.
 */

/* ------------------------------------------------------------------------- */
/**
 * Detailed description for constructor.
 */
AnimScene::AnimScene():
    animations_(),
    anim_timer_id_(-1),
    interval_(0)
{
    ANIMSCENE_TRACE_ENTRY;

    ANIMSCENE_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * Detailed description for destructor.
 */
AnimScene::~AnimScene()
{
    ANIMSCENE_TRACE_ENTRY;

    ANIMSCENE_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void AnimScene::startAnimations (unsigned interval)
{
    if (interval == 0) {
        interval = 100;
    }
    QGraphicsScene * scn = baseScene ();
    if (anim_timer_id_ == -1) {
        anim_timer_id_ = scn->startTimer (interval);
    } else if (interval_ != interval) {
        scn->killTimer (anim_timer_id_);
        anim_timer_id_ = scn->startTimer (interval);
    }
    interval_ = interval;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void AnimScene::stopAnimations()
{
    if (anim_timer_id_ != -1) {
        QGraphicsScene * scn = baseScene ();
        scn->killTimer (anim_timer_id_);
        anim_timer_id_ = -1;
    }
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void AnimScene::animationTick()
{
    // tick for everybody
    foreach(AnimItem * it, animations_) {
        it->animationTick (interval_);
    }

    // remove those that ended
    int i_max = animations_.count();
    for (int i = i_max - 1; i >= 0; --i) {
        AnimItem * it = animations_.at (i);
        if (it->atVeryEnd()) {
            if (it->deleteOnFinish ()) {
                remAnimationItem (i);
            } else {
                takeAnimationItem (i);
            }
        }
    }
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool AnimScene::addAnimationItem (AnimItem *item)
{
    bool b_ret = false;
    for (;;) {

        if (animations_.contains (item)) {
            ANIMSCENE_DEBUGM("The animation is already part of this list\n");
            break;
        }

        item->animInstalled (this);
        animations_.append (item);

        b_ret = true;
        break;
    }
    return b_ret;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool AnimScene::remAnimationItem (AnimItem *item)
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
bool AnimScene::remAnimationItem (int i)
{
    bool b_ret = false;
    for (;;) {

        if ((i < 0) || (i >= animations_.count ())) {
            ANIMSCENE_DEBUGM("Index %d outside valid range\n", i);
            break;
        }

        AnimItem * item = animations_.at (i);
        animations_.removeAt (i);
        item->animUninstalled ();
        delete item;

        b_ret = true;
        break;
    }
    return b_ret;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
AnimItem * AnimScene::takeAnimationItem (int i)
{
    AnimItem * item = NULL;
    for (;;) {

        if ((i < 0) || (i >= animations_.count ())) {
            ANIMSCENE_DEBUGM("Index %d outside valid range\n", i);
            break;
        }

        AnimItem * item = animations_.at (i);
        animations_.removeAt (i);
        item->animUninstalled ();

        break;
    }
    return item;
}
/* ========================================================================= */
