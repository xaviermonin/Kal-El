#include "kenetworkreply.h"
#include "keinternetexplorer.h"

KENetworkReply::KENetworkReply(const QNetworkRequest& request, QIODevice* device, QObject *parent)
    : QNetworkReply(parent)
{
    setRequest(request);

    ie = new KEInternetExplorer(false, this);

    connect(ie, SIGNAL(navigateComplete(QString)), this, SLOT(setContent()));

    QByteArray postData;
    QString headers = headersFromNetworkRequest(request);

    if (device != NULL)
        postData = device->readAll();

    ie->navigate(request.url().toString(), headers, postData);
}

KENetworkReply::~KENetworkReply()
{
    if (ie != NULL)
        ie->close();
}

bool KENetworkReply::isSequential() const
{
    return true;
}

QString KENetworkReply::headersFromNetworkRequest(const QNetworkRequest& request) const
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

    return strHeader;
}

void KENetworkReply::abort()
{
    ie->stop();
    ie->close();
    ie = NULL;
}

qint64 KENetworkReply::bytesAvailable() const
{
    return content.size() - offset + QIODevice::bytesAvailable();
}

qint64 KENetworkReply::readData(char *data, qint64 maxSize)
{
    if (offset < content.size())
    {
        qint64 number = qMin(maxSize, content.size() - offset);
        memcpy(data, content.constData() + offset, number);
        offset += number;
        return number;
    }
    else
    {
        return -1;
    }
}

void KENetworkReply::setContent()
{
    qWarning("Document complete. Read content.");

    this->content = ie->contentText().toLatin1();

    // setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/html; charset=UTF-8"));
    setHeader(QNetworkRequest::ContentLengthHeader, QVariant(this->content.size()));

    emit readyRead();
    emit finished();

    ie->close();
}
