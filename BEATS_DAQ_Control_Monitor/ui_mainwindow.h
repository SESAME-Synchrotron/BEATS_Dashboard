/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "QESimpleShape.h"
#include "QSimpleShape.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *generalTittle;
    QGroupBox *commonIOCsGB;
    QGridLayout *gridLayout_5;
    QGridLayout *commonIOCsLAyout;
    QLabel *tomoScanSupportIOC;
    QLabel *tomoScanSupportIOCSts;
    QLabel *writerSupportIOCSts;
    QPushButton *shutterIOCStop;
    QPushButton *writerSupportIOCStart;
    QPushButton *tomoScanSupportIOCRestart;
    QESimpleShape *tomoScanSupportIOCInd;
    QESimpleShape *motorIOCInd;
    QLabel *shutterIOC;
    QESimpleShape *writerSupportIOCInd;
    QLabel *motorIOCSts;
    QLabel *shutterIOCSts;
    QESimpleShape *shutterIOCInd;
    QLabel *writerSupportIOC;
    QPushButton *writerSupportIOCStop;
    QPushButton *motorIOCRestart;
    QPushButton *tomoScanSupportIOCStart;
    QPushButton *tomoScanSupportIOCStop;
    QPushButton *shutterIOCStart;
    QPushButton *motorIOCStop;
    QPushButton *shutterIOCRestart;
    QLabel *motorIOC;
    QPushButton *writerSupportIOCRestart;
    QPushButton *motorIOCStart;
    QGroupBox *PCOGB;
    QGridLayout *gridLayout_10;
    QGridLayout *PCOLayout;
    QPushButton *PCOIOCStart;
    QPushButton *PCODriverStart;
    QLabel *PCOIOCSts;
    QESimpleShape *PCOIOCInd;
    QLabel *PCODriver;
    QPushButton *PCOIOCStop;
    QPushButton *PCOIOCRestart;
    QPushButton *PCO;
    QLabel *PCOIOC;
    QLabel *PCOState;
    QESimpleShape *PCOStateInd;
    QLabel *PCOSts;
    QGridLayout *gridLayout_6;
    QLabel *generalSts;
    QLabel *currentCamera;
    QPushButton *TCPServerSocketRestart;
    QLabel *currentStage;
    QGridLayout *ImageJLayout;
    QLabel *ImageJ;
    QPushButton *ImageJStart;
    QPushButton *help;
    QLineEdit *password;
    QGridLayout *gridLayout_2;
    QGroupBox *contScanGB;
    QGridLayout *gridLayout_7;
    QGridLayout *contScanLayout;
    QPushButton *contTomoScanIOCStart;
    QLabel *contWriterServerSts;
    QLabel *contPythonServer;
    QPushButton *contPythonServerStart;
    QLabel *contTomoScanIOCSts;
    QESimpleShape *PCOContWriterServerInd;
    QLabel *contMEDM;
    QPushButton *contTomoScanIOCStop;
    QLabel *contWriterServer;
    QPushButton *contWriterServerRestart;
    QPushButton *contMEDMStart;
    QLabel *contTomoScanIOc;
    QPushButton *contWriterServerStart;
    QLabel *contPythonServerSts;
    QPushButton *contPythonServerRestart;
    QESimpleShape *PCOContTomoScanIOCInd;
    QPushButton *contTomoScanIOCRestart;
    QPushButton *contPythonServerStop;
    QPushButton *contWriterServerStop;
    QESimpleShape *PCOContPythonServerInd;
    QESimpleShape *FLIRContTomoScanIOCInd;
    QESimpleShape *FLIRContPythonServerInd;
    QESimpleShape *FLIRContWriterServerInd;
    QGroupBox *stepScanGB;
    QGridLayout *gridLayout_8;
    QGridLayout *stepScanLayout;
    QLabel *stepMEDM;
    QPushButton *stepPythonServerStop;
    QLabel *stepPythonServer;
    QESimpleShape *PCOStepTomoScanIOCInd;
    QPushButton *stepMEDMStart;
    QPushButton *stepTomoScanIOCStart;
    QLabel *stepWriterServer;
    QPushButton *stepTomoScanIOCStop;
    QLabel *stepPythonServerSts;
    QPushButton *stepWriterServerStop;
    QLabel *stepTomoScanIOC;
    QPushButton *stepWriterServerRestart;
    QPushButton *stepPythonServerRestart;
    QPushButton *stepTomoScanIOCRestart;
    QPushButton *stepPythonServerStart;
    QLabel *stepWriterServerSts;
    QESimpleShape *PCOStepPythonServerInd;
    QESimpleShape *PCOStepWriterServerInd;
    QPushButton *stepWriterServerStart;
    QLabel *stepTomoScanIOCSts;
    QESimpleShape *FLIRStepTomoScanIOCInd;
    QESimpleShape *FLIRStepPythonServerInd;
    QESimpleShape *FLIRStepWriterServerInd;
    QLabel *CameraType;
    QGroupBox *FLIRGB;
    QGridLayout *gridLayout_9;
    QGridLayout *FLIRLayout;
    QESimpleShape *FLIRStateInd;
    QPushButton *FLIR;
    QPushButton *FLIRIOCStop;
    QLabel *FLIRState;
    QPushButton *FLIRIOCRestart;
    QLabel *FLIRDriver;
    QLabel *FLIRIOC;
    QESimpleShape *FLIRIOCInd;
    QLabel *FLIRIOCSts;
    QPushButton *FLIRIOCStart;
    QPushButton *FLIRDriverStart;
    QLabel *FLIRSts;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1006, 649);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        generalTittle = new QLabel(centralwidget);
        generalTittle->setObjectName(QStringLiteral("generalTittle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(generalTittle->sizePolicy().hasHeightForWidth());
        generalTittle->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        generalTittle->setFont(font);
        generalTittle->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border: 1px solid black;\n"
"border-radius: 5px;\n"
"margin-top: 0.5em;\n"
"subcontrol-origin: margin;\n"
"left: 10px;\n"
"padding: 0 3px 0 3px;"));
        generalTittle->setAlignment(Qt::AlignCenter);
        generalTittle->setMargin(10);
        generalTittle->setIndent(0);

        gridLayout->addWidget(generalTittle, 0, 0, 1, 1);

        commonIOCsGB = new QGroupBox(centralwidget);
        commonIOCsGB->setObjectName(QStringLiteral("commonIOCsGB"));
        commonIOCsGB->setStyleSheet(QLatin1String("QGroupBox {\n"
"  border: 1px solid black;\n"
"  border-radius: 5px;\n"
"  margin-top: 0.5em;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 3px 0 3px;\n"
"}\n"
""));
        gridLayout_5 = new QGridLayout(commonIOCsGB);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        commonIOCsLAyout = new QGridLayout();
        commonIOCsLAyout->setObjectName(QStringLiteral("commonIOCsLAyout"));
        tomoScanSupportIOC = new QLabel(commonIOCsGB);
        tomoScanSupportIOC->setObjectName(QStringLiteral("tomoScanSupportIOC"));

        commonIOCsLAyout->addWidget(tomoScanSupportIOC, 2, 0, 1, 1);

        tomoScanSupportIOCSts = new QLabel(commonIOCsGB);
        tomoScanSupportIOCSts->setObjectName(QStringLiteral("tomoScanSupportIOCSts"));
        tomoScanSupportIOCSts->setCursor(QCursor(Qt::IBeamCursor));
        tomoScanSupportIOCSts->setFrameShape(QFrame::StyledPanel);
        tomoScanSupportIOCSts->setAlignment(Qt::AlignCenter);

        commonIOCsLAyout->addWidget(tomoScanSupportIOCSts, 2, 5, 1, 1);

        writerSupportIOCSts = new QLabel(commonIOCsGB);
        writerSupportIOCSts->setObjectName(QStringLiteral("writerSupportIOCSts"));
        writerSupportIOCSts->setCursor(QCursor(Qt::IBeamCursor));
        writerSupportIOCSts->setFrameShape(QFrame::StyledPanel);
        writerSupportIOCSts->setAlignment(Qt::AlignCenter);

        commonIOCsLAyout->addWidget(writerSupportIOCSts, 3, 5, 1, 1);

        shutterIOCStop = new QPushButton(commonIOCsGB);
        shutterIOCStop->setObjectName(QStringLiteral("shutterIOCStop"));
        shutterIOCStop->setCursor(QCursor(Qt::PointingHandCursor));

        commonIOCsLAyout->addWidget(shutterIOCStop, 0, 3, 1, 1);

        writerSupportIOCStart = new QPushButton(commonIOCsGB);
        writerSupportIOCStart->setObjectName(QStringLiteral("writerSupportIOCStart"));
        writerSupportIOCStart->setCursor(QCursor(Qt::PointingHandCursor));

        commonIOCsLAyout->addWidget(writerSupportIOCStart, 3, 2, 1, 1);

        tomoScanSupportIOCRestart = new QPushButton(commonIOCsGB);
        tomoScanSupportIOCRestart->setObjectName(QStringLiteral("tomoScanSupportIOCRestart"));
        tomoScanSupportIOCRestart->setCursor(QCursor(Qt::PointingHandCursor));

        commonIOCsLAyout->addWidget(tomoScanSupportIOCRestart, 2, 4, 1, 1);

        tomoScanSupportIOCInd = new QESimpleShape(commonIOCsGB);
        tomoScanSupportIOCInd->setObjectName(QStringLiteral("tomoScanSupportIOCInd"));

        commonIOCsLAyout->addWidget(tomoScanSupportIOCInd, 2, 1, 1, 1);

        motorIOCInd = new QESimpleShape(commonIOCsGB);
        motorIOCInd->setObjectName(QStringLiteral("motorIOCInd"));
        motorIOCInd->setProperty("colour0", QVariant(QColor(5, 240, 5)));

        commonIOCsLAyout->addWidget(motorIOCInd, 1, 1, 1, 1);

        shutterIOC = new QLabel(commonIOCsGB);
        shutterIOC->setObjectName(QStringLiteral("shutterIOC"));

        commonIOCsLAyout->addWidget(shutterIOC, 0, 0, 1, 1);

        writerSupportIOCInd = new QESimpleShape(commonIOCsGB);
        writerSupportIOCInd->setObjectName(QStringLiteral("writerSupportIOCInd"));
        writerSupportIOCInd->setProperty("colour0", QVariant(QColor(5, 240, 5)));

        commonIOCsLAyout->addWidget(writerSupportIOCInd, 3, 1, 1, 1);

        motorIOCSts = new QLabel(commonIOCsGB);
        motorIOCSts->setObjectName(QStringLiteral("motorIOCSts"));
        motorIOCSts->setCursor(QCursor(Qt::IBeamCursor));
        motorIOCSts->setFrameShape(QFrame::StyledPanel);
        motorIOCSts->setAlignment(Qt::AlignCenter);

        commonIOCsLAyout->addWidget(motorIOCSts, 1, 5, 1, 1);

        shutterIOCSts = new QLabel(commonIOCsGB);
        shutterIOCSts->setObjectName(QStringLiteral("shutterIOCSts"));
        shutterIOCSts->setCursor(QCursor(Qt::IBeamCursor));
        shutterIOCSts->setFrameShape(QFrame::StyledPanel);
        shutterIOCSts->setAlignment(Qt::AlignCenter);

        commonIOCsLAyout->addWidget(shutterIOCSts, 0, 5, 1, 1);

        shutterIOCInd = new QESimpleShape(commonIOCsGB);
        shutterIOCInd->setObjectName(QStringLiteral("shutterIOCInd"));
        shutterIOCInd->setProperty("colour0", QVariant(QColor(5, 240, 5)));

        commonIOCsLAyout->addWidget(shutterIOCInd, 0, 1, 1, 1);

        writerSupportIOC = new QLabel(commonIOCsGB);
        writerSupportIOC->setObjectName(QStringLiteral("writerSupportIOC"));

        commonIOCsLAyout->addWidget(writerSupportIOC, 3, 0, 1, 1);

        writerSupportIOCStop = new QPushButton(commonIOCsGB);
        writerSupportIOCStop->setObjectName(QStringLiteral("writerSupportIOCStop"));
        writerSupportIOCStop->setCursor(QCursor(Qt::PointingHandCursor));

        commonIOCsLAyout->addWidget(writerSupportIOCStop, 3, 3, 1, 1);

        motorIOCRestart = new QPushButton(commonIOCsGB);
        motorIOCRestart->setObjectName(QStringLiteral("motorIOCRestart"));
        motorIOCRestart->setCursor(QCursor(Qt::PointingHandCursor));

        commonIOCsLAyout->addWidget(motorIOCRestart, 1, 4, 1, 1);

        tomoScanSupportIOCStart = new QPushButton(commonIOCsGB);
        tomoScanSupportIOCStart->setObjectName(QStringLiteral("tomoScanSupportIOCStart"));
        tomoScanSupportIOCStart->setCursor(QCursor(Qt::PointingHandCursor));

        commonIOCsLAyout->addWidget(tomoScanSupportIOCStart, 2, 2, 1, 1);

        tomoScanSupportIOCStop = new QPushButton(commonIOCsGB);
        tomoScanSupportIOCStop->setObjectName(QStringLiteral("tomoScanSupportIOCStop"));
        tomoScanSupportIOCStop->setCursor(QCursor(Qt::PointingHandCursor));

        commonIOCsLAyout->addWidget(tomoScanSupportIOCStop, 2, 3, 1, 1);

        shutterIOCStart = new QPushButton(commonIOCsGB);
        shutterIOCStart->setObjectName(QStringLiteral("shutterIOCStart"));
        shutterIOCStart->setCursor(QCursor(Qt::PointingHandCursor));

        commonIOCsLAyout->addWidget(shutterIOCStart, 0, 2, 1, 1);

        motorIOCStop = new QPushButton(commonIOCsGB);
        motorIOCStop->setObjectName(QStringLiteral("motorIOCStop"));
        motorIOCStop->setCursor(QCursor(Qt::PointingHandCursor));

        commonIOCsLAyout->addWidget(motorIOCStop, 1, 3, 1, 1);

        shutterIOCRestart = new QPushButton(commonIOCsGB);
        shutterIOCRestart->setObjectName(QStringLiteral("shutterIOCRestart"));
        shutterIOCRestart->setCursor(QCursor(Qt::PointingHandCursor));

        commonIOCsLAyout->addWidget(shutterIOCRestart, 0, 4, 1, 1);

        motorIOC = new QLabel(commonIOCsGB);
        motorIOC->setObjectName(QStringLiteral("motorIOC"));

        commonIOCsLAyout->addWidget(motorIOC, 1, 0, 1, 1);

        writerSupportIOCRestart = new QPushButton(commonIOCsGB);
        writerSupportIOCRestart->setObjectName(QStringLiteral("writerSupportIOCRestart"));
        writerSupportIOCRestart->setCursor(QCursor(Qt::PointingHandCursor));

        commonIOCsLAyout->addWidget(writerSupportIOCRestart, 3, 4, 1, 1);

        motorIOCStart = new QPushButton(commonIOCsGB);
        motorIOCStart->setObjectName(QStringLiteral("motorIOCStart"));
        motorIOCStart->setCursor(QCursor(Qt::PointingHandCursor));

        commonIOCsLAyout->addWidget(motorIOCStart, 1, 2, 1, 1);


        gridLayout_5->addLayout(commonIOCsLAyout, 0, 0, 1, 1);


        gridLayout->addWidget(commonIOCsGB, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 2);

        PCOGB = new QGroupBox(centralwidget);
        PCOGB->setObjectName(QStringLiteral("PCOGB"));
        PCOGB->setStyleSheet(QLatin1String("QGroupBox {\n"
"  border: 1px solid black;\n"
"  border-radius: 5px;\n"
"  margin-top: 0.5em;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 3px 0 3px;\n"
"}\n"
""));
        gridLayout_10 = new QGridLayout(PCOGB);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        PCOLayout = new QGridLayout();
        PCOLayout->setSpacing(5);
        PCOLayout->setObjectName(QStringLiteral("PCOLayout"));
        PCOIOCStart = new QPushButton(PCOGB);
        PCOIOCStart->setObjectName(QStringLiteral("PCOIOCStart"));
        PCOIOCStart->setCursor(QCursor(Qt::PointingHandCursor));

        PCOLayout->addWidget(PCOIOCStart, 2, 2, 1, 1);

        PCODriverStart = new QPushButton(PCOGB);
        PCODriverStart->setObjectName(QStringLiteral("PCODriverStart"));
        PCODriverStart->setCursor(QCursor(Qt::PointingHandCursor));

        PCOLayout->addWidget(PCODriverStart, 3, 2, 1, 3);

        PCOIOCSts = new QLabel(PCOGB);
        PCOIOCSts->setObjectName(QStringLiteral("PCOIOCSts"));
        PCOIOCSts->setCursor(QCursor(Qt::IBeamCursor));
        PCOIOCSts->setFrameShape(QFrame::StyledPanel);
        PCOIOCSts->setAlignment(Qt::AlignCenter);

        PCOLayout->addWidget(PCOIOCSts, 2, 5, 1, 1);

        PCOIOCInd = new QESimpleShape(PCOGB);
        PCOIOCInd->setObjectName(QStringLiteral("PCOIOCInd"));

        PCOLayout->addWidget(PCOIOCInd, 2, 1, 1, 1);

        PCODriver = new QLabel(PCOGB);
        PCODriver->setObjectName(QStringLiteral("PCODriver"));

        PCOLayout->addWidget(PCODriver, 3, 0, 1, 1);

        PCOIOCStop = new QPushButton(PCOGB);
        PCOIOCStop->setObjectName(QStringLiteral("PCOIOCStop"));
        PCOIOCStop->setCursor(QCursor(Qt::PointingHandCursor));

        PCOLayout->addWidget(PCOIOCStop, 2, 3, 1, 1);

        PCOIOCRestart = new QPushButton(PCOGB);
        PCOIOCRestart->setObjectName(QStringLiteral("PCOIOCRestart"));
        PCOIOCRestart->setCursor(QCursor(Qt::PointingHandCursor));

        PCOLayout->addWidget(PCOIOCRestart, 2, 4, 1, 1);

        PCO = new QPushButton(PCOGB);
        PCO->setObjectName(QStringLiteral("PCO"));
        PCO->setCursor(QCursor(Qt::PointingHandCursor));

        PCOLayout->addWidget(PCO, 0, 0, 1, 6);

        PCOIOC = new QLabel(PCOGB);
        PCOIOC->setObjectName(QStringLiteral("PCOIOC"));
        PCOIOC->setCursor(QCursor(Qt::ArrowCursor));

        PCOLayout->addWidget(PCOIOC, 2, 0, 1, 1);

        PCOState = new QLabel(PCOGB);
        PCOState->setObjectName(QStringLiteral("PCOState"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PCOState->sizePolicy().hasHeightForWidth());
        PCOState->setSizePolicy(sizePolicy1);

        PCOLayout->addWidget(PCOState, 1, 0, 1, 1);

        PCOStateInd = new QESimpleShape(PCOGB);
        PCOStateInd->setObjectName(QStringLiteral("PCOStateInd"));
        PCOStateInd->setEdgeColour(QColor(0, 0, 0));
        PCOStateInd->setProperty("colour0", QVariant(QColor(5, 240, 5)));
        PCOStateInd->setProperty("colour1", QVariant(QColor(255, 0, 0)));
        PCOStateInd->setProperty("colour2", QVariant(QColor(255, 0, 0)));
        PCOStateInd->setProperty("colour3", QVariant(QColor(255, 0, 0)));

        PCOLayout->addWidget(PCOStateInd, 1, 1, 1, 1);

        PCOSts = new QLabel(PCOGB);
        PCOSts->setObjectName(QStringLiteral("PCOSts"));
        PCOSts->setCursor(QCursor(Qt::IBeamCursor));
        PCOSts->setFrameShape(QFrame::StyledPanel);
        PCOSts->setAlignment(Qt::AlignCenter);
        PCOSts->setWordWrap(false);

        PCOLayout->addWidget(PCOSts, 1, 2, 1, 4);


        gridLayout_10->addLayout(PCOLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(PCOGB, 1, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        generalSts = new QLabel(centralwidget);
        generalSts->setObjectName(QStringLiteral("generalSts"));
        QFont font1;
        font1.setPointSize(11);
        generalSts->setFont(font1);
        generalSts->setCursor(QCursor(Qt::IBeamCursor));
        generalSts->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        generalSts->setFrameShape(QFrame::StyledPanel);
        generalSts->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(generalSts, 1, 0, 1, 2);

        currentCamera = new QLabel(centralwidget);
        currentCamera->setObjectName(QStringLiteral("currentCamera"));
        currentCamera->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 0);"));
        currentCamera->setFrameShape(QFrame::StyledPanel);

        gridLayout_6->addWidget(currentCamera, 3, 0, 1, 1);

        TCPServerSocketRestart = new QPushButton(centralwidget);
        TCPServerSocketRestart->setObjectName(QStringLiteral("TCPServerSocketRestart"));
        TCPServerSocketRestart->setCursor(QCursor(Qt::PointingHandCursor));
        TCPServerSocketRestart->setFlat(false);

        gridLayout_6->addWidget(TCPServerSocketRestart, 0, 1, 1, 1);

        currentStage = new QLabel(centralwidget);
        currentStage->setObjectName(QStringLiteral("currentStage"));
        currentStage->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 0);"));
        currentStage->setFrameShape(QFrame::StyledPanel);

        gridLayout_6->addWidget(currentStage, 2, 0, 1, 1);

        ImageJLayout = new QGridLayout();
        ImageJLayout->setObjectName(QStringLiteral("ImageJLayout"));
        ImageJ = new QLabel(centralwidget);
        ImageJ->setObjectName(QStringLiteral("ImageJ"));

        ImageJLayout->addWidget(ImageJ, 0, 0, 1, 1);

        ImageJStart = new QPushButton(centralwidget);
        ImageJStart->setObjectName(QStringLiteral("ImageJStart"));
        ImageJStart->setCursor(QCursor(Qt::PointingHandCursor));

        ImageJLayout->addWidget(ImageJStart, 0, 1, 1, 1);


        gridLayout_6->addLayout(ImageJLayout, 0, 0, 1, 1);

        help = new QPushButton(centralwidget);
        help->setObjectName(QStringLiteral("help"));
        sizePolicy1.setHeightForWidth(help->sizePolicy().hasHeightForWidth());
        help->setSizePolicy(sizePolicy1);
        help->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_6->addWidget(help, 3, 2, 1, 1);

        password = new QLineEdit(centralwidget);
        password->setObjectName(QStringLiteral("password"));
        QFont font2;
        font2.setPointSize(7);
        password->setFont(font2);
        password->setEchoMode(QLineEdit::Password);

        gridLayout_6->addWidget(password, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_6, 3, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        contScanGB = new QGroupBox(centralwidget);
        contScanGB->setObjectName(QStringLiteral("contScanGB"));
        contScanGB->setStyleSheet(QLatin1String("QGroupBox {\n"
"  border: 1px solid black;\n"
"  border-radius: 5px;\n"
"  margin-top: 0.5em;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 3px 0 3px;\n"
"}\n"
""));
        gridLayout_7 = new QGridLayout(contScanGB);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        contScanLayout = new QGridLayout();
        contScanLayout->setObjectName(QStringLiteral("contScanLayout"));
        contTomoScanIOCStart = new QPushButton(contScanGB);
        contTomoScanIOCStart->setObjectName(QStringLiteral("contTomoScanIOCStart"));
        contTomoScanIOCStart->setCursor(QCursor(Qt::PointingHandCursor));

        contScanLayout->addWidget(contTomoScanIOCStart, 0, 3, 1, 1);

        contWriterServerSts = new QLabel(contScanGB);
        contWriterServerSts->setObjectName(QStringLiteral("contWriterServerSts"));
        contWriterServerSts->setCursor(QCursor(Qt::IBeamCursor));
        contWriterServerSts->setFrameShape(QFrame::StyledPanel);
        contWriterServerSts->setFrameShadow(QFrame::Sunken);
        contWriterServerSts->setAlignment(Qt::AlignCenter);

        contScanLayout->addWidget(contWriterServerSts, 2, 6, 1, 1);

        contPythonServer = new QLabel(contScanGB);
        contPythonServer->setObjectName(QStringLiteral("contPythonServer"));

        contScanLayout->addWidget(contPythonServer, 1, 0, 1, 1);

        contPythonServerStart = new QPushButton(contScanGB);
        contPythonServerStart->setObjectName(QStringLiteral("contPythonServerStart"));
        contPythonServerStart->setCursor(QCursor(Qt::PointingHandCursor));

        contScanLayout->addWidget(contPythonServerStart, 1, 3, 1, 1);

        contTomoScanIOCSts = new QLabel(contScanGB);
        contTomoScanIOCSts->setObjectName(QStringLiteral("contTomoScanIOCSts"));
        contTomoScanIOCSts->setCursor(QCursor(Qt::IBeamCursor));
        contTomoScanIOCSts->setFrameShape(QFrame::StyledPanel);
        contTomoScanIOCSts->setFrameShadow(QFrame::Sunken);
        contTomoScanIOCSts->setAlignment(Qt::AlignCenter);

        contScanLayout->addWidget(contTomoScanIOCSts, 0, 6, 1, 1);

        PCOContWriterServerInd = new QESimpleShape(contScanGB);
        PCOContWriterServerInd->setObjectName(QStringLiteral("PCOContWriterServerInd"));

        contScanLayout->addWidget(PCOContWriterServerInd, 2, 1, 1, 1);

        contMEDM = new QLabel(contScanGB);
        contMEDM->setObjectName(QStringLiteral("contMEDM"));

        contScanLayout->addWidget(contMEDM, 3, 0, 1, 1);

        contTomoScanIOCStop = new QPushButton(contScanGB);
        contTomoScanIOCStop->setObjectName(QStringLiteral("contTomoScanIOCStop"));
        contTomoScanIOCStop->setCursor(QCursor(Qt::PointingHandCursor));

        contScanLayout->addWidget(contTomoScanIOCStop, 0, 4, 1, 1);

        contWriterServer = new QLabel(contScanGB);
        contWriterServer->setObjectName(QStringLiteral("contWriterServer"));

        contScanLayout->addWidget(contWriterServer, 2, 0, 1, 1);

        contWriterServerRestart = new QPushButton(contScanGB);
        contWriterServerRestart->setObjectName(QStringLiteral("contWriterServerRestart"));
        contWriterServerRestart->setCursor(QCursor(Qt::PointingHandCursor));

        contScanLayout->addWidget(contWriterServerRestart, 2, 5, 1, 1);

        contMEDMStart = new QPushButton(contScanGB);
        contMEDMStart->setObjectName(QStringLiteral("contMEDMStart"));
        contMEDMStart->setCursor(QCursor(Qt::PointingHandCursor));

        contScanLayout->addWidget(contMEDMStart, 3, 3, 1, 4);

        contTomoScanIOc = new QLabel(contScanGB);
        contTomoScanIOc->setObjectName(QStringLiteral("contTomoScanIOc"));

        contScanLayout->addWidget(contTomoScanIOc, 0, 0, 1, 1);

        contWriterServerStart = new QPushButton(contScanGB);
        contWriterServerStart->setObjectName(QStringLiteral("contWriterServerStart"));
        contWriterServerStart->setCursor(QCursor(Qt::PointingHandCursor));

        contScanLayout->addWidget(contWriterServerStart, 2, 3, 1, 1);

        contPythonServerSts = new QLabel(contScanGB);
        contPythonServerSts->setObjectName(QStringLiteral("contPythonServerSts"));
        contPythonServerSts->setCursor(QCursor(Qt::IBeamCursor));
        contPythonServerSts->setFrameShape(QFrame::StyledPanel);
        contPythonServerSts->setFrameShadow(QFrame::Sunken);
        contPythonServerSts->setAlignment(Qt::AlignCenter);

        contScanLayout->addWidget(contPythonServerSts, 1, 6, 1, 1);

        contPythonServerRestart = new QPushButton(contScanGB);
        contPythonServerRestart->setObjectName(QStringLiteral("contPythonServerRestart"));
        contPythonServerRestart->setCursor(QCursor(Qt::PointingHandCursor));

        contScanLayout->addWidget(contPythonServerRestart, 1, 5, 1, 1);

        PCOContTomoScanIOCInd = new QESimpleShape(contScanGB);
        PCOContTomoScanIOCInd->setObjectName(QStringLiteral("PCOContTomoScanIOCInd"));
        PCOContTomoScanIOCInd->setProperty("colour0", QVariant(QColor(5, 240, 5)));

        contScanLayout->addWidget(PCOContTomoScanIOCInd, 0, 1, 1, 1);

        contTomoScanIOCRestart = new QPushButton(contScanGB);
        contTomoScanIOCRestart->setObjectName(QStringLiteral("contTomoScanIOCRestart"));
        contTomoScanIOCRestart->setCursor(QCursor(Qt::PointingHandCursor));

        contScanLayout->addWidget(contTomoScanIOCRestart, 0, 5, 1, 1);

        contPythonServerStop = new QPushButton(contScanGB);
        contPythonServerStop->setObjectName(QStringLiteral("contPythonServerStop"));
        contPythonServerStop->setCursor(QCursor(Qt::PointingHandCursor));

        contScanLayout->addWidget(contPythonServerStop, 1, 4, 1, 1);

        contWriterServerStop = new QPushButton(contScanGB);
        contWriterServerStop->setObjectName(QStringLiteral("contWriterServerStop"));
        contWriterServerStop->setCursor(QCursor(Qt::PointingHandCursor));

        contScanLayout->addWidget(contWriterServerStop, 2, 4, 1, 1);

        PCOContPythonServerInd = new QESimpleShape(contScanGB);
        PCOContPythonServerInd->setObjectName(QStringLiteral("PCOContPythonServerInd"));

        contScanLayout->addWidget(PCOContPythonServerInd, 1, 1, 1, 1);

        FLIRContTomoScanIOCInd = new QESimpleShape(contScanGB);
        FLIRContTomoScanIOCInd->setObjectName(QStringLiteral("FLIRContTomoScanIOCInd"));
        FLIRContTomoScanIOCInd->setProperty("colour0", QVariant(QColor(5, 240, 5)));

        contScanLayout->addWidget(FLIRContTomoScanIOCInd, 0, 2, 1, 1);

        FLIRContPythonServerInd = new QESimpleShape(contScanGB);
        FLIRContPythonServerInd->setObjectName(QStringLiteral("FLIRContPythonServerInd"));

        contScanLayout->addWidget(FLIRContPythonServerInd, 1, 2, 1, 1);

        FLIRContWriterServerInd = new QESimpleShape(contScanGB);
        FLIRContWriterServerInd->setObjectName(QStringLiteral("FLIRContWriterServerInd"));

        contScanLayout->addWidget(FLIRContWriterServerInd, 2, 2, 1, 1);


        gridLayout_7->addLayout(contScanLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(contScanGB, 1, 1, 1, 1);

        stepScanGB = new QGroupBox(centralwidget);
        stepScanGB->setObjectName(QStringLiteral("stepScanGB"));
        stepScanGB->setStyleSheet(QLatin1String("QGroupBox {\n"
"  border: 1px solid black;\n"
"  border-radius: 5px;\n"
"  margin-top: 0.5em;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 3px 0 3px;\n"
"}\n"
""));
        gridLayout_8 = new QGridLayout(stepScanGB);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        stepScanLayout = new QGridLayout();
        stepScanLayout->setObjectName(QStringLiteral("stepScanLayout"));
        stepMEDM = new QLabel(stepScanGB);
        stepMEDM->setObjectName(QStringLiteral("stepMEDM"));

        stepScanLayout->addWidget(stepMEDM, 3, 0, 1, 1);

        stepPythonServerStop = new QPushButton(stepScanGB);
        stepPythonServerStop->setObjectName(QStringLiteral("stepPythonServerStop"));
        stepPythonServerStop->setCursor(QCursor(Qt::PointingHandCursor));

        stepScanLayout->addWidget(stepPythonServerStop, 1, 4, 1, 1);

        stepPythonServer = new QLabel(stepScanGB);
        stepPythonServer->setObjectName(QStringLiteral("stepPythonServer"));

        stepScanLayout->addWidget(stepPythonServer, 1, 0, 1, 1);

        PCOStepTomoScanIOCInd = new QESimpleShape(stepScanGB);
        PCOStepTomoScanIOCInd->setObjectName(QStringLiteral("PCOStepTomoScanIOCInd"));
        PCOStepTomoScanIOCInd->setProperty("colour0", QVariant(QColor(5, 240, 5)));

        stepScanLayout->addWidget(PCOStepTomoScanIOCInd, 0, 1, 1, 1);

        stepMEDMStart = new QPushButton(stepScanGB);
        stepMEDMStart->setObjectName(QStringLiteral("stepMEDMStart"));
        stepMEDMStart->setCursor(QCursor(Qt::PointingHandCursor));

        stepScanLayout->addWidget(stepMEDMStart, 3, 3, 1, 4);

        stepTomoScanIOCStart = new QPushButton(stepScanGB);
        stepTomoScanIOCStart->setObjectName(QStringLiteral("stepTomoScanIOCStart"));
        stepTomoScanIOCStart->setCursor(QCursor(Qt::PointingHandCursor));

        stepScanLayout->addWidget(stepTomoScanIOCStart, 0, 3, 1, 1);

        stepWriterServer = new QLabel(stepScanGB);
        stepWriterServer->setObjectName(QStringLiteral("stepWriterServer"));

        stepScanLayout->addWidget(stepWriterServer, 2, 0, 1, 1);

        stepTomoScanIOCStop = new QPushButton(stepScanGB);
        stepTomoScanIOCStop->setObjectName(QStringLiteral("stepTomoScanIOCStop"));
        stepTomoScanIOCStop->setCursor(QCursor(Qt::PointingHandCursor));

        stepScanLayout->addWidget(stepTomoScanIOCStop, 0, 4, 1, 1);

        stepPythonServerSts = new QLabel(stepScanGB);
        stepPythonServerSts->setObjectName(QStringLiteral("stepPythonServerSts"));
        stepPythonServerSts->setCursor(QCursor(Qt::IBeamCursor));
        stepPythonServerSts->setFrameShape(QFrame::StyledPanel);
        stepPythonServerSts->setFrameShadow(QFrame::Sunken);
        stepPythonServerSts->setAlignment(Qt::AlignCenter);

        stepScanLayout->addWidget(stepPythonServerSts, 1, 6, 1, 1);

        stepWriterServerStop = new QPushButton(stepScanGB);
        stepWriterServerStop->setObjectName(QStringLiteral("stepWriterServerStop"));
        stepWriterServerStop->setCursor(QCursor(Qt::PointingHandCursor));

        stepScanLayout->addWidget(stepWriterServerStop, 2, 4, 1, 1);

        stepTomoScanIOC = new QLabel(stepScanGB);
        stepTomoScanIOC->setObjectName(QStringLiteral("stepTomoScanIOC"));

        stepScanLayout->addWidget(stepTomoScanIOC, 0, 0, 1, 1);

        stepWriterServerRestart = new QPushButton(stepScanGB);
        stepWriterServerRestart->setObjectName(QStringLiteral("stepWriterServerRestart"));
        stepWriterServerRestart->setCursor(QCursor(Qt::PointingHandCursor));

        stepScanLayout->addWidget(stepWriterServerRestart, 2, 5, 1, 1);

        stepPythonServerRestart = new QPushButton(stepScanGB);
        stepPythonServerRestart->setObjectName(QStringLiteral("stepPythonServerRestart"));
        stepPythonServerRestart->setCursor(QCursor(Qt::PointingHandCursor));

        stepScanLayout->addWidget(stepPythonServerRestart, 1, 5, 1, 1);

        stepTomoScanIOCRestart = new QPushButton(stepScanGB);
        stepTomoScanIOCRestart->setObjectName(QStringLiteral("stepTomoScanIOCRestart"));
        stepTomoScanIOCRestart->setCursor(QCursor(Qt::PointingHandCursor));

        stepScanLayout->addWidget(stepTomoScanIOCRestart, 0, 5, 1, 1);

        stepPythonServerStart = new QPushButton(stepScanGB);
        stepPythonServerStart->setObjectName(QStringLiteral("stepPythonServerStart"));
        stepPythonServerStart->setCursor(QCursor(Qt::PointingHandCursor));

        stepScanLayout->addWidget(stepPythonServerStart, 1, 3, 1, 1);

        stepWriterServerSts = new QLabel(stepScanGB);
        stepWriterServerSts->setObjectName(QStringLiteral("stepWriterServerSts"));
        stepWriterServerSts->setCursor(QCursor(Qt::IBeamCursor));
        stepWriterServerSts->setFrameShape(QFrame::StyledPanel);
        stepWriterServerSts->setFrameShadow(QFrame::Sunken);
        stepWriterServerSts->setAlignment(Qt::AlignCenter);

        stepScanLayout->addWidget(stepWriterServerSts, 2, 6, 1, 1);

        PCOStepPythonServerInd = new QESimpleShape(stepScanGB);
        PCOStepPythonServerInd->setObjectName(QStringLiteral("PCOStepPythonServerInd"));

        stepScanLayout->addWidget(PCOStepPythonServerInd, 1, 1, 1, 1);

        PCOStepWriterServerInd = new QESimpleShape(stepScanGB);
        PCOStepWriterServerInd->setObjectName(QStringLiteral("PCOStepWriterServerInd"));

        stepScanLayout->addWidget(PCOStepWriterServerInd, 2, 1, 1, 1);

        stepWriterServerStart = new QPushButton(stepScanGB);
        stepWriterServerStart->setObjectName(QStringLiteral("stepWriterServerStart"));
        stepWriterServerStart->setCursor(QCursor(Qt::PointingHandCursor));

        stepScanLayout->addWidget(stepWriterServerStart, 2, 3, 1, 1);

        stepTomoScanIOCSts = new QLabel(stepScanGB);
        stepTomoScanIOCSts->setObjectName(QStringLiteral("stepTomoScanIOCSts"));
        stepTomoScanIOCSts->setCursor(QCursor(Qt::IBeamCursor));
        stepTomoScanIOCSts->setFrameShape(QFrame::StyledPanel);
        stepTomoScanIOCSts->setFrameShadow(QFrame::Sunken);
        stepTomoScanIOCSts->setAlignment(Qt::AlignCenter);

        stepScanLayout->addWidget(stepTomoScanIOCSts, 0, 6, 1, 1);

        FLIRStepTomoScanIOCInd = new QESimpleShape(stepScanGB);
        FLIRStepTomoScanIOCInd->setObjectName(QStringLiteral("FLIRStepTomoScanIOCInd"));
        FLIRStepTomoScanIOCInd->setProperty("colour0", QVariant(QColor(5, 240, 5)));

        stepScanLayout->addWidget(FLIRStepTomoScanIOCInd, 0, 2, 1, 1);

        FLIRStepPythonServerInd = new QESimpleShape(stepScanGB);
        FLIRStepPythonServerInd->setObjectName(QStringLiteral("FLIRStepPythonServerInd"));

        stepScanLayout->addWidget(FLIRStepPythonServerInd, 1, 2, 1, 1);

        FLIRStepWriterServerInd = new QESimpleShape(stepScanGB);
        FLIRStepWriterServerInd->setObjectName(QStringLiteral("FLIRStepWriterServerInd"));

        stepScanLayout->addWidget(FLIRStepWriterServerInd, 2, 2, 1, 1);


        gridLayout_8->addLayout(stepScanLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(stepScanGB, 1, 0, 1, 1);

        CameraType = new QLabel(centralwidget);
        CameraType->setObjectName(QStringLiteral("CameraType"));
        CameraType->setFont(font);
        CameraType->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        CameraType->setFrameShape(QFrame::StyledPanel);
        CameraType->setFrameShadow(QFrame::Plain);
        CameraType->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(CameraType, 0, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout_2, 2, 0, 1, 2);

        FLIRGB = new QGroupBox(centralwidget);
        FLIRGB->setObjectName(QStringLiteral("FLIRGB"));
        FLIRGB->setStyleSheet(QLatin1String("QGroupBox {\n"
"  border: 1px solid black;\n"
"  border-radius: 5px;\n"
"  margin-top: 0.5em;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 3px 0 3px;\n"
"}\n"
""));
        gridLayout_9 = new QGridLayout(FLIRGB);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        FLIRLayout = new QGridLayout();
        FLIRLayout->setObjectName(QStringLiteral("FLIRLayout"));
        FLIRStateInd = new QESimpleShape(FLIRGB);
        FLIRStateInd->setObjectName(QStringLiteral("FLIRStateInd"));
        FLIRStateInd->setEdgeColour(QColor(0, 0, 0));
        FLIRStateInd->setProperty("colour0", QVariant(QColor(5, 240, 5)));
        FLIRStateInd->setProperty("colour1", QVariant(QColor(255, 0, 0)));
        FLIRStateInd->setProperty("colour2", QVariant(QColor(255, 0, 0)));
        FLIRStateInd->setProperty("colour3", QVariant(QColor(255, 0, 0)));

        FLIRLayout->addWidget(FLIRStateInd, 1, 1, 1, 1);

        FLIR = new QPushButton(FLIRGB);
        FLIR->setObjectName(QStringLiteral("FLIR"));
        FLIR->setCursor(QCursor(Qt::PointingHandCursor));

        FLIRLayout->addWidget(FLIR, 0, 0, 1, 6);

        FLIRIOCStop = new QPushButton(FLIRGB);
        FLIRIOCStop->setObjectName(QStringLiteral("FLIRIOCStop"));
        FLIRIOCStop->setCursor(QCursor(Qt::PointingHandCursor));

        FLIRLayout->addWidget(FLIRIOCStop, 2, 3, 1, 1);

        FLIRState = new QLabel(FLIRGB);
        FLIRState->setObjectName(QStringLiteral("FLIRState"));
        sizePolicy1.setHeightForWidth(FLIRState->sizePolicy().hasHeightForWidth());
        FLIRState->setSizePolicy(sizePolicy1);

        FLIRLayout->addWidget(FLIRState, 1, 0, 1, 1);

        FLIRIOCRestart = new QPushButton(FLIRGB);
        FLIRIOCRestart->setObjectName(QStringLiteral("FLIRIOCRestart"));
        FLIRIOCRestart->setCursor(QCursor(Qt::PointingHandCursor));

        FLIRLayout->addWidget(FLIRIOCRestart, 2, 4, 1, 1);

        FLIRDriver = new QLabel(FLIRGB);
        FLIRDriver->setObjectName(QStringLiteral("FLIRDriver"));

        FLIRLayout->addWidget(FLIRDriver, 3, 0, 1, 1);

        FLIRIOC = new QLabel(FLIRGB);
        FLIRIOC->setObjectName(QStringLiteral("FLIRIOC"));
        FLIRIOC->setCursor(QCursor(Qt::ArrowCursor));

        FLIRLayout->addWidget(FLIRIOC, 2, 0, 1, 1);

        FLIRIOCInd = new QESimpleShape(FLIRGB);
        FLIRIOCInd->setObjectName(QStringLiteral("FLIRIOCInd"));
        FLIRIOCInd->setProperty("colour0", QVariant(QColor(5, 240, 5)));

        FLIRLayout->addWidget(FLIRIOCInd, 2, 1, 1, 1);

        FLIRIOCSts = new QLabel(FLIRGB);
        FLIRIOCSts->setObjectName(QStringLiteral("FLIRIOCSts"));
        FLIRIOCSts->setCursor(QCursor(Qt::IBeamCursor));
        FLIRIOCSts->setFrameShape(QFrame::StyledPanel);
        FLIRIOCSts->setAlignment(Qt::AlignCenter);

        FLIRLayout->addWidget(FLIRIOCSts, 2, 5, 1, 1);

        FLIRIOCStart = new QPushButton(FLIRGB);
        FLIRIOCStart->setObjectName(QStringLiteral("FLIRIOCStart"));
        FLIRIOCStart->setCursor(QCursor(Qt::PointingHandCursor));

        FLIRLayout->addWidget(FLIRIOCStart, 2, 2, 1, 1);

        FLIRDriverStart = new QPushButton(FLIRGB);
        FLIRDriverStart->setObjectName(QStringLiteral("FLIRDriverStart"));
        FLIRDriverStart->setCursor(QCursor(Qt::PointingHandCursor));

        FLIRLayout->addWidget(FLIRDriverStart, 3, 2, 1, 3);

        FLIRSts = new QLabel(FLIRGB);
        FLIRSts->setObjectName(QStringLiteral("FLIRSts"));
        FLIRSts->setCursor(QCursor(Qt::IBeamCursor));
        FLIRSts->setFrameShape(QFrame::StyledPanel);
        FLIRSts->setAlignment(Qt::AlignCenter);
        FLIRSts->setWordWrap(false);

        FLIRLayout->addWidget(FLIRSts, 1, 2, 1, 4);


        gridLayout_9->addLayout(FLIRLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(FLIRGB, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        TCPServerSocketRestart->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        generalTittle->setText(QApplication::translate("MainWindow", "<html><head/><body><p>DCA | BEATS | Control &amp; Monitor</p></body></html>", Q_NULLPTR));
        commonIOCsGB->setTitle(QApplication::translate("MainWindow", "Common IOCs", Q_NULLPTR));
        tomoScanSupportIOC->setText(QApplication::translate("MainWindow", "TomoScan Support IOC", Q_NULLPTR));
        tomoScanSupportIOCSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        writerSupportIOCSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        shutterIOCStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        writerSupportIOCStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        tomoScanSupportIOCRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        tomoScanSupportIOCInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "PA:BEATS:STA_A_FES_OPEN_PL", Q_NULLPTR)));
        tomoScanSupportIOCInd->setProperty("variableSubstitutions", QVariant(QString()));
        motorIOCInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "IOC:m4", Q_NULLPTR)));
        shutterIOC->setText(QApplication::translate("MainWindow", "Shutter IOC", Q_NULLPTR));
        writerSupportIOCInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "BEATS:WRITER:NumSaved", Q_NULLPTR)));
        motorIOCSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        shutterIOCSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        shutterIOCInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "MIRRORS-IOC:scan1", Q_NULLPTR)));
        writerSupportIOC->setText(QApplication::translate("MainWindow", "Writer Support IOC", Q_NULLPTR));
        writerSupportIOCStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        motorIOCRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        tomoScanSupportIOCStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        tomoScanSupportIOCStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        shutterIOCStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        motorIOCStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        shutterIOCRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        motorIOC->setText(QApplication::translate("MainWindow", "Motor IOC", Q_NULLPTR));
        writerSupportIOCRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        motorIOCStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        PCOGB->setTitle(QApplication::translate("MainWindow", "PCO camera", Q_NULLPTR));
        PCOIOCStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        PCODriverStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        PCOIOCSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        PCOIOCInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "TEST-PCO:HDF1:StoreAttr", Q_NULLPTR)));
        PCODriver->setText(QApplication::translate("MainWindow", "PCO Driver", Q_NULLPTR));
        PCOIOCStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        PCOIOCRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        PCO->setText(QApplication::translate("MainWindow", "PCO", Q_NULLPTR));
        PCOIOC->setText(QApplication::translate("MainWindow", "PCO IOC", Q_NULLPTR));
        PCOState->setText(QApplication::translate("MainWindow", "PCO State", Q_NULLPTR));
        PCOStateInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "TEST-PCO:cam1:DetectorState_RBV", Q_NULLPTR)));
        PCOSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        generalSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        currentCamera->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        TCPServerSocketRestart->setText(QApplication::translate("MainWindow", "Restart TCP Server Socket", Q_NULLPTR));
        currentStage->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        ImageJ->setText(QApplication::translate("MainWindow", "ImageJ", Q_NULLPTR));
        ImageJStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        help->setText(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        password->setText(QString());
        contScanGB->setTitle(QApplication::translate("MainWindow", "Continuous Scan", Q_NULLPTR));
        contTomoScanIOCStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        contWriterServerSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        contPythonServer->setText(QApplication::translate("MainWindow", "Python Server", Q_NULLPTR));
        contPythonServerStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        contTomoScanIOCSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        PCOContWriterServerInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "BEATS:PCO:WRITER:CONT:Status", Q_NULLPTR)));
        contMEDM->setText(QApplication::translate("MainWindow", "MEDM", Q_NULLPTR));
        contTomoScanIOCStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        contWriterServer->setText(QApplication::translate("MainWindow", "Writer Server", Q_NULLPTR));
        contWriterServerRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        contMEDMStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        contTomoScanIOc->setText(QApplication::translate("MainWindow", "TomoScan IOC", Q_NULLPTR));
        contWriterServerStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        contPythonServerSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        contPythonServerRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        PCOContTomoScanIOCInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "tomoscanBEATS:PcoMicosCont:ScanStatus", Q_NULLPTR)));
        contTomoScanIOCRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        contPythonServerStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        contWriterServerStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        PCOContPythonServerInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "tomoscanBEATS:PcoMicosCont:ServerRunning", Q_NULLPTR)));
        FLIRContTomoScanIOCInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "tomoscanBEATS:FlirMicosCont:CameraObjective", Q_NULLPTR)));
        FLIRContPythonServerInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "tomoscanBEATS:FlirMicosCont:ServerRunning", Q_NULLPTR)));
        FLIRContWriterServerInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "BEATS:FLIR:WRITER:CONT:Status", Q_NULLPTR)));
        stepScanGB->setTitle(QApplication::translate("MainWindow", "Step Scan", Q_NULLPTR));
        stepMEDM->setText(QApplication::translate("MainWindow", "MEDM", Q_NULLPTR));
        stepPythonServerStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        stepPythonServer->setText(QApplication::translate("MainWindow", "Python Server", Q_NULLPTR));
        PCOStepTomoScanIOCInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "tomoscanBEATS:PcoMicosStep:ScanStatus", Q_NULLPTR)));
        stepMEDMStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        stepTomoScanIOCStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        stepWriterServer->setText(QApplication::translate("MainWindow", "Writer Server", Q_NULLPTR));
        stepTomoScanIOCStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        stepPythonServerSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        stepWriterServerStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        stepTomoScanIOC->setText(QApplication::translate("MainWindow", "TomoScan IOC", Q_NULLPTR));
        stepWriterServerRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        stepPythonServerRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        stepTomoScanIOCRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        stepPythonServerStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        stepWriterServerSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        PCOStepPythonServerInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "tomoscanBEATS:PcoMicosStep:ServerRunning", Q_NULLPTR)));
        PCOStepWriterServerInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "BEATS:PCO:WRITER:STEP:Status", Q_NULLPTR)));
        stepWriterServerStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        stepTomoScanIOCSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        FLIRStepTomoScanIOCInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "tomoscanBEATS:FlirMicosStep:CameraObjective", Q_NULLPTR)));
        FLIRStepPythonServerInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "tomoscanBEATS:FlirMicosStep:ServerRunning", Q_NULLPTR)));
        FLIRStepWriterServerInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "BEATS:FLIR:WRITER:STEP:Status", Q_NULLPTR)));
        CameraType->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        FLIRGB->setTitle(QApplication::translate("MainWindow", "FLIR Camera", Q_NULLPTR));
        FLIRStateInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "FLIR:cam1:DetectorState_RBV", Q_NULLPTR)));
        FLIR->setText(QApplication::translate("MainWindow", "FLIR", Q_NULLPTR));
        FLIRIOCStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        FLIRState->setText(QApplication::translate("MainWindow", "FLIR State", Q_NULLPTR));
        FLIRIOCRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        FLIRDriver->setText(QApplication::translate("MainWindow", "FLIR Driver", Q_NULLPTR));
        FLIRIOC->setText(QApplication::translate("MainWindow", "FLIR IOC", Q_NULLPTR));
        FLIRIOCInd->setProperty("variable", QVariant(QApplication::translate("MainWindow", "FLIR:cam1:ARCheckConnection", Q_NULLPTR)));
        FLIRIOCInd->setProperty("variableSubstitutions", QVariant(QString()));
        FLIRIOCSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
        FLIRIOCStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        FLIRDriverStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        FLIRSts->setText(QApplication::translate("MainWindow", "---", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
