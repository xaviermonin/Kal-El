#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QSignalSpy>
#include <QBuffer>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "kenetworkaccessmanager.h"

class KENetworkAccessManagerTest : public QObject
{
    Q_OBJECT

public:
    KENetworkAccessManagerTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void get();
    void post();

private:

};

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
    KENetworkAccessManager manager;
    QNetworkRequest request(QUrl("http://www.perdu.com"));

    QNetworkReply* reply = manager.get(request);

    QSignalSpy spy(reply, SIGNAL(finished()));
    QVERIFY(spy.isValid());

    while(spy.count() == 0)
        QTest::qWait(100);

    QString content = reply->readAll();
    QVERIFY(content.contains("Perdu sur l'Internet ?\r\n"));

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

    QNetworkAccessManager manager;
    QNetworkReply* reply = manager.post(request, &buffer);

    QSignalSpy spy(reply, SIGNAL(finished()));
    QVERIFY(spy.isValid());

    while(spy.count() == 0)
        QTest::qWait(100);

    QString content = reply->readAll();
    QVERIFY(content.contains("kepropertyname"));
}

QTEST_MAIN(KENetworkAccessManagerTest)

#include "tst_kenetworkaccessmanagertest.moc"
