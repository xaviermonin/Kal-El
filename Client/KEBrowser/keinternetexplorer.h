#ifndef KEBROWSER_H
#define KEBROWSER_H

#include <QObject>
#include <QString>

class QAxObject;
class QNetworkRequest;
class QVariant;
struct IDispatch;

class KEInternetExplorer : public QObject
{
    Q_OBJECT
public:
    explicit KEInternetExplorer(bool visible, QObject* parent = 0);
    virtual ~KEInternetExplorer();

    void get(const QNetworkRequest& request);
    void post(const QNetworkRequest& request, QByteArray postData);

    void close();

    void setSilence(bool);
    bool silence() const;

    void setVisible(bool);
    bool visible() const;

    void navigate(const QString& url, const QString &headers = "", const QByteArray &postData = "", const QString &targetFrameName = "", int flags = 0);

signals:
    void DocumentComplete(IDispatch*, QVariant& url);

protected slots:
    virtual void DocumentCompleteInternal(IDispatch*, QVariant& url);

private:
    void setConnections();
    QString headerFromNetworkRequest(const QNetworkRequest&) const;

private:
    QAxObject* ie;
};

#endif // KEBROWSER_H
