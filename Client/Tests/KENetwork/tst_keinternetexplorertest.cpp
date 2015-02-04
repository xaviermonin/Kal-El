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
    KEInternetExplorer* ie = NULL;
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
    QSignalSpy spy(ie, SIGNAL(documentComplete(IDispatch*,QVariant&)));

    ie->navigate("http://www.perdu.com/");

    while (spy.count() == 0)
        QTest::qWait(20);

    KEHtmlDocument* doc = ie->HtmlDocument();
    QString content = doc->bodyHtml();
    QVERIFY(content.contains("<h1>Perdu sur l'Internet ?</h1>"));
}

QTEST_MAIN(KEInternetExplorerTest)

#include "tst_keinternetexplorertest.moc"
