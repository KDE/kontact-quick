#include "maillistcontroller.h"

#include <QStringList>

#include <akonadi2common/clientapi.h>

#include "maillistmodel.h"

MailListController::MailListController(QObject *parent) : QObject(parent), m_model(new MailListModel)
{
}

MailListModel *MailListController::model() const
{
    return m_model.data();

}

void MailListController::loadAllMail()
{
        Akonadi2::Query query;
        query.syncOnDemand = false;
        query.processAll = false;
        query.liveQuery = true;
        query.requestedProperties << "subject" << "sender" << "senderName" << "date" << "unread" << "important";
        m_model->runQuery(query);
}

void MailListController::loadMailFolder(const QString &folderId)
{
        Akonadi2::Query query;
        query.syncOnDemand = false;
        query.processAll = false;
        query.liveQuery = true;
        query.requestedProperties << "subject" << "sender" << "senderName" << "date" << "unread" << "important" << "folder";
        query.propertyFilter.insert("folder", folderId.toLatin1());
        m_model->runQuery(query);
}

void MailListController::loadUnreadMail()
{
        Akonadi2::Query query;
        query.syncOnDemand = false;
        query.processAll = false;
        query.liveQuery = true;
        query.requestedProperties << "subject" << "sender" << "senderName" << "date" << "unread" << "important";
        query.propertyFilter.insert("unread", true);
        m_model->runQuery(query);
}

void MailListController::loadImportantMail()
{
        Akonadi2::Query query;
        query.syncOnDemand = false;
        query.processAll = false;
        query.liveQuery = true;
        query.requestedProperties << "subject" << "sender" << "senderName" << "date" << "unread" << "important";
        query.propertyFilter.insert("important", true);
        m_model->runQuery(query);
}

QString MailListController::selectedMail() const
{
    return m_selectedMail;
}

void MailListController::setSelectedMail(const QString& id)
{
    if (m_selectedMail != id) {
       m_selectedMail = id;
       emit selectedMailChanged();
    }
}

void MailListController::markMailImportant(bool important)
{
    qDebug() << "user action: mark mail important ";
}

void MailListController::markMailUnread(bool unread)
{
    qDebug() << "user action: mark mail unread ";
}

void MailListController::deleteMail()
{
    qDebug() << "user action: delete mail";
}

