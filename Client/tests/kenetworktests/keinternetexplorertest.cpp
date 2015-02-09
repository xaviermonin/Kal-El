#include "keinternetexplorertest.h"

KEInternetExplorerTest::KEInternetExplorerTest()
{
}

void KEInternetExplorerTest::initTestCase()
{
    ie = new KEInternetExplorer(false);
}

void KEInternetExplorerTest::cleanupTestCase()
{
    delete ie;
}

void KEInternetExplorerTest::get()
{
    QSignalSpy spy(ie, SIGNAL(navigateComplete(QString)));
    QVERIFY(spy.isValid());

    ie->navigate("http://www.perdu.com");

    while (spy.count() == 0)
        QTest::qWait(100);

    QByteArray content = ie->content();

    QVERIFY(content.contains("<title>Vous Etes Perdu ?</title>"));
}

void KEInternetExplorerTest::post()
{
    QSignalSpy spy(ie, SIGNAL(navigateComplete(QString)));
    QVERIFY(spy.isValid());

    ie->navigate("http://www.htmlcodetutorial.com/cgi-bin/mycgi.pl",
                 "Content-Type: application/x-www-form-urlencoded",
                 "kepropertyname=kepropertyvalue");

    while (spy.count() == 0)
        QTest::qWait(100);

    QString contentText = ie->content();

    QVERIFY(contentText.contains("kepropertyname"));
}
