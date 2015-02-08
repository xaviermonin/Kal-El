#include <QString>
#include <QtTest>
#include <QCoreApplication>
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

}

void KENetworkReplyTest::post()
{

}

#include "tst_kenetworkreplytest.moc"
