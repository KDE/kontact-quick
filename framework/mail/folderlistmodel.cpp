#include "folderlistmodel.h"
#include <akonadi2common/clientapi.h>
#include <akonadi2common/applicationdomaintype.h>

FolderListModel::FolderListModel(QObject *parent) : QIdentityProxyModel()
{
    Akonadi2::Query query;
    query.syncOnDemand = false;
    query.processAll = false;
    query.liveQuery = true;
    query.requestedProperties << "name" << "icon";
    mModel = Akonadi2::Store::loadModel<Akonadi2::ApplicationDomain::Folder>(query);
    setSourceModel(mModel.data());
}

FolderListModel::~FolderListModel()
{

}

QHash< int, QByteArray > FolderListModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[Name] = "name";
    roles[Icon] = "icon";
    roles[Id] = "id";

    return roles;
}

QVariant FolderListModel::data(const QModelIndex &idx, int role) const
{
    auto srcIdx = mapToSource(idx);
    switch (role) {
        case Name:
            return srcIdx.sibling(srcIdx.row(), 0).data(Qt::DisplayRole).toString();
        case Icon:
            return srcIdx.sibling(srcIdx.row(), 1).data(Qt::DisplayRole).toString();
        case Id:
            return srcIdx.data(Akonadi2::Store::DomainObjectBaseRole).value<Akonadi2::ApplicationDomain::ApplicationDomainType::Ptr>()->identifier();
    }
    return QIdentityProxyModel::data(idx, role);
}
