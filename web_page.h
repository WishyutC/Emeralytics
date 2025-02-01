#ifndef WEB_PAGE_H
#define WEB_PAGE_H

#include <QWidget>
#include <QWebEngineView>
#include <QVBoxLayout>

class web_page : public QWidget {
    Q_OBJECT

public:
    explicit web_page(QWidget *parent = nullptr);

    // Method to load a URL dynamically
    void loadUrl(const QString &url);

private:
    QWebEngineView *webView;   // The QWebEngineView to display the web page
    QVBoxLayout *layout;       // Layout for the web page widget
};

#endif // WEB_PAGE_H
