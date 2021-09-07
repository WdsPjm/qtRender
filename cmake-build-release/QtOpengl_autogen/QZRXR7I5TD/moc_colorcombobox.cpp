/****************************************************************************
** Meta object code from reading C++ file 'colorcombobox.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QtButton/colorcombobox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colorcombobox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ColorComboBox_t {
    const uint offsetsAndSize[22];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ColorComboBox_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ColorComboBox_t qt_meta_stringdata_ColorComboBox = {
    {
QT_MOC_LITERAL(0, 13), // "ColorComboBox"
QT_MOC_LITERAL(14, 12), // "colorChanged"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 9), // "colorName"
QT_MOC_LITERAL(38, 5), // "color"
QT_MOC_LITERAL(44, 19), // "currentIndexChanged"
QT_MOC_LITERAL(64, 5), // "index"
QT_MOC_LITERAL(70, 16), // "setShowColorName"
QT_MOC_LITERAL(87, 13), // "showColorName"
QT_MOC_LITERAL(101, 12), // "setColorName"
QT_MOC_LITERAL(114, 9) // "initItems"

    },
    "ColorComboBox\0colorChanged\0\0colorName\0"
    "color\0currentIndexChanged\0index\0"
    "setShowColorName\0showColorName\0"
    "setColorName\0initItems"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorComboBox[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   66, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    2 /* Public */,
       1,    1,   53,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   56,    2, 0x08,    6 /* Private */,
       7,    1,   59,    2, 0x0a,    8 /* Public */,
       9,    1,   62,    2, 0x0a,   10 /* Public */,
      10,    0,   65,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QColor,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::Bool, 0x00015103, uint(-1), 0,

       0        // eod
};

void ColorComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ColorComboBox *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->colorChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->colorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 2: _t->currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setShowColorName((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setColorName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->initItems(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ColorComboBox::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColorComboBox::colorChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ColorComboBox::*)(const QColor & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColorComboBox::colorChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ColorComboBox *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getShowColorName(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ColorComboBox *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setShowColorName(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ColorComboBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QComboBox::staticMetaObject>(),
    qt_meta_stringdata_ColorComboBox.offsetsAndSize,
    qt_meta_data_ColorComboBox,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ColorComboBox_t
, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<ColorComboBox, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ColorComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ColorComboBox.stringdata0))
        return static_cast<void*>(this);
    return QComboBox::qt_metacast(_clname);
}

int ColorComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ColorComboBox::colorChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ColorComboBox::colorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
