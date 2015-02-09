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

void KEInternetExplorerTest::get_data()
{
    QTest::addColumn<QString>("url");
    QTest::addColumn<QByteArray>("result");

    QTest::newRow("http html") << "http://www.perdu.com"
                               << QByteArray("<title>Vous Etes Perdu ?</title>");

    QTest::newRow("http old html") << "http://www.kli.org/tlh/phrases.html"
                               << QByteArray("<TT class=tlh>tlhIngan maH!</TT>");

    QTest::newRow("https raw") << "https://raw.githubusercontent.com/xaviermonin/Kal-El/master/LICENSE"
                               << QByteArray("Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>");

    QTest::newRow("https redirect raw") << "https://raw.githubusercontent.com/xaviermonin/Kal-El/master/LICENSE"
                               << QByteArray("Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>");
}

void KEInternetExplorerTest::get()
{
    QFETCH(QString, url);
    QFETCH(QByteArray, result);

    QSignalSpy spy(ie, SIGNAL(navigateComplete(QString)));
    QVERIFY(spy.isValid());

    ie->navigate(url);

    while (spy.count() == 0)
        QTest::qWait(100);

    QByteArray content = ie->content();

    QVERIFY(content.contains(result));
}

void KEInternetExplorerTest::post_data()
{

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
