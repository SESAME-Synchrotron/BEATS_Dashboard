#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir::setCurrent("/home/control/DAQ/operation/BEATS_Dashboard/Scripts");       // set the directory of the bash scripts

    // read PVs and SEVR//

    this->PCOIOC                      = new QEpicsPV("TEST-PCO:HDF1:StoreAttr");
    this->FLIRIOC                     = new QEpicsPV("FLIR:cam1:AsynIO");
    this->PCOState                    = new QEpicsPV("TEST-PCO:cam1:StatusMessage_RBV");
    this->FLIRState                   = new QEpicsPV("FLIR:cam1:DetectorState_RBV");

    this->shutterIOC                  = new QEpicsPV("I10EH-SHUTTER:command");
    this->motorIOC                    = new QEpicsPV("I10-EH-MO-MICOS:m1");
    this->tomoScanSupportIOC          = new QEpicsPV("PA:BEATS:STA_A_FES_OPEN_PL");
    this->writerSupportIOC            = new QEpicsPV("BEATS:WRITER:NumSaved");
    this->sscanIOC                    = new QEpicsPV("BEATS:scan1");

    this->exposureShutterIOC          = new QEpicsPV("I10EH-SHUTTER:command");
//    this->radiationShutterIOC         = new QEpicsPV("I10FE-PSS-PHST:getStatus");
//    this->photonShutterIOC            = new QEpicsPV("I10FE-VA-PSH:getStatus");
    this->combinedStopperIOC          = new QEpicsPV("I10OH-VA-COMB:getStatus");
    this->PSSIOC                      = new QEpicsPV("I10OH-VA-COMB:isPSSInterlock");

//    this->radiationShutterFault       = new QEpicsPV("I10FE-PSS-PHST:getFault");
//    this->photonShutterFault          = new QEpicsPV("I10FE-VA-PSH:getFault");
    this->combinedStopperFault        = new QEpicsPV("I10OH-VA-COMB:getFault");

    this->PCO_TomoScanIOCStep         = new QEpicsPV("tomoscanBEATS:PcoMicosStep:ScanStatus");
    this->PCO_PythonServerStep        = new QEpicsPV("tomoscanBEATS:PcoMicosStep:ServerRunning");
    this->PCO_TomoScanIOCCont         = new QEpicsPV("tomoscanBEATS:PcoMicosCont:ScanStatus");
    this->PCO_PythonServerCont        = new QEpicsPV("tomoscanBEATS:PcoMicosCont:ServerRunning");

    this->FLIR_TomoScanIOCStep        = new QEpicsPV("tomoscanBEATS:FlirMicosStep:CameraObjective");
    this->FLIR_PythonServerStep       = new QEpicsPV("tomoscanBEATS:FlirMicosStep:ServerRunning");
    this->FLIR_TomoScanIOCCont        = new QEpicsPV("tomoscanBEATS:FlirMicosCont:CameraObjective");
    this->FLIR_PythonServerCont       = new QEpicsPV("tomoscanBEATS:FlirMicosCont:ServerRunning");

    this->writerServerStep            = new QEpicsPV("BEATS:WRITER:STEP:Status");
    this->writerServerCont            = new QEpicsPV("BEATS:WRITER:CONT:Status");
    this->writerServerTrig            = new QEpicsPV("BEATS:WRITER:NewFileTrigger");

    this->PCO_WriterServerStep        = new QEpicsPV("BEATS:PCO:WRITER:STEP:Status");
    this->PCO_WriterServerCont        = new QEpicsPV("BEATS:PCO:WRITER:CONT:Status");
    this->FLIR_WriterServerStep       = new QEpicsPV("BEATS:FLIR:WRITER:STEP:Status");
    this->FLIR_WriterServerCont       = new QEpicsPV("BEATS:FLIR:WRITER:CONT:Status");

    this->PCOIOC_SEVR                 = new QEpicsPV("TEST-PCO:HDF1:StoreAttr.SEVR");
    this->FLIRIOC_SEVR                = new QEpicsPV("FLIR:cam1:AsynIO.CNCT");

    this->shutterIOC_SEVR             = new QEpicsPV("I10EH-SHUTTER:command.SEVR");
    this->motorIOC_SEVR               = new QEpicsPV("I10-EH-MO-MICOS:m1.SEVR");
    this->tomoScanSupportIOC_SEVR     = new QEpicsPV("PA:BEATS:STA_A_FES_OPEN_PL.SEVR");
    this->writerSupportIOC_SEVR       = new QEpicsPV("BEATS:WRITER:NumSaved.SEVR");
    this->sscanIOC_SEVR               = new QEpicsPV("BEATS:scan1.SEVR");

    this->exposureShutterIOC_SEVR     = new QEpicsPV("I10EH-SHUTTER:command.SEVR");
