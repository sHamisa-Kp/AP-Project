/********************************************************************************
** Form generated from reading UI file 'pacmanwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACMANWINDOW_H
#define UI_PACMANWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pacmanwindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QLCDNumber *highScroreLcdNumber_2;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLCDNumber *livesLcdNumber_2;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_8;
    QLCDNumber *timeLcdNumber_2;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_9;
    QLabel *scoreLabel;
    QLCDNumber *scoreLcdNumber_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QLCDNumber *levelLcdNumber_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pauseButton;
    QPushButton *controlsButton;
    QPushButton *exitButton;

    void setupUi(QDialog *Pacmanwindow)
    {
        if (Pacmanwindow->objectName().isEmpty())
            Pacmanwindow->setObjectName(QStringLiteral("Pacmanwindow"));
        Pacmanwindow->resize(650, 510);
        Pacmanwindow->setMinimumSize(QSize(650, 510));
        Pacmanwindow->setMaximumSize(QSize(650, 510));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Pacmanwindow->setPalette(palette);
        Pacmanwindow->setWindowTitle(QStringLiteral(""));
        Pacmanwindow->setAutoFillBackground(true);
        Pacmanwindow->setSizeGripEnabled(false);
        Pacmanwindow->setModal(false);
        layoutWidget = new QWidget(Pacmanwindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(500, 10, 141, 81));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_6->setPalette(palette1);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        label_6->setFont(font);
        label_6->setTextFormat(Qt::AutoText);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_6);

        highScroreLcdNumber_2 = new QLCDNumber(layoutWidget);
        highScroreLcdNumber_2->setObjectName(QStringLiteral("highScroreLcdNumber_2"));
        highScroreLcdNumber_2->setFrameShape(QFrame::NoFrame);
        highScroreLcdNumber_2->setFrameShadow(QFrame::Plain);
        highScroreLcdNumber_2->setDigitCount(5);
        highScroreLcdNumber_2->setSegmentStyle(QLCDNumber::Outline);

        verticalLayout_6->addWidget(highScroreLcdNumber_2);

        graphicsView = new QGraphicsView(Pacmanwindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(50, 0, 450, 480));
        graphicsView->setMinimumSize(QSize(450, 480));
        graphicsView->setMaximumSize(QSize(640, 480));
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setBackgroundBrush(brush1);
        layoutWidget_3 = new QWidget(Pacmanwindow);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(500, 170, 141, 81));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_7->setPalette(palette2);
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_7);

        livesLcdNumber_2 = new QLCDNumber(layoutWidget_3);
        livesLcdNumber_2->setObjectName(QStringLiteral("livesLcdNumber_2"));
        livesLcdNumber_2->setFrameShape(QFrame::NoFrame);
        livesLcdNumber_2->setSegmentStyle(QLCDNumber::Outline);

        verticalLayout_7->addWidget(livesLcdNumber_2);

        layoutWidget_4 = new QWidget(Pacmanwindow);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(500, 330, 141, 81));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_8->setPalette(palette3);
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_8);

        timeLcdNumber_2 = new QLCDNumber(layoutWidget_4);
        timeLcdNumber_2->setObjectName(QStringLiteral("timeLcdNumber_2"));
        timeLcdNumber_2->setFrameShape(QFrame::NoFrame);
        timeLcdNumber_2->setDigitCount(5);
        timeLcdNumber_2->setSegmentStyle(QLCDNumber::Outline);

        verticalLayout_8->addWidget(timeLcdNumber_2);

        layoutWidget_2 = new QWidget(Pacmanwindow);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(500, 90, 141, 81));
        verticalLayout_9 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        scoreLabel = new QLabel(layoutWidget_2);
        scoreLabel->setObjectName(QStringLiteral("scoreLabel"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        scoreLabel->setPalette(palette4);
        scoreLabel->setFont(font1);
        scoreLabel->setLineWidth(0);
        scoreLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(scoreLabel);

        scoreLcdNumber_2 = new QLCDNumber(layoutWidget_2);
        scoreLcdNumber_2->setObjectName(QStringLiteral("scoreLcdNumber_2"));
        scoreLcdNumber_2->setFrameShape(QFrame::NoFrame);
        scoreLcdNumber_2->setSmallDecimalPoint(false);
        scoreLcdNumber_2->setDigitCount(5);
        scoreLcdNumber_2->setSegmentStyle(QLCDNumber::Outline);

        verticalLayout_9->addWidget(scoreLcdNumber_2);

        label = new QLabel(Pacmanwindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 41, 71));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/pacright2.png")));
        label_2 = new QLabel(Pacmanwindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 110, 51, 61));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/ghostrightblue2.png")));
        label_3 = new QLabel(Pacmanwindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 220, 59, 61));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/ghostdownred1.png")));
        label_4 = new QLabel(Pacmanwindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 330, 59, 61));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/ghostuporange1.png")));
        label_5 = new QLabel(Pacmanwindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 430, 59, 61));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/ghostleft2.png")));
        layoutWidget1 = new QWidget(Pacmanwindow);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(500, 250, 141, 81));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_10->setPalette(palette5);
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_10);

        levelLcdNumber_2 = new QLCDNumber(layoutWidget1);
        levelLcdNumber_2->setObjectName(QStringLiteral("levelLcdNumber_2"));
        levelLcdNumber_2->setFrameShape(QFrame::NoFrame);
        levelLcdNumber_2->setSegmentStyle(QLCDNumber::Outline);

        verticalLayout->addWidget(levelLcdNumber_2);

        widget = new QWidget(Pacmanwindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(520, 410, 121, 109));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pauseButton = new QPushButton(widget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        QPalette palette6;
        QBrush brush3(QColor(213, 213, 213, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        pauseButton->setPalette(palette6);
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        pauseButton->setFont(font2);
        pauseButton->setAutoDefault(false);
        pauseButton->setFlat(false);

        verticalLayout_2->addWidget(pauseButton);

        controlsButton = new QPushButton(widget);
        controlsButton->setObjectName(QStringLiteral("controlsButton"));
        controlsButton->setEnabled(true);
        controlsButton->setFont(font2);
        controlsButton->setAutoDefault(false);

        verticalLayout_2->addWidget(controlsButton);

        exitButton = new QPushButton(widget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setSizeIncrement(QSize(100, 0));
        exitButton->setFont(font2);
        exitButton->setAutoDefault(false);
        exitButton->setFlat(false);

        verticalLayout_2->addWidget(exitButton);


        retranslateUi(Pacmanwindow);

        pauseButton->setDefault(false);
        controlsButton->setDefault(false);
        exitButton->setDefault(false);


        QMetaObject::connectSlotsByName(Pacmanwindow);
    } // setupUi

    void retranslateUi(QDialog *Pacmanwindow)
    {
        label_6->setText(QApplication::translate("Pacmanwindow", "HighScore", nullptr));
        label_7->setText(QApplication::translate("Pacmanwindow", "Lives", nullptr));
        label_8->setText(QApplication::translate("Pacmanwindow", "Time", nullptr));
        scoreLabel->setText(QApplication::translate("Pacmanwindow", "Score", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_10->setText(QApplication::translate("Pacmanwindow", "Level", nullptr));
        pauseButton->setText(QApplication::translate("Pacmanwindow", "Pause (P)", nullptr));
        controlsButton->setText(QApplication::translate("Pacmanwindow", "Controls (C)", nullptr));
        exitButton->setText(QApplication::translate("Pacmanwindow", "Exit (ESC)", nullptr));
#ifndef QT_NO_SHORTCUT
        exitButton->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        Q_UNUSED(Pacmanwindow);
    } // retranslateUi

};

namespace Ui {
    class Pacmanwindow: public Ui_Pacmanwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACMANWINDOW_H
