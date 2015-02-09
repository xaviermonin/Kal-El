#ifndef TST_KEINTERNETXPLORERTEST_H
#define TST_KEINTERNETXPLORERTEST_H

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
    void get_data();

    void post();
    void post_data();

private:
    KEInternetExplorer* ie;
};

#endif // TST_KEINTERNETXPLORERTEST_H
