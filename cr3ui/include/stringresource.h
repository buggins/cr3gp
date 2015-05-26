/*
 * stringresource.h
 *
 *  Created on: Aug 21, 2013
 *      Author: vlopatin
 */

#ifndef STRINGRESOURCE_H_
#define STRINGRESOURCE_H_

#ifndef STRING_RES_IMPL
#define S(x) extern const char * STR_ ## x;
#else
#define S(x) const char * STR_ ## x  = # x;
#endif

S(NOW_READING)
S(BROWSE_FILESYSTEM)
S(BROWSE_LIBRARY)
S(ONLINE_CATALOGS)
S(RECENT_BOOKS)
S(SD_CARD_DIR)
S(INTERNAL_STORAGE_DIR)
S(BOOKS_BY_AUTHOR)
S(BOOKS_BY_TITLE)
S(BOOKS_BY_FILENAME)
S(BOOKS_BY_SERIES)
S(BOOKS_SEARCH)
S(READER_TOC)
S(READER_BOOKMARKS)
S(BOOK_COUNT)
S(FOLDER_COUNT)

S(OPDS_CATALOG_PROPS_DIALOG_TITLE)
S(OPDS_CATALOG_NAME)
S(OPDS_CATALOG_URL)
S(OPDS_CATALOG_LOGIN)
S(OPDS_CATALOG_PASSWORD)
S(OPDS_BOOK_DOWNLOAD)
S(OPDS_BOOK_OPEN)
S(OPDS_BOOK_DOWNLOADING)

S(ERROR_DOWNLOADS_DIRECTORY_NOT_SET)
S(ERROR_DOWNLOADS_DIRECTORY_NOT_WRITABLE)
S(ERROR_DOWNLOADS_CANNOT_START_DOWNLOAD)

S(SETTINGS_BROWSER)
S(SETTINGS_BROWSER_DESC)
S(SETTINGS_READER)
S(SETTINGS_READER_DESC)

S(SETTINGS_THEME)
S(SETTINGS_THEME_VALUE_LIGHT)
S(SETTINGS_THEME_VALUE_DARK)
S(SETTINGS_THEME_VALUE_WHITE)
S(SETTINGS_THEME_VALUE_BLACK)

S(SETTINGS_FONTS_AND_COLORS)
S(SETTINGS_FONT_FACE)
S(SETTINGS_FONT_SIZE)
S(SETTINGS_FONT_COLOR)
S(SETTINGS_BACKGROUND_COLOR)
S(SETTINGS_BACKGROUND_TEXTURE)
S(SETTINGS_BACKGROUND_TEXTURE_ENABLED)
S(SETTINGS_BACKGROUND_TEXTURE_ENABLED_VALUE_ON)
S(SETTINGS_BACKGROUND_TEXTURE_ENABLED_VALUE_OFF)

S(SETTINGS_FONT_SAMPLE_TEXT)

S(SETTINGS_TEXT_FORMATTING)
S(SETTINGS_TEXT_FORMATTING_DESCRIPTION)
S(SETTINGS_PAGE_LAYOUT)
S(SETTINGS_PAGE_LAYOUT_DESCRIPTION)
S(SETTINGS_PAGE_MARGINS)
S(SETTINGS_INTERLINE_SPACE)
S(SETTINGS_FLOATING_PUNCTUATION)
S(SETTINGS_FLOATING_PUNCTUATION_VALUE_ON)
S(SETTINGS_FLOATING_PUNCTUATION_VALUE_OFF)

S(SETTINGS_INTERFACE)
S(SETTINGS_INTERFACE_DESCRIPTION)


