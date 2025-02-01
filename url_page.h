// url_page.h
#ifndef URL_PAGE_H
#define URL_PAGE_H

#include <QWidget>
#include <QWebEngineView>  // If using Qt WebEngine to load web pages

class url_page : public QWidget
{
    Q_OBJECT

public:
    explicit url_page(QWidget *parent = nullptr);
    explicit url_page(const QString &url, QWidget *parent = nullptr);  // Add a constructor that takes a URL
    void loadUrl(const QString &url);

private:
    QWebEngineView *webView;
};

#endif // URL_PAGE_H
