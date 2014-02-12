#include "cr3mainwindow.h"

#include "cr3qt.h"
#include <QApplication>

using namespace CRUI;


int main(int argc, char *argv[])
{
    int res = 0;
    {
        lString16 exePath = LVExtractPath(Utf8ToUnicode(argv[0]));
        LVAppendPathDelimiter(exePath);
        InitCREngine(exePath);
        QApplication a(argc, argv);
        OpenGLWindow w;
        bool fullscreen = w.getSettings()->getBoolDef(PROP_APP_FULLSCREEN, false);
        if (fullscreen)
            w.showFullScreen();
        else
            w.show();
        res = a.exec();
    }
    crconfig.uninitEngine();
    return res;
}
