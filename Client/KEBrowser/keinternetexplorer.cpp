#include "keinternetexplorer.h"
#include <ActiveQt/QAxObject>
#include <QNetworkRequest>
#include <Windows.h>
#include <QDebug>

typedef enum BrowserNavConstants {
    navOpenInNewWindow = 0x1,
    navNoHistory = 0x2,
    navNoReadFromCache = 0x4,
    navNoWriteToCache = 0x8,
    navAllowAutosearch = 0x10,
    navBrowserBar = 0x20,
    navHyperlink = 0x40,
    navEnforceRestricted = 0x80,
    navNewWindowsManaged = 0x0100,
    navUntrustedForDownload = 0x0200,
    navTrustedForActiveX = 0x0400,
    navOpenInNewTab = 0x0800,
    navOpenInBackgroundTab = 0x1000,
    navKeepWordWheelText = 0x2000,
    navVirtualTab = 0x4000,
    navBlockRedirectsXDomain = 0x8000,
    navOpenNewForegroundTab = 0x10000
} BrowserNavConstants;

KEInternetExplorer::KEInternetExplorer(bool visible = false, QObject *parent)
    : QObject(parent)
{
    CoInitialize(0);

    ie = new QAxObject(this);
    if (!ie->setControl("InternetExplorer.Application"))
    {
        qWarning("Internet Explorer: initialisation failed");
        ie = NULL;
        return;
    }

    setVisible(visible);
}

void KEInternetExplorer::close()
{
    if (ie != NULL)
    {
        ie->dynamicCall("Quit()");
        ie = NULL;
    }
}

KEInternetExplorer::~KEInternetExplorer()
{
    close();
}

void KEInternetExplorer::setSilence(bool state)
{
    ie->setProperty("Silence", state);
}

void KEInternetExplorer::setVisible(bool state)
{
    ie->setProperty("Visible", state);
}

bool KEInternetExplorer::visible() const
{
    return ie->property("Visible").toBool();
}

bool KEInternetExplorer::silence() const
{
    return ie->property("Silence").toBool();
}

void KEInternetExplorer::get(const QNetworkRequest& request)
{
    QList<QByteArray> headers = request.rawHeaderList();
    QString strHeader;

    for (QList<QByteArray>::iterator it = headers.begin(); it != headers.end(); ++it)
    {
        strHeader.append(*it);
        strHeader.append(": ");
        strHeader.append(request.rawHeader(*it));
        strHeader.append("\r\n");
    }

    qDebug() << "Headers: " << strHeader;

    navigate(request.url().toString(), strHeader);
}

void KEInternetExplorer::post(const QString& url)
{
    //navigate(url, QVariant(), QVariant(), );
}

void KEInternetExplorer::navigate(const QString& url, const QString& headers,
                                  const QString& postData,
                                  const QString& targetFrameName, int flags)
{
    if (!ie)
        return;

    ie->dynamicCall("Navigate2(QVariant, QVariant, QVariant, QVariant, QVariant)",
                    url, flags, targetFrameName, postData, headers);
    /*ie->dynamicCall("Navigate2(QVariant, QVariant, QVariant, QVariant, QVariant)",
                    "http://echo.fr", 0, "", "pomme=truc", "Content: pomme");*/
}







