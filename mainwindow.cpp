#include "mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include "color.h"
#include <QLineEdit>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QKeyEvent>
#include <QImage>
#include <QPixmap>
#include <QIcon>
#include <QEvent>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), option(0)
{
    QString text_color = Main_theme::White.name();
    QString background_color = Main_theme::Maingreen.name();
    QString icon_background = Main_theme::Lightgreen.name();
    QString icon_hover = Main_theme::GreenAccent.name();


    // Set the background color
    this->setStyleSheet("background-color: " + background_color + ";");

    // Create the main widget and layout
    QWidget* mainWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(mainWidget);

    // Initialize the struct for holding UI elements
    Element asset;

    // Create a label (first element in the struct array)
    asset.elements[0] = new QLabel("Emeralytics", this);
    QLabel* label1 = qobject_cast<QLabel*>(asset.elements[0]);
    if (label1) {
        label1->setAlignment(Qt::AlignCenter);
        label1->setStyleSheet("color: " + text_color + "; font-size: 70px; font-family: 'Roboto', sans-serif;");
        label1->setGeometry(600 ,300 , 700, 200);

    }

    asset.elements[3] = new QLabel(this);
    QLabel* github_icon = new QLabel(this);
    if(github_icon){
        // Create a QLabel for the image
        github_icon->setPixmap(QPixmap("/home/wishayut/Desktop/C&Cpp/114pj/114pj/icon/github_icon.png"));
        github_icon->setScaledContents(true);
        github_icon->setStyleSheet(
            "QLabel {"
            "  background: " + icon_background + ";"
                                "  border-radius: 20px;"
                          "}"
            "QLabel:hover {"
            "  background: " + icon_hover + ";"
                           "}"
            );
        github_icon->setGeometry(720, 600, 80, 80);
        github_icon->setAttribute(Qt::WA_Hover);
        github_icon->setCursor(Qt::PointingHandCursor);

    }


    asset.elements[4] = new QLabel(this);
    QLabel* garuda_icon = new QLabel(this);
    if(garuda_icon){
        // Create a QLabel for the image
        garuda_icon->setPixmap(QPixmap("/home/wishayut/Desktop/C&Cpp/114pj/114pj/icon/garuda_icon.png"));
        garuda_icon->setScaledContents(true);
        garuda_icon->setStyleSheet(
            "QLabel {"
            "  background: " + icon_background + ";"
                                "  border-radius: 20px;"
                                "}"
                                "QLabel:hover {"
                                "  background: " + icon_hover + ";"
                           "}"
            );
        garuda_icon->setGeometry(850, 600, 80, 80);
        garuda_icon->setAttribute(Qt::WA_Hover);
        github_icon->setCursor(Qt::PointingHandCursor);

    }

    asset.elements[5] = new QLabel(this);
    QLabel* qt_icon = new QLabel(this);
    if(qt_icon){
        // Create a QLabel for the image
        qt_icon->setPixmap(QPixmap("/home/wishayut/Desktop/C&Cpp/114pj/114pj/icon/Qt_logo.png"));
        qt_icon->setScaledContents(true);
        qt_icon->setStyleSheet(
            "QLabel {"
            "  background: " + icon_background + ";"
                                "  border-radius: 20px;"
                                "}"
                                "QLabel:hover {"
                                "  background: " + icon_hover + ";"
                           "}"
            );
        qt_icon->setGeometry(970, 600, 80, 80);
        qt_icon->setAttribute(Qt::WA_Hover);
        qt_icon->setCursor(Qt::PointingHandCursor);

    }

    asset.elements[6] = new QLabel(this);
    QLabel* canvas_icon = new QLabel(this);
    if(canvas_icon){
        // Create a QLabel for the image
        canvas_icon->setPixmap(QPixmap("/home/wishayut/Desktop/C&Cpp/114pj/114pj/icon/canva-logo.png"));
        canvas_icon->setScaledContents(true);
        canvas_icon->setStyleSheet(
            "QLabel {"
            "  background: " + icon_background + ";"
                                "  border-radius: 20px;"
                                "}"
                                "QLabel:hover {"
                                "  background: " + icon_hover + ";"
                           "}"
            );
        canvas_icon->setGeometry(1090, 600, 80, 80);

    }
    // Create a search bar
    asset.elements[2] = new QLineEdit(this);
    search_bar = qobject_cast<QLineEdit*>(asset.elements[2]);
    if (search_bar) {
        search_bar->setPlaceholderText("Search Emeralytics or type a URL");
        search_bar->setStyleSheet("font-size: 16px; padding: 5px 0px 0px 20px; border-radius: 20px; background:" + text_color + ";");
        search_bar->setGeometry(600, 500, 700, 40);

        // Connect the Enter key event to the onSearch slot
        connect(search_bar, &QLineEdit::returnPressed, this, &MainWindow::onSearch);
    }

    // Set the layout to the main widget and set it as the central widget
    mainWidget->setLayout(layout);


    // Initialize the network manager
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::onReplyFinished);
}

MainWindow::~MainWindow()
{
    // Cleanup
}

// Slot for search button/Enter key action
void MainWindow::onSearch()
{
    QString searchQuery = search_bar->text();  // Get the search query from the search bar
    emit searchPressed(searchQuery);  // Emit search query when Enter is pressed
}

// Slot for handling the network reply
void MainWindow::onReplyFinished(QNetworkReply *reply)
{
    if (reply->error()) {
        qDebug() << "Error: " << reply->errorString();
    } else {
        // Handle the data from the reply (printing the result for now)
        QByteArray data = reply->readAll();
        qDebug() << "Search results: " << data;

        // Process the data and display it in your UI (as needed)
    }

    reply->deleteLater();  // Clean up the reply object
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        // Debugging line
        qDebug() << "Enter key pressed!";

        // Set option to 1 when Enter key is pressed
        option = 1;
        emit searchPressed(search_bar->text());  // Emit the signal with the search query
    }
}