//    this->radiationShutterIOC_SEVR    = new QEpicsPV("I10FE-PSS-PHST:getStatus.SEVR");
//    this->photonShutterIOC_SEVR       = new QEpicsPV("I10FE-VA-PSH:getStatus.SEVR");
    this->combinedStopperIOC_SEVR     = new QEpicsPV("I10OH-VA-COMB:getStatus.SEVR");
    this->PSSIOC_SEVR                 = new QEpicsPV("I10OH-VA-COMB:isPSSInterlock.SEVR");

    this->PCO_TomoScanIOCStep_SEVR   = new QEpicsPV("tomoscanBEATS:PcoMicosStep:ScanStatus.SEVR");
    this->PCO_PythonServerStep_SEVR  = new QEpicsPV("tomoscanBEATS:PcoMicosStep:ServerRunning.SEVR");
    this->PCO_TomoScanIOCCont_SEVR   = new QEpicsPV("tomoscanBEATS:PcoMicosCont:ScanStatus.SEVR");
    this->PCO_PythonServerCont_SEVR  = new QEpicsPV("tomoscanBEATS:PcoMicosCont:ServerRunning.SEVR");

    this->FLIR_TomoScanIOCStep_SEVR    = new QEpicsPV("tomoscanBEATS:FlirMicosStep:CameraObjective.SEVR");
    this->FLIR_PythonServerStep_SEVR   = new QEpicsPV("tomoscanBEATS:FlirMicosStep:ServerRunning.SEVR");
    this->FLIR_TomoScanIOCCont_SEVR    = new QEpicsPV("tomoscanBEATS:FlirMicosCont:CameraObjective.SEVR");
    this->FLIR_PythonServerCont_SEVR   = new QEpicsPV("tomoscanBEATS:FlirMicosCont:ServerRunning.SEVR");

    this->writerServerStep_SEVR       = new QEpicsPV("BEATS:WRITER:STEP:Status.SEVR");
    this->writerServerCont_SEVR       = new QEpicsPV("BEATS:WRITER:CONT:Status.SEVR");
    this->writerServerTrig_SEVR       = new QEpicsPV("BEATS:WRITER:NewFileTrigger.SEVR");

    ui->PCOGB->setEnabled(false);
    ui->FLIRGB->setEnabled(false);
    ui->stepScanGB->setEnabled(false);
    ui->contScanGB->setEnabled(false);
    ui->singleShotImageStart->setEnabled(false);

    ui->TCPServerSocketRestart->setEnabled(false);
    ui->TCPServerSocketRestart->setHidden(true);
    ui->password->setHidden(true);
    ui->PCO_StatusHidden->setHidden(true);

    ui->shutterIOCStart->setEnabled(false);
    ui->shutterIOCStop->setEnabled(false);
    ui->shutterIOCRestart->setEnabled(false);

//    ui->PCOstep->setHidden(true);
//    ui->PCOcont->setHidden(true);
//    ui->FLIRstep->setHidden(true);
//    ui->FLIRcont->setHidden(true);

    ui->faults->setHidden(true);
    ui->photonShutterFault->setHidden(true);
    ui->radiationShutterFault->setHidden(true);
    ui->exposureShutterFault->setHidden(true);
    ui->combinedStopperFault->setHidden(true);
    ui->PSSFault->setHidden(true);

    ui->radiationShutter->setHidden(true);
    ui->radiationShutterInd->setHidden(true);
    ui->radiationShutterSts->setHidden(true);
    ui->photonShutter->setHidden(true);
    ui->photonShutterInd->setHidden(true);
    ui->photonShutterSts->setHidden(true);

    ui->filterPluginSettings->setEnabled(false);

    TimerH = new QTimer(this);
    this->TimerH->start(400);

    connect(TimerH, SIGNAL(timeout()), this, SLOT(checkStatusH()));    // infinite loop

    TimerL = new QTimer(this);
    this->TimerL->start(1000);

    connect(TimerL, SIGNAL(timeout()), this, SLOT(checkStatusL()));    // infinite loop

    scanSts = new QTimer(this);
    this->scanSts->start(2000);

    connect(scanSts, SIGNAL(timeout()), this, SLOT(checkScanSts()));    // infinite loop

    if (PCO_TomoScanIOC_Step_SEVR_ != NULL or PCO_TomoScanIOC_Cont_SEVR_ != NULL)
        ui->FLIR->setEnabled(false);

    if (FLIR_TomoScanIOC_Step_SEVR_ != NULL or FLIR_TomoScanIOC_Cont_SEVR_ != NULL)
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
    cameraFilter = "TEST-PCO";

    if ((PCOIOC_SEVR_ != NULL) and PCO_FilterValue)
        ui->filterPluginEnable->setChecked(true);
    else
        ui->filterPluginEnable->setChecked(false);

    ui->generalSts->setText(camera + " Detector has been selected");

    // hide the FLIR indicators objects
    ui->FLIRStepTomoScanIOCInd->setHidden(true);
    ui->FLIRStepPythonServerInd->setHidden(true);
    ui->FLIRStepWriterServerInd->setHidden(true);
    ui->FLIRFilterInd->setHidden(true);
    ui->FLIRContTomoScanIOCInd->setHidden(true);
    ui->FLIRContPythonServerInd->setHidden(true);
    ui->FLIRContWriterServerInd->setHidden(true);

    ui->PCOStepTomoScanIOCInd->setHidden(false);
    ui->PCOStepPythonServerInd->setHidden(false);
    ui->PCOStepWriterServerInd->setHidden(false);
    ui->PCOFilterInd->setHidden(false);
    ui->PCOContTomoScanIOCInd->setHidden(false);
    ui->PCOContPythonServerInd->setHidden(false);
    ui->PCOContWriterServerInd->setHidden(false);
}

