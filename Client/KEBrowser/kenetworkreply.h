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

protected slots:
    void documentComplete();

private:
    KEInternetExplorer* ie;
};

#endif // KENETWORKREPLY_H
