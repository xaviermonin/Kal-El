// Author: mlvjr
// Source : http://stackoverflow.com/a/12683094

#ifndef TESTRUNNER_H
#define TESTRUNNER_H

#include <QList>
#include <QTimer>
#include <QCoreApplication>
#include <QtTest>

class TestRunner: public QObject
{
    Q_OBJECT

public:
    TestRunner(int argc, char* argv[])
        : m_overallResult(0)
    {
        this->argc = argc;
        this->argv = argv;
    }

    void addTest(QObject * test) {
        test->setParent(this);
        m_tests.append(test);
    }

    bool runTests() {
        QCoreApplication app(argc, argv);
        QTimer::singleShot(0, this, SLOT(run()) );
        app.exec();

        return m_overallResult == 0;
    }
private slots:
    void run() {
        doRunTests();
        QCoreApplication::instance()->quit();
    }
private:
    void doRunTests() {
        foreach (QObject * test, m_tests) {
            m_overallResult|= QTest::qExec(test);
        }
    }

    QList<QObject *> m_tests;
    int m_overallResult;
    int argc;
    char** argv;
};

#endif // TESTRUNNER_H