void MainWindow::on_FLIR_clicked()
{
//    QProcess* FLIRIOCStart = new QProcess(this);
//    FLIRIOCStart->start("gnome-terminal -x ./FLIR_CameraStart.sh ");
    camera = "FLIR";
    cameraFilter = camera;

    if ((FLIRIOC_SEVR_ != NULL) and FLIR_FilterValue)
        ui->filterPluginEnable->setChecked(true);
    else
        ui->filterPluginEnable->setChecked(false);

    ui->generalSts->setText(camera + " Detector has been selected");

    // hide the PCO indicators objects
    ui->PCOStepTomoScanIOCInd->setHidden(true);
    ui->PCOStepPythonServerInd->setHidden(true);
    ui->PCOStepWriterServerInd->setHidden(true);
    ui->PCOFilterInd->setHidden(true);
    ui->PCOContTomoScanIOCInd->setHidden(true);
    ui->PCOContPythonServerInd->setHidden(true);
    ui->PCOContWriterServerInd->setHidden(true);

    ui->FLIRStepTomoScanIOCInd->setHidden(false);
    ui->FLIRStepPythonServerInd->setHidden(false);
    ui->FLIRStepWriterServerInd->setHidden(false);
    ui->FLIRFilterInd->setHidden(false);
    ui->FLIRContTomoScanIOCInd->setHidden(false);
    ui->FLIRContPythonServerInd->setHidden(false);
    ui->FLIRContWriterServerInd->setHidden(false);
}
/* --------------------------------------------------------------*/
void MainWindow::startProcess(QString Process, QString Camera)
{
    process = Process;
    cam = Camera;

    std::string command = "gnome-terminal -- ./BEATS_GUI_Bash_Start --process ";
    command += cam.toStdString();
    command += process.toStdString();
    system(command.c_str());
}

void MainWindow::stopProcess(QString Process, QString Camera)
{
    process = Process;
    cam = Camera;

    std::string command = "gnome-terminal -- ./BEATS_GUI_Bash_Stop --process ";
    command += cam.toStdString();
    command += process.toStdString();
    system(command.c_str());
}

void MainWindow::restartProcess(QString Process, QString Camera)
{
    process = Process;
    cam = Camera;

    std::string command = "gnome-terminal -- ./BEATS_GUI_Bash_Restart --process ";
    command += cam.toStdString();
    command += process.toStdString();
    system(command.c_str());
}
/* --------------------------------------------------------------*/

void MainWindow::on_PCOIOCStart_clicked()
{
    std::string command = "gnome-terminal -- python3 TCPClientSocket.py --process start ";
    system(command.c_str());
}

void MainWindow::on_PCOIOCStop_clicked()
{
    std::string command = "gnome-terminal -- python3 TCPClientSocket.py --process stop ";
    system(command.c_str());
}

void MainWindow::on_PCOIOCRestart_clicked()
{
    std::string command = "gnome-terminal -- python3 TCPClientSocket.py --process restart ";
    system(command.c_str());
}

void MainWindow::on_TCPServerSocketRestart_clicked()
{
    std::string command = "gnome-terminal -- python3 TCPClientSocket.py --process TCPServerSocketRestart ";
    system(command.c_str());

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
//    startProcess("shutterIOC","");
//    ui->generalSts->setText("Shutter IOC " + started + " ...");
}

void MainWindow::on_shutterIOCStop_clicked()
{
//    stopProcess("shutterIOC","");
//    ui->generalSts->setText("Shutter IOC " + stopped + " ...");
}

