// url_page.cpp
#include "url_page.h"
#include <QWebEngineView>  // If using Qt WebEngine to load web pages

url_page::url_page(QWidget *parent) : QWidget(parent), webView(new QWebEngineView(this))
{
    setFixedSize(1024, 800);  // Set a fixed size for the window
    webView->setGeometry(0, 0, 1024, 800);  // Set the view geometry within the widget
}

url_page::url_page(const QString &url, QWidget *parent) : QWidget(parent), webView(new QWebEngineView(this))
{
    setFixedSize(1024, 800);  // Set a fixed size for the window
    webView->setGeometry(0, 0, 1024, 800);  // Set the view geometry within the widget
    loadUrl(url);  // Load the URL directly
}

void url_page::loadUrl(const QString &url)
{
    webView->load(QUrl(url));  // Load the provided URL
}
