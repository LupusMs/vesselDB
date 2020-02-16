#include <QtCore>
#include <TreeFrogView>
#include "vessel.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT vessel_showView : public TActionView
{
  Q_OBJECT
public:
  vessel_showView() : TActionView() { }
  QString toString();
};

QString vessel_showView::toString()
{
  responsebody.reserve(1315);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Vessel, vessel);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Vessel</h1>\n<dt>Imo</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vessel.imo());
  responsebody += QStringLiteral("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vessel.name());
  responsebody += QStringLiteral("</dd><br />\n<dt>Build Year</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vessel.buildYear());
  responsebody += QStringLiteral("</dd><br />\n<dt>Type</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vessel.type());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", vessel.imo()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(vessel_showView)

#include "vessel_showView.moc"
