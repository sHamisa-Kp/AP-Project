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

QT_BEGIN_NAMESPACE

class Ui_Pacmanwindow
{
public:
    QGraphicsView *graphicsView;
    QLabel *label_8;
    QLCDNumber *livesLcdNumber_2;
    QLabel *label_7;
    QLCDNumber *scoreLcdNumber_2;
    QLabel *scoreLabel;
    QLCDNumber *timeLcdNumber_2;

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
        graphicsView = new QGraphicsView(Pacmanwindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(180, 20, 450, 480));
        graphicsView->setMinimumSize(QSize(450, 480));
        graphicsView->setMaximumSize(QSize(640, 480));
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setBackgroundBrush(brush1);
        label_8 = new QLabel(Pacmanwindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 340, 139, 37));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_8->setPalette(palette1);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);
        livesLcdNumber_2 = new QLCDNumber(Pacmanwindow);
        livesLcdNumber_2->setObjectName(QStringLiteral("livesLcdNumber_2"));
        livesLcdNumber_2->setGeometry(QRect(10, 240, 139, 36));
        livesLcdNumber_2->setFrameShape(QFrame::NoFrame);
        livesLcdNumber_2->setSegmentStyle(QLCDNumber::Outline);
        label_7 = new QLabel(Pacmanwindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 180, 139, 79));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_7->setPalette(palette2);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);
        scoreLcdNumber_2 = new QLCDNumber(Pacmanwindow);
        scoreLcdNumber_2->setObjectName(QStringLiteral("scoreLcdNumber_2"));
        scoreLcdNumber_2->setGeometry(QRect(10, 90, 139, 36));
        scoreLcdNumber_2->setFrameShape(QFrame::NoFrame);
        scoreLcdNumber_2->setSmallDecimalPoint(false);
        scoreLcdNumber_2->setDigitCount(5);
        scoreLcdNumber_2->setSegmentStyle(QLCDNumber::Outline);
        scoreLabel = new QLabel(Pacmanwindow);
        scoreLabel->setObjectName(QStringLiteral("scoreLabel"));
        scoreLabel->setGeometry(QRect(0, 30, 139, 79));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        scoreLabel->setPalette(palette3);
        scoreLabel->setFont(font);
        scoreLabel->setLineWidth(0);
        scoreLabel->setAlignment(Qt::AlignCenter);
        timeLcdNumber_2 = new QLCDNumber(Pacmanwindow);
        timeLcdNumber_2->setObjectName(QStringLiteral("timeLcdNumber_2"));
        timeLcdNumber_2->setGeometry(QRect(10, 380, 139, 36));
        timeLcdNumber_2->setFrameShape(QFrame::NoFrame);
        timeLcdNumber_2->setSmallDecimalPoint(false);
        timeLcdNumber_2->setDigitCount(5);
        timeLcdNumber_2->setSegmentStyle(QLCDNumber::Outline);

        retranslateUi(Pacmanwindow);

        QMetaObject::connectSlotsByName(Pacmanwindow);
    } // setupUi

    void retranslateUi(QDialog *Pacmanwindow)
    {
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("Pacmanwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("Pacmanwindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Time</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("Pacmanwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("Pacmanwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; color:#ffffff;\">Lives</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        scoreLabel->setToolTip(QApplication::translate("Pacmanwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">shamisa</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        scoreLabel->setText(QApplication::translate("Pacmanwindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; color:#ffffff;\">Score</span></p></body></html>", nullptr));
        Q_UNUSED(Pacmanwindow);
    } // retranslateUi

};

namespace Ui {
    class Pacmanwindow: public Ui_Pacmanwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACMANWINDOW_H
