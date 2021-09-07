/****************************************************************************
** Meta object code from reading C++ file 'xslider.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QtButton/xslider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xslider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_XSlider_t {
    const uint offsetsAndSize[34];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_XSlider_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_XSlider_t qt_meta_stringdata_XSlider = {
    {
QT_MOC_LITERAL(0, 7), // "XSlider"
QT_MOC_LITERAL(8, 7), // "clicked"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 8), // "initForm"
QT_MOC_LITERAL(26, 9), // "initStyle"
QT_MOC_LITERAL(36, 15), // "setSliderHeight"
QT_MOC_LITERAL(52, 12), // "sliderHeight"
QT_MOC_LITERAL(65, 14), // "setNormalColor"
QT_MOC_LITERAL(80, 11), // "normalColor"
QT_MOC_LITERAL(92, 14), // "setGrooveColor"
QT_MOC_LITERAL(107, 11), // "grooveColor"
QT_MOC_LITERAL(119, 20), // "setHandleBorderColor"
QT_MOC_LITERAL(140, 17), // "handleBorderColor"
QT_MOC_LITERAL(158, 14), // "setHandleColor"
QT_MOC_LITERAL(173, 11), // "handleColor"
QT_MOC_LITERAL(185, 12), // "setTextColor"
QT_MOC_LITERAL(198, 9) // "textColor"

    },
    "XSlider\0clicked\0\0initForm\0initStyle\0"
    "setSliderHeight\0sliderHeight\0"
    "setNormalColor\0normalColor\0setGrooveColor\0"
    "grooveColor\0setHandleBorderColor\0"
    "handleBorderColor\0setHandleColor\0"
    "handleColor\0setTextColor\0textColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XSlider[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       6,   89, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   69,    2, 0x08,    8 /* Private */,
       4,    0,   70,    2, 0x08,    9 /* Private */,
       5,    1,   71,    2, 0x0a,   10 /* Public */,
       7,    1,   74,    2, 0x0a,   12 /* Public */,
       9,    1,   77,    2, 0x0a,   14 /* Public */,
      11,    1,   80,    2, 0x0a,   16 /* Public */,
      13,    1,   83,    2, 0x0a,   18 /* Public */,
      15,    1,   86,    2, 0x0a,   20 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QColor,    8,
    QMetaType::Void, QMetaType::QColor,   10,
    QMetaType::Void, QMetaType::QColor,   12,
    QMetaType::Void, QMetaType::QColor,   14,
    QMetaType::Void, QMetaType::QColor,   16,

 // properties: name, type, flags
       6, QMetaType::Int, 0x00015103, uint(-1), 0,
       8, QMetaType::QColor, 0x00015103, uint(-1), 0,
      10, QMetaType::QColor, 0x00015103, uint(-1), 0,
      12, QMetaType::QColor, 0x00015103, uint(-1), 0,
      14, QMetaType::QColor, 0x00015103, uint(-1), 0,
      16, QMetaType::QColor, 0x00015103, uint(-1), 0,

       0        // eod
};

void XSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<XSlider *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->initForm(); break;
        case 2: _t->initStyle(); break;
        case 3: _t->setSliderHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setNormalColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 5: _t->setGrooveColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 6: _t->setHandleBorderColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 7: _t->setHandleColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 8: _t->setTextColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (XSlider::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XSlider::clicked)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<XSlider *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getSliderHeight(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->getNormalColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->getGrooveColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->getHandleBorderColor(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->getHandleColor(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = _t->getTextColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<XSlider *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSliderHeight(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setNormalColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setGrooveColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setHandleBorderColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->setHandleColor(*reinterpret_cast< QColor*>(_v)); break;
        case 5: _t->setTextColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject XSlider::staticMetaObject = { {
    QMetaObject::SuperData::link<QSlider::staticMetaObject>(),
    qt_meta_stringdata_XSlider.offsetsAndSize,
    qt_meta_data_XSlider,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_XSlider_t
, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<QColor, std::true_type>, QtPrivate::TypeAndForceComplete<QColor, std::true_type>, QtPrivate::TypeAndForceComplete<QColor, std::true_type>, QtPrivate::TypeAndForceComplete<QColor, std::true_type>, QtPrivate::TypeAndForceComplete<QColor, std::true_type>, QtPrivate::TypeAndForceComplete<XSlider, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>


>,
    nullptr
} };


const QMetaObject *XSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XSlider.stringdata0))
        return static_cast<void*>(this);
    return QSlider::qt_metacast(_clname);
}

int XSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void XSlider::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
