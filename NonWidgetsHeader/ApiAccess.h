#ifndef APIACCESS_H
#define APIACCESS_H

#include "NonWidgetsHeader/DataInterface.h"
#include "WidgetsHeader/MaterialTracker/MaterialTracker.h"
#include <QCoreApplication>
#include <QEventLoop>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QTime>

class MaterialTracker;

class ApiAccess : public QObject
{

public:
    ApiAccess();
    ~ApiAccess();

    // Query API: Account Materials
    void QueryForMaterialsAPI(MaterialTracker* materialTracker);

    void GetMaterialsApiReply(QNetworkReply* reply, MaterialTracker* materialTracker);
    void GetAccountNamesApiReply(QNetworkReply* reply, MaterialTracker* materialTracker);
    void GetInventoryApiReply(QNetworkReply* reply, MaterialTracker* materialTracker);
    void GetBankApiReply(QNetworkReply* reply, MaterialTracker* materialTracker);

private:
    // --- Data Structures ---
    QVector<QString> vMasterID;
    QVector<QString> vMasterCount;
    // Account names
    QVector<QString> vAccountNames;
    // Account inventory
    QVector<QString> vInvID;
    QVector<QString> vInvCount;
    // Account bank
    QVector<QString> vBankID;
    QVector<QString> vBankCount;

    // --- Network Access ---
    DataInterface* dataInterface;
    QNetworkAccessManager* managerAccountMaterials;

    // --- Functions ---
    void delaySeconds(int secToWait);
    void delayMilliSeconds(int msecToWait);
    void NonModalErrorMessage(QString errorMsg);
};

#endif // APIACCESS_H