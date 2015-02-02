#include "kenetworkreply.h"
#include "keinternetexplorer.h"

KENetworkReply::KENetworkReply(const QNetworkRequest& request, QObject *parent)
    : QNetworkReply(parent)
{
    setRequest(request);

    ie = new KEInternetExplorer(false, this);

    connect(ie, SIGNAL(documentComplete(IDispatch*,QVariant&)), this, SLOT(documentComplete()));

    ie->navigate(request.url().toString());
}

KENetworkReply::~KENetworkReply()
{

}

void KENetworkReply::documentComplete()
{
    qWarning("Document complete. Read content.");
}