S(SETTINGS_FONT_KERNING)
S(SETTINGS_FONT_KERNING_VALUE_ON)
S(SETTINGS_FONT_KERNING_VALUE_OFF)
S(SETTINGS_FONT_ANTIALIASING)
S(SETTINGS_FONT_ANTIALIASING_VALUE_ON)
S(SETTINGS_FONT_ANTIALIASING_VALUE_OFF)
S(SETTINGS_FONT_EMBOLDEN)
S(SETTINGS_FONT_EMBOLDEN_VALUE_ON)
S(SETTINGS_FONT_EMBOLDEN_VALUE_OFF)
S(SETTINGS_FONT_RENDERING)
S(SETTINGS_FONT_RENDERING_DESCRIPTION)
S(SETTINGS_FONT_GAMMA)
S(SETTINGS_FONT_BYTECODE_INTERPRETOR)
S(SETTINGS_FONT_BYTECODE_INTERPRETOR_VALUE_ON)
S(SETTINGS_FONT_BYTECODE_INTERPRETOR_VALUE_OFF)
S(SETTINGS_COLOR_CORRECTION)
S(SETTINGS_BRIGHTNESS)
S(SETTINGS_CONTRAST)

S(SETTINGS_VIEW_MODE)
S(SETTINGS_VIEW_MODE_DESCRIPTION)
S(SETTINGS_VIEW_MODE_VALUE_SCROLL)
S(SETTINGS_VIEW_MODE_VALUE_1PAGE)
S(SETTINGS_VIEW_MODE_VALUE_2PAGES)
S(SETTINGS_VIEW_PAGE_ANIMATION)
S(SETTINGS_VIEW_PAGE_ANIMATION_DESCRIPTION)
S(SETTINGS_VIEW_PAGE_ANIMATION_VALUE_NONE)
S(SETTINGS_VIEW_PAGE_ANIMATION_VALUE_SLIDE1)
S(SETTINGS_VIEW_PAGE_ANIMATION_VALUE_SLIDE2)
S(SETTINGS_VIEW_PAGE_ANIMATION_VALUE_FADE)
S(SETTINGS_VIEW_PAGE_ANIMATION_VALUE_3D)

S(SETTINGS_APP_FULLSCREEN)
S(SETTINGS_APP_FULLSCREEN_VALUE_ON)
S(SETTINGS_APP_FULLSCREEN_VALUE_OFF)

S(SETTINGS_APP_SCREEN_UPDATE_MODE)
S(SETTINGS_APP_SCREEN_UPDATE_MODE_DESCRIPTION)
S(SETTINGS_APP_SCREEN_UPDATE_MODE_QUALITY)
S(SETTINGS_APP_SCREEN_UPDATE_MODE_FAST)
S(SETTINGS_APP_SCREEN_UPDATE_MODE_FAST2)

S(SETTINGS_APP_SCREEN_UPDATE_INTERVAL)
S(SETTINGS_APP_SCREEN_UPDATE_INTERVAL_DESCRIPTION)

S(SETTINGS_APP_READER_TOOLBAR)
S(SETTINGS_APP_READER_TOOLBAR_DESCRIPTION)
S(SETTINGS_APP_READER_TOOLBAR_VALUE_OFF)
S(SETTINGS_APP_READER_TOOLBAR_VALUE_TOP)
S(SETTINGS_APP_READER_TOOLBAR_VALUE_LEFT)
S(SETTINGS_APP_READER_TOOLBAR_VALUE_SHORT_SIDE)
S(SETTINGS_APP_READER_TOOLBAR_VALUE_LONG_SIDE)

S(SETTINGS_APP_BOOK_COVER_VISIBLE)
S(SETTINGS_APP_BOOK_COVER_VISIBLE_VALUE_OFF)
S(SETTINGS_APP_BOOK_COVER_VISIBLE_VALUE_ON)
S(SETTINGS_APP_BOOK_COVER_COLOR)

S(SETTINGS_TTS_VOICE)
S(SETTINGS_TTS_VOICE_VALUE_SYSTEM)
S(SETTINGS_TTS_RATE)
S(SETTINGS_TTS_SAMPLE)
S(SETTINGS_TTS_SAMPLE_PLAY)
S(TTS_PLAY_IN_PROGRESS)

S(PINCH_CHANGING_PAGE_MARGINS)
S(PINCH_CHANGING_INTERLINE_SPACING)
S(PINCH_CHANGING_FONT_SIZE)

