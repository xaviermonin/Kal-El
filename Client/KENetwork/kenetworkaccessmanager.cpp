#include "kenetworkaccessmanager.h"
#include "kenetworkreply.h"

KENetworkAccessManager::KENetworkAccessManager(BackendMode mode, QObject *parent)
    : QNetworkAccessManager(parent)
{
    this->mode = mode;
}

KENetworkAccessManager::~KENetworkAccessManager()
{

}

void KENetworkAccessManager::setBackEndMode(KENetworkAccessManager::BackendMode mode)
{
    this->mode = mode;
}

KENetworkAccessManager::BackendMode KENetworkAccessManager::backendMode() const
{
    return mode;
}

QNetworkReply* KENetworkAccessManager::createRequest(QNetworkAccessManager::Operation operation,
                                                    const QNetworkRequest &request,
                                                    QIODevice *outgoingData)
{
    if (mode == Standard)
        return QNetworkAccessManager::createRequest(operation, request, outgoingData);

    if (request.url().scheme() != "http" &&
        request.url().scheme() != "https")
        return QNetworkAccessManager::createRequest(operation, request, outgoingData);

    switch (operation)
    {
        case GetOperation: return new KENetworkReply(request); break;
        case PostOperation: return new KENetworkReply(request, outgoingData); break;
        default: QNetworkAccessManager::createRequest(operation, request, outgoingData);
    }

    return QNetworkAccessManager::createRequest(operation, request, outgoingData);
}

