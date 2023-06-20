#include "singleshot.h"
#include "ui_singleshot.h"

using namespace std;

singleShot::singleShot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::singleShot)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());      // fix the window size

    ui->statusVAL->setText("");
    ui->imagePathVAL->setEnabled(false);

    ui->readoutGB->setEnabled(false);
    ui->collectGB->setEnabled(false);
    ui->saveGB->setEnabled(false);
}

singleShot::~singleShot()
{
    delete ui;
}

void singleShot::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Space)       // if the space key only pressed
    {
        if(!interlock and trigger1)         // interlock: to avoid multi acquiring (until each acquiring has been done) and triggr: to check if the prefix is correct
        {
            interlock = 1;                  // lock
            ui->statusVAL->setText("");

//            Client::writePV(BEATS_triggerMode, BEATS_triggerMode_val);
//            Client::writePV(BEATS_imageMode, BEATS_imageMode_val);
//            Client::writePV(BEATS_NImages, BEATS_NImages_val);

            if(ui->saveImage->isChecked())
            {
                /* if the save button is checked and the path is correct and non empty do acquiring */

                if(ui->imagePathVAL->text().isEmpty() or trigger2 == 0)
                {
                    QMessageBox::warning(this, "Invalid path", "please enter a valid path ");
                    interlock = 0;
                }
                else
                {   acquire();
                    ui->statusVAL->setText("saving image to " + ui->imagePathVAL->text() + "...");
                    reshaping();
                }
            }
            else
            {
                /* if the save button is not checked, do the noraml acquiring without saving */
                acquire();
                interlock = 0;  // unlock after acquiring
            }
        }
        else
        {
            ui->statusVAL->setText("wait until finishing previous image ...");
            QMessageBox::warning(this, "warning", "wait until finish processing the previous image ...");
        }
    }
}

void singleShot::acquire()
{
    ui->statusVAL->setText("open exposure shutter...");
    Client::writePV(BEATS_exposureShutter, BEATS_exposureShutter_HVal);     // open exposure shutter
    usleep(10000);                                                          // wait 0.01 seconds
    Client::writePV(BEATS_acquire, BEATS_acquire_val);                      // acquire
    ui->statusVAL->setText("acquire image...");
    usleep(this->exposureTime->get().toDouble() * 1000000);                 // wait (exposure time)
    Client::writePV(BEATS_exposureShutter, BEATS_exposureShutter_LVal);     // close the exposure shutter
    usleep(10000);                                                          // wait 0.01 seconds
}

void singleShot::reshaping()
{
    /* strip and reshaping the main array to the required size */

    usleep(600000);     // unnecessary

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

    interlock = 0;
}

void singleShot::saveImage(int sizeX, int sizeY, QVariantList list)
{
    ui->statusVAL->setText("start saving PNG image ...");

    QImage image(sizeX, sizeY, QImage::Format_RGB32);

    if(list.size() == sizeX * sizeY) {
        for (int row = 0; row < sizeY; ++row) {
            for (int col = 0; col < sizeX; ++col) {
                QVariant pixelValue = list[row * sizeX + col];
                int pixel = pixelValue.toInt();

                image.setPixel(col, row, pixel);
//                std::cout<<pixel<<std::endl;
            }
        }
    }
    else {
        // Handle error: Invalid size of the reshapedArray
        // For example, display an error message or take appropriate action.
    }

    QString filename = "/home/dcasu/aaa.png";
    image.save(filename, "PNG");

    ui->statusVAL->setText("image saved to " + filename + "!");
}

void singleShot::on_saveImage_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
        ui->imagePathVAL->setEnabled(true);
    else
        ui->imagePathVAL->setEnabled(false);
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
        ui->saveGB->setEnabled(true);
    }
    else
    {
        trigger1 = 0;

        setBorderLineEdit(true, ui->prefixVAL);
        ui->readoutGB->setEnabled(false);
        ui->collectGB->setEnabled(false);
        ui->saveGB->setEnabled(false);
    }
}

void singleShot::on_imagePathVAL_textEdited(const QString &arg1)
{
    if(regex_match(arg1.toStdString(), regex("^[^-\\s][a-zA-Z0-9\\-]*$")))
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

void singleShot::setPrefix(QString val)
{
    delete this->regionSizeX;
    delete this->regionSizeY;
    delete this->imageSize;
    delete this->exposureTime;
    delete this->acquireBusy;
    delete this->arrayData;
    delete this->imageCounter;

    PV_Prefix = val + "cam1:";
    PV_PrefixArrayData = val;

    BEATS_regionSizeX_RBV  = PV_Prefix + "ArraySizeX_RBV"  ;
    BEATS_regionSizeY_RBV  = PV_Prefix + "ArraySizeY_RBV"  ;
    BEATS_imageSize_RBV    = PV_Prefix + "ArraySize_RBV"   ;
    BEATS_triggerMode      = PV_Prefix + "TriggerMode"     ;
    BEATS_imageMode        = PV_Prefix + "ImageMode"       ;
    BEATS_NImages          = PV_Prefix + "NumImages"       ;
    BEATS_exposureTime_RBV = PV_Prefix + "AcquireTime_RBV" ;
    BEATS_acquireBusy      = PV_Prefix + "AcquireBusy"     ;
    BEATS_acquire          = PV_Prefix + "Acquire"         ;
    BEATS_arrayData        = PV_PrefixArrayData + "image1:ArrayData";
    BEATS_imageCounter     = PV_Prefix + "ArrayCounter_RBV";

    this->regionSizeX  = new QEpicsPV(BEATS_regionSizeX_RBV);
    this->regionSizeY  = new QEpicsPV(BEATS_regionSizeY_RBV);
    this->imageSize    = new QEpicsPV(BEATS_imageSize_RBV);
    this->exposureTime = new QEpicsPV(BEATS_exposureTime_RBV);
    this->acquireBusy  = new QEpicsPV(BEATS_acquireBusy);
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
    ui->imagesRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->exposureAutoVAL->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->exposureTimeVAL->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->exposureTimeRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->imagesCounterRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->imagesCounter0->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);
    ui->acquireBusyRBV->setVariableNameSubstitutionsProperty("P=" + PV_Prefix);

    cout<<"setPrefix"<<endl;
    cout<<BEATS_acquireBusy.toStdString()<<endl;
}
