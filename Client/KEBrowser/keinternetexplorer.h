#ifndef KEBROWSER_H
#define KEBROWSER_H

#include <QObject>
#include <QString>

class QAxObject;
class QNetworkRequest;
class QVariant;

class KEInternetExplorer : public QObject
{
    Q_OBJECT
public:
    explicit KEInternetExplorer(bool visible, QObject* parent = 0);
    virtual ~KEInternetExplorer();

    void get(const QNetworkRequest& request);
    void post(const QString &url);

    void close();

private:
    void navigate(const QString& url, const QString &headers = "", const QString &postData = "", const QString &targetFrameName = "", int flags = 0);

    void setSilence(bool);
    bool silence() const;

    void setVisible(bool);
    bool visible() const;

private:
    QAxObject* ie;
};

#endif // KEBROWSER_H
