#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>

#define BIND_PORT 12345
#define PORT_MESS 12346

class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject* parent = nullptr);
    void InitSocket(void);
    void InitSocketMess(void);
    void ReadDatagram(QNetworkDatagram datagram);
    void ReadMess(QNetworkDatagram datagram);
    void SendDatagram(QByteArray data);
    void SendMess(QByteArray data);

private slots:
    void readPendingDatagrams(void);
    void readPendingMess(void);

private:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket* serviceUdpSocketMess;

signals:
    void sig_sendTimeToGUI(QDateTime data);
    void sig_sendToGUI(QString data);
};

#endif  // UDPWORKER_H
