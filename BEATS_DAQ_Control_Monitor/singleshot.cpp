#include "singleshot.h"
#include "ui_singleshot.h"

using namespace std;

singleShot::singleShot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::singleShot)
{
    ui->setupUi(this);

//    this->setFixedSize(this->size());      // fix the window size

    ui->statusVAL->setText("");
    ui->imagePathVAL->setEnabled(false);
    ui->tiff->setEnabled(false);
    ui->png->setEnabled(false);

    ui->readoutGB->setEnabled(false);
    ui->collectGB->setEnabled(false);
    ui->singleShotImageMode->setEnabled(false);
    ui->saveGB->setEnabled(false);
    ui->sscanGB->setEnabled(false);

    Client::writePV(interlock, 0);

}

singleShot::~singleShot()
{
    delete ui;
}

void singleShot::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Space)
    {
        acquire();
    }
}

//void singleShot::acquire()
//{
//    ui->statusVAL->setText("open exposure shutter...");
//    Client::writePV(BEATS_exposureShutter, BEATS_exposureShutter_HVal);
//    usleep(10000);
//    Client::writePV(BEATS_acquire, BEATS_acquire_val);
//    ui->statusVAL->setText("acquire image...");
//    usleep(this->exposureTime->get().toDouble() * 1000000);
//    Client::writePV(BEATS_exposureShutter, BEATS_exposureShutter_LVal);
//    usleep(10000);
//}

void singleShot::acquire()
{
//    QDir::setCurrent("/home/control/Desktop/");
    if(!(this->acquire_->get().toInt() == 1) and !(this->acquireBusy->get().toInt() == 1))
        if(this->_interlock->get().toBool() == 0 and trigger1 == 1)
        {
            interlock = 1;
            ui->statusVAL->setText("");

            if(ui->saveImage->isChecked())
            {
                if(ui->imagePathVAL->text().isEmpty() or trigger2 == 0)
                {
                    QMessageBox::warning(this, "Invalid path", "please enter a valid path ");
    //                    interlock = 0;
                }
                else
                {
                    Client::writeStringToWaveform("SingleShot:ImagePath", ui->imagePathVAL->text() + QString::fromStdString(imageExtension));
                    string command = "python3.9 /home/control/DAQ/operation/BEATS_Dashboard/Scripts/singleShotImage.py --saveImage Yes --detectorPVPrefix ";
                    command += ui->prefixVAL->text().toStdString();
                    system(command.c_str());
    //                    acquire();
    //                    reshaping();
                    ui->statusVAL->setText("saving image to " + ui->imagePathVAL->text() + "...");
                }
            }
            else
            {
                string command = "python3.9 /home/control/DAQ/operation/BEATS_Dashboard/Scripts/singleShotImage.py --detectorPVPrefix ";
                command += ui->prefixVAL->text().toStdString();
                system(command.c_str());
    //                acquire();
    //                interlock = 0;
            }
        }
        else
        {
            ui->statusVAL->setText("wait until finishing previous image ...");
            QMessageBox::warning(this, "warning", "wait until finish processing the previous image ...");
        }
    else
        QMessageBox::warning(this, "warning", "there is an external process running, please wait until finish ...");
}

void singleShot::reshaping()
{
    usleep(600000);

    int sizeX = this->regionSizeX->get().toInt();
    int sizeY = this->regionSizeY->get().toInt();
    auto size = this->imageSize->get().toLongLong();
    mainArray = this->arrayData->get().toList();

    ui->statusVAL->setText("reshaping the array to " + this->regionSizeX->get().toString() + " X " + this->regionSizeY->get().toString() + "...");

    if(mainArray.size() <= size)
        acquiredArray = mainArray;
    else
        acquiredArray = mainArray.mid(0, size);

    int index = 0;
    reshapedArray.clear();

    for(int row = 0; row < sizeX; ++row)
    {
        reshapedList.clear(); // Clear the inner list for each row

        for(int col = 0; col < sizeY; ++col)
        {
            reshapedList.append(acquiredArray.at(index));
            ++index;
        }
        reshapedArray.append(reshapedList);
    }
    ui->statusVAL->setText("image reshaped!");

    saveImage(sizeX, sizeY, reshapedArray);

//    for(QVariant& l:reshapedArray)
//        std::cout<<l.toString().toStdString()<<std::endl;
//    std::cout<<"    "<< reshapedArray.size()<<std::endl;
}

