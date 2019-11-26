#include "dialog.h"
#include <QApplication>
#include "digiclock.h"
#include <QSettings>
#include <QDir>
void appAutoRun(bool bAutoRun)
{
    //HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run
    QSettings  reg("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);

    if (bAutoRun)
    {
         QString strAppPath=QDir::toNativeSeparators(QCoreApplication::applicationFilePath());
        //strAppPath.replace(QChar('/'),QChar('\\'),Qt::CaseInsensitive);
        reg.setValue("wirtepad",strAppPath);
    }
    else
    {
        reg.setValue("wirtepad","");
    }

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DigiClock clock;

    appAutoRun(true);
    clock.setWindowFlags(clock.windowFlags() | Qt::WindowStaysOnTopHint);
    clock.show();

    //Dialog w;
    //w.show();

    return a.exec();
}
