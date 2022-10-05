#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include <QString>
#include <QProcess>
#include <QDir>
#include <QDesktopServices>
#include <QCryptographicHash>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir::setCurrent("/opt/operation/BEATS_Dashboard/Scripts");       // set the directory of the bash scripts

    // read PVs and SEVR//

    this->PCOIOC                      = new QEpicsPV("TEST-PCO:HDF1:StoreAttr");
    this->FLIRIOC                     = new QEpicsPV("FLIR:cam1:ARCheckConnection");
    this->PCOState                    = new QEpicsPV("TEST-PCO:cam1:DetectorState_RBV");
    this->FLIRState                   = new QEpicsPV("FLIR:cam1:DetectorState_RBV");

    this->shutterIOC                  = new QEpicsPV("MIRRORS-IOC:scan1");
    this->motorIOC                    = new QEpicsPV("IOC:m4");
    this->tomoScanSupportIOC          = new QEpicsPV("PA:BEATS:STA_A_FES_OPEN_PL");
    this->writerSupportIOC            = new QEpicsPV("BEATS:WRITER:NumSaved");

    this->PCO_TomoScanIOCStep         = new QEpicsPV("BEATS_STEP:SR_0_State");
    this->PCO_PythonServerStep        = new QEpicsPV("BEATS_STEP:TomoScan:ServerRunning");
    this->PCO_TomoScanIOCCont         = new QEpicsPV("BEATS_CONTINUOUS:SR_0_State");
    this->PCO_PythonServerCont        = new QEpicsPV("BEATS_CONTINUOUS:TomoScan:ServerRunning");

    this->FLIR_TomoScanIOCStep        = new QEpicsPV("beats:TomoScanStep:CameraObjective");
    this->FLIR_PythonServerStep       = new QEpicsPV("beats:TomoScanStep:ServerRunning");
    this->FLIR_TomoScanIOCCont        = new QEpicsPV("beats:TomoScanCont:CameraObjective");
    this->FLIR_PythonServerCont       = new QEpicsPV("beats:TomoScanCont:ServerRunning");

    this->writerServerStep            = new QEpicsPV("BEATS:WRITER:STEP:Status");
    this->writerServerCont            = new QEpicsPV("BEATS:WRITER:CONT:Status");
    this->writerServerTrig            = new QEpicsPV("BEATS:WRITER:NewFileTrigger");

    this->PCO_WriterServerStep        = new QEpicsPV("BEATS:PCO:WRITER:STEP:Status");
    this->PCO_WriterServerCont        = new QEpicsPV("BEATS:PCO:WRITER:CONT:Status");
    this->FLIR_WriterServerStep       = new QEpicsPV("BEATS:FLIR:WRITER:STEP:Status");
    this->FLIR_WriterServerCont       = new QEpicsPV("BEATS:FLIR:WRITER:CONT:Status");

    this->PCOIOC_SEVR                 = new QEpicsPV("TEST-PCO:HDF1:StoreAttr.SEVR");
    this->FLIRIOC_SEVR                = new QEpicsPV("FLIR:cam1:ARCheckConnection.SEVR");

    this->shutterIOC_SEVR             = new QEpicsPV("MIRRORS-IOC:scan1.SEVR");
    this->motorIOC_SEVR               = new QEpicsPV("IOC:m4.SEVR");
    this->tomoScanSupportIOC_SEVR     = new QEpicsPV("PA:BEATS:STA_A_FES_OPEN_PL.SEVR");
    this->writerSupportIOC_SEVR       = new QEpicsPV("BEATS:WRITER:NumSaved.SEVR");

    this->PCO_TomoScanIOCStep_SEVR   = new QEpicsPV("BEATS_STEP:SR_0_State.SEVR");
    this->PCO_PythonServerStep_SEVR  = new QEpicsPV("BEATS_STEP:TomoScan:ServerRunning.SEVR");
    this->PCO_TomoScanIOCCont_SEVR   = new QEpicsPV("BEATS_CONTINUOUS:SR_0_State.SEVR");
    this->PCO_PythonServerCont_SEVR  = new QEpicsPV("BEATS_CONTINUOUS:TomoScan:ServerRunning.SEVR");

    this->FLIR_TomoScanIOCStep_SEVR    = new QEpicsPV("beats:TomoScanStep:CameraObjective.SEVR");
    this->FLIR_PythonServerStep_SEVR   = new QEpicsPV("beats:TomoScanStep:ServerRunning.SEVR");
    this->FLIR_TomoScanIOCCont_SEVR    = new QEpicsPV("beats:TomoScanCont:CameraObjective.SEVR");
    this->FLIR_PythonServerCont_SEVR   = new QEpicsPV("beats:TomoScanCont:ServerRunning.SEVR");

    this->writerServerStep_SEVR       = new QEpicsPV("BEATS:WRITER:STEP:Status.SEVR");
    this->writerServerCont_SEVR       = new QEpicsPV("BEATS:WRITER:CONT:Status.SEVR");
    this->writerServerTrig_SEVR       = new QEpicsPV("BEATS:WRITER:NewFileTrigger.SEVR");

    ui->PCOGB->setEnabled(false);
    ui->FLIRGB->setEnabled(false);
    ui->stepScanGB->setEnabled(false);
    ui->contScanGB->setEnabled(false);

    ui->TCPServerSocketRestart->setEnabled(false);
    ui->TCPServerSocketRestart->setHidden(true);
    ui->password->setHidden(true);

    TimerH = new QTimer(this);
    this->TimerH->start(400);

    connect(TimerH, SIGNAL(timeout()), this, SLOT(checkStatusH()));    // infinite loop

    TimerL = new QTimer(this);
    this->TimerL->start(1000);

    connect(TimerL, SIGNAL(timeout()), this, SLOT(checkStatusL()));    // infinite loop

    if ( PCO_WriterServer_Step_ == 1 or PCO_WriterServer_Cont_ == 1 or PCO_TomoScanIOC_Step_SEVR_ != NULL or PCO_TomoScanIOC_Cont_SEVR_ != NULL)
        ui->FLIR->setEnabled(false);

    if (FLIR_WriterServer_Step_ == 1 or FLIR_WriterServer_Cont_ == 1 or FLIR_TomoScanIOC_Step_SEVR_ != NULL or FLIR_TomoScanIOC_Cont_SEVR_ != NULL)
        ui->PCO->setEnabled(false);

    if (PCO_TomoScanIOC_Step_SEVR_ != NULL)
        ui->generalSts->setText("PCO TomoScan IOC -Step- is running ...");
    if (PCO_TomoScanIOC_Cont_SEVR_ != NULL)
        ui->generalSts->setText("PCO TomoScan IOC -Continuous- is running ...");
    if (FLIR_TomoScanIOC_Step_SEVR_ != NULL)
        ui->generalSts->setText("FLIR TomoScan IOC -Step- is running ...");
    if (FLIR_TomoScanIOC_Cont_SEVR_ != NULL)
        ui->generalSts->setText("FLIR TomoScan IOC -Continuous- is running ...");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PCO_clicked()
{
    camera = "PCO";

    ui->generalSts->setText(camera + " Camera is selected");

    // hide the FLIR indicators objects
    ui->FLIRStepTomoScanIOCInd->setHidden(true);
    ui->FLIRStepPythonServerInd->setHidden(true);
    ui->FLIRStepWriterServerInd->setHidden(true);
    ui->FLIRContTomoScanIOCInd->setHidden(true);
    ui->FLIRContPythonServerInd->setHidden(true);
    ui->FLIRContWriterServerInd->setHidden(true);

    ui->PCOStepTomoScanIOCInd->setHidden(false);
    ui->PCOStepPythonServerInd->setHidden(false);
    ui->PCOStepWriterServerInd->setHidden(false);
    ui->PCOContTomoScanIOCInd->setHidden(false);
    ui->PCOContPythonServerInd->setHidden(false);
    ui->PCOContWriterServerInd->setHidden(false);
}