void singleShot::saveImage(int sizeX, int sizeY, QVariantList list)
{
    ui->statusVAL->setText("start saving PNG image ...");

    QImage image(sizeX, sizeY, QImage::Format_Grayscale8);

    if(list.size() == sizeX * sizeY) {
        for (int row = 0; row < sizeY; ++row) {
            for (int col = 0; col < sizeX; ++col) {
                QVariant pixelValue = list[row * sizeX + col];
                auto pixel = pixelValue.toUInt();

                QColor color(pixel, pixel, pixel);
                image.setPixelColor(col, row, color);
//                image.setPixel(col, row, pixel);
            }
        }
    }

    else {
        // Handle error: Invalid size of the reshapedArray
        // For example, display an error message or take appropriate action.
    }

    QString filename = ui->imagePathVAL->text();
    image.save(filename);

    ui->statusVAL->setText("image saved to " + filename + "!");
//    interlock = 0;
}

void singleShot::on_singleShotCheckBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        ui->saveGB->setEnabled(true);
        ui->sscanCheckBox->setEnabled(false);
    }

    else{
        ui->saveGB->setEnabled(false);
        ui->sscanCheckBox->setEnabled(true);
    }
}

void singleShot::on_sscanCheckBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        ui->sscanGB->setEnabled(true);
        ui->singleShotCheckBox->setEnabled(false);
        QString path;

        if(PV_Prefix == "TEST-PCO:cam1:")
            path = "A:\\PCO_Data";
        else
            path = "/home/dcasu";

        Client::writeStringToWaveform(BEATS_filePath, path);
        Client::writePV(BEATS_autoIncreament, 1);
        Client::writeStringToWaveform(BEATS_fileFormat, "%s%s_%3.3d.h5");
        Client::writePV(BEATS_autoSave, 1);
        Client::writePV(PV_Prefix + "ArrayCallbacks", 1);
        Client::writePV(image_Prefix + "ArrayCallbacks", 1);
        Client::writePV(image_Prefix + "EnableCallbacks", 1);
        Client::writePV(HDF_Prefix + "ArrayCallbacks", 1);
        Client::writePV(HDF_Prefix + "EnableCallbacks", 1);
        Client::writePV(BEATS_imageMode, 0);
        Client::writePV(BEATS_acquire, 1);
        Client::writePV(BEATS_acquire, 0);
        Client::writePV(BEATS_fileWriteMode, 1);
        Client::writePV(BEATS_numCapture, this->NImages->get().toInt());
    }

    else{
        ui->sscanGB->setEnabled(false);
        ui->singleShotCheckBox->setEnabled(true);
    }
}

void singleShot::on_saveImage_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        ui->imagePathVAL->setEnabled(true);
        ui->tiff->setEnabled(true);
        ui->png->setEnabled(true);
    }

    else{
        ui->imagePathVAL->setEnabled(false);
        ui->tiff->setEnabled(false);
        ui->png->setEnabled(false);
    }
}

void singleShot::on_acquire_clicked()
{
    acquire();
}

void singleShot::on_tiff_clicked()
{
    imageExtension = ".tiff";
}

void singleShot::on_png_clicked()
{
    imageExtension = ".png";
}

void singleShot::setBorderLineEdit(bool val, QLineEdit *lineEdit)
{
    if(val)
        lineEdit->setStyleSheet("border: 2.25px solid red;");
    else
        lineEdit->setStyleSheet("");
}

