if (NOT ANIMSCENE_BUILD_MODE)
    set (ANIMSCENE_BUILD_MODE STATIC)
endif ()

include(pile_support)
pileInclude (AnimScene)
animsceneInit(${ANIMSCENE_BUILD_MODE})