void MainWindow::on_FLIR_clicked()
{
//    QProcess* FLIRIOCStart = new QProcess(this);
//    FLIRIOCStart->start("gnome-terminal -x ./FLIR_CameraStart.sh ");
    camera = "FLIR";

    ui->generalSts->setText(camera + " Camera is selected");

    // hide the PCO indicators objects
    ui->PCOStepTomoScanIOCInd->setHidden(true);
    ui->PCOStepPythonServerInd->setHidden(true);
    ui->PCOStepWriterServerInd->setHidden(true);
    ui->PCOContTomoScanIOCInd->setHidden(true);
    ui->PCOContPythonServerInd->setHidden(true);
    ui->PCOContWriterServerInd->setHidden(true);

    ui->FLIRStepTomoScanIOCInd->setHidden(false);
    ui->FLIRStepPythonServerInd->setHidden(false);
    ui->FLIRStepWriterServerInd->setHidden(false);
    ui->FLIRContTomoScanIOCInd->setHidden(false);
    ui->FLIRContPythonServerInd->setHidden(false);
    ui->FLIRContWriterServerInd->setHidden(false);
}
/* --------------------------------------------------------------*/
void MainWindow::startProcess(QString Process, QString Camera)
{
    process = Process;
    cam = Camera;
    QProcess* startProcess = new QProcess(this);
    startProcess->start("gnome-terminal -x ./BEATS_GUI_Bash_Start --process " + cam + process);
}

void MainWindow::stopProcess(QString Process, QString Camera)
{
    process = Process;
    cam = Camera;
    QProcess* stopProcess = new QProcess(this);
    stopProcess->start("gnome-terminal -x ./BEATS_GUI_Bash_Stop --process " + cam + process);
}

void MainWindow::restartProcess(QString Process, QString Camera)
{
    process = Process;
    cam = Camera;
    QProcess* restartProcess = new QProcess(this);
    restartProcess->start("gnome-terminal -x ./BEATS_GUI_Bash_Restart --process " + cam + process);
}
/* --------------------------------------------------------------*/

void MainWindow::on_PCOIOCStart_clicked()
{
    QProcess* PCOStart = new QProcess(this);
    PCOStart->start("gnome-terminal -x python TCPClientSocket.py --process start");
}

