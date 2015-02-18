#ifndef GPIOPINSINPUT_H
#define GPIOPINSINPUT_H

#include <QQuickItem>
#include <QTimer>
#include <linux/types.h>

class GPIOPinsInput : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(GPIOPinsInput)
    Q_PROPERTY(int state READ state WRITE setState NOTIFY stateChanged)
public:
    explicit GPIOPinsInput(QQuickItem *parent = 0);
    ~GPIOPinsInput();
    int state() const;
    void setState(const int state);
    Q_INVOKABLE QString getHexState();
    
signals:
    void stateChanged();
public slots:
    void readRegister();
private:
    __s32 m_state;

    
};

QML_DECLARE_TYPE(GPIOPinsInput)
#endif // GPIOPINSINPUT_H
