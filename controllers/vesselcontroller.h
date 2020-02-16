#ifndef VESSELCONTROLLER_H
#define VESSELCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT VesselController : public ApplicationController
{
    Q_OBJECT
public:
    VesselController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &imo);
    void create();
    void save(const QString &imo);
    void remove(const QString &imo);
    void getVessels();
};

#endif // VESSELCONTROLLER_H
