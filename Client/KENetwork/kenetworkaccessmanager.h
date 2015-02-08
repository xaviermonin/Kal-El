#ifndef KENETWORKACCESSMANAGER_H
#define KENETWORKACCESSMANAGER_H

#include <QNetworkAccessManager>

class KENetworkAccessManager : public QNetworkAccessManager
{
    Q_OBJECT

public:

    enum BackendMode { Standard, InternetExplorer };

    explicit KENetworkAccessManager(BackendMode mode = Standard, QObject* parent = 0);
    ~KENetworkAccessManager();

    void setBackEndMode(BackendMode mode);
    BackendMode backendMode() const;

protected:
    QNetworkReply* createRequest(Operation op, const QNetworkRequest &request, QIODevice *outgoingData);

private:
    BackendMode mode;
};

#endif // KENETWORKACCESSMANAGER_H