S(SETTINGS_CONTROLS)
S(SETTINGS_CONTROLS_DESCRIPTION)
S(SETTINGS_CONTROLS_TAP_ZONES_NORMAL)
S(SETTINGS_CONTROLS_TAP_ZONES_NORMAL_DESCRIPTION)
S(SETTINGS_CONTROLS_TAP_ZONES_DOUBLE)
S(SETTINGS_CONTROLS_TAP_ZONES_DOUBLE_DESCRIPTION)

S(SETTINGS_INTERFACE_LANGUAGE)
S(INTERFACE_LANGUAGE_VALUE_SYSTEM)
S(INTERFACE_LANGUAGE_VALUE_EN)
S(INTERFACE_LANGUAGE_VALUE_RU)

S(SETTINGS_HYPHENATION_DICTIONARY)
S(HYPHENATION_DICTIONARY_VALUE_NONE)
S(HYPHENATION_DICTIONARY_VALUE_ALGORITHM)
S(HYPHENATION_DICTIONARY_VALUE_EN)
S(HYPHENATION_DICTIONARY_VALUE_RU)
S(HYPHENATION_DICTIONARY_VALUE_BG)
S(HYPHENATION_DICTIONARY_VALUE_CA)
S(HYPHENATION_DICTIONARY_VALUE_CS)
S(HYPHENATION_DICTIONARY_VALUE_CZ)
S(HYPHENATION_DICTIONARY_VALUE_DE)
S(HYPHENATION_DICTIONARY_VALUE_EL)
S(HYPHENATION_DICTIONARY_VALUE_FI)
S(HYPHENATION_DICTIONARY_VALUE_EO)
S(HYPHENATION_DICTIONARY_VALUE_ES)
S(HYPHENATION_DICTIONARY_VALUE_ID)
S(HYPHENATION_DICTIONARY_VALUE_FR)
S(HYPHENATION_DICTIONARY_VALUE_HU)
S(HYPHENATION_DICTIONARY_VALUE_IT)
S(HYPHENATION_DICTIONARY_VALUE_KA)
S(HYPHENATION_DICTIONARY_VALUE_NL)
S(HYPHENATION_DICTIONARY_VALUE_LT)
S(HYPHENATION_DICTIONARY_VALUE_NB)
S(HYPHENATION_DICTIONARY_VALUE_PL)
S(HYPHENATION_DICTIONARY_VALUE_PT)
S(HYPHENATION_DICTIONARY_VALUE_UK)
S(HYPHENATION_DICTIONARY_VALUE_SV)
S(HYPHENATION_DICTIONARY_VALUE_TR)

S(RESOURCE_BACKGROUND_NAME_PAPER1)
S(RESOURCE_BACKGROUND_NAME_PAPER2)
S(RESOURCE_BACKGROUND_NAME_FABRIC1)
S(RESOURCE_BACKGROUND_NAME_FABRIC2)
S(RESOURCE_BACKGROUND_NAME_SAND1)
S(RESOURCE_BACKGROUND_NAME_SAND2)
S(RESOURCE_BACKGROUND_NAME_WALL1)
S(RESOURCE_BACKGROUND_NAME_OLDBOOK1)
S(RESOURCE_BACKGROUND_NAME_OLDBOOK2)
S(RESOURCE_BACKGROUND_NAME_STONES1)

S(RESOURCE_BACKGROUND_NAME_PAPER1_DARK)
S(RESOURCE_BACKGROUND_NAME_PAPER2_DARK)
S(RESOURCE_BACKGROUND_NAME_FABRIC1_DARK)
S(RESOURCE_BACKGROUND_NAME_FABRIC2_DARK)
S(RESOURCE_BACKGROUND_NAME_SAND1_DARK)
S(RESOURCE_BACKGROUND_NAME_SAND2_DARK)
S(RESOURCE_BACKGROUND_NAME_WALL1_DARK)
S(RESOURCE_BACKGROUND_NAME_OLDBOOK1_DARK)
S(RESOURCE_BACKGROUND_NAME_OLDBOOK2_DARK)
S(RESOURCE_BACKGROUND_NAME_STONES1_DARK)


#endif /* STRINGRESOURCE_H_ */
