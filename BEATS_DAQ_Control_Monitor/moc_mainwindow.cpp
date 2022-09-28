/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[55];
    char stringdata0[1429];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "on_PCO_clicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "on_FLIR_clicked"
QT_MOC_LITERAL(4, 43, 26), // "on_shutterIOCStart_clicked"
QT_MOC_LITERAL(5, 70, 25), // "on_shutterIOCStop_clicked"
QT_MOC_LITERAL(6, 96, 28), // "on_shutterIOCRestart_clicked"
QT_MOC_LITERAL(7, 125, 24), // "on_motorIOCStart_clicked"
QT_MOC_LITERAL(8, 150, 23), // "on_motorIOCStop_clicked"
QT_MOC_LITERAL(9, 174, 34), // "on_tomoScanSupportIOCStart_cl..."
QT_MOC_LITERAL(10, 209, 26), // "on_motorIOCRestart_clicked"
QT_MOC_LITERAL(11, 236, 33), // "on_tomoScanSupportIOCStop_cli..."
QT_MOC_LITERAL(12, 270, 36), // "on_tomoScanSupportIOCRestart_..."
QT_MOC_LITERAL(13, 307, 32), // "on_writerSupportIOCStart_clicked"
QT_MOC_LITERAL(14, 340, 31), // "on_writerSupportIOCStop_clicked"
QT_MOC_LITERAL(15, 372, 34), // "on_writerSupportIOCRestart_cl..."
QT_MOC_LITERAL(16, 407, 31), // "on_stepTomoScanIOCStart_clicked"
QT_MOC_LITERAL(17, 439, 30), // "on_stepTomoScanIOCStop_clicked"
QT_MOC_LITERAL(18, 470, 33), // "on_stepTomoScanIOCRestart_cli..."
QT_MOC_LITERAL(19, 504, 32), // "on_stepPythonServerStart_clicked"
QT_MOC_LITERAL(20, 537, 31), // "on_stepPythonServerStop_clicked"
QT_MOC_LITERAL(21, 569, 34), // "on_stepPythonServerRestart_cl..."
QT_MOC_LITERAL(22, 604, 32), // "on_stepWriterServerStart_clicked"
QT_MOC_LITERAL(23, 637, 31), // "on_stepWriterServerStop_clicked"
QT_MOC_LITERAL(24, 669, 34), // "on_stepWriterServerRestart_cl..."
QT_MOC_LITERAL(25, 704, 24), // "on_stepMEDMStart_clicked"
QT_MOC_LITERAL(26, 729, 31), // "on_contTomoScanIOCStart_clicked"
QT_MOC_LITERAL(27, 761, 32), // "on_contPythonServerStart_clicked"
QT_MOC_LITERAL(28, 794, 30), // "on_contTomoScanIOCStop_clicked"
QT_MOC_LITERAL(29, 825, 24), // "on_contMEDMStart_clicked"
QT_MOC_LITERAL(30, 850, 33), // "on_contTomoScanIOCRestart_cli..."
QT_MOC_LITERAL(31, 884, 34), // "on_contPythonServerRestart_cl..."
QT_MOC_LITERAL(32, 919, 34), // "on_contWriterServerRestart_cl..."
QT_MOC_LITERAL(33, 954, 31), // "on_contWriterServerStop_clicked"
QT_MOC_LITERAL(34, 986, 31), // "on_contPythonServerStop_clicked"
QT_MOC_LITERAL(35, 1018, 32), // "on_contWriterServerStart_clicked"
QT_MOC_LITERAL(36, 1051, 12), // "checkStatusH"
QT_MOC_LITERAL(37, 1064, 12), // "checkStatusL"
QT_MOC_LITERAL(38, 1077, 23), // "on_FLIRIOCStart_clicked"
QT_MOC_LITERAL(39, 1101, 22), // "on_FLIRIOCStop_clicked"
QT_MOC_LITERAL(40, 1124, 25), // "on_FLIRIOCRestart_clicked"
QT_MOC_LITERAL(41, 1150, 22), // "on_PCOIOCStart_clicked"
QT_MOC_LITERAL(42, 1173, 21), // "on_PCOIOCStop_clicked"
QT_MOC_LITERAL(43, 1195, 24), // "on_PCOIOCRestart_clicked"
QT_MOC_LITERAL(44, 1220, 22), // "on_ImageJStart_clicked"
QT_MOC_LITERAL(45, 1243, 15), // "on_help_clicked"
QT_MOC_LITERAL(46, 1259, 26), // "on_FLIRDriverStart_clicked"
QT_MOC_LITERAL(47, 1286, 25), // "on_PCODriverStart_clicked"
QT_MOC_LITERAL(48, 1312, 12), // "startProcess"
QT_MOC_LITERAL(49, 1325, 7), // "Process"
QT_MOC_LITERAL(50, 1333, 6), // "Camera"
QT_MOC_LITERAL(51, 1340, 11), // "stopProcess"
QT_MOC_LITERAL(52, 1352, 14), // "restartProcess"
QT_MOC_LITERAL(53, 1367, 33), // "on_TCPServerSocketRestart_cli..."
QT_MOC_LITERAL(54, 1401, 27) // "on_password_editingFinished"

    },
    "MainWindow\0on_PCO_clicked\0\0on_FLIR_clicked\0"
    "on_shutterIOCStart_clicked\0"
    "on_shutterIOCStop_clicked\0"
    "on_shutterIOCRestart_clicked\0"
    "on_motorIOCStart_clicked\0"
    "on_motorIOCStop_clicked\0"
    "on_tomoScanSupportIOCStart_clicked\0"
    "on_motorIOCRestart_clicked\0"
    "on_tomoScanSupportIOCStop_clicked\0"
    "on_tomoScanSupportIOCRestart_clicked\0"
    "on_writerSupportIOCStart_clicked\0"
    "on_writerSupportIOCStop_clicked\0"
    "on_writerSupportIOCRestart_clicked\0"
    "on_stepTomoScanIOCStart_clicked\0"
    "on_stepTomoScanIOCStop_clicked\0"
    "on_stepTomoScanIOCRestart_clicked\0"
    "on_stepPythonServerStart_clicked\0"
    "on_stepPythonServerStop_clicked\0"
    "on_stepPythonServerRestart_clicked\0"
    "on_stepWriterServerStart_clicked\0"
    "on_stepWriterServerStop_clicked\0"
    "on_stepWriterServerRestart_clicked\0"
    "on_stepMEDMStart_clicked\0"
    "on_contTomoScanIOCStart_clicked\0"
    "on_contPythonServerStart_clicked\0"
    "on_contTomoScanIOCStop_clicked\0"
    "on_contMEDMStart_clicked\0"
    "on_contTomoScanIOCRestart_clicked\0"
    "on_contPythonServerRestart_clicked\0"
    "on_contWriterServerRestart_clicked\0"
    "on_contWriterServerStop_clicked\0"
    "on_contPythonServerStop_clicked\0"
    "on_contWriterServerStart_clicked\0"
    "checkStatusH\0checkStatusL\0"
    "on_FLIRIOCStart_clicked\0on_FLIRIOCStop_clicked\0"
    "on_FLIRIOCRestart_clicked\0"
    "on_PCOIOCStart_clicked\0on_PCOIOCStop_clicked\0"
    "on_PCOIOCRestart_clicked\0"
    "on_ImageJStart_clicked\0on_help_clicked\0"
    "on_FLIRDriverStart_clicked\0"
    "on_PCODriverStart_clicked\0startProcess\0"
    "Process\0Camera\0stopProcess\0restartProcess\0"
    "on_TCPServerSocketRestart_clicked\0"
    "on_password_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      51,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  269,    2, 0x08 /* Private */,
       3,    0,  270,    2, 0x08 /* Private */,
       4,    0,  271,    2, 0x08 /* Private */,
       5,    0,  272,    2, 0x08 /* Private */,
       6,    0,  273,    2, 0x08 /* Private */,
       7,    0,  274,    2, 0x08 /* Private */,
       8,    0,  275,    2, 0x08 /* Private */,
       9,    0,  276,    2, 0x08 /* Private */,
      10,    0,  277,    2, 0x08 /* Private */,
      11,    0,  278,    2, 0x08 /* Private */,
      12,    0,  279,    2, 0x08 /* Private */,
      13,    0,  280,    2, 0x08 /* Private */,
      14,    0,  281,    2, 0x08 /* Private */,
      15,    0,  282,    2, 0x08 /* Private */,
      16,    0,  283,    2, 0x08 /* Private */,
      17,    0,  284,    2, 0x08 /* Private */,
      18,    0,  285,    2, 0x08 /* Private */,
      19,    0,  286,    2, 0x08 /* Private */,
      20,    0,  287,    2, 0x08 /* Private */,
      21,    0,  288,    2, 0x08 /* Private */,
      22,    0,  289,    2, 0x08 /* Private */,
      23,    0,  290,    2, 0x08 /* Private */,
      24,    0,  291,    2, 0x08 /* Private */,
      25,    0,  292,    2, 0x08 /* Private */,
      26,    0,  293,    2, 0x08 /* Private */,
      27,    0,  294,    2, 0x08 /* Private */,
      28,    0,  295,    2, 0x08 /* Private */,
      29,    0,  296,    2, 0x08 /* Private */,
      30,    0,  297,    2, 0x08 /* Private */,
      31,    0,  298,    2, 0x08 /* Private */,
      32,    0,  299,    2, 0x08 /* Private */,
      33,    0,  300,    2, 0x08 /* Private */,
      34,    0,  301,    2, 0x08 /* Private */,
      35,    0,  302,    2, 0x08 /* Private */,
      36,    0,  303,    2, 0x08 /* Private */,
      37,    0,  304,    2, 0x08 /* Private */,
      38,    0,  305,    2, 0x08 /* Private */,
      39,    0,  306,    2, 0x08 /* Private */,
      40,    0,  307,    2, 0x08 /* Private */,
      41,    0,  308,    2, 0x08 /* Private */,
      42,    0,  309,    2, 0x08 /* Private */,
      43,    0,  310,    2, 0x08 /* Private */,
      44,    0,  311,    2, 0x08 /* Private */,
      45,    0,  312,    2, 0x08 /* Private */,
      46,    0,  313,    2, 0x08 /* Private */,
      47,    0,  314,    2, 0x08 /* Private */,
      48,    2,  315,    2, 0x08 /* Private */,
      51,    2,  320,    2, 0x08 /* Private */,
      52,    2,  325,    2, 0x08 /* Private */,
      53,    0,  330,    2, 0x08 /* Private */,
      54,    0,  331,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   49,   50,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   49,   50,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   49,   50,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_PCO_clicked(); break;
        case 1: _t->on_FLIR_clicked(); break;
        case 2: _t->on_shutterIOCStart_clicked(); break;
        case 3: _t->on_shutterIOCStop_clicked(); break;
        case 4: _t->on_shutterIOCRestart_clicked(); break;
        case 5: _t->on_motorIOCStart_clicked(); break;
        case 6: _t->on_motorIOCStop_clicked(); break;
        case 7: _t->on_tomoScanSupportIOCStart_clicked(); break;
        case 8: _t->on_motorIOCRestart_clicked(); break;
        case 9: _t->on_tomoScanSupportIOCStop_clicked(); break;
        case 10: _t->on_tomoScanSupportIOCRestart_clicked(); break;
        case 11: _t->on_writerSupportIOCStart_clicked(); break;
        case 12: _t->on_writerSupportIOCStop_clicked(); break;
        case 13: _t->on_writerSupportIOCRestart_clicked(); break;
        case 14: _t->on_stepTomoScanIOCStart_clicked(); break;
        case 15: _t->on_stepTomoScanIOCStop_clicked(); break;
        case 16: _t->on_stepTomoScanIOCRestart_clicked(); break;
        case 17: _t->on_stepPythonServerStart_clicked(); break;
        case 18: _t->on_stepPythonServerStop_clicked(); break;
        case 19: _t->on_stepPythonServerRestart_clicked(); break;
        case 20: _t->on_stepWriterServerStart_clicked(); break;
        case 21: _t->on_stepWriterServerStop_clicked(); break;
        case 22: _t->on_stepWriterServerRestart_clicked(); break;
        case 23: _t->on_stepMEDMStart_clicked(); break;
        case 24: _t->on_contTomoScanIOCStart_clicked(); break;
        case 25: _t->on_contPythonServerStart_clicked(); break;
        case 26: _t->on_contTomoScanIOCStop_clicked(); break;
        case 27: _t->on_contMEDMStart_clicked(); break;
        case 28: _t->on_contTomoScanIOCRestart_clicked(); break;
        case 29: _t->on_contPythonServerRestart_clicked(); break;
        case 30: _t->on_contWriterServerRestart_clicked(); break;
        case 31: _t->on_contWriterServerStop_clicked(); break;
        case 32: _t->on_contPythonServerStop_clicked(); break;
        case 33: _t->on_contWriterServerStart_clicked(); break;
        case 34: _t->checkStatusH(); break;
        case 35: _t->checkStatusL(); break;
        case 36: _t->on_FLIRIOCStart_clicked(); break;
        case 37: _t->on_FLIRIOCStop_clicked(); break;
        case 38: _t->on_FLIRIOCRestart_clicked(); break;
        case 39: _t->on_PCOIOCStart_clicked(); break;
        case 40: _t->on_PCOIOCStop_clicked(); break;
        case 41: _t->on_PCOIOCRestart_clicked(); break;
        case 42: _t->on_ImageJStart_clicked(); break;
        case 43: _t->on_help_clicked(); break;
        case 44: _t->on_FLIRDriverStart_clicked(); break;
        case 45: _t->on_PCODriverStart_clicked(); break;
        case 46: _t->startProcess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 47: _t->stopProcess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 48: _t->restartProcess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 49: _t->on_TCPServerSocketRestart_clicked(); break;
        case 50: _t->on_password_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 51)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 51;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 51)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 51;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
