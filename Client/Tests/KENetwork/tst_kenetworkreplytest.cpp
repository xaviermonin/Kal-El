#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QNetworkRequest>
#include <QSignalSpy>
#include <QBuffer>
#include "kenetworkreply.h"

class KENetworkReplyTest : public QObject
{
    Q_OBJECT

public:
    KENetworkReplyTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void get();
    void post();

private:

};

KENetworkReplyTest::KENetworkReplyTest()
{
}

void KENetworkReplyTest::initTestCase()
{

}

void KENetworkReplyTest::cleanupTestCase()
{
}

void KENetworkReplyTest::get()
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://www.perdu.com"));

    KENetworkReply networkReply(request);

    while(!networkReply.isReadable())
          QTest::qWait(100);

    QString content = networkReply.readAll();

    QVERIFY(content.contains("Perdu sur l'Internet ?\r\n"));
}

void KENetworkReplyTest::post()
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://www.htmlcodetutorial.com/cgi-bin/mycgi.pl"));
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      "application/x-www-form-urlencoded");

    QByteArray header = QString("kepropertyname=kepropertyvalue").toLatin1();
    QBuffer buffer;
    buffer.setBuffer(&header);

    KENetworkReply networkReply(request, &buffer);

    while(!networkReply.isReadable())
          QTest::qWait(100);

    QString content = networkReply.readAll();

    QVERIFY(content.contains("kepropertyname"));
}

#include "tst_kenetworkreplytest.moc"
