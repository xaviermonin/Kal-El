#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "keinternetexplorer.h"

class KEInternetExplorerTest : public QObject
{
    Q_OBJECT

public:
    KEInternetExplorerTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void get_data();
    void get();
};

KEInternetExplorerTest::KEInternetExplorerTest()
{
}

void KEInternetExplorerTest::initTestCase()
{
}

void KEInternetExplorerTest::cleanupTestCase()
{
}

void KEInternetExplorerTest::get_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("0") << QString();
}

void KEInternetExplorerTest::get()
{
    QFETCH(QString, data);
    QVERIFY2(true, "Failure");
}

QTEST_MAIN(KEInternetExplorerTest)

#include "tst_keinternetexplorertest.moc"
