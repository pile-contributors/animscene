/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/*!
\file         animitem.h
\date         December 2015
\author       Nicu Tofan

\brief        Contains the definition for AnimItem class.

*//*

 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Please read COPYING and README files in root folder
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
#ifndef PILE_ANIM_ITEM_H
#define PILE_ANIM_ITEM_H
//
//
//
//
/*  INCLUDES    ------------------------------------------------------------ */

#include <animscene/animscene-config.h>

/*  INCLUDES    ============================================================ */
//
//
//
//
/*  DEFINITIONS    --------------------------------------------------------- */

class AnimScene;

/*  DEFINITIONS    ========================================================= */
//
//
//
//
/*  CLASS    --------------------------------------------------------------- */

//! One animation item.
class ANIMSCENE_EXPORT AnimItem {
    //
    //
    //
    //
    /*  DEFINITIONS    ----------------------------------------------------- */

    friend class AnimScene;

public:

    //! Various 1-bit switches.
    enum Flag {
        NO_ANIM_FLAGS    = 0x00000,

        DO_NOT_DELETE    = 0x00001,
        AUTO_RESTART     = 0x00002, /**< get back to 0 automagically */
        RUN_FOREVER      = 0x00004, /**< never stops */
        SKIP_ME          = 0x00008, /**< does not feel the passage of time */

        ALL_ANIM_FLAGS = DO_NOT_DELETE | AUTO_RESTART,
        DEFAULT_ANIM_FLAGS = AUTO_RESTART
    };

    //! The type of the callback used to inform another object that
    //! properties changed. Return false to terminate this animation.
    typedef bool (*KbAnimItem) (AnimItem *, void *);

    /*  DEFINITIONS    ===================================================== */
    //
    //
    //
    //
    /*  DATA    ------------------------------------------------------------ */

private:

    AnimScene * anim_scene_; /**< the scene that manages us */
    unsigned total_duration_; /**< the number of miliseconds this is gonna take */
    unsigned current_time_; /**< current location inside time interval */
    unsigned anim_flags_; /**< various switches */
    unsigned count_; /**< number of times to repeat this */
    KbAnimItem kb_tik_; /**< the callback to use when time ticks */
    KbAnimItem kb_end_; /**< the callback to use when the animation ended */
    void * user_data_; /**< user data for the callback */

    /*  DATA    ============================================================ */
    //
    //
    //
    //
    /*  FUNCTIONS    ------------------------------------------------------- */

public:

    //! Constructor.
    AnimItem (
            unsigned duration = 0,
            KbAnimItem kb_tik = NULL,
            KbAnimItem kb_end = NULL,
            void* user_data = NULL,
            unsigned flags = DEFAULT_ANIM_FLAGS);


    //! destructor
    virtual ~AnimItem ();

    //! This item was installed in a scene.
    virtual void
    animInstalled (
            AnimScene * scene);

    //! This item was removed from the scene.
    virtual void
    animUninstalled () {
        anim_scene_ = NULL;
    }

    //! We're informed that some time has passed.
    virtual void
    animationTick (
            unsigned interval);


    //! Set a flag.
    void
    setAnimFlag (
            Flag flg,
            bool value = true) {
        if (value) {
            anim_flags_ = anim_flags_ | flg;
        } else {
            resetAnimFlag (flg);
        }
    }

    //! Reset a flag.
    void
    resetAnimFlag (
            Flag flg) {
        anim_flags_ = anim_flags_ & (~flg);
    }

    //! Tell if a flag is set or not.
    bool
    isAnimFlagSet (
            Flag flg) const {
        return (anim_flags_ & flg) == flg;
    }

    //! Is the scene allowed to delete the item when it finishes?
    bool
    deleteOnFinish () const {
        return !isAnimFlagSet (DO_NOT_DELETE);
    }

    //! Shoulld we reset the counter to 0 when it reaches the end?
    bool
    autoRestart () const {
        return !isAnimFlagSet (AUTO_RESTART);
    }

    //! Is this ever gonna stop?
    bool
    runForever () const {
        return !isAnimFlagSet (RUN_FOREVER);
    }

    //! Is it skipped by animation?
    bool
    skipMe () const {
        return !isAnimFlagSet (SKIP_ME);
    }

    //! Number of times the animation will be repeated.
    unsigned
    count () const;

    //! Change the number of times the animation will be repeated.
    void
    setCount (
            unsigned count);

    //! Tell if this animation is at the beginning of its cycle.
    bool
    atStart () const {
        return current_time_ == 0;
    }

    //! Tell if this animation is at the end of its cycle.
    bool
    atEnd () const {
        return current_time_ >= total_duration_;
    }

    //! Tell if this animation is at the end of its cycle and has no more counts.
    bool
    atVeryEnd () const;

    //! The proportion that passed from the total (a value between 0 and 1)
    virtual double
    fractionDone () const;

    //! The percent that passed from the total (a value between 0 and 100)
    double
    percentDone () const {
        return fractionDone () * 100;
    }

    //! Total duration of this animation in miliseconds.
    unsigned
    totalDuration() const;

    //! Change total duration.
    void
    setTotalDuration (
            unsigned value);

    //! Number of miliseconds that this animation run for.
    unsigned
    currentTime() const;



private:


    /*  FUNCTIONS    ======================================================= */
    //
    //
    //
    //
}; /* class AnimItem */

/*  CLASS    =============================================================== */
//
//
//
//

#endif // PILE_ANIM_ITEM_H
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