void MainWindow::on_PCOIOCStop_clicked()
{
    QProcess* PCOStop = new QProcess(this);
    PCOStop->start("gnome-terminal -x python TCPClientSocket.py --process stop");
}

void MainWindow::on_PCOIOCRestart_clicked()
{
    QProcess* PCORestart = new QProcess(this);
    PCORestart->start("gnome-terminal -x python TCPClientSocket.py --process restart");
}

void MainWindow::on_TCPServerSocketRestart_clicked()
{
    QProcess* TCPServerSocketRestart = new QProcess(this);
    TCPServerSocketRestart->start("gnome-terminal -x python TCPClientSocket.py --process TCPServerSocketRestart");

    ui->TCPServerSocketRestart->setEnabled(false);
}

void MainWindow::on_FLIRIOCStart_clicked()
{
    startProcess("FLIRIOC","");
    ui->generalSts->setText("FLIR IOC " + started + " ...");
}

void MainWindow::on_FLIRIOCStop_clicked()
{
    stopProcess("FLIRIOC","");
    ui->generalSts->setText("FLIR IOC " + stopped + " ...");
}

void MainWindow::on_FLIRIOCRestart_clicked()
{
    restartProcess("FLIRIOC","");
    ui->generalSts->setText("FLIR IOC " + restarted + " ...");
}
/* --------------------------------------------------------------*/

void MainWindow::on_PCODriverStart_clicked()
{
    startProcess("Driver","PCO");
}
/* --------------------------------------------------------------*/

void MainWindow::on_FLIRDriverStart_clicked()
{
    startProcess("Driver","FLIR");
}
/* --------------------------------------------------------------*/

void MainWindow::on_shutterIOCStart_clicked()
{
    startProcess("shutterIOC","");
    ui->generalSts->setText("Shutter IOC " + started + " ...");
}

void MainWindow::on_shutterIOCStop_clicked()
{
    stopProcess("shutterIOC","");
    ui->generalSts->setText("Shutter IOC " + stopped + " ...");
}

void MainWindow::on_shutterIOCRestart_clicked()
{
    restartProcess("shutterIOC","");
    ui->generalSts->setText("Shutter IOC " + restarted + " ...");
}
/* --------------------------------------------------------------*/

void MainWindow::on_motorIOCStart_clicked()
{
    startProcess("motorIOC","");
    ui->generalSts->setText("Motor IOC " + started + " ...");
}

void MainWindow::on_motorIOCStop_clicked()
{
    stopProcess("motorIOC","");
    ui->generalSts->setText("Motor IOC " + stopped + " ...");
}

void MainWindow::on_motorIOCRestart_clicked()
{
    restartProcess("motorIOC","");
    ui->generalSts->setText("Motor IOC " + restarted + " ...");
}
/* --------------------------------------------------------------*/

void MainWindow::on_tomoScanSupportIOCStart_clicked()
{
    startProcess("tomoscanSupportIOC","");
    ui->generalSts->setText("Tomoscan Support IOC " + started + " ...");
}

void MainWindow::on_tomoScanSupportIOCStop_clicked()
{
    stopProcess("tomoscanSupportIOC","");
    ui->generalSts->setText("Tomoscan Support IOC " + stopped + " ...");
}

void MainWindow::on_tomoScanSupportIOCRestart_clicked()
{
    restartProcess("tomoscanSupportIOC","");
    ui->generalSts->setText("Tomoscan Support IOC " + restarted + " ...");
}
/* --------------------------------------------------------------*/

void MainWindow::on_writerSupportIOCStart_clicked()
{
    startProcess("writerSupportIOC","");
    ui->generalSts->setText("Writer Support IOC " + started + " ...");
}

void MainWindow::on_writerSupportIOCStop_clicked()
{
    stopProcess("writerSupportIOC","");
    ui->generalSts->setText("Writer Support IOC " + stopped + " ...");
}

void MainWindow::on_writerSupportIOCRestart_clicked()
{
    restartProcess("writerSupportIOC","");
    ui->generalSts->setText("Writer Support IOC " + restarted + " ...");
}
/* --------------------------------------------------------------*/

void MainWindow::on_stepTomoScanIOCStart_clicked()
{
    startProcess("_StepTomoscanIOC",camera);
    ui->generalSts->setText(camera + " - Step TomoScan IOC " + started + " ...");

    // stop the continuous writer for PCO & FLIR in case the writer was started (if you exit from GUI by mistake and run it again)
    stopProcess("_WriterServerCont","PCO");
    stopProcess("_WriterServerCont","FLIR");

    if (camera == "PCO" ){
        stopProcess("_StepTomoscanIOC","FLIR");
        stopProcess("_ContTomoscanIOC","FLIR");
    }
    if (camera == "FLIR" ){
        stopProcess("_StepTomoscanIOC","PCO");
        stopProcess("_ContTomoscanIOC","PCO");
    }
}

void MainWindow::on_stepTomoScanIOCStop_clicked()
{
    stopProcess("_StepTomoscanIOC",camera);
    ui->generalSts->setText(camera + " - Step TomoScan IOC " + stopped + " ...");

    // stop the python and writer servers also!!!
    stopProcess("_PythonServerStep",camera);
    stopProcess("_WriterServerStep",camera);
}

