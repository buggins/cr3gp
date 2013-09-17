#include "cruiconfig.h"
#include "lvstream.h"
#include "glfont.h"
#include "gldrawbuf.h"
#include "fileinfo.h"
#include "lvtinydom.h"
#include "cruitheme.h"
#include "crui.h"
#include "crcoverpages.h"

using namespace CRUI;

CRUIConfig crconfig;

CRUIConfig::CRUIConfig() {
    docCacheMaxBytes = 32*1024*1024;
    coverDirMaxItems = 1000;
    coverDirMaxFiles = 200;
    coverDirMaxSize = 16*1024*1024;
    coverRenderCacheMaxItems = 1000;
    coverRenderCacheMaxBytes = 16 * 1024 * 1024;
    uiFontFace = "Arial";
}

void CRUIConfig::setupUserDir(lString8 baseDir) {
    LVAppendPathDelimiter(baseDir);
    // coverpage file cache
    crconfig.coverCacheDir = baseDir + "coverpages";
    // document cache
    crconfig.docCacheDir = baseDir + "cache";

    crconfig.dbFile = baseDir + "cr3db.sqlite";
    crconfig.iniFile = baseDir + "cr3.ini";
}

/// sets resourceDir, i18ndir, hyphdir
void CRUIConfig::setupResources(lString8 baseDir) {
    LVAppendPathDelimiter(baseDir);
    crconfig.resourceDir = baseDir;
    crconfig.i18nDir = baseDir + "i18n";
    crconfig.hyphDir = baseDir + "hyph";
    crconfig.cssDir = baseDir + "hyph";
}

void CRUIConfig::setupResourcesForScreenSize() {
	CRLog::trace("setupResourcesForScreenSize(%d,%d)", deviceInfo.shortSide, deviceInfo.longSide);

    // calculate fonts size
    int sz = deviceInfo.shortSide;
    int sz1 = sz / 38;
    int sz2 = sz / 28;
    int sz3 = sz / 25;
    int sz4 = sz / 20;
    int sz5 = sz / 17;
    currentTheme->setFontForSize(CRUI::FONT_SIZE_XSMALL, fontMan->GetFont(sz1, 400, false, css_ff_sans_serif, uiFontFace, 0));
    currentTheme->setFontForSize(CRUI::FONT_SIZE_SMALL, fontMan->GetFont(sz2, 400, false, css_ff_sans_serif, uiFontFace, 0));
    currentTheme->setFontForSize(CRUI::FONT_SIZE_MEDIUM, fontMan->GetFont(sz3, 400, false, css_ff_sans_serif, uiFontFace, 0));
    currentTheme->setFontForSize(CRUI::FONT_SIZE_LARGE, fontMan->GetFont(sz4, 400, false, css_ff_sans_serif, uiFontFace, 0));
    currentTheme->setFontForSize(CRUI::FONT_SIZE_XLARGE, fontMan->GetFont(sz5, 400, false, css_ff_sans_serif, uiFontFace, 0));

    // calculate folder icons size
    int folderIconSize;
    bool vertical = deviceInfo.width < deviceInfo.height * 85 / 100;
    if (vertical) {
        int nowReadingH = deviceInfo.height * 20 / 100;
        int recentH = deviceInfo.height * 25 / 100;
        int otherH = (deviceInfo.height - nowReadingH - recentH) / 3;
        folderIconSize = otherH - sz5*2 - PT_TO_PX(4);
    } else {
        int nowReadingH = deviceInfo.height * 30 / 100;
        int recentH = deviceInfo.height * 40 / 100;
        int otherH = (deviceInfo.height - nowReadingH - recentH);
        folderIconSize = otherH - sz5*2 - PT_TO_PX(4);
    }
    if (folderIconSize < 48)
        folderIconSize = 32;
    else if (folderIconSize < 64)
        folderIconSize = 48;
    else if (folderIconSize < 128)
        folderIconSize = 64;
    else if (folderIconSize < 256)
        folderIconSize = 128;
    else
        folderIconSize = 256;
    char s[32];
    sprintf(s, "icons/%dx%d", folderIconSize, folderIconSize);

    lString8Collection dirs;
    dirs.add(resourceDir + s);
    if (deviceInfo.shortSide <= 420) {
    	CRLog::info("screen density normal");
        dirs.add(resourceDir + "screen-density-normal");
        dirs.add(resourceDir + "screen-density-high");
        dirs.add(resourceDir + "screen-density-xhigh");
    } else if (deviceInfo.shortSide <= 480) {
    	CRLog::info("screen density high");
        dirs.add(resourceDir + "screen-density-high");
        dirs.add(resourceDir + "screen-density-xhigh");
        dirs.add(resourceDir + "screen-density-normal");
    } else if (deviceInfo.shortSide <= 800) {
    	CRLog::info("screen density xhigh");
        dirs.add(resourceDir + "screen-density-xhigh");
        dirs.add(resourceDir + "screen-density-xxhigh");
        dirs.add(resourceDir + "screen-density-high");
        dirs.add(resourceDir + "screen-density-normal");
    } else {
    	CRLog::info("screen density xxhigh");
        dirs.add(resourceDir + "screen-density-xxhigh");
        dirs.add(resourceDir + "screen-density-xhigh");
        dirs.add(resourceDir + "screen-density-high");
        dirs.add(resourceDir + "screen-density-normal");
    }
    resourceResolver->setDirList(dirs);
}


