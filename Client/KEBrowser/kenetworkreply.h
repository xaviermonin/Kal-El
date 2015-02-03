#ifndef KENETWORKREPLY_H
#define KENETWORKREPLY_H

#include <QNetworkReply>

class KEInternetExplorer;

class KENetworkReply : public QNetworkReply
{
    Q_OBJECT
public:
    KENetworkReply(const QNetworkRequest &request, QObject* parent = 0);
    ~KENetworkReply();

    virtual bool isSequential() const;
    virtual void abort();
    virtual qint64 bytesAvailable() const;

protected:
    qint64 readData(char *data, qint64 maxSize);

protected slots:
    void setContent();

private:
    KEInternetExplorer* ie;

    QByteArray content;
    qint64 offset;
};

#endif // KENETWORKREPLY_H
