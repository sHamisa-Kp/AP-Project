/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QPlainTextEdit *nameText;
    QRadioButton *easyButton;
    QRadioButton *mediumButton;
    QRadioButton *hardButton;
    QPushButton *startButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QStringLiteral("Options"));
        Options->setWindowModality(Qt::NonModal);
        Options->setEnabled(true);
        Options->resize(525, 450);
        Options->setMinimumSize(QSize(525, 450));
        Options->setMaximumSize(QSize(525, 450));
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
        Options->setPalette(palette);
        nameText = new QPlainTextEdit(Options);
        nameText->setObjectName(QStringLiteral("nameText"));
        nameText->setGeometry(QRect(230, 260, 81, 29));
        nameText->setFrameShape(QFrame::Panel);
        nameText->setLineWrapMode(QPlainTextEdit::NoWrap);
        nameText->setTabStopWidth(9);
        nameText->setMaximumBlockCount(9);
        easyButton = new QRadioButton(Options);
        easyButton->setObjectName(QStringLiteral("easyButton"));
        easyButton->setGeometry(QRect(110, 310, 102, 20));
        QPalette palette1;
        QBrush brush2(QColor(255, 204, 102, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        easyButton->setPalette(palette1);
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setBold(true);
        font.setWeight(75);
        easyButton->setFont(font);
        mediumButton = new QRadioButton(Options);
        mediumButton->setObjectName(QStringLiteral("mediumButton"));
        mediumButton->setGeometry(QRect(230, 310, 102, 20));
        QPalette palette2;
        QBrush brush4(QColor(128, 0, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        mediumButton->setPalette(palette2);
        mediumButton->setFont(font);
        hardButton = new QRadioButton(Options);
        hardButton->setObjectName(QStringLiteral("hardButton"));
        hardButton->setGeometry(QRect(350, 310, 102, 20));
        QPalette palette3;
        QBrush brush5(QColor(255, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        hardButton->setPalette(palette3);
        hardButton->setFont(font);
        startButton = new QPushButton(Options);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(330, 370, 115, 32));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush6(QColor(255, 255, 102, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        QBrush brush7(QColor(148, 148, 148, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        startButton->setPalette(palette4);
        startButton->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/dot.png"), QSize(), QIcon::Normal, QIcon::Off);
        startButton->setIcon(icon);
        startButton->setAutoDefault(false);
        startButton->setFlat(true);
        label = new QLabel(Options);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 260, 71, 29));
        QPalette palette5;
        QBrush brush8(QColor(255, 244, 82, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label->setPalette(palette5);
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setMargin(2);
        label_2 = new QLabel(Options);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(270, 350, 41, 61));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/pacright2.png")));
        label_3 = new QLabel(Options);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 10, 531, 161));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/paclogo.png")));
        label_4 = new QLabel(Options);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 160, 59, 61));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/ghostdownblue2.png")));
        label_5 = new QLabel(Options);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(130, 350, 59, 61));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/ghostrightred2.png")));
        label_6 = new QLabel(Options);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(460, 350, 59, 61));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/images/ghostleft2.png")));
        label_7 = new QLabel(Options);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(380, 160, 59, 61));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/images/ghostdownorange2.png")));

        retranslateUi(Options);

        startButton->setDefault(false);


        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QWidget *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Pacman", nullptr));
        easyButton->setText(QApplication::translate("Options", "Easy", nullptr));
        mediumButton->setText(QApplication::translate("Options", "Medium", nullptr));
        hardButton->setText(QApplication::translate("Options", "Hard", nullptr));
        startButton->setText(QApplication::translate("Options", "PLAY GAME", nullptr));
        label->setText(QApplication::translate("Options", "Name", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