void CRUIConfig::createDefaultTheme() {
    currentTheme = new CRUITheme(lString8("BLACK"));
    currentTheme->setTextColor(0x000000);
    currentTheme->setFontForSize(CRUI::FONT_SIZE_XSMALL, fontMan->GetFont(PT_TO_PX(6), 400, false, css_ff_sans_serif, uiFontFace, 0));
    currentTheme->setFontForSize(CRUI::FONT_SIZE_SMALL, fontMan->GetFont(PT_TO_PX(8), 400, false, css_ff_sans_serif, uiFontFace, 0));
    currentTheme->setFontForSize(CRUI::FONT_SIZE_MEDIUM, fontMan->GetFont(PT_TO_PX(12), 400, false, css_ff_sans_serif, uiFontFace, 0));
    currentTheme->setFontForSize(CRUI::FONT_SIZE_LARGE, fontMan->GetFont(PT_TO_PX(16), 400, false, css_ff_sans_serif, uiFontFace, 0));
    currentTheme->setFontForSize(CRUI::FONT_SIZE_XLARGE, fontMan->GetFont(PT_TO_PX(22), 400, false, css_ff_sans_serif, uiFontFace, 0));

    //currentTheme->setListDelimiterVertical(resourceResolver->getIcon("divider_light_v3.png"));
    currentTheme->setListDelimiterVertical("list_delimiter_h.png");
    CRUIStyle * buttonStyle = currentTheme->addSubstyle("BUTTON");
    //keyboard_key_feedback_background.9
    buttonStyle->setBackground("btn_default_normal.9")->setFontSize(FONT_SIZE_LARGE);
    //buttonStyle->setBackground("keyboard_key_feedback_background.9")->setFontSize(FONT_SIZE_LARGE)->setPadding(10);
    //buttonStyle->setBackground("btn_default_normal.9")->setFontSize(FONT_SIZE_LARGE)->setPadding(10);
    buttonStyle->addSubstyle(STATE_PRESSED, STATE_PRESSED)->setBackground("btn_default_pressed.9");
    buttonStyle->addSubstyle(STATE_FOCUSED, STATE_FOCUSED)->setBackground("btn_default_selected.9");
    buttonStyle->addSubstyle(STATE_DISABLED, STATE_DISABLED)->setTextColor(0x80000000);

    buttonStyle = currentTheme->addSubstyle("BUTTON_NOBACKGROUND");
    buttonStyle->addSubstyle(STATE_PRESSED, STATE_PRESSED)->setBackground(0xC0C0C080);
    buttonStyle->addSubstyle(STATE_FOCUSED, STATE_FOCUSED)->setBackground(0xE0C0C080);
    buttonStyle->addSubstyle(STATE_DISABLED, STATE_DISABLED)->setTextColor(0x80000000);

    CRUIStyle * listItemStyle = currentTheme->addSubstyle("LIST_ITEM");
    listItemStyle->setMargin(0)->setPadding(7);
    listItemStyle->addSubstyle(STATE_FOCUSED, STATE_FOCUSED)->setBackground(0x40C0C080);
    listItemStyle->addSubstyle(STATE_DISABLED, STATE_DISABLED)->setTextColor(0x80000000);

    CRUIStyle * homeStyle = currentTheme->addSubstyle("HOME_WIDGET");
    homeStyle->setBackground("tx_wood_v3.jpg", true);
    homeStyle->setBackground2("list_shadow_vertical.9");

    CRUIStyle * fileListStyle = currentTheme->addSubstyle("FILE_LIST");
    fileListStyle->setBackground("tx_wood_v3.jpg", true);
    fileListStyle->setBackground2("list_shadow_vertical.9");
    fileListStyle->setListDelimiterVertical("divider_light_v3.png");

    CRUIStyle * homeListCaption = currentTheme->addSubstyle("HOME_LIST_CAPTION");
    //homeListCaption->setTextColor(0x40000000);
    homeListCaption->setTextColor(0x00402000);
    homeListCaption->setFontSize(CRUI::FONT_SIZE_SMALL);

    CRUIStyle * toolbar = currentTheme->addSubstyle("TOOL_BAR");
    //homeListCaption->setTextColor(0x40000000);
    toolbar->setBackground("tx_wood_v3.jpg", true);
    toolbar->setBackground2("toolbar_shadow.9");
    toolbar->setFontSize(CRUI::FONT_SIZE_SMALL);

    resourceResolver->setIconColorTransform(0x888888, 0x302820);
}

