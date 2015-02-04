#include "kehtmldocument.h"

KEHtmlDocument::KEHtmlDocument(QAxObject* ie, QObject *parent)
    : QObject(parent)
{
    axDoc = ie->querySubObject("Document");
}

KEHtmlDocument::~KEHtmlDocument()
{
    // delete axDoc;
}

QString KEHtmlDocument::bodyText()
{
    return body()->property("innerText").toString();
}

QString KEHtmlDocument::bodyHtml()
{
    return body()->property("innerHTML").toString();
}

QAxObject* KEHtmlDocument::body()
{
    if (!axBody)
        axBody = axDoc->querySubObject("body");

    return axBody;
}

/*QString KEHtmlDocument::header()
{
    doc->querySubObject("head");
}*/

