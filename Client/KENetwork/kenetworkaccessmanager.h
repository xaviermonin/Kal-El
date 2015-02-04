#ifndef KENETWORKACCESSMANAGER_H
#define KENETWORKACCESSMANAGER_H

#include <QNetworkAccessManager>

class KENetworkAccessManager : public QNetworkAccessManager
{
public:
    KENetworkAccessManager();
    virtual ~KENetworkAccessManager();
};

#endif // KENETWORKACCESSMANAGER_H