void MainWindow::on_shutterIOCRestart_clicked()
{
//    restartProcess("shutterIOC","");
//    ui->generalSts->setText("Shutter IOC " + restarted + " ...");
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

void MainWindow::on_motorGUI_clicked()
{
    startProcess("motorGUI","");
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

void MainWindow::on_sscanIOCStart_clicked()
{
    startProcess("SSCAN_IOC","");
    ui->generalSts->setText("SSCAN IOC " + started + " ...");
}

void MainWindow::on_sscanIOCStop_clicked()
{
    stopProcess("SSCAN_IOC","");
    ui->generalSts->setText("SSCAN IOC " + stopped + " ...");
}

void MainWindow::on_sscanIOCRestart_clicked()
{
    restartProcess("SSCAN_IOC","");
    ui->generalSts->setText("SSCAN IOC " + restarted + " ...");
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

    if(isSingleShotImageOpened)
        openSingleShot->close();        // close single shot image GUI if tomoscan process has been started
}

void MainWindow::on_stepTomoScanIOCStop_clicked()
{
    stopProcess("_StepTomoscanIOC",camera);
    ui->generalSts->setText(camera + " - Step TomoScan IOC " + stopped + " ...");

    Client::writePV("BEATS:WRITER:NewFileTrigger", 0);
    Client::writePV("BEATS:WRITER:FileCreated", 0);
    Client::writePV("BEATS:PCO:WRITER:STEP:Status",0);
    Client::writePV("BEATS:PCO:WRITER:CONT:Status",0);
    Client::writePV("BEATS:FLIR:WRITER:STEP:Status",0);
    Client::writePV("BEATS:FLIR:WRITER:CONT:Status",0);

    // stop the python and writer servers also!!!
    stopProcess("_PythonServerStep",camera);
    stopProcess("_WriterServerStep",camera);

    ui->filterPluginEnable->setChecked(false);
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
    Client::writePV("BEATS:WRITER:NewFileTrigger", 0);
    Client::writePV("BEATS:WRITER:FileCreated", 0);

    stopProcess("_PythonServerStep",camera);
    ui->generalSts->setText(camera + " - Step Python Server " + stopped + " ...");
}

void MainWindow::on_stepPythonServerRestart_clicked()
{
    Client::writePV("BEATS:WRITER:NewFileTrigger", 0);
    Client::writePV("BEATS:WRITER:FileCreated", 0);

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
    Client::writePV("BEATS:WRITER:NewFileTrigger", 0);
    Client::writePV("BEATS:WRITER:FileCreated", 0);
    Client::writePV("BEATS:PCO:WRITER:STEP:Status",0);
    Client::writePV("BEATS:PCO:WRITER:CONT:Status",0);
    Client::writePV("BEATS:FLIR:WRITER:STEP:Status",0);
    Client::writePV("BEATS:FLIR:WRITER:CONT:Status",0);

    stopProcess("_WriterServerStep",camera);
    ui->generalSts->setText(camera + " - Step Writer Server " + stopped + " ...");
}

void MainWindow::on_stepWriterServerRestart_clicked()
{
    Client::writePV("BEATS:WRITER:NewFileTrigger", 0);
    Client::writePV("BEATS:WRITER:FileCreated", 0);
    Client::writePV("BEATS:PCO:WRITER:STEP:Status",0);
    Client::writePV("BEATS:PCO:WRITER:CONT:Status",0);
    Client::writePV("BEATS:FLIR:WRITER:STEP:Status",0);
    Client::writePV("BEATS:FLIR:WRITER:CONT:Status",0);

    restartProcess("_WriterServerStep",camera);
    ui->generalSts->setText(camera + " - Step Writer Server " + restarted + " ...");
}
/* --------------------------------------------------------------*/

void MainWindow::on_stepMEDMStart_clicked()
{
//    process = Process;
//    cam = Camera;
//    QProcess* startProcess = new QProcess(this);
//    startProcess->start("gnome-terminal -x  nohup medm -x -macro \"P=tomoscanBEATS:,R=FlirMicosStep:,BEAMLINE=tomoScan_BEATS_FLIR_MICOS_Step\" /opt/epics/synApps/support/BEATS_tomoscan/tomoScanApp/op/adl/tomoScan-Step.adl &");

    startProcess("_StepMEDM",camera);
}
/* --------------------------------------------------------------*/

void MainWindow::on_filterPluginEnable_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked) {

        Client::writePV(cameraFilter + ":Proc1:EnableCallbacks", 1);
        Client::writePV(cameraFilter + ":Proc1:EnableFilter", 1);
        Client::writePV(cameraFilter + ":ZMQ1:NDArrayPort", "PROC1");
        Client::writePV(cameraFilter + ":Proc1:NumFilter", 1);
        Client::writePV(cameraFilter + ":Proc1:FilterCallbacks", 1);
        ui->filterPluginSettings->setEnabled(true);
    }
    else {

        Client::writePV(cameraFilter + ":Proc1:EnableCallbacks", 0);
        Client::writePV(cameraFilter + ":Proc1:EnableFilter", 0);
        ui->filterPluginSettings->setEnabled(false);

        camera == "PCO" ? Client::writePV(cameraFilter + ":ZMQ1:NDArrayPort", "PCO1") : Client::writePV(cameraFilter + ":ZMQ1:NDArrayPort", "flir");
    }
}
/* --------------------------------------------------------------*/

void MainWindow::on_filterPluginSettings_clicked()
{
    startProcess("Filter", camera);
}
/* --------------------------------------------------------------*/

void MainWindow::on_PCOFilterInd_dbValueChanged(bool out)
{
    PCO_FilterValue = out;
}