void MainWindow::on_stepTomoScanIOCRestart_clicked()
{
    restartProcess("_StepTomoscanIOC",camera);
    ui->generalSts->setText(camera + " - Step TomoScan IOC " + restarted + " ...");
}
/* --------------------------------------------------------------*/

void MainWindow::on_stepPythonServerStart_clicked()
{
    startProcess("_PythonServerStep",camera);
    ui->generalSts->setText(camera + " - Step Python Server " + started + " ...");
}

void MainWindow::on_stepPythonServerStop_clicked()
{
    stopProcess("_PythonServerStep",camera);
    ui->generalSts->setText(camera + " - Step Python Server " + stopped + " ...");
}

void MainWindow::on_stepPythonServerRestart_clicked()
{
    restartProcess("_PythonServerStep",camera);
    ui->generalSts->setText(camera + " - Step Python Server " + restarted + " ...");
}
/* --------------------------------------------------------------*/

void MainWindow::on_stepWriterServerStart_clicked()
{
    startProcess("_WriterServerStep",camera);
    ui->generalSts->setText(camera + " Step Writer Server " + started + " ...");

    // stop the continuous writer for PCO & FLIR in case the writer was started (if you exit from GUI by mistake and run it again)
    stopProcess("_WriterServerCont","PCO");
    stopProcess("_WriterServerCont","FLIR");
}

void MainWindow::on_stepWriterServerStop_clicked()
{
    stopProcess("_WriterServerStep",camera);
    ui->generalSts->setText(camera + " - Step Writer Server " + stopped + " ...");
}

void MainWindow::on_stepWriterServerRestart_clicked()
{
    restartProcess("_WriterServerStep",camera);
    ui->generalSts->setText(camera + " - Step Writer Server " + restarted + " ...");
}
/* --------------------------------------------------------------*/

void MainWindow::on_stepMEDMStart_clicked()
{
    startProcess("_StepMEDM",camera);
}
/* --------------------------------------------------------------*/

void MainWindow::on_contTomoScanIOCStart_clicked()
{
    startProcess("_ContTomoscanIOC",camera);
    ui->generalSts->setText(camera + " - Continuous TomoScan IOC " + started + " ...");

    // stop the step writer for PCO & FLIR in case the writer was started (if you exit from GUI by mistake and run it again)
    stopProcess("_WriterServerStep","PCO");
    stopProcess("_WriterServerStep","FLIR");

    if (camera == "PCO" ){
        stopProcess("_StepTomoscanIOC","FLIR");
        stopProcess("_ContTomoscanIOC","FLIR");
    }
    if (camera == "FLIR" ){
        stopProcess("_StepTomoscanIOC","PCO");
        stopProcess("_ContTomoscanIOC","PCO");
    }
}

void MainWindow::on_contTomoScanIOCStop_clicked()
{
    stopProcess("_ContTomoscanIOC",camera);
    ui->generalSts->setText(camera + " - Continuous TomoScan IOC " + stopped + " ...");

    // stop the python and writer servers also!!!
    stopProcess("_PythonServerCont",camera);
    stopProcess("_WriterServerCont",camera);
}

void MainWindow::on_contTomoScanIOCRestart_clicked()
{
    restartProcess("_ContTomoscanIOC",camera);
    ui->generalSts->setText(camera + " - Continuous TomoScan IOC " + restarted + " ...");
}
/* --------------------------------------------------------------*/

void MainWindow::on_contPythonServerStart_clicked()
{
    startProcess("_PythonServerCont",camera);
    ui->generalSts->setText(camera + " - Continuous Python Server " + started + " ...");
}

void MainWindow::on_contPythonServerStop_clicked()
{
    stopProcess("_PythonServerCont",camera);
    ui->generalSts->setText(camera + " - Continuous Python Server " + stopped + " ...");
}

void MainWindow::on_contPythonServerRestart_clicked()
{
    restartProcess("_PythonServerCont",camera);
    ui->generalSts->setText(camera + " - Continuous Python Server " + restarted + " ...");
}
/* --------------------------------------------------------------*/

void MainWindow::on_contWriterServerStart_clicked()
{
    startProcess("_WriterServerCont",camera);
    ui->generalSts->setText(camera + " - Continuous Writer Server " + started + " ...");

    // stop the step writer for PCO & FLIR in case the writer was started (if you exit from GUI by mistake and run it again)
    stopProcess("_WriterServerStep","PCO");
    stopProcess("_WriterServerStep","FLIR");
}

void MainWindow::on_contWriterServerStop_clicked()
{
    stopProcess("_WriterServerCont",camera);
    ui->generalSts->setText(camera + " - Continuous Writer Server " + stopped + " ...");
}

void MainWindow::on_contWriterServerRestart_clicked()
{
    restartProcess("_WriterServerCont",camera);
    ui->generalSts->setText(camera + " - Continuous Writer Server " + restarted + " ...");
}
/* --------------------------------------------------------------*/

void MainWindow::on_contMEDMStart_clicked()
{
    startProcess("_ContMEDM",camera);
}
/* --------------------------------------------------------------*/

