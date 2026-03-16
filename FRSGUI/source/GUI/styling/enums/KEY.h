
#ifndef KEY_H
#define KEY_H

namespace fr
{
    enum class KEY
    {
        // Basic styling key
        POSITION,
        SIZE,
        BACKGROUND_COLOR,
        OUTLINE_COLOR,
        OUTLINE_THICKNESS,
        VISIBLE,
        CURSOR_COLOR,
        CHARACTER_SIZE,
        TEXT_COLOR,
        FONT,
        SELECT_MARK_COLOR,
        CENTER_TEXT_VERTICALLY,
        CENTER_TEXT_HORIZONTALLY,

        // LAST ELEMENT - only for development use | inner FRSGUI functionality
        DEVEL_LAST_KEY
    };

}

#endif
