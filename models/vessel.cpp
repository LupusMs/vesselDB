#include <TreeFrogModel>
#include "vessel.h"
#include "sqlobjects/vesselobject.h"

Vessel::Vessel() :
    TAbstractModel(),
    d(new VesselObject())
{
    d->imo = 0;
    d->build_year = 0;
}

Vessel::Vessel(const Vessel &other) :
    TAbstractModel(),
    d(other.d)
{ }

Vessel::Vessel(const VesselObject &object) :
    TAbstractModel(),
    d(new VesselObject(object))
{ }

Vessel::~Vessel()
{
    // If the reference count becomes 0,
    // the shared data object 'VesselObject' is deleted.
}

int Vessel::imo() const
{
    return d->imo;
}

QString Vessel::name() const
{
    return d->name;
}

void Vessel::setName(const QString &name)
{
    d->name = name;
}

int Vessel::buildYear() const
{
    return d->build_year;
}

void Vessel::setBuildYear(int buildYear)
{
    d->build_year = buildYear;
}

QString Vessel::type() const
{
    return d->type;
}

void Vessel::setType(const QString &type)
{
    d->type = type;
}

Vessel &Vessel::operator=(const Vessel &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Vessel Vessel::create(const QString &name, int buildYear, const QString &type)
{
    VesselObject obj;
    obj.name = name;
    obj.build_year = buildYear;
    obj.type = type;
    if (!obj.create()) {
        return Vessel();
    }
    return Vessel(obj);
}

Vessel Vessel::create(const QVariantMap &values)
{
    Vessel model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Vessel Vessel::get(int imo)
{
    TSqlORMapper<VesselObject> mapper;
    return Vessel(mapper.findByPrimaryKey(imo));
}

int Vessel::count()
{
    TSqlORMapper<VesselObject> mapper;
    return mapper.findCount();
}

QList<Vessel> Vessel::getAll()
{
    return tfGetModelListByCriteria<Vessel, VesselObject>(TCriteria());
}

QJsonArray Vessel::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<VesselObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<VesselObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Vessel(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Vessel::modelData()
{
    return d.data();
}

const TModelObject *Vessel::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Vessel &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Vessel &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Vessel)
