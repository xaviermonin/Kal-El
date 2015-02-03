#include "kenetworkreply.h"
#include "keinternetexplorer.h"

KENetworkReply::KENetworkReply(const QNetworkRequest& request, QObject *parent)
    : QNetworkReply(parent)
{
    setRequest(request);

    ie = new KEInternetExplorer(false, this);

    connect(ie, SIGNAL(documentComplete(IDispatch*,QVariant&)), this, SLOT(setContent()));

    ie->navigate(request.url().toString());
}

KENetworkReply::~KENetworkReply()
{
    if (!ie)
        ie->close();
}

bool KENetworkReply::isSequential() const
{
    return true;
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

    this->content = "This is my content";

    // setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/html; charset=UTF-8"));
    setHeader(QNetworkRequest::ContentLengthHeader, QVariant(this->content.size()));

    emit readyRead();
    emit finished();

    ie->close();
}