void MainWindow::on_FLIRFilterInd_dbValueChanged(bool out)
{
    FLIR_FilterValue = out;
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

    ui->filterPluginEnable->setChecked(false);

    if(isSingleShotImageOpened)
        openSingleShot->close();        // close single shot image GUI if tomoscan process has been started
}

void MainWindow::on_contTomoScanIOCStop_clicked()
{
    stopProcess("_ContTomoscanIOC",camera);
    ui->generalSts->setText(camera + " - Continuous TomoScan IOC " + stopped + " ...");

    Client::writePV("BEATS:WRITER:NewFileTrigger", 0);
    Client::writePV("BEATS:WRITER:FileCreated", 0);
    Client::writePV("BEATS:PCO:WRITER:STEP:Status",0);
    Client::writePV("BEATS:PCO:WRITER:CONT:Status",0);
    Client::writePV("BEATS:FLIR:WRITER:STEP:Status",0);
    Client::writePV("BEATS:FLIR:WRITER:CONT:Status",0);

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
    Client::writePV("BEATS:WRITER:NewFileTrigger", 0);
    Client::writePV("BEATS:WRITER:FileCreated", 0);

    stopProcess("_PythonServerCont",camera);
    ui->generalSts->setText(camera + " - Continuous Python Server " + stopped + " ...");
}

void MainWindow::on_contPythonServerRestart_clicked()
{
    Client::writePV("BEATS:WRITER:NewFileTrigger", 0);
    Client::writePV("BEATS:WRITER:FileCreated", 0);

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
    Client::writePV("BEATS:WRITER:NewFileTrigger", 0);
    Client::writePV("BEATS:WRITER:FileCreated", 0);
    Client::writePV("BEATS:PCO:WRITER:STEP:Status",0);
    Client::writePV("BEATS:PCO:WRITER:CONT:Status",0);
    Client::writePV("BEATS:FLIR:WRITER:STEP:Status",0);
    Client::writePV("BEATS:FLIR:WRITER:CONT:Status",0);

    stopProcess("_WriterServerCont",camera);
    ui->generalSts->setText(camera + " - Continuous Writer Server " + stopped + " ...");
}

