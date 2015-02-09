#ifndef KENETWORKACCESSMANAGERTEST
#define KENETWORKACCESSMANAGERTEST

#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QSignalSpy>
#include <QBuffer>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "kenetworkaccessmanager.h"

class KENetworkAccessManagerTest : public QObject
{
    Q_OBJECT

public:
    KENetworkAccessManagerTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void get();
    void post();

private:

};

#endif // KENETWORKACCESSMANAGERTEST

