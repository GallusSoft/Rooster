/*

This file is part of Rooster from Gallus

Copyright (C) 2014 Adam Oren and Gallus <gallussoft@gmail.com>

Redistribution and use of this program's code, including all
included support files, such as headers, or any derivative works are
permitted provided that the following conditions are met:

* Redistributions may not be sold, nor may they be used in a
  commercial product.

* Redistributions that are modified from the original source must
  include the complete source code, including the source code for all
  components used by a binary built from the modified sources.
  However, as a special exception, the source code distributed need
  not include anything that is normally distributed (in either source
  or binary form) with the major components (compiler, kernel, and so
  on) of the operating system on which the executable runs, unless
  that component itself accompanies the executable.

* Neither the name of the copright holder, the copyright holder's
  organizatiom, nor the names of its contributors may be used to
  endorse or promote products derived from this software without
  specific prior written permission.

* Redistributions must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the
  distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/

#include "rooster.h"
#include "ui_rooster.h"
#include <QtMultimedia/QSoundEffect>
#include <QSettings>
#include <QDir>
#include <QFileDialog>
#include <iostream>
#include <QDateTime>
#include <QTimer>

using namespace std;

void rooster::readsettings()
{

    QSettings settings(QSettings::IniFormat, QSettings::UserScope,"Gallus", "rooster");
    ui->arrivaltime->setTime(settings.value("arrivetime").toTime());
    ui->origin->setText(settings.value("origin").toString());
    ui->dest->setText(settings.value("dest").toString());
    ui->pretime->setValue(settings.value("pretime", 60).toInt());
    ui->beginchecking->setValue(settings.value("beginchecking", 60).toInt());
    *soundfile = settings.value("soundfile", QDir("Alarm_Bellusion.wav").path()).toString();
    move(settings.value("windowpos").toPoint());
}

void rooster::writesettings()
{

    QSettings settings(QSettings::IniFormat, QSettings::UserScope,"Gallus", "rooster");
    settings.setValue("arrivetime",ui->arrivaltime->time());
    settings.setValue("origin",ui->origin->text());
    settings.setValue("dest",ui->dest->text());
    settings.setValue("pretime",ui->pretime->value());
    settings.setValue("beginchecking",ui->beginchecking->value());
    settings.setValue("soundfile",*soundfile);
    settings.setValue("windowpos",pos());
}


rooster::rooster(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rooster)
{
    ui->setupUi(this);
    soundfile = new QString();
    arrivaltime = new QDateTime;
    alarmsettime = new QDateTime;
    beginSecs = new int;
    listenTimer = new QTimer;
    beginTimer = new QTimer;
    fadeTimer = new QTimer;
    ttmintot = new int;
    alarmset = new bool(false);
    maxvolume = new qreal(1.0);
    msgBox = new QMessageBox;
    msgBox->setText("Alarm Audio File is missing.");
    msgBox->setInformativeText("Please click Ok to locate the file.");
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setDefaultButton(QMessageBox::Ok);
    readsettings();
    alarm = new QSoundEffect;
    alarm->setSource(QUrl::fromLocalFile(*soundfile));
    alarm->setLoopCount(QSoundEffect::Infinite);
    alarm->setVolume(1.0);
    connect(msgBox->button(QMessageBox::Ok), SIGNAL(clicked()), this, SLOT(on_actionChoose_Audio_File_triggered()));

}

rooster::~rooster()
{
    writesettings();
    if (alarm->isPlaying())
        killalarm();
    if (listenTimer->isActive())
        listenTimer->~QTimer();
    if (beginTimer->isActive())
        beginTimer->~QTimer();
    if (fadeTimer->isActive())
        fadeTimer->~QTimer();
    delete ui;
}


QString phantomio::getTransitTime( QString com, QStringList args )
{
    QProcess process;
    process.start(com, args);
    process.waitForStarted(-1);
    QString phantomTamed;
    QByteArray bytes;
    process.waitForFinished(-1);
    process.waitForReadyRead(-1);
    bytes = process.readAllStandardOutput();
    process.waitForBytesWritten(-1);
    QStringList qlines = QString(bytes).split("\n");
    process.waitForBytesWritten(-1);
    cout << "1st line is: " << qlines[0].toStdString() << endl;

    if (qlines[0] == "Unable to access network")
    {
        return "connection down";
    }

    else if (qlines[0].contains("null"))
    {
        return "bad page";
    }

    else
    {
        qlines.removeLast();
        for (int i=0; i < qlines.size(); i++ )
        {
            cout << "line "<< i << " is: " << qlines[i].toStdString() << endl;
        }

        if (qlines.size() > 1)
        {
            phantomTamed = qlines.last();
            return phantomTamed;
        }

        else
        {
            phantomTamed = qlines[0];
            return phantomTamed;
        }
    }
}

void rooster::fadein()
{
    if ( alarm->volume() < *maxvolume )
    {
        if ( alarm->volume() >= 0.96 )
            alarm->setVolume(1.0);
        else
        {
            alarm->setVolume(alarm->volume()+0.04);
        }
}
    else
    {

        fadeTimer->stop();
    }
}

void rooster::setalarm()
{
    if (beginTimer->isActive())
        beginTimer->~QTimer();
    ui->alarmButton->setText("Change Alarm");
    ui->statusBar->showMessage(QString("Alarm is set. Including pretime, current transit time is %1 mins.").arg(*ttmintot), 15000);
    *alarmset = true;
    beginTimer->singleShot((*beginSecs*1000), this, SLOT(checktraffic()));
}

void rooster::playalarm()
{
    ui->alarmButton->setText("Stop Alarm");
    cout << "Sound file is: " << soundfile->toStdString() << endl;
    if (ui->actionFade_in_Alarm_Volume->isChecked())
        alarm->setVolume(0.04);
    alarm->play();
    if (ui->actionFade_in_Alarm_Volume->isChecked())
    {
    connect(fadeTimer, SIGNAL(timeout()), this, SLOT(fadein()));
    fadeTimer->start(1000);
    }
}

void rooster::listen()
{
    if (listenTimer->isActive())
        listenTimer->~QTimer();
    ui->alarmButton->setText("Change Alarm");
    *alarmset = true;
    listenTimer->singleShot(60000, this, SLOT(checktraffic()));
}

void rooster::killalarm()
{
    alarm->stop();
    ui->alarmButton->setText("Set Alarm");
}

void rooster::checktraffic()
{

    QString traveltimestring, origin, dest;

    phantomio talker;
    QString prog = "phantomjs";
    QString settings = "--load-images=false";
    QString getpage = QDir::currentPath().append("/getpage.js");
    cout << "getpage is: " << getpage.toStdString() << endl;
    QStringList args;

    int tthours(0);
    int ttmins(0);

    origin = ui->origin->text();
    dest = ui->dest->text();

    for (int i=0 ; i < origin.size() ; i++)
    {
        if ( !(origin[i].isLetterOrNumber()) )
        {
            origin.replace(i, 1, " ");
        }
    }
    origin = origin.simplified();

    for (int i=0 ; i < dest.size() ; i++)
    {
        if ( !(dest[i].isLetterOrNumber()) )
        {
            dest.replace(i, 1, " ");
        }
    }
    dest = dest.simplified();

    args.append(settings);
    args.append(getpage);
    args.append(origin);
    args.append(dest);
    traveltimestring = talker.getTransitTime(prog, args);
    talker.kill();
    if (traveltimestring == "connection down")
        {
            cout<<"Check your Internet connection"<<endl;
            rooster::ui->statusBar->showMessage("Check your Internet connection.");
            playalarm();
        }
    else if (traveltimestring == "bad page")
        {
            cout<<"Check your addresses. Google wasn't able to find your locations.\n";
            rooster::ui->statusBar->showMessage("Bad page. Please check your addresses.");
            ui->arrivaltime->setReadOnly(false);
            ui->origin->setReadOnly(false);
            ui->dest->setReadOnly(false);
            ui->pretime->setReadOnly(false);
            ui->beginchecking->setReadOnly(false);
        }
    else
    {
        traveltimestring = traveltimestring.simplified();
        QStringList traveltimewords = traveltimestring.split(QRegularExpression("\\s+"));
        cout << "traveltime string list size is: " << traveltimewords.size()<<endl;
        for (int i=0; i < traveltimewords.size(); i++ )
        {
            cout << "line "<< i << " is: " << traveltimewords[i].toStdString() << endl;
        }

        if (traveltimewords.size() == 2)
          {
            if ((traveltimewords[1] == "mins")||(traveltimewords[1] == "min")) ttmins=traveltimewords[0].toInt();
            else if ((traveltimewords[1] == "hours")||(traveltimewords[1] == "hour")) tthours=traveltimewords[0].toInt();
          }
        else { tthours=traveltimewords[0].toInt(); ttmins=traveltimewords[2].toInt(); }

        ttmins += ui->pretime->value();
        *ttmintot = (tthours*60)+ttmins;
        cout << "hours: " << tthours << " mins: " << ttmins <<endl;
        QDateTime now = QDateTime::currentDateTime().toLocalTime();
        cout << "Current time: " << now.toString("MMMM d hh:mm:ss ap").toStdString() << endl;
        QDateTime ifwebegannow = now.addSecs( (tthours * 60 * 60) + (ttmins * 60) );
        cout << "If we began now: " << ifwebegannow.toString("MMMM d hh:mm:ss ap").toStdString() << endl;
        QDateTime listentime = arrivaltime->addSecs((ui->beginchecking->value()*60)*-1);
        cout << "Arrival time: " << arrivaltime->toString("MMMM d hh:mm:ss ap").toStdString() << endl;
        cout << "Current time: " << now.toString("MMMM d hh:mm:ss ap").toStdString() << endl;

        rooster::ui->statusBar->clearMessage();
        if ( now < listentime )
        {
            cout << "I'm about to set the alarm" << endl;
            *beginSecs = (int)now.secsTo(listentime);
            cout << "Time to wait in seconds: " << *beginSecs << endl;
            setalarm();
        }

        else if ( now >= listentime )
        {
            cout << "I'm checking if we should play the alarm" << endl;
            if ( ifwebegannow >= *arrivaltime )
            {
                cout << "I'm about to play the alarm" << endl;
                playalarm();
            }
            else
            {
                cout << "I'm about to listen" << endl;
                ui->statusBar->showMessage(QString("Current time in traffic: %1.").arg(traveltimestring), 15000);
                listen();
            }
        }
    }
}

void rooster::on_alarmButton_clicked()
{
    if ( !alarm->isPlaying() )
    {
        if ( !QFile::exists(*soundfile) )
            msgBox->exec();
        else if ( *alarmset )
        {
            if (beginTimer->isActive())
                beginTimer->~QTimer();
            if (listenTimer->isActive())
                listenTimer->~QTimer();
            ui->arrivaltime->setReadOnly(false);
            ui->origin->setReadOnly(false);
            ui->dest->setReadOnly(false);
            ui->pretime->setReadOnly(false);
            ui->beginchecking->setReadOnly(false);
            ui->statusBar->clearMessage();
            ui->alarmButton->setText("Set Alarm");
            *alarmset = false;
        }
        else
        {
            ui->arrivaltime->setReadOnly(true);
            ui->origin->setReadOnly(true);
            ui->dest->setReadOnly(true);
            ui->pretime->setReadOnly(true);
            ui->beginchecking->setReadOnly(true);
            *alarmsettime = QDateTime::currentDateTime().toLocalTime();
            *arrivaltime = QDateTime::currentDateTime().toLocalTime();
            arrivaltime->setTime(ui->arrivaltime->time());
            if ( *alarmsettime > *arrivaltime )
                *arrivaltime = arrivaltime->addDays(1);
            ui->statusBar->showMessage("Checking current transit time ...");
            checktraffic();
        }
    }
    else
    {
        killalarm();
        ui->arrivaltime->setReadOnly(false);
        ui->origin->setReadOnly(false);
        ui->dest->setReadOnly(false);
        ui->pretime->setReadOnly(false);
        ui->beginchecking->setReadOnly(false);
        *alarmset = false;
    }
}

void rooster::on_actionChoose_Audio_File_triggered()
{
    QString getfile = QFileDialog::getOpenFileName(this, tr("Choose Audio File"), "/", tr("Audio Files (*.wav)"));

    if (!getfile.isNull())
    {
        *soundfile = getfile;
        alarm->setSource(QUrl::fromLocalFile(*soundfile));
    }
}

void rooster::on_arrivaltime_timeChanged(const QTime &time)
{
    ui->label_6->setText(QString("before %1, begin checking traffic.").arg(time.toString("h:mm AP")));
}

void rooster::on_pretime_valueChanged(int arg1)
{
    ui->beginchecking->setMinimum(arg1);
}
