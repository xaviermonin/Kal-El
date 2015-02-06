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
    void get();

private:
    KEInternetExplorer* ie;
};

KEInternetExplorerTest::KEInternetExplorerTest()
{
}

void KEInternetExplorerTest::initTestCase()
{
    ie = new KEInternetExplorer(false);
}

void KEInternetExplorerTest::cleanupTestCase()
{
    if (ie != NULL)
    {
        delete ie;
        ie = NULL;
    }
}

void KEInternetExplorerTest::get()
{
    QSignalSpy spy(ie, SIGNAL(navigateComplete(QString)));

    ie->navigate("http://www.perdu.com/");

    while (spy.count() == 0)
        QTest::qWait(100);

    QString contentHtml = ie->contentHtml();
    QString contentText = ie->contentText();

    QVERIFY(contentHtml.contains("<title>Vous Etes Perdu ?</title>"));
    QVERIFY(contentText.contains("Perdu sur l'Internet ?\r\n"));
}

QTEST_MAIN(KEInternetExplorerTest)

#include "tst_keinternetexplorertest.moc"
