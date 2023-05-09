#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qepicspv.h>
#include <client.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PCO_clicked();

    void on_FLIR_clicked();

    void on_shutterIOCStart_clicked();

    void on_shutterIOCStop_clicked();

    void on_shutterIOCRestart_clicked();

    void on_motorIOCStart_clicked();

    void on_motorIOCStop_clicked();

    void on_tomoScanSupportIOCStart_clicked();

    void on_motorIOCRestart_clicked();

    void on_motorGUI_clicked();

    void on_tomoScanSupportIOCStop_clicked();

    void on_tomoScanSupportIOCRestart_clicked();

    void on_writerSupportIOCStart_clicked();

    void on_writerSupportIOCStop_clicked();

    void on_writerSupportIOCRestart_clicked();

    void on_stepTomoScanIOCStart_clicked();

    void on_stepTomoScanIOCStop_clicked();

    void on_stepTomoScanIOCRestart_clicked();

    void on_stepPythonServerStart_clicked();

    void on_stepPythonServerStop_clicked();

    void on_stepPythonServerRestart_clicked();

    void on_stepWriterServerStart_clicked();

    void on_stepWriterServerStop_clicked();

    void on_stepWriterServerRestart_clicked();

    void on_stepMEDMStart_clicked();

    void on_contTomoScanIOCStart_clicked();

    void on_contPythonServerStart_clicked();

    void on_contTomoScanIOCStop_clicked();

    void on_contMEDMStart_clicked();

    void on_contTomoScanIOCRestart_clicked();

    void on_contPythonServerRestart_clicked();

    void on_contWriterServerRestart_clicked();

    void on_contWriterServerStop_clicked();

    void on_contPythonServerStop_clicked();

    void on_contWriterServerStart_clicked();

    void checkStatusH();
    void checkStatusL();
    void checkScanSts();

    void on_FLIRIOCStart_clicked();

    void on_FLIRIOCStop_clicked();

    void on_FLIRIOCRestart_clicked();

    void on_PCOIOCStart_clicked();

    void on_PCOIOCStop_clicked();

    void on_PCOIOCRestart_clicked();

    void on_ImageJStart_clicked();

    void on_help_clicked();

    void on_FLIRDriverStart_clicked();

    void on_PCODriverStart_clicked();

    void startProcess(QString Process, QString Camera);
    void stopProcess(QString Process, QString Camera);
    void restartProcess(QString Process, QString Camera);

    void on_TCPServerSocketRestart_clicked();

    void on_password_editingFinished();

    void set_PCO_indicators_color(char PCO_Color);
    void set_FLIR_indicators_color(char FLIR_Color);

    void on_motroReset_clicked();

private:
    Ui::MainWindow *ui;

    QString camera = NULL;
    QString cam;
    QString process;
    char PCO_color;
    char FLIR_color;
    QTimer* TimerH;
    QTimer* TimerL;
    QTimer* scanSts;

    QString started = "Started";
    QString running = "Running";
    QString stopped = "Stopped";
    QString restarted = "Restarted";
