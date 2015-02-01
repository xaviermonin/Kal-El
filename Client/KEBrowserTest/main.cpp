#include <QCoreApplication>
#include "../KEBrowser/keinternetexplorer.h"
#include <QThread>
#include <QNetworkRequest>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    KEInternetExplorer browser(true);

    QNetworkRequest request;
    request.setRawHeader("Content", "pomme de terre");
    request.setHeader(QNetworkRequest::ContentLengthHeader, 10);
    request.setUrl(QUrl("http://blog.xavier-monin.net"));

    browser.get(request);

    return a.exec();
}