void MainWindow::on_contWriterServerRestart_clicked()
{
    Client::writePV("BEATS:WRITER:NewFileTrigger", 0);
    Client::writePV("BEATS:WRITER:FileCreated", 0);
    Client::writePV("BEATS:PCO:WRITER:STEP:Status",0);
    Client::writePV("BEATS:PCO:WRITER:CONT:Status",0);
    Client::writePV("BEATS:FLIR:WRITER:STEP:Status",0);
    Client::writePV("BEATS:FLIR:WRITER:CONT:Status",0);

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
   sscanIOC_SEVR_                = this->sscanIOC_SEVR->get().toString();

   exposureShutterIOC_SEVR_      = this->exposureShutterIOC_SEVR->get().toString();
//   radiationShutterIOC_SEVR_     = this->radiationShutterIOC_SEVR->get().toString();
//   photonShutterIOC_SEVR_        = this->photonShutterIOC_SEVR->get().toString();
   combinedStopperIOC_SEVR_      = this->combinedStopperIOC_SEVR->get().toString();
   PSSIOC_SEVR_                  = this->PSSIOC_SEVR->get().toString();

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

//   radiationShutter              = this->radiationShutterIOC->get().toInt();
//   photonShutter                 = this->photonShutterIOC->get().toInt();
   combinedStopper               = this->combinedStopperIOC->get().toInt();
   PSS                           = this->PSSIOC->get().toBool();

//   radiationShutterFault_        = this->radiationShutterFault->get().toInt();
//   photonShutterFault_           = this->photonShutterFault->get().toInt();
   combinedStopperFault_         = this->combinedStopperFault->get().toInt();

   writerServer_Step_            = this->writerServerStep->get().toInt();
   writerServer_Cont_            = this->writerServerCont->get().toInt();

   PCO_WriterServer_Step_        = this->PCO_WriterServerStep->get().toInt();
   PCO_WriterServer_Cont_        = this->PCO_WriterServerCont->get().toInt();
   FLIR_WriterServer_Step_       = this->FLIR_WriterServerStep->get().toInt();
   FLIR_WriterServer_Cont_       = this->FLIR_WriterServerCont->get().toInt();

   PCO_PythonServer_Step_        = this->PCO_PythonServerStep->get().toInt();
   PCO_PythonServer_Cont_        = this->PCO_PythonServerCont->get().toInt();
   FLIR_PythonServer_Step_       = this->FLIR_PythonServerStep->get().toInt();
   FLIR_PythonServer_Cont_       = this->FLIR_PythonServerCont->get().toInt();
/* --------------------------------------------------------------*/

//    if (shutterIOC_SEVR_ != NULL){
//        ui->shutterIOCStart->setEnabled(false);
//        ui->shutterIOCStop->setEnabled(true);
//        ui->shutterIOCRestart->setEnabled(true);

//        ui->shutterIOCSts->setText(running);
//    }
//    else {
//            ui->shutterIOCStart->setEnabled(true);
//            ui->shutterIOCStop->setEnabled(false);
//            ui->shutterIOCRestart->setEnabled(false);

//            ui->shutterIOCSts->setText(stopped);
//    }

//       if (exposureShutterIOC_SEVR_ != NULL or radiationShutterIOC_SEVR_ != NULL or photonShutterIOC_SEVR_ != NULL or combinedStopperIOC_SEVR_ != NULL or PSSIOC_SEVR_ != NULL){
       if (exposureShutterIOC_SEVR_ != NULL or combinedStopperIOC_SEVR_ != NULL or PSSIOC_SEVR_ != NULL){

           ui->shutterIOCSts->setText(running);
           ui->shutterIOCInd->setColour0Property(QColor(0,255,0));
       }

       else {
           ui->shutterIOCSts->setText("Check the IOCs");
           ui->shutterIOCInd->setColour0Property(QColor(255,0,0));
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

    if (sscanIOC_SEVR_ != NULL){
        ui->sscanIOCStart->setEnabled(false);
        ui->sscanIOCStop->setEnabled(true);
        ui->sscanIOCRestart->setEnabled(true);

        ui->sscanIOCSts->setText(running);
    }
    else {
        ui->sscanIOCStart->setEnabled(true);
        ui->sscanIOCStop->setEnabled(false);
        ui->sscanIOCRestart->setEnabled(false);

        ui->sscanIOCSts->setText(stopped);
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

//    if (!(ui->shutterIOCStart->isEnabled() or ui->motorIOCStart->isEnabled() or ui->tomoScanSupportIOCStart->isEnabled() or ui->writerSupportIOCStart->isEnabled())){
//    if (!(ui->shutterIOCSts->text().toStdString() == "Check the IOCs" or ui->motorIOCStart->isEnabled() or ui->tomoScanSupportIOCStart->isEnabled() or ui->writerSupportIOCStart->isEnabled() or (radiationShutter != 3 or radiationShutterFault_ != 0) or (photonShutter != 3 or photonShutterFault_ != 0) or (combinedStopperFault_ != 0) or (PSS != 1))){
//    if (!(ui->shutterIOCSts->text().toStdString() == "Check the IOCs" or ui->motorIOCStart->isEnabled() or ui->tomoScanSupportIOCStart->isEnabled() or ui->writerSupportIOCStart->isEnabled() or (combinedStopperFault_ != 0) or (PSS != 1))){
    if (!(ui->motorIOCStart->isEnabled() or ui->tomoScanSupportIOCStart->isEnabled() or ui->writerSupportIOCStart->isEnabled())){

        ui->PCOGB->setEnabled(true);
        ui->FLIRGB->setEnabled(true);

        if (ui->PCO_StatusHidden->text().toStdString() == "Disconnected" or ui->PCO_StatusHidden->text().toStdString() == "disconnected" or PCOIOC_SEVR_ == NULL){
//            ui->PCO->setEnabled(false);
            ui->PCOSts->setText("Disconnected");
            set_PCO_indicators_color('R');
//            std::cout<<ui->PCO_StatusHidden->text().toStdString()<<std::endl;

        }
        else {
//            ui->PCO->setEnabled(true);
            ui->PCOSts->setText("Connected");
            set_PCO_indicators_color('G');
//            std::cout<<ui->PCO_StatusHidden->text().toStdString()<<std::endl;
        }

        if (FLIRState_ == 9 or FLIRIOC_SEVR_ == NULL){
//            ui->FLIR->setEnabled(false);
            ui->FLIRSts->setText("Disconnected");
            set_FLIR_indicators_color('R');
        }
        else {
//            ui->FLIR->setEnabled(true);
            ui->FLIRSts->setText("Connected");
            set_FLIR_indicators_color('G');
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
                ui->CameraType->setText(camera + " Detector && Step Scan have been selected");
                ui->stepTomoScanIOCSts->setText(running);
//                ui->PCOstep->setHidden(false);
            }
            else
            {
                ui->stepTomoScanIOCStart->setEnabled(true);
                ui->stepTomoScanIOCStop->setEnabled(false);
                ui->stepTomoScanIOCRestart->setEnabled(false);

                ui->contScanGB->setHidden(false);
                ui->FLIRGB->setEnabled(true);

                ui->stepTomoScanIOCSts->setText(stopped);
//                ui->PCOstep->setHidden(true);
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
                ui->CameraType->setText(camera + " Detector && Continuous Scan have been selected");
                ui->contTomoScanIOCSts->setText(running);
//                ui->PCOcont->setHidden(false);
            }
            else
            {
                ui->contTomoScanIOCStart->setEnabled(true);
                ui->contTomoScanIOCStop->setEnabled(false);
                ui->contTomoScanIOCRestart->setEnabled(false);

                ui->stepScanGB->setHidden(false);
                ui->FLIR->setEnabled(true);

                ui->contTomoScanIOCSts->setText(stopped);
//                ui->PCOcont->setHidden(true);
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
                ui->CameraType->setText(camera + " Detector && Step Scan have been selected");
                ui->stepTomoScanIOCSts->setText(running);
//                ui->FLIRstep->setHidden(false);
            }
            else
            {
                ui->stepTomoScanIOCStart->setEnabled(true);
                ui->stepTomoScanIOCStop->setEnabled(false);
                ui->stepTomoScanIOCRestart->setEnabled(false);

                ui->contScanGB->setHidden(false);
                ui->PCOGB->setEnabled(true);

                ui->stepTomoScanIOCSts->setText(stopped);
//                ui->FLIRstep->setHidden(true);
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
                ui->CameraType->setText(camera + " Detector && Continuous Scan have been selected");
                ui->contTomoScanIOCSts->setText(running);
//                ui->FLIRcont->setHidden(false);
            }
            else
            {
                ui->contTomoScanIOCStart->setEnabled(true);
                ui->contTomoScanIOCStop->setEnabled(false);
                ui->contTomoScanIOCRestart->setEnabled(false);

                ui->stepScanGB->setHidden(false);
                ui->PCO->setEnabled(true);

                ui->contTomoScanIOCSts->setText(stopped);
//                ui->FLIRcont->setHidden(true);
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

//        ui->generalSts->setText("Please make sure to start the common IOCs to be able to continue! or check the radiation & photon shutters are opened");
        ui->generalSts->setText("Please make sure to start the common IOCs to be able to continue!");
    }

    if ((PCOIOC_SEVR_ == NULL or ui->PCO_StatusHidden->text().toStdString() == "Disconnected" or ui->PCO_StatusHidden->text().toStdString() == "disconnected") && camera == "PCO"){

        ui->stepScanGB->setEnabled(false);
        ui->contScanGB->setEnabled(false);

        ui->generalSts->setText("Can't select the scan mode or make any process, check the (Detector Power, Ethernet Connection, PCO IOC)");
    }

    if ((FLIRIOC_SEVR_ == NULL or FLIRState_ == 9) && camera == "FLIR"){

        ui->stepScanGB->setEnabled(false);
        ui->contScanGB->setEnabled(false);

        ui->generalSts->setText("Can't select the scan mode or make any process, check the (Detector Power, Ethernet Connection, FLIR IOC)");
    }

    ui->currentCamera->setText("Current Chosen Detector: "+ camera);
    ui->currentStage->setText("Current Rotation Stage: Micos");

}

void MainWindow::checkStatusL(){

    switch (PCOState_) {

//      case 0:
//        ui->PCOSts->setText("Connected");
//        break;

      case 1:
        ui->PCOSts->setText("Acquire");
        set_PCO_indicators_color('G');
        break;

      case 2:
        ui->PCOSts->setText("Readout");
        set_PCO_indicators_color('G');
        break;

      case 3:
        ui->PCOSts->setText("Correct");
        set_PCO_indicators_color('G');
        break;

      case 4:
        ui->PCOSts->setText("Saving");
        set_PCO_indicators_color('G');
        break;

      case 5:
        ui->PCOSts->setText("Aborting");
        set_PCO_indicators_color('G');
        break;

      case 6:
        ui->PCOSts->setText("Error");
        set_PCO_indicators_color('R');
        break;

      case 7:
        ui->PCOSts->setText("Waiting");
        set_PCO_indicators_color('G');
        break;

      case 8:
        ui->PCOSts->setText("Initializing");
        set_PCO_indicators_color('G');
        break;

      case 10:
        ui->PCOSts->setText("Aborted");
        set_PCO_indicators_color('G');
        break;
    }

    switch (FLIRState_) {

//      case 0:
//        ui->FLIRSts->setText("Connected");
//        break;

      case 1:
        ui->FLIRSts->setText("Acquire");
        set_FLIR_indicators_color('G');
        break;

      case 2:
        ui->FLIRSts->setText("Readout");
        set_FLIR_indicators_color('G');
        break;

      case 3:
        ui->FLIRSts->setText("Correct");
        set_FLIR_indicators_color('G');
        break;

      case 4:
        ui->FLIRSts->setText("Saving");
        set_FLIR_indicators_color('G');
        break;

      case 5:
        ui->FLIRSts->setText("Aborting");
        set_FLIR_indicators_color('G');
        break;

      case 6:
        ui->FLIRSts->setText("Error");
        set_FLIR_indicators_color('R');
        break;

      case 7:
        ui->FLIRSts->setText("Waiting");
        set_FLIR_indicators_color('G');
        break;

      case 8:
        ui->FLIRSts->setText("Initializing");
        set_FLIR_indicators_color('G');
        break;

      case 10:
        ui->FLIRSts->setText("Aborted");
        set_FLIR_indicators_color('G');
        break;
    }
}

void MainWindow::set_PCO_indicators_color(char PCO_Color)
{
    PCO_color = PCO_Color;

    switch (PCO_color) {

    case 'R':
        ui->PCOStateInd->setColour0Property(QColor(255,0,0));
        break;

    case 'G':
        ui->PCOStateInd->setColour0Property(QColor(0,255,0));
        break;

    default:
        ui->PCOStateInd->setColour0Property(QColor(0,0,0));
    }
}

void MainWindow::set_FLIR_indicators_color(char FLIR_Color)
{
    FLIR_color = FLIR_Color;

    switch (FLIR_color) {

    case 'R':
        ui->FLIRStateInd->setColour0Property(QColor(255,0,0));
        break;

    case 'G':
        ui->FLIRStateInd->setColour0Property(QColor(0,255,0));
        break;
    default:
        ui->FLIRStateInd->setColour0Property(QColor(0,0,0));
    }
}

void MainWindow::on_help_clicked()
{
    QDesktopServices::openUrl(QUrl("https://beats.readthedocs.io/daq_dashboard.html"));

}

void MainWindow::checkScanSts()
{
//    int x = 0;
    if (writerSupportIOC_SEVR_ != NULL and motorIOC_SEVR_ != NULL and tomoScanSupportIOC_SEVR_ != NULL and (PCOIOC_SEVR_ != NULL or FLIRIOC_SEVR_ != NULL))
    {
        if (PCO_TomoScanIOC_Step_SEVR_ != NULL && PCO_PythonServer_Step_SEVR_ != NULL && PCO_PythonServer_Step_ ==1 && PCO_WriterServer_Step_ == 1 )
            Client::writePV("BEATS:ScanMode", 1);
        else if (PCO_TomoScanIOC_Cont_SEVR_ != NULL && PCO_PythonServer_Cont_SEVR_ != NULL && PCO_PythonServer_Cont_ ==1 && PCO_WriterServer_Cont_ == 1)
            Client::writePV("BEATS:ScanMode", 2);
        else if (FLIR_TomoScanIOC_Step_SEVR_ != NULL && FLIR_PythonServer_Step_SEVR_ != NULL && FLIR_PythonServer_Step_ ==1 && FLIR_WriterServer_Step_ == 1)
            Client::writePV("BEATS:ScanMode", 3);
        else if (FLIR_TomoScanIOC_Cont_SEVR_ != NULL && FLIR_PythonServer_Cont_SEVR_ != NULL && FLIR_PythonServer_Cont_ ==1 && FLIR_WriterServer_Cont_ == 1)
            Client::writePV("BEATS:ScanMode", 4);
        else
            Client::writePV("BEATS:ScanMode", 0);
    }
    else if(writerSupportIOC_SEVR_ != NULL)
        Client::writePV("BEATS:ScanMode", 0);

    if (tomoScanSupportIOC_SEVR_ != NULL and ((ui->PCO_StatusHidden->text().toStdString() != "Disconnected" and ui->PCO_StatusHidden->text().toStdString() != "disconnected" and PCOIOC_SEVR_ != NULL) or (FLIRState_ != 9 and FLIRIOC_SEVR_ != NULL)) and (PCO_TomoScanIOC_Step_SEVR_ == NULL and PCO_TomoScanIOC_Cont_SEVR_ == NULL and FLIR_TomoScanIOC_Step_SEVR_ == NULL and FLIR_TomoScanIOC_Cont_SEVR_ == NULL)){
        ui->singleShotImageStart->setEnabled(true);
    }
    else
        ui->singleShotImageStart->setEnabled(false);
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

void MainWindow::on_motroReset_clicked()
{
     ui->generalSts->setText(camera + " Reset MICOS controller to default setttings");
     Client::writePV("I10-EH-MO-MICOS:m1:LIMITTYPE_CMD", 2);
     Client::writePV("I10-EH-MO-MICOS:m1.LLM",-9999);
     Client::writePV("I10-EH-MO-MICOS:m1.HLM", 9999);
     Client::writePV("I10-EH-MO-MICOS:m1.ACCL", 0.1);
     Client::writePV("I10-EH-MO-MICOS:m1.VMAX", 180);
     Client::writePV("I10-EH-MO-MICOS:m1.VELO", 10);
     Client::writePV("I10-EH-MO-MICOS:m1.DIR", 1);
}

void MainWindow::on_singleShotImageStart_clicked()
{
    if(!isSingleShotImageOpened){
        openSingleShot = new singleShot(this);
        openSingleShot->setAttribute(Qt::WA_DeleteOnClose);
        connect(openSingleShot, &QObject::destroyed, this, &MainWindow::on_singleShotImageStart_closed);
        openSingleShot->show();
        isSingleShotImageOpened = true;
    }
}

void MainWindow::on_singleShotImageStart_closed()
{
    isSingleShotImageOpened = false;
}

void MainWindow::on_sscanStart_clicked()
{
    std::string command = "cd && /home/control/DAQ/operation/TomoscanSupportIOCs/sscanIOC/run_sscan1.sh";
    system(command.c_str());
}
