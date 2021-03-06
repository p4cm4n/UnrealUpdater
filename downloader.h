/**
 *  This work is distributed under the General Public License,
 *	see LICENSE for details
 *
 *  @author Gwenna�l ARBONA
 **/

#ifndef DOWNLOADER_H
#define DOWNLOADER_H

/*----------------------------------------------
    Includes & definitions
----------------------------------------------*/

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimer>
#include <QTime>
#include <QUrl>

#include "common.h"


/*----------------------------------------------
	Class definitions
----------------------------------------------*/

class Downloader : public QObject
{
	Q_OBJECT

public:
	Downloader();
    ~Downloader();

public slots:
    void Connect(void);
    void Reconnect(void);
    void Login(QString pwd);
    void DownloadFile(QString dir, QString file);
    void FilePart(void);
    void UpdateDownloadInfo(void);
    void UpdateSpeedInfo(void);
    void FileError(QNetworkReply::NetworkError code);
    void FileFinished(QNetworkReply* mreply);

signals:
    void AskForPassword(void);
    void Stage1(void);
    void Stage2(void);
    void BytesDownloaded(int, float);
    void FileDownloaded(void);
    void Log(QString message, bool bIsHeavy);

private:
    float   currentSpeed;
    bool    bDownloading;
    int     downloadedSize;
    int     lastDownloadedSize;
    int     chronoSize;
    QString passWd;
    QUrl*   baseUrl;
	QFile*  currentFile;
    QTime*  chrono;
    QTimer* timeoutTimer;
    QTimer* speedUpdateTimer;
    QTimer* downloadUpdateTimer;
	QString currentFtpDir;
	QString currentFtpFile;
    QNetworkReply* reply;
    QNetworkAccessManager* ftp;

};

#endif // DOWNLOADER_H
