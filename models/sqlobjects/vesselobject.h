#ifndef VESSELOBJECT_H
#define VESSELOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT VesselObject : public TSqlObject, public QSharedData
{
public:
    int imo {0};
    QString name;
    int build_year {0};
    QString type;

    enum PropertyIndex {
        Imo = 0,
        Name,
        BuildYear,
        Type,
    };

    int primaryKeyIndex() const override { return Imo; }
    int autoValueIndex() const override { return Imo; }
    QString tableName() const override { return QStringLiteral("vessel"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int imo READ getimo WRITE setimo)
    T_DEFINE_PROPERTY(int, imo)
    Q_PROPERTY(QString name READ getname WRITE setname)
    T_DEFINE_PROPERTY(QString, name)
    Q_PROPERTY(int build_year READ getbuild_year WRITE setbuild_year)
    T_DEFINE_PROPERTY(int, build_year)
    Q_PROPERTY(QString type READ gettype WRITE settype)
    T_DEFINE_PROPERTY(QString, type)
};

#endif // VESSELOBJECT_H
