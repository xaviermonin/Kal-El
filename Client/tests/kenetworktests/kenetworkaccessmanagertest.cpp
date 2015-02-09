#include "kenetworkaccessmanagertest.h"

KENetworkAccessManagerTest::KENetworkAccessManagerTest()
{
}

void KENetworkAccessManagerTest::initTestCase()
{

}

void KENetworkAccessManagerTest::cleanupTestCase()
{
}

void KENetworkAccessManagerTest::get()
{
    KENetworkAccessManager manager(KENetworkAccessManager::InternetExplorer);
    QNetworkRequest request(QUrl("http://www.perdu.com"));

    QNetworkReply* reply = manager.get(request);

    QSignalSpy spy(reply, SIGNAL(finished()));
    QVERIFY(spy.isValid());

    while(spy.count() == 0)
        QTest::qWait(100);

    QString content = reply->readAll();
    QVERIFY(content.contains("<h1>Perdu sur l'Internet ?</h1>"));

    delete reply;
}

void KENetworkAccessManagerTest::post()
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://www.htmlcodetutorial.com/cgi-bin/mycgi.pl"));
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      "application/x-www-form-urlencoded");

    QByteArray header = QString("kepropertyname=kepropertyvalue").toLatin1();
    QBuffer buffer;
    buffer.setBuffer(&header);

    KENetworkAccessManager manager(KENetworkAccessManager::InternetExplorer);
    QNetworkReply* reply = manager.post(request, &buffer);

    QSignalSpy spy(reply, SIGNAL(finished()));
    QVERIFY(spy.isValid());

    while(spy.count() == 0)
        QTest::qWait(100);

    QString content = reply->readAll();
    QVERIFY(content.contains("kepropertyname"));
}