void singleShot::on_prefixVAL_textEdited(const QString &arg1)
{
    if(arg1 == "TEST-PCO:" or arg1 == "FLIR:")
    {
        trigger1 = 1;
        setBorderLineEdit(false, ui->prefixVAL);

        setPrefix(arg1);

        ui->readoutGB->setEnabled(true);
        ui->collectGB->setEnabled(true);
        ui->singleShotImageMode->setEnabled(true);

        if(arg1 == "TEST-PCO:")
            Client::writePV(BEATS_triggerMode, 0);
        else
        {
            Client::writePV(BEATS_triggerSource, 0);
            Client::writePV(BEATS_triggerMode, 0);
        }
        Client::writePV(BEATS_imageMode, 0);
        Client::writePV(BEATS_acquire, 1);
        Client::writePV(BEATS_acquire, 0);
    }
    else
    {
        trigger1 = 0;

        setBorderLineEdit(true, ui->prefixVAL);

        ui->readoutGB->setEnabled(false);
        ui->collectGB->setEnabled(false);
        ui->singleShotImageMode->setEnabled(false);
        ui->saveGB->setEnabled(false);
        ui->sscanGB->setEnabled(false);
    }
}

void singleShot::on_imagePathVAL_textEdited(const QString &arg1)
{
    QFileInfo file(arg1);
    QDir dir(file.path());

    if((regex_match(arg1.toStdString(), regex("^[a-zA-Z0-9\\-_/]*$"))) and dir.exists())
    {
        trigger2 = 1;
        setBorderLineEdit(false, ui->imagePathVAL);
    }
    else
    {
        trigger2 = 0;
        setBorderLineEdit(true, ui->imagePathVAL);
    }
}

void singleShot::on_imagesVAL_textEdited(const QString &arg1)
{
    Client::writePV(BEATS_numCapture, arg1);
}

void singleShot::on_oneD_clicked()
{
    sscan("run_sscan1.sh");
}

void singleShot::on_twoD_clicked()
{
    sscan("run_sscan2.sh");
}

void singleShot::on_threeD_clicked()
{
    sscan("run_sscan3.sh");
}

void singleShot::on_FourD_clicked()
{
    sscan("run_sscan4.sh");
}

void singleShot::sscan(QString scan)
{
    if(!(this->acquire_->get().toInt() == 1) and !(this->acquireBusy->get().toInt() == 1)){

        if(PV_Prefix == "TEST-PCO:cam1:"){
            Client::writePV(BEATS_imageMode, 0);
            Client::writePV(BEATS_triggerMode, 0);
        }
        else{
            Client::writePV(BEATS_imageMode, 1);
            Client::writePV(BEATS_triggerMode, 1);
            Client::writePV(BEATS_triggerSource, 0);
        }
        Client::writePV(BEATS_acquire, 1);
        Client::writePV(BEATS_startCapture, 1);
        scan_ = scan;
        std::string command = "cd && /home/control/DAQ/operation/TomoscanSupportIOCs/sscanIOC/";
        command += scan_.toStdString();
        system(command.c_str());
    }
    else
        QMessageBox::warning(this, "warning", "there is an external process running, please wait until finish ...");
}

