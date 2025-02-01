#include "web_page.h"
#include <QWebEngineView>
#include <QVBoxLayout>
#include <QUrl>

web_page::web_page(QWidget *parent) : QWidget(parent) {
    QWebEngineView *view = new QWebEngineView();
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    setLayout(layout);
    connect(view, &QWebEngineView::loadFinished, this, [](bool success) {
        if (!success) {
            qDebug() << "Failed to load the webpage.";
        }
    });
}

// Function to load a URL based on the search query
void web_page::loadUrl(const QString &url) {
    QWebEngineView *view = findChild<QWebEngineView*>();  // Find the web engine view
    if (view) {
        view->load(QUrl(url));  // Load the URL passed to the function
    }
}
