/**
 * @file animscene.h
 * @brief Declarations for AnimScene class
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_ANIMSCENE_H_INCLUDE
#define GUARD_ANIMSCENE_H_INCLUDE

#include <animscene/animscene-config.h>
#include <QList>

class AnimItem;

QT_BEGIN_NAMESPACE
class QGraphicsScene;
QT_END_NAMESPACE

//! A scene.
class ANIMSCENE_EXPORT AnimScene {
    friend class AnimItem;

public:

    //! Constructor.
    AnimScene ();

    //! destructor
    virtual ~AnimScene ();

    //! Get the inner scene.
    virtual QGraphicsScene *
    baseScene () = 0;

    //! Start the animation engine
    void
    startAnimations (
            unsigned interval = 100);

    //! Stop the animation engine
    void
    stopAnimations ();

    //! Is the animation engine running or not?
    bool
    isAnimationStarted () const {
        return anim_timer_id_ != -1;
    }

    //! Advance the animations.
    void
    animationTick ();

    //! Get the animation timer id.
    int
    animationTimerId () const {
        return anim_timer_id_;
    }

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

private:
    QList<AnimItem*> animations_; /**< the list of animations */
    int anim_timer_id_; /**< id of the timer used with animations */
    unsigned interval_; /**< the interval between two ticks */

};

#endif // GUARD_ANIMSCENE_H_INCLUDE
