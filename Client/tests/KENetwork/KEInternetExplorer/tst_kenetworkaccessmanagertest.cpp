#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QSignalSpy>
#include <QBuffer>
#include <QNetworkRequest>
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

    manager.get(request);
}

void KENetworkAccessManagerTest::post()
{

}

#include "tst_kenetworkaccessmanagertest.moc"
