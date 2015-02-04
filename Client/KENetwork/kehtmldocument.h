#ifndef KEHTMLDOCUMENT_H
#define KEHTMLDOCUMENT_H

#include <QAxObject>

class KEHtmlDocument : public QObject
{
    Q_OBJECT
public:
    KEHtmlDocument(QAxObject* ie, QObject *parent = 0);
    ~KEHtmlDocument();

    // QString header();

    QString bodyText();
    QString bodyHtml();

signals:

public slots:
private:
    QAxObject* body();
private:
    QAxObject* axDoc = NULL;
    QAxObject* axBody = NULL;
};

#endif // KEHTMLDOCUMENT_H
