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
    void post();

private:

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

void KEInternetExplorerTest::get()
{
    KEInternetExplorer ie(false);

    QSignalSpy spy(&ie, SIGNAL(navigateComplete(QString)));

    ie.navigate("http://www.perdu.com/");

    while (spy.count() == 0)
        QTest::qWait(100);

    QString contentHtml = ie.contentHtml();
    QString contentText = ie.contentText();

    QVERIFY(contentHtml.contains("<title>Vous Etes Perdu ?</title>"));
    QVERIFY(contentText.contains("Perdu sur l'Internet ?\r\n"));
}

void KEInternetExplorerTest::post()
{
    KEInternetExplorer ie(false);

    QSignalSpy spy(&ie, SIGNAL(navigateComplete(QString)));

    ie.navigate("http://www.htmlcodetutorial.com/cgi-bin/mycgi.pl",
                 "Content-Type: application/x-www-form-urlencoded",
                 "kepropertyname=kepropertyvalue");

    while (spy.count() == 0)
        QTest::qWait(100);

    QString contentText = ie.contentText();

    QVERIFY(contentText.contains("kepropertyname"));
}

QTEST_MAIN(KEInternetExplorerTest)

#include "tst_keinternetexplorertest.moc"
