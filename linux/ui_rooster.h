/********************************************************************************
** Form generated from reading UI file 'rooster.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOSTER_H
#define UI_ROOSTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rooster
{
public:
    QAction *actionChoose_Audio_File;
    QAction *actionFade_in_Alarm_Volume;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *origin;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QSpinBox *pretime;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *dest;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QTimeEdit *arrivaltime;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QSpinBox *beginchecking;
    QLabel *label_6;
    QPushButton *alarmButton;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *rooster)
    {
        if (rooster->objectName().isEmpty())
            rooster->setObjectName(QStringLiteral("rooster"));
        rooster->resize(520, 196);
        rooster->setMinimumSize(QSize(520, 196));
        rooster->setMaximumSize(QSize(520, 196));
        actionChoose_Audio_File = new QAction(rooster);
        actionChoose_Audio_File->setObjectName(QStringLiteral("actionChoose_Audio_File"));
        actionFade_in_Alarm_Volume = new QAction(rooster);
        actionFade_in_Alarm_Volume->setObjectName(QStringLiteral("actionFade_in_Alarm_Volume"));
        actionFade_in_Alarm_Volume->setCheckable(true);
        actionFade_in_Alarm_Volume->setChecked(true);
        centralWidget = new QWidget(rooster);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 481, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        origin = new QLineEdit(layoutWidget);
        origin->setObjectName(QStringLiteral("origin"));
        origin->setMinimumSize(QSize(287, 0));
        origin->setMaximumSize(QSize(287, 16777215));
        origin->setMaxLength(100);

        horizontalLayout_2->addWidget(origin);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        pretime = new QSpinBox(layoutWidget);
        pretime->setObjectName(QStringLiteral("pretime"));
        pretime->setMinimumSize(QSize(95, 0));
        pretime->setMaximumSize(QSize(95, 16777215));
        pretime->setAutoFillBackground(false);
        pretime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pretime->setReadOnly(false);
        pretime->setMaximum(240);
        pretime->setSingleStep(5);
        pretime->setValue(60);

        horizontalLayout_2->addWidget(pretime);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 60, 481, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        dest = new QLineEdit(layoutWidget1);
        dest->setObjectName(QStringLiteral("dest"));
        dest->setMinimumSize(QSize(287, 0));
        dest->setMaximumSize(QSize(287, 16777215));
        dest->setMaxLength(100);

        horizontalLayout_3->addWidget(dest);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(label);

        arrivaltime = new QTimeEdit(layoutWidget1);
        arrivaltime->setObjectName(QStringLiteral("arrivaltime"));
        arrivaltime->setMinimumSize(QSize(95, 0));
        arrivaltime->setMaximumSize(QSize(95, 16777215));
        arrivaltime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(arrivaltime);

        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 100, 481, 29));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        beginchecking = new QSpinBox(layoutWidget_2);
        beginchecking->setObjectName(QStringLiteral("beginchecking"));
        beginchecking->setMinimumSize(QSize(80, 0));
        beginchecking->setMaximumSize(QSize(95, 16777215));
        beginchecking->setMaximum(240);
        beginchecking->setSingleStep(5);
        beginchecking->setValue(60);

        horizontalLayout_7->addWidget(beginchecking);

        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        alarmButton = new QPushButton(layoutWidget_2);
        alarmButton->setObjectName(QStringLiteral("alarmButton"));

        horizontalLayout_7->addWidget(alarmButton);

        rooster->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(rooster);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 520, 20));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        rooster->setMenuBar(menuBar);
        statusBar = new QStatusBar(rooster);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setSizeGripEnabled(false);
        rooster->setStatusBar(statusBar);
        QWidget::setTabOrder(origin, dest);
        QWidget::setTabOrder(dest, pretime);
        QWidget::setTabOrder(pretime, arrivaltime);
        QWidget::setTabOrder(arrivaltime, beginchecking);
        QWidget::setTabOrder(beginchecking, alarmButton);

        menuBar->addAction(menuSettings->menuAction());
        menuSettings->addAction(actionFade_in_Alarm_Volume);
        menuSettings->addAction(actionChoose_Audio_File);

        retranslateUi(rooster);

        QMetaObject::connectSlotsByName(rooster);
    } // setupUi

    void retranslateUi(QMainWindow *rooster)
    {
        rooster->setWindowTitle(QApplication::translate("rooster", "Rooster", 0));
        actionChoose_Audio_File->setText(QApplication::translate("rooster", "Choose Audio File ...", 0));
        actionFade_in_Alarm_Volume->setText(QApplication::translate("rooster", "Fade in Alarm Volume", 0));
        origin->setPlaceholderText(QApplication::translate("rooster", "Start Address", 0));
        label_3->setText(QApplication::translate("rooster", "Ready in:", 0));
#ifndef QT_NO_TOOLTIP
        pretime->setToolTip(QApplication::translate("rooster", "This is the time it takes for you to get ready.", 0));
#endif // QT_NO_TOOLTIP
        pretime->setSpecialValueText(QString());
        pretime->setSuffix(QApplication::translate("rooster", " mins", 0));
        pretime->setPrefix(QString());
        dest->setPlaceholderText(QApplication::translate("rooster", "Destination Address", 0));
        label->setText(QApplication::translate("rooster", "Arrive at:", 0));
#ifndef QT_NO_TOOLTIP
        arrivaltime->setToolTip(QApplication::translate("rooster", "The time you wish to arrive at your destination.", 0));
#endif // QT_NO_TOOLTIP
        arrivaltime->setSpecialValueText(QString());
#ifndef QT_NO_TOOLTIP
        beginchecking->setToolTip(QApplication::translate("rooster", "There is no need to check traffic all night. Please set this to a reasonable value.", 0));
#endif // QT_NO_TOOLTIP
        beginchecking->setSpecialValueText(QString());
        beginchecking->setSuffix(QApplication::translate("rooster", " mins", 0));
        label_6->setText(QApplication::translate("rooster", " before arrival time, begin checking traffic.", 0));
        alarmButton->setText(QApplication::translate("rooster", "Set Alarm", 0));
        alarmButton->setShortcut(QApplication::translate("rooster", "Return", 0));
        menuSettings->setTitle(QApplication::translate("rooster", "Settings", 0));
#ifndef QT_NO_STATUSTIP
        statusBar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class rooster: public Ui_rooster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOSTER_H
