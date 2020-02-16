#include <QtCore>
#include <TreeFrogView>
#include "vessel.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT vessel_createView : public TActionView
{
  Q_OBJECT
public:
  vessel_createView() : TActionView() { }
  QString toString();
};

QString vessel_createView::toString()
{
  responsebody.reserve(1436);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, vessel);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Vessel</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>Name<br /><input name=\"vessel[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vessel["name"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Build Year<br /><input name=\"vessel[buildYear]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vessel["buildYear"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Type<br /><input name=\"vessel[type]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vessel["type"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(vessel_createView)

#include "vessel_createView.moc"
