#ifndef SINGLESHOT_H
#define SINGLESHOT_H

#include <QMainWindow>

#include <qepicspv.h>
#include "client.h"

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#include <QLineEdit>
#include <regex>

namespace Ui {
class singleShot;
}

class singleShot : public QMainWindow
{
    Q_OBJECT

public:
    explicit singleShot(QWidget *parent = nullptr);
    ~singleShot();

private slots:

    void on_saveImage_stateChanged(int arg1);

    void on_prefixVAL_textEdited(const QString &arg1);

    void on_imagePathVAL_textEdited(const QString &arg1);

private:

    Ui::singleShot *ui;

    void keyPressEvent(QKeyEvent* event);

    void reshaping();

    void saveImage(int sizeX, int sizeY, QVariantList list);

    void setBorderLineEdit(bool val, QLineEdit *lineEdit);

    void setPrefix(QString val);

    void acquire();

    QString PV_Prefix = "F";
    QString PV_PrefixArrayData = "F";

    QString BEATS_binningX;
    QString BEATS_binningY ;
    QString BEATS_regionStartX;
    QString BEATS_regionStartY;
    QString BEATS_regionSizeX_RBV  = PV_Prefix + "ArraySizeX_RBV"  ;
    QString BEATS_regionSizeY_RBV  = PV_Prefix + "ArraySizeY_RBV"  ;
    QString BEATS_imageSize_RBV    = PV_Prefix + "ArraySize_RBV"   ;
    QString BEATS_triggerMode      = PV_Prefix + "TriggerMode"     ; int BEATS_triggerMode_val  = 0;
    QString BEATS_imageMode        = PV_Prefix + "ImageMode"       ; int BEATS_imageMode_val    = 0;
    QString BEATS_NImages          = PV_Prefix + "NumImages"       ; int BEATS_NImages_val      = 1;
    QString BEATS_exposureTime_RBV = PV_Prefix + "AcquireTime_RBV" ;
    QString BEATS_acquireBusy      = PV_Prefix + "AcquireBusy"     ;
    QString BEATS_acquire          = PV_Prefix + "Acquire"         ; int BEATS_acquire_val      = 1;
    QString BEATS_arrayData        = PV_PrefixArrayData + "image1:ArrayData";
    QString BEATS_imageCounter     = PV_Prefix + "ArrayCounter_RBV";
    QString BEATS_exposureShutter  = "I10EH-SHUTTER:command";
    QString interlock              = "SingleShot:Interlock";

    QEpicsPV* regionSizeX  = new QEpicsPV(BEATS_regionSizeX_RBV);
    QEpicsPV* regionSizeY  = new QEpicsPV(BEATS_regionSizeY_RBV);
    QEpicsPV* imageSize    = new QEpicsPV(BEATS_imageSize_RBV);
    QEpicsPV* exposureTime = new QEpicsPV(BEATS_exposureTime_RBV);
    QEpicsPV* acquireBusy  = new QEpicsPV(BEATS_acquireBusy);
    QEpicsPV* arrayData    = new QEpicsPV(BEATS_arrayData);
    QEpicsPV* imageCounter = new QEpicsPV(BEATS_imageCounter);
    QEpicsPV* exposureShutter = new QEpicsPV(BEATS_exposureShutter); int BEATS_exposureShutter_HVal = 1; int BEATS_exposureShutter_LVal = 0;
    QEpicsPV* _interlock  = new QEpicsPV(interlock);

    bool trigger1 = 0;
    bool trigger2 = 0;

    QVariantList mainArray;
    QVariantList acquiredArray;
    QVariantList reshapedList;
    QVariantList reshapedArray;
};

#endif // SINGLESHOT_H
