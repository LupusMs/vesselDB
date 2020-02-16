#include "vesselcontroller.h"
#include "vessel.h"


void VesselController::index()
{
    auto vesselList = Vessel::getAll();
    texport(vesselList);
    render();
}

void VesselController::show(const QString &imo)
{
    auto vessel = Vessel::get(imo.toInt());
    texport(vessel);
    render();
}

void VesselController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto vessel = httpRequest().formItems("vessel");
        auto model = Vessel::create(vessel);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.imo()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(vessel);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void VesselController::save(const QString &imo)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Vessel::get(imo.toInt());
        if (!model.isNull()) {
            auto vessel = model.toVariantMap();
            texport(vessel);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        auto model = Vessel::get(imo.toInt());
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", imo));
            break;
        }

        auto vessel = httpRequest().formItems("vessel");
        model.setProperties(vessel);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.imo()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(vessel);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void VesselController::remove(const QString &imo)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto vessel = Vessel::get(imo.toInt());
    vessel.remove();
    redirect(urla("index"));
}

void VesselController::getVessels() {
    renderJson(Vessel::getAllJson());
}


// Don't remove below this line
T_DEFINE_CONTROLLER(VesselController)