/// on GL context close, delete all GL objects
void CRUIConfig::clearGraphicsCaches() {
	CRLog::trace("CRUIConfig::clearGraphicsCaches()");
	//coverPageManager->cancelAll();
	//coverPageManager->clearImageCache();
	resourceResolver->clearImageCache();
	LVGLClearImageCache();
	fontMan->clearGlyphCache();
}

void CRUIConfig::initEngine() {

    if (systemLanguage.empty())
        systemLanguage = "en";

    LVAppendPathDelimiter(hyphDir);
    LVAppendPathDelimiter(cssDir);
    LVAppendPathDelimiter(resourceDir);
    LVAppendPathDelimiter(coverCacheDir);
    LVAppendPathDelimiter(docCacheDir);
    LVAppendPathDelimiter(i18nDir);

    // Logger
    if (!logFile.empty())
        CRLog::setFileLogger(logFile.c_str(), true);
    CRLog::setLogLevel(CRLog::LL_TRACE);

    // Concurrency
    CRSetupEngineConcurrency();

    InitFontManager(lString8());
    LVInitGLFontManager(fontMan);
    for (int i = 0; i<fontFiles.length(); i++) {
        fontMan->RegisterFont(fontFiles[i]);
    }
    lString8 fallbackFont = fallbackFontFace;
    bool configuredFallbackFontFound = false;
    lString8 foundFallbackFont;
    lString16Collection faceList;
    fontMan->getFaceList(faceList);
    for (int i = 0; i < faceList.length(); i++) {
    	lString8 face = UnicodeToUtf8(faceList[i]);
    	if (face == fallbackFont)
    		configuredFallbackFontFound = true;
    	if (face == "Droid Sans Fallback" || face == "Arial Unicode") // TODO: more faces
    		foundFallbackFont = face;
    }
    if (!configuredFallbackFontFound)
    	fallbackFont = foundFallbackFont;
    if (!fallbackFont.empty()) {
    	fontMan->SetFallbackFontFace(fallbackFont);
    }


    //fontMan->SetFallbackFontFace(lString8("Tizen Sans Fallback"));
    //dirs.add(UnicodeToUtf8(resourceDir));
    lString8Collection dirs;
    dirs.add(resourceDir + "screen-density-xhigh");
    LVCreateResourceResolver(dirs);
    LVGLCreateImageCache();

    // coverpage file cache
    CRSetupCoverpageManager(Utf8ToUnicode(coverCacheDir), coverDirMaxItems, coverDirMaxFiles, coverDirMaxSize, coverRenderCacheMaxItems, coverRenderCacheMaxBytes);

    // document cache
    ldomDocCache::init(Utf8ToUnicode(docCacheDir), docCacheMaxBytes);

    // I18N
    CRIniFileTranslator * fallbackTranslator = CRIniFileTranslator::create((i18nDir + "en.ini").c_str());
    CRIniFileTranslator * mainTranslator = CRIniFileTranslator::create((i18nDir + "ru.ini").c_str());
    CRI18NTranslator::setTranslator(mainTranslator);
    CRI18NTranslator::setDefTranslator(fallbackTranslator);

    HyphMan::initDictionaries(lString16(), true);

    bookDB = new CRBookDB();
    if (bookDB->open(dbFile.c_str()))
        CRLog::error("Error while opening DB file");
    if (!bookDB->updateSchema())
        CRLog::error("Error while updating DB schema");
    if (!bookDB->fillCaches())
        CRLog::error("Error while filling caches");

    CRSetupDirectoryCacheManager();

    createDefaultTheme();
}



void CRUIConfig::uninitEngine() {
    CRStopCoverpageManager();
    CRStopDirectoryCacheManager();
    if (bookDB) {
        bookDB->close();
        delete bookDB;
        bookDB = NULL;
    }
}
