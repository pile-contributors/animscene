
# enable/disable cmake debug messages related to this pile
set (ANIMSCENE_DEBUG_MSG ON)

# make sure support code is present; no harm
# in including it twice; the user, however, should have used
# pileInclude() from pile_support.cmake module.
include(pile_support)

# initialize this module
macro    (animsceneInit
          ref_cnt_use_mode)

    # default name
    if (NOT ANIMSCENE_INIT_NAME)
        set(ANIMSCENE_INIT_NAME "AnimScene")
    endif ()

    # compose the list of headers and sources
    set(ANIMSCENE_HEADERS
        "animscene.h")
    set(ANIMSCENE_SOURCES
        "animscene.cc")

    pileSetSources(
        "${ANIMSCENE_INIT_NAME}"
        "${ANIMSCENE_HEADERS}"
        "${ANIMSCENE_SOURCES}")

    pileSetCommon(
        "${ANIMSCENE_INIT_NAME}"
        "0;0;1;d"
        "ON"
        "${ref_cnt_use_mode}"
        ""
        "category1"
        "tag1;tag2")

endmacro ()