void MainWindow::on_ImageJStart_clicked()
{
    startProcess("ImageJ","");
}
/* --------------------------------------------------------------*/

void MainWindow::checkStatusH()
{
   // get the SEVR as string (to make the comparison with NULL)
   PCOIOC_SEVR_                  = this->PCOIOC_SEVR->get().toString();
   FLIRIOC_SEVR_                 = this->FLIRIOC_SEVR->get().toString();

   shutterIOC_SEVR_              = this->shutterIOC_SEVR->get().toString();
   motorIOC_SEVR_                = this->motorIOC_SEVR->get().toString();
   tomoScanSupportIOC_SEVR_      = this->tomoScanSupportIOC_SEVR->get().toString();
   writerSupportIOC_SEVR_        = this->writerSupportIOC_SEVR->get().toString();

   PCO_TomoScanIOC_Step_SEVR_    = this->PCO_TomoScanIOCStep_SEVR->get().toString();
   PCO_PythonServer_Step_SEVR_   = this->PCO_PythonServerStep_SEVR->get().toString();
   PCO_TomoScanIOC_Cont_SEVR_    = this->PCO_TomoScanIOCCont_SEVR->get().toString();
   PCO_PythonServer_Cont_SEVR_   = this->PCO_PythonServerCont_SEVR->get().toString();

   FLIR_TomoScanIOC_Step_SEVR_   = this->FLIR_TomoScanIOCStep_SEVR->get().toString();
   FLIR_PythonServer_Step_SEVR_  = this->FLIR_PythonServerStep_SEVR->get().toString();
   FLIR_TomoScanIOC_Cont_SEVR_   = this->FLIR_TomoScanIOCCont_SEVR->get().toString();
   FLIR_PythonServer_Cont_SEVR_  = this->FLIR_PythonServerCont_SEVR->get().toString();

   writerServer_Step_SEVR_       = this->writerServerStep_SEVR->get().toString();
   writerServer_Cont_SEVR_       = this->writerServerCont_SEVR->get().toString();

   // get the int value (as a trigger , if x==1)
   PCOState_                     = this->PCOState->get().toInt();
   FLIRState_                    = this->FLIRState->get().toInt();

   writerServer_Step_            = this->writerServerStep->get().toInt();
   writerServer_Cont_            = this->writerServerCont->get().toInt();

   PCO_WriterServer_Step_        = this->PCO_WriterServerStep->get().toInt();
   PCO_WriterServer_Cont_        = this->PCO_WriterServerCont->get().toInt();
   FLIR_WriterServer_Step_       = this->FLIR_WriterServerStep->get().toInt();
   FLIR_WriterServer_Cont_       = this->FLIR_WriterServerCont->get().toInt();

   PCO_PythonServer_Step_  = this->PCO_PythonServerStep->get().toInt();
   PCO_PythonServer_Cont_  = this->PCO_PythonServerCont->get().toInt();
   FLIR_PythonServer_Step_ = this->FLIR_PythonServerStep->get().toInt();
   FLIR_PythonServer_Cont_ = this->FLIR_PythonServerCont->get().toInt();
/* --------------------------------------------------------------*/

    if (shutterIOC_SEVR_ != NULL){
        ui->shutterIOCStart->setEnabled(false);
        ui->shutterIOCStop->setEnabled(true);
        ui->shutterIOCRestart->setEnabled(true);

        ui->shutterIOCSts->setText(running);
    }
    else {
            ui->shutterIOCStart->setEnabled(true);
            ui->shutterIOCStop->setEnabled(false);
            ui->shutterIOCRestart->setEnabled(false);

            ui->shutterIOCSts->setText(stopped);
    }


    if (motorIOC_SEVR_ != NULL){
        ui->motorIOCStart->setEnabled(false);
        ui->motorIOCStop->setEnabled(true);
        ui->motorIOCRestart->setEnabled(true);

        ui->motorIOCSts->setText(running);
    }
    else {
        ui->motorIOCStart->setEnabled(true);
        ui->motorIOCStop->setEnabled(false);
        ui->motorIOCRestart->setEnabled(false);

        ui->motorIOCSts->setText(stopped);
    }


    if (tomoScanSupportIOC_SEVR_ != NULL){
        ui->tomoScanSupportIOCStart->setEnabled(false);
        ui->tomoScanSupportIOCStop->setEnabled(true);
        ui->tomoScanSupportIOCRestart->setEnabled(true);

        ui->tomoScanSupportIOCSts->setText(running);
    }
    else {
        ui->tomoScanSupportIOCStart->setEnabled(true);
        ui->tomoScanSupportIOCStop->setEnabled(false);
        ui->tomoScanSupportIOCRestart->setEnabled(false);

        ui->tomoScanSupportIOCSts->setText(stopped);
    }


    if (writerSupportIOC_SEVR_ != NULL){
        ui->writerSupportIOCStart->setEnabled(false);
        ui->writerSupportIOCStop->setEnabled(true);
        ui->writerSupportIOCRestart->setEnabled(true);

        ui->writerSupportIOCSts->setText(running);
    }
    else {
        ui->writerSupportIOCStart->setEnabled(true);
        ui->writerSupportIOCStop->setEnabled(false);
        ui->writerSupportIOCRestart->setEnabled(false);

        ui->writerSupportIOCSts->setText(stopped);
    }

    if (PCOIOC_SEVR_ != NULL){

        ui->PCOIOCStart->setEnabled(false);
        ui->PCOIOCStop->setEnabled(true);
        ui->PCOIOCRestart->setEnabled(true);

        ui->PCOIOCSts->setText(running);
    }
    else {
        ui->PCOIOCStart->setEnabled(true);
        ui->PCOIOCStop->setEnabled(false);
        ui->PCOIOCRestart->setEnabled(false);

        ui->PCOIOCSts->setText(stopped);
    }

    if (FLIRIOC_SEVR_ != NULL){

        ui->FLIRIOCStart->setEnabled(false);
        ui->FLIRIOCStop->setEnabled(true);
        ui->FLIRIOCRestart->setEnabled(true);

        ui->FLIRIOCSts->setText(running);
    }
    else {
        ui->FLIRIOCStart->setEnabled(true);
        ui->FLIRIOCStop->setEnabled(false);
        ui->FLIRIOCRestart->setEnabled(false);

        ui->FLIRIOCSts->setText(stopped);
    }
    /* --------------------------------------------------------------*/

    if (!(ui->shutterIOCStart->isEnabled() or ui->motorIOCStart->isEnabled() or ui->tomoScanSupportIOCStart->isEnabled() or ui->writerSupportIOCStart->isEnabled())){

        ui->PCOGB->setEnabled(true);
        ui->FLIRGB->setEnabled(true);

        if (PCOState_ == 9 or PCOIOC_SEVR_ == NULL){
//            ui->PCO->setEnabled(false);
            ui->PCOSts->setText("Disconnected");
        }
        else {
//            ui->PCO->setEnabled(true);
            ui->PCOSts->setText("Connected");

        }

        if (FLIRState_ == 9 or FLIRIOC_SEVR_ == NULL){
//            ui->FLIR->setEnabled(false);
            ui->FLIRSts->setText("Disconnected");
        }
        else {
//            ui->FLIR->setEnabled(true);
            ui->FLIRSts->setText("Connected");
        }

        if (PCOIOC_SEVR_ != NULL && camera == "PCO"){

            ui->stepScanGB->setEnabled(true);
            ui->contScanGB->setEnabled(true);

            if (PCO_TomoScanIOC_Step_SEVR_ != NULL){

                ui->stepTomoScanIOCStart->setEnabled(false);
                ui->stepTomoScanIOCStop->setEnabled(true);
                ui->stepTomoScanIOCRestart->setEnabled(true);

                ui->contScanGB->setHidden(true);
                ui->FLIRGB->setEnabled(false);

//                ui->generalSts->setText("PCO TomoScan IOC -Step- is running ...");
                ui->CameraType->setText(camera + " Camera && Step Scan is selected");
                ui->stepTomoScanIOCSts->setText(running);
            }
            else
            {
                ui->stepTomoScanIOCStart->setEnabled(true);
                ui->stepTomoScanIOCStop->setEnabled(false);
                ui->stepTomoScanIOCRestart->setEnabled(false);

                ui->contScanGB->setHidden(false);
                ui->FLIRGB->setEnabled(true);

                ui->stepTomoScanIOCSts->setText(stopped);
            }

            if (PCO_PythonServer_Step_SEVR_ != NULL && PCO_TomoScanIOC_Step_SEVR_ != NULL && PCO_PythonServer_Step_ ==1){

                ui->stepPythonServerStart->setEnabled(false);
                ui->stepPythonServerStop->setEnabled(true);
                ui->stepPythonServerRestart->setEnabled(true);

                ui->stepPythonServerSts->setText(running);
            }

            else if (PCO_TomoScanIOC_Step_SEVR_ == NULL){

                ui->stepPythonServerStart->setEnabled(false);
                ui->stepPythonServerStop->setEnabled(false);
                ui->stepPythonServerRestart->setEnabled(false);

                ui->stepPythonServerSts->setText(stopped);
            }
            else
            {
                ui->stepPythonServerStart->setEnabled(true);
                ui->stepPythonServerStop->setEnabled(false);
                ui->stepPythonServerRestart->setEnabled(false);

                ui->stepPythonServerSts->setText(stopped);
            }

            if (PCO_TomoScanIOC_Cont_SEVR_ != NULL){

                ui->contTomoScanIOCStart->setEnabled(false);
                ui->contTomoScanIOCStop->setEnabled(true);
                ui->contTomoScanIOCRestart->setEnabled(true);

                ui->stepScanGB->setHidden(true);
                ui->FLIR->setEnabled(false);

//                ui->generalSts->setText("PCO TomoScan IOC -Continuous- is running ...");
                ui->CameraType->setText(camera + " Camera && Continuous Scan is selected");
                ui->contTomoScanIOCSts->setText(running);
            }
            else
            {
                ui->contTomoScanIOCStart->setEnabled(true);
                ui->contTomoScanIOCStop->setEnabled(false);
                ui->contTomoScanIOCRestart->setEnabled(false);

                ui->stepScanGB->setHidden(false);
                ui->FLIR->setEnabled(true);

                ui->contTomoScanIOCSts->setText(stopped);
            }

            if (PCO_PythonServer_Cont_SEVR_ != NULL && PCO_TomoScanIOC_Cont_SEVR_ != NULL && PCO_PythonServer_Cont_ == 1){

                ui->contPythonServerStart->setEnabled(false);
                ui->contPythonServerStop->setEnabled(true);
                ui->contPythonServerRestart->setEnabled(true);

                ui->contPythonServerSts->setText(running);
            }

            else if (PCO_TomoScanIOC_Cont_SEVR_ == NULL){

                ui->contPythonServerStart->setEnabled(false);
                ui->contPythonServerStop->setEnabled(false);
                ui->contPythonServerRestart->setEnabled(false);

                ui->contPythonServerSts->setText(stopped);
            }
            else
            {
                ui->contPythonServerStart->setEnabled(true);
                ui->contPythonServerStop->setEnabled(false);
                ui->contPythonServerRestart->setEnabled(false);

                ui->contPythonServerSts->setText(stopped);
            }
        }

        if (FLIRIOC_SEVR_ != NULL && camera == "FLIR"){
            ui->stepScanGB->setEnabled(true);
            ui->contScanGB->setEnabled(true);

            if (FLIR_TomoScanIOC_Step_SEVR_ != NULL){

                ui->stepTomoScanIOCStart->setEnabled(false);
                ui->stepTomoScanIOCStop->setEnabled(true);
                ui->stepTomoScanIOCRestart->setEnabled(true);

                ui->contScanGB->setHidden(true);
                ui->PCOGB->setEnabled(false);

//                ui->generalSts->setText("FLIR TomoScan IOC -Step- is running ...");
                ui->CameraType->setText(camera + " Camera && Step Scan is selected");
                ui->stepTomoScanIOCSts->setText(running);
            }
            else
            {
                ui->stepTomoScanIOCStart->setEnabled(true);
                ui->stepTomoScanIOCStop->setEnabled(false);
                ui->stepTomoScanIOCRestart->setEnabled(false);

                ui->contScanGB->setHidden(false);
                ui->PCOGB->setEnabled(true);

                ui->stepTomoScanIOCSts->setText(stopped);
            }

            if (FLIR_PythonServer_Step_SEVR_ != NULL && FLIR_TomoScanIOC_Step_SEVR_ != NULL && FLIR_PythonServer_Step_ ==1){

                ui->stepPythonServerStart->setEnabled(false);
                ui->stepPythonServerStop->setEnabled(true);
                ui->stepPythonServerRestart->setEnabled(true);

                ui->stepPythonServerSts->setText(running);
            }

            else if (FLIR_TomoScanIOC_Step_SEVR_ == NULL){

                ui->stepPythonServerStart->setEnabled(false);
                ui->stepPythonServerStop->setEnabled(false);
                ui->stepPythonServerRestart->setEnabled(false);

                ui->stepPythonServerSts->setText(stopped);
            }
            else
            {
                ui->stepPythonServerStart->setEnabled(true);
                ui->stepPythonServerStop->setEnabled(false);
                ui->stepPythonServerRestart->setEnabled(false);

                ui->stepPythonServerSts->setText(stopped);
            }

            if (FLIR_TomoScanIOC_Cont_SEVR_ != NULL){

                ui->contTomoScanIOCStart->setEnabled(false);
                ui->contTomoScanIOCStop->setEnabled(true);
                ui->contTomoScanIOCRestart->setEnabled(true);

                ui->stepScanGB->setHidden(true);
                ui->PCO->setEnabled(false);

//                ui->generalSts->setText("FLIR TomoScan IOC -Continuous- is running ...");
                ui->CameraType->setText(camera + " Camera && Continuous Scan is selected");
                ui->contTomoScanIOCSts->setText(running);
            }
            else
            {
                ui->contTomoScanIOCStart->setEnabled(true);
                ui->contTomoScanIOCStop->setEnabled(false);
                ui->contTomoScanIOCRestart->setEnabled(false);

                ui->stepScanGB->setHidden(false);
                ui->PCO->setEnabled(true);

                ui->contTomoScanIOCSts->setText(stopped);
            }

            if (FLIR_PythonServer_Cont_SEVR_ != NULL && FLIR_TomoScanIOC_Cont_SEVR_ != NULL && FLIR_PythonServer_Cont_ == 1){

                ui->contPythonServerStart->setEnabled(false);
                ui->contPythonServerStop->setEnabled(true);
                ui->contPythonServerRestart->setEnabled(true);

                ui->contPythonServerSts->setText(running);
            }

            else if (FLIR_TomoScanIOC_Cont_SEVR_ == NULL){

                ui->contPythonServerStart->setEnabled(false);
                ui->contPythonServerStop->setEnabled(false);
                ui->contPythonServerRestart->setEnabled(false);

                ui->contPythonServerSts->setText(stopped);
            }
            else
            {
                ui->contPythonServerStart->setEnabled(true);
                ui->contPythonServerStop->setEnabled(false);
                ui->contPythonServerRestart->setEnabled(false);

                ui->contPythonServerSts->setText(stopped);
            }
        }

        /* --------------------------------------------------------------*/

        if (writerServer_Step_SEVR_ != NULL && writerServer_Step_ == 1){

            ui->stepWriterServerStart->setEnabled(false);
            ui->stepWriterServerStop->setEnabled(true);
            ui->stepWriterServerRestart->setEnabled(true);

            if ( PCO_WriterServer_Step_ == 1 or PCO_WriterServer_Cont_ == 1 or PCO_TomoScanIOC_Step_SEVR_ != NULL or PCO_TomoScanIOC_Cont_SEVR_ != NULL)
                ui->FLIR->setEnabled(false);
            else
                ui->FLIR->setEnabled(true);

            ui->stepWriterServerSts->setText(running);
        }
        else
        {
            ui->stepWriterServerStart->setEnabled(true);
            ui->stepWriterServerStop->setEnabled(false);
            ui->stepWriterServerRestart->setEnabled(false);

            ui->stepWriterServerSts->setText(stopped);
        }

        if (writerServer_Cont_SEVR_ != NULL && writerServer_Cont_ == 1){

            ui->contWriterServerStart->setEnabled(false);
            ui->contWriterServerStop->setEnabled(true);
            ui->contWriterServerRestart->setEnabled(true);

            if (FLIR_WriterServer_Step_ == 1 or FLIR_WriterServer_Cont_ == 1 or FLIR_TomoScanIOC_Step_SEVR_ != NULL or FLIR_TomoScanIOC_Cont_SEVR_ != NULL)
                ui->PCO->setEnabled(false);
            else
                ui->PCO->setEnabled(true);

            ui->contWriterServerSts->setText(running);
        }
        else
        {
            ui->contWriterServerStart->setEnabled(true);
            ui->contWriterServerStop->setEnabled(false);
            ui->contWriterServerRestart->setEnabled(false);

            ui->contWriterServerSts->setText(stopped);
        }

    }
    else {

        ui->PCOGB->setEnabled(false);
        ui->FLIRGB->setEnabled(false);
        ui->stepScanGB->setEnabled(false);
        ui->contScanGB->setEnabled(false);

        ui->generalSts->setText("Please make sure to start the common IOCs to begin scan!");
    }

    if ((PCOIOC_SEVR_ == NULL or PCOState_ == 9) && camera == "PCO"){

        ui->stepScanGB->setEnabled(false);
        ui->contScanGB->setEnabled(false);

        ui->generalSts->setText("Can't begin the scan or make any process, check the (Camera Power, Ethernet Connection, PCO IOC)");
    }

    if ((FLIRIOC_SEVR_ == NULL or FLIRState_ == 9) && camera == "FLIR"){

        ui->stepScanGB->setEnabled(false);
        ui->contScanGB->setEnabled(false);

        ui->generalSts->setText("Can't begin the scan or make any process, check the (Camera Power, Ethernet Connection, FLIR IOC)");
    }

    ui->currentCamera->setText("Current Chosen Camera: "+ camera);
}

