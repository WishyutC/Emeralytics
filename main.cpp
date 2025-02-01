#include "mainwindow.h"
#include "web_page.h"
#include <QApplication>
#include <QUrl>
#include <QIcon>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon("/home/wishayut/Desktop/C&Cpp/114pj/114pj/emerald.ico"));

    MainWindow main_w;
    main_w.setWindowTitle("Emeralytics");

    web_page page;  // Create the web_page instance

    // Set the main window size
    main_w.setFixedSize(1920, 1080);
    main_w.show();



    // Connect the searchPressed signal from MainWindow to load the page in web_page
    QObject::connect(&main_w, &MainWindow::searchPressed, [&page](const QString &query) {
        QString url = "https://duckduckgo.com/?q=" + query;  // Construct URL with query
        page.loadUrl(url);  // Load the URL with the search query
        page.resize(1024, 800);
        page.show();  // Show the web page
    });

    return a.exec();
}
