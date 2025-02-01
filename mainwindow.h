#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include "web_page.h"
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event) override;

    int option;

private:
    QWidget *mainWidget;
    QNetworkAccessManager *manager;
    QLineEdit *search_bar;

    struct Element {
        QWidget* elements[50];
    };

    Element asset;
    web_page *page;

signals:
    void searchPressed(const QString &query);  // Signal to handle the search query

private slots:
    void onSearch();  // Slot for the search action
    void onReplyFinished(QNetworkReply *reply);  // Slot for handling the reply from the API

};

#endif // MAINWINDOW_H
