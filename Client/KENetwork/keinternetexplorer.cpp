#include "keinternetexplorer.h"
#include <ActiveQt/QAxObject>
#include <QNetworkRequest>
#include <QDebug>
#include <initguid.h>
#include <QUuid>

#include <Windows.h>
#include <ocidl.h>

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

    setConnections();
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

QByteArray KEInternetExplorer::content()
{
    QAxObject* document = ie->querySubObject("Document");

    IPersistStreamInit* pPersistStreamInit = NULL;

    document->queryInterface(QUuid(__uuidof(IPersistStreamInit)),
                             (void**)&pPersistStreamInit);

    if (!pPersistStreamInit)
        return QByteArray();

    // Fill stream

    IStream* pStream = 0;

    if (FAILED(CreateStreamOnHGlobal(0, TRUE, &pStream)))
        return QByteArray();

    if (FAILED(pPersistStreamInit->Save(pStream, FALSE)))
    {
        pPersistStreamInit->Release();
        return QByteArray();
    }

    // Read stream

    LARGE_INTEGER liBeggining = {0};

    STATSTG statstg = {0};

    pStream->Seek(liBeggining, 0, NULL);
    pStream->Stat(&statstg, STATFLAG_NONAME);

    quint64 sizeRequired = statstg.cbSize.QuadPart;

    char* pSource = new char[sizeRequired];

    if (FAILED(pStream->Read(pSource, sizeRequired, NULL)))
    {
        delete pSource;
        pStream->Release();
        pPersistStreamInit->Release();
        return QByteArray();
    }

    pStream->Release();
    pPersistStreamInit->Release();

    QByteArray data(pSource, sizeRequired);

    delete pSource;

    return data;
}

bool KEInternetExplorer::silence() const
{
    return ie->property("Silence").toBool();
}

void KEInternetExplorer::navigate(const QString& url, const QString& headers,
                                  const QByteArray& postData,
                                  const QString& targetFrameName, int flags)
{
    if (!ie)
    {
        qWarning("IE closed");
        return;
    }

    ie->dynamicCall("Navigate2(QVariant, QVariant, QVariant, QVariant, QVariant)",
                    url, flags, targetFrameName, postData, headers);
}

void KEInternetExplorer::stop()
{
    ie->dynamicCall("Stop()");
}

void KEInternetExplorer::documentCompleteInternal(IDispatch* disp, QVariant &url)
{
    emit documentComplete(disp, url);
}

void KEInternetExplorer::navigateCompleteInternal(QString url)
{
    emit navigateComplete(url);
}

void KEInternetExplorer::beforeNavigateInternal(QString url, int flag, QString targetFrameName,
                                                QVariant& postData, QString header, bool& cancel)
{
    emit beforeNavigate(url, flag, targetFrameName, postData, header, cancel);
}

void KEInternetExplorer::downloadBeginInternal()
{
    emit downloadBegin();
}

void KEInternetExplorer::downloadCompleteInternal()
{
    emit downloadComplete();
}

void KEInternetExplorer::exceptionInternal(int, QString, QString, QString)
{

}

void KEInternetExplorer::setConnections()
{
    connect(ie, SIGNAL(DocumentComplete(IDispatch*, QVariant&)), this, SLOT(documentCompleteInternal(IDispatch*,QVariant&)));
    connect(ie, SIGNAL(NavigateComplete(QString)), this, SLOT(navigateCompleteInternal(QString)));
    connect(ie, SIGNAL(BeforeNavigate(QString, int, QString, QVariant&, QString, bool&)),
            this, SLOT(beforeNavigateInternal(QString,int,QString,QVariant&,QString,bool&)));
    connect(ie, SIGNAL(DownloadBegin()), this, SLOT(downloadBeginInternal()));
    connect(ie, SIGNAL(DownloadComplete()), this, SLOT(downloadCompleteInternal()));
    connect(ie, SIGNAL(exception(int, QString, QString, QString)),
            this, SLOT(exceptionInternal(int,QString,QString,QString)));
}

QAxObject *KEInternetExplorer::documentElement()
{
    QAxObject* document = ie->querySubObject("Document");
    if (document == NULL || document->isNull())
    {
        qDebug("Document node null");
        return NULL;
    }

    QAxObject* documentElement = document->querySubObject("documentElement");
    if (!documentElement || documentElement->isNull())
    {
        qWarning("DocumentElement node null");
        return NULL;
    }

    return documentElement;
}

QString KEInternetExplorer::getDocumentElementProperty(QString name)
{
    QAxObject* axDocumentElement = documentElement();
    if (axDocumentElement == NULL)
        return QString::null;

    QVariant propertyValue = axDocumentElement->property(name.toLatin1().constData());

    delete axDocumentElement;

    if (!propertyValue.isValid())
    {
        qDebug("document element property invalid");
        return QString::null;
    }

    return propertyValue.toString();
}