/* --------------------------------------------------------------*/

    QEpicsPV* PCOIOC;
    QEpicsPV* FLIRIOC;
    QEpicsPV* PCOState;
    QEpicsPV* FLIRState;

    QEpicsPV* shutterIOC;
    QEpicsPV* motorIOC;
    QEpicsPV* tomoScanSupportIOC;
    QEpicsPV* writerSupportIOC;

    QEpicsPV* exposureShutterIOC;
    QEpicsPV* radiationShutterIOC;
    QEpicsPV* photonShutterIOC;
    QEpicsPV* combinedStopperIOC;
    QEpicsPV* PSSIOC;

    QEpicsPV* radiationShutterFault;
    QEpicsPV* photonShutterFault;
    QEpicsPV* combinedStopperFault;

    QEpicsPV* PCO_TomoScanIOCStep;
    QEpicsPV* PCO_PythonServerStep;
    QEpicsPV* PCO_TomoScanIOCCont;
    QEpicsPV* PCO_PythonServerCont;

    QEpicsPV* FLIR_TomoScanIOCStep;
    QEpicsPV* FLIR_PythonServerStep;
    QEpicsPV* FLIR_TomoScanIOCCont;
    QEpicsPV* FLIR_PythonServerCont;

    QEpicsPV* writerServerCont;
    QEpicsPV* writerServerStep;
    QEpicsPV* writerServerTrig;

    QEpicsPV* PCO_WriterServerCont;
    QEpicsPV* PCO_WriterServerStep;
    QEpicsPV* FLIR_WriterServerCont;
    QEpicsPV* FLIR_WriterServerStep;

    QEpicsPV* PCOIOC_SEVR;
    QEpicsPV* FLIRIOC_SEVR;

    QEpicsPV* shutterIOC_SEVR;
    QEpicsPV* motorIOC_SEVR;
    QEpicsPV* tomoScanSupportIOC_SEVR;
    QEpicsPV* writerSupportIOC_SEVR;

    QEpicsPV* exposureShutterIOC_SEVR;
    QEpicsPV* radiationShutterIOC_SEVR;
    QEpicsPV* photonShutterIOC_SEVR;
    QEpicsPV* combinedStopperIOC_SEVR;
    QEpicsPV* PSSIOC_SEVR;

    QEpicsPV* PCO_TomoScanIOCStep_SEVR;
    QEpicsPV* PCO_PythonServerStep_SEVR;
    QEpicsPV* PCO_TomoScanIOCCont_SEVR;
    QEpicsPV* PCO_PythonServerCont_SEVR;

    QEpicsPV* FLIR_TomoScanIOCStep_SEVR;
    QEpicsPV* FLIR_PythonServerStep_SEVR;
    QEpicsPV* FLIR_TomoScanIOCCont_SEVR;
    QEpicsPV* FLIR_PythonServerCont_SEVR;

    QEpicsPV* writerServerCont_SEVR;
    QEpicsPV* writerServerStep_SEVR;
    QEpicsPV* writerServerTrig_SEVR;
/* --------------------------------------------------------------*/

    QString PCOIOC_SEVR_;
    QString FLIRIOC_SEVR_;

    QString shutterIOC_SEVR_;
    QString motorIOC_SEVR_;
    QString tomoScanSupportIOC_SEVR_;
    QString writerSupportIOC_SEVR_;

    QString exposureShutterIOC_SEVR_;
    QString radiationShutterIOC_SEVR_;
    QString photonShutterIOC_SEVR_;
    QString combinedStopperIOC_SEVR_;
    QString PSSIOC_SEVR_;

    QString PCO_TomoScanIOC_Step_SEVR_;
    QString PCO_PythonServer_Step_SEVR_;
    QString PCO_TomoScanIOC_Cont_SEVR_;
    QString PCO_PythonServer_Cont_SEVR_;

    QString FLIR_TomoScanIOC_Step_SEVR_;
    QString FLIR_PythonServer_Step_SEVR_;
    QString FLIR_TomoScanIOC_Cont_SEVR_;
    QString FLIR_PythonServer_Cont_SEVR_;

    QString writerServer_Step_SEVR_;
    QString writerServer_Cont_SEVR_;

    int PCOState_;
    int FLIRState_;

    int writerServer_Step_;
    int writerServer_Cont_;

    int PCO_WriterServer_Step_;
    int PCO_WriterServer_Cont_;
    int FLIR_WriterServer_Step_;
    int FLIR_WriterServer_Cont_;

    int PCO_PythonServer_Step_;
    int PCO_PythonServer_Cont_;
    int FLIR_PythonServer_Step_;
    int FLIR_PythonServer_Cont_;

    int radiationShutter;
    int photonShutter;
    int combinedStopper;
    bool PSS;

    int radiationShutterFault_;
    int photonShutterFault_;
    int combinedStopperFault_;

};
#endif // MAINWINDOW_H
