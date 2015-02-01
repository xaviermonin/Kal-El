#include <QCoreApplication>
#include "../KEBrowser/keinternetexplorer.h"
#include <QThread>
#include <QNetworkRequest>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    KEInternetExplorer browser(true);

    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setUrl(QUrl("http://blog.xavier-monin.net"));

    browser.post(request, QByteArray("element=truc&chose=prout"));

    return a.exec();
}
