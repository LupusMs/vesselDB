#ifndef VESSEL_H
#define VESSEL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VesselObject;
class QJsonArray;


class T_MODEL_EXPORT Vessel : public TAbstractModel
{
public:
    Vessel();
    Vessel(const Vessel &other);
    Vessel(const VesselObject &object);
    ~Vessel();

    int imo() const;
    QString name() const;
    void setName(const QString &name);
    int buildYear() const;
    void setBuildYear(int buildYear);
    QString type() const;
    void setType(const QString &type);
    Vessel &operator=(const Vessel &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Vessel create(const QString &name, int buildYear, const QString &type);
    static Vessel create(const QVariantMap &values);
    static Vessel get(int imo);
    static int count();
    static QList<Vessel> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<VesselObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Vessel &model);
    friend QDataStream &operator>>(QDataStream &ds, Vessel &model);
};

Q_DECLARE_METATYPE(Vessel)
Q_DECLARE_METATYPE(QList<Vessel>)

#endif // VESSEL_H
