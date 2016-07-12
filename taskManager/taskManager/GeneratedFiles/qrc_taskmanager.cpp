/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.6.0
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_taskmanager)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_taskmanager)()
{
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_taskmanager)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_taskmanager)()
{
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_taskmanager)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_taskmanager)(); }
   } dummy;
}
