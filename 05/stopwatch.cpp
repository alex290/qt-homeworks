#include "stopwatch.h"

Stopwatch::Stopwatch(QObject* parent) : QObject{ parent }
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Stopwatch::TimeOut);
}

void Stopwatch::StartTimer()
{
    timer->start(100);
}

void Stopwatch::StopTimer()
{
    timer->stop();
}

void Stopwatch::ClearSecond()
{
    sec = 0;
    last_sec = 0;
    round = 0;
}

void Stopwatch::NewRound(long& sec_, size_t& round_)
{
    round++;
    sec_ = sec - last_sec;
    round_ = round;
    last_sec = sec;
}

void Stopwatch::TimeOut()
{
    emit UpdateTime(++sec);
}
