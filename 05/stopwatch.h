#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject* parent = nullptr);

    void StartTimer();
    void StopTimer();
    void ClearSecond();
    void NewRound(long& sec_, size_t& round_);

signals:
    void UpdateTime(const long& sec);

private:
    QTimer* timer;

    long sec{ 0 };
    long last_sec{ 0 };
    size_t round{ 0 };

private slots:
    void TimeOut();
};

#endif  // STOPWATCH_H