void singleShot::setPrefix(QString val)
{
    delete this->regionSizeX;
    delete this->regionSizeY;
    delete this->NImages;
    delete this->imageSize;
    delete this->exposureTime;
    delete this->acquireBusy;
    delete this->acquire_;
    delete this->arrayData;
    delete this->imageCounter;

    PV_Prefix = val + "cam1:";
    HDF_Prefix = val + "HDF1:";
    image_Prefix = val + "image1:";
    PV_PrefixArrayData = val;

    BEATS_regionSizeX_RBV  = PV_Prefix + "ArraySizeX_RBV"  ;
    BEATS_regionSizeY_RBV  = PV_Prefix + "ArraySizeY_RBV"  ;
    BEATS_NImages          = PV_Prefix + "NumImages"       ;
    BEATS_imageSize_RBV    = PV_Prefix + "ArraySize_RBV"   ;
    BEATS_triggerMode      = PV_Prefix + "TriggerMode"     ;
    BEATS_triggerSource    = PV_Prefix + "TriggerSource"    ;
    BEATS_imageMode        = PV_Prefix + "ImageMode"       ;
    BEATS_NImages          = PV_Prefix + "NumImages"       ;
    BEATS_exposureTime_RBV = PV_Prefix + "AcquireTime_RBV" ;
    BEATS_acquireBusy      = PV_Prefix + "AcquireBusy"     ;
    BEATS_acquire          = PV_Prefix + "Acquire"         ;
    BEATS_arrayData        = PV_PrefixArrayData + "image1:ArrayData";
    BEATS_imageCounter     = PV_Prefix + "ArrayCounter_RBV";
    BEATS_filePath         = HDF_Prefix + "FilePath"        ;
    BEATS_autoIncreament   = HDF_Prefix + "AutoIncrement"  ;
    BEATS_fileFormat       = HDF_Prefix + "FileTemplate";
    BEATS_autoSave         = HDF_Prefix + "AutoSave";
    BEATS_fileWriteMode    = HDF_Prefix + "FileWriteMode";
    BEATS_numCapture       = HDF_Prefix + "NumCapture";
    BEATS_arrayCallbacks   = HDF_Prefix + "ArrayCallbacks"   ;
    BEATS_enableCallbacks  = HDF_Prefix + "EnableCallbacks"  ;
    BEATS_startCapture     = HDF_Prefix + "Capture";

    this->regionSizeX  = new QEpicsPV(BEATS_regionSizeX_RBV);
    this->regionSizeY  = new QEpicsPV(BEATS_regionSizeY_RBV);
    this->NImages      = new QEpicsPV(BEATS_NImages);
    this->imageSize    = new QEpicsPV(BEATS_imageSize_RBV);
    this->exposureTime = new QEpicsPV(BEATS_exposureTime_RBV);
    this->acquireBusy  = new QEpicsPV(BEATS_acquireBusy);
    this->acquire_     = new QEpicsPV(BEATS_acquire);
    this->arrayData    = new QEpicsPV(BEATS_arrayData);
    this->imageCounter = new QEpicsPV(BEATS_imageCounter);

    ui->binningX->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->binningXRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->binningY->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->binningYRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->regionStartX->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->regionStartXRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->regionStartY->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->regionStartYRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->regionSizeX->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->regionSizeXRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->regionSizeY->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->regionSizeYRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->gainAutoVAL->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->gainAutoRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->gainVAL->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->gainRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->colorModeVAL->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->colorModeRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->colorModeRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->triggerModeRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->imageModeRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->imagesVAL->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->imagesRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->exposureAutoVAL->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->exposureTimeVAL->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->exposureTimeRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->imagesCounterRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->imagesCounter0->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->acquireBusyRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->startAcquire->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->stopAcquire->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->delFramesRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->filePathRBV->setVariableNameSubstitutionsProperty("P=" + HDF_Prefix);
    ui->filenameFormatVAL->setVariableNameSubstitutionsProperty("P=" + HDF_Prefix);
    ui->filenameVAL->setVariableNameSubstitutionsProperty("P=" + HDF_Prefix);
    ui->filenameRBV->setVariableNameSubstitutionsProperty("P=" + HDF_Prefix);
    ui->nextFileVAL->setVariableNameSubstitutionsProperty("P=" + HDF_Prefix);
    ui->nextFileRBV->setVariableNameSubstitutionsProperty("P=" + HDF_Prefix);
    ui->filenameFormatVAL->setVariableNameSubstitutionsProperty("P=" + HDF_Prefix);
    ui->filenameFormatRBV->setVariableNameSubstitutionsProperty("P=" + HDF_Prefix);
    ui->autoIncreamentRBV->setVariableNameSubstitutionsProperty("P=" + HDF_Prefix);
    ui->captureRBV->setVariableNameSubstitutionsProperty("P=" + HDF_Prefix);
    ui->IcaptureRBV->setVariableNameSubstitutionsProperty("P=" + HDF_Prefix);
    ui->capturingRBV->setVariableNameSubstitutionsProperty("P=" + HDF_Prefix);
}
