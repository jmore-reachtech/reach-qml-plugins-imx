#ifndef SQLITE_H
#define SQLITE_H

#include <QQuickItem>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlResult>
#include <QtSql/QSqlRecord>
#include <QFile>
#include <QDir>
#include <QCryptographicHash>
#include <QDebug>
#include <QProcess>

#define DATABASE_NAME "settings.sqlite"
#define DATABASE_BACKUP_NAME "settingsbak.sqlite"
#define DATABASE_PATH "/application/databases"
#define VM_DATABASE_PATH "/home/reach/databases"
#define SYNC_CMD "/bin/sync"

class SqLite : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(SqLite)
    
public:
    SqLite(QQuickItem *parent = 0);
    ~SqLite();

    Q_INVOKABLE bool openDB();
    Q_INVOKABLE void closeDB();
    Q_INVOKABLE QString lastError();
    Q_INVOKABLE int execSql(QString sql);
    Q_INVOKABLE int execSql(QString sql, QStringList arguments);
    Q_INVOKABLE QVariantList getRows(QString sql);

private:
    QSqlDatabase* db;
    void backupDB();
    bool restoreDB();
    bool backUpFlag;

};

QML_DECLARE_TYPE(SqLite)

#endif // SQLITE_H

