#ifndef KEBROWSER_H
#define KEBROWSER_H

#include <QObject>
#include <QString>

class QAxObject;
class QNetworkRequest;
class QVariant;
struct IDispatch;

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

class KEInternetExplorer : public QObject
{
    Q_OBJECT
public:
    explicit KEInternetExplorer(bool visible, QObject* parent = 0);
    virtual ~KEInternetExplorer();

    void close();

    void setSilence(bool);
    bool silence() const;

    void setVisible(bool);
    bool visible() const;

    QString contentHtml();
    QString contentText();

    void navigate(const QString& url, const QString &headers = "", const QByteArray &postData = "", const QString &targetFrameName = "", int flags = 0);

    void stop();

signals:
    void documentComplete(IDispatch*, QVariant& url);
    void navigateComplete(QString url);
    void beforeNavigate(QString, int, QString, QVariant&, QString, bool&);
    void downloadBegin();
    void downloadComplete();

private slots:
    void documentCompleteInternal(IDispatch*, QVariant& url);
    void navigateCompleteInternal(QString url);
    void beforeNavigateInternal(QString url, int flag, QString targetFrameName, QVariant&postData, QString header, bool&cancel);
    void downloadBeginInternal();
    void downloadCompleteInternal();
    void exceptionInternal(int,QString,QString,QString);

private:
    void setConnections();
    QAxObject* documentElement();
    QString getDocumentElementProperty(QString name);

private:
    QAxObject* ie;
};

#endif // KEBROWSER_H
