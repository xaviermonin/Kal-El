#ifndef KENETWORKREPLYTEST
#define KENETWORKREPLYTEST

#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QNetworkRequest>
#include <QSignalSpy>
#include <QBuffer>
#include "kenetworkreply.h"

class KENetworkReplyTest : public QObject
{
    Q_OBJECT

public:
    KENetworkReplyTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void get();
    void post();

private:

};

#endif // KENETWORKREPLYTEST
