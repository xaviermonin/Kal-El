#include <QtTest>
#include <QCoreApplication>
#include "tst_keinternetexplorertest.cpp"
#include "tst_kenetworkreplytest.cpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setAttribute(Qt::AA_Use96Dpi, true);
    QTEST_DISABLE_KEYPAD_NAVIGATION

    KEInternetExplorerTest tcInternetExplorer;
    KENetworkReplyTest tcNetworkReply;

    QTest::qExec(&tcInternetExplorer, argc, argv);
    QTest::qExec(&tcNetworkReply, argc, argv);
}
