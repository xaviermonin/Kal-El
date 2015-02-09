#include "testrunner.h"
#include "keinternetexplorertest.h"
#include "kenetworkaccessmanagertest.h"
#include "kenetworkreplytest.h"

#include <QDebug>

int main(int arc, char* argv[]) {
    TestRunner testRunner(arc, argv);
    testRunner.addTest(new KEInternetExplorerTest());
    testRunner.addTest(new KENetworkReplyTest());
    testRunner.addTest(new KENetworkAccessManagerTest());

    qDebug() << "Overall result: " << (testRunner.runTests()?"PASS":"FAIL");

    return 0;
}