void MainWindow::checkStatusL(){

    switch (PCOState_) {

//      case 0:
//        ui->PCOSts->setText("Connected");
//        break;

      case 1:
        ui->PCOSts->setText("Acquire");
        break;

      case 2:
        ui->PCOSts->setText("Readout");
        break;

      case 3:
        ui->PCOSts->setText("Correct");
        break;

      case 4:
        ui->PCOSts->setText("Saving");
        break;

      case 5:
        ui->PCOSts->setText("Aborting");
        break;

      case 6:
        ui->PCOSts->setText("Error");
        break;

      case 7:
        ui->PCOSts->setText("Waiting");
        break;

      case 8:
        ui->PCOSts->setText("Initializing");
        break;

      case 10:
        ui->PCOSts->setText("Aborted");
        break;
    }

    switch (FLIRState_) {

//      case 0:
//        ui->FLIRSts->setText("Connected");
//        break;

      case 1:
        ui->FLIRSts->setText("Acquire");
        break;

      case 2:
        ui->FLIRSts->setText("Readout");
        break;

      case 3:
        ui->FLIRSts->setText("Correct");
        break;

      case 4:
        ui->FLIRSts->setText("Saving");
        break;

      case 5:
        ui->FLIRSts->setText("Aborting");
        break;

      case 6:
        ui->FLIRSts->setText("Error");
        break;

      case 7:
        ui->FLIRSts->setText("Waiting");
        break;

      case 8:
        ui->FLIRSts->setText("Initializing");
        break;

      case 10:
        ui->FLIRSts->setText("Aborted");
        break;
    }
}

void MainWindow::on_help_clicked()
{
    QDesktopServices::openUrl(QUrl("https://hesebscantool.readthedocs.io/en/latest/runScan.html#live-data-plotting"));

}

void MainWindow::on_password_editingFinished()
{
    QString pass = ui->password->text();
    QByteArray passArray = pass.toLocal8Bit();
    QString hash = QString(QCryptographicHash::hash((passArray),QCryptographicHash::Md5).toHex());

    if (hash == "81dc9bdb52d04dc20036dbd8313ed055"){
        ui->TCPServerSocketRestart->setEnabled(true);
        ui->password->clear();
    }
}
