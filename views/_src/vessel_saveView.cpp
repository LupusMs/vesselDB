#include <QtCore>
#include <TreeFrogView>
#include "vessel.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT vessel_saveView : public TActionView
{
  Q_OBJECT
public:
  vessel_saveView() : TActionView() { }
  QString toString();
};

QString vessel_saveView::toString()
{
  responsebody.reserve(1836);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, vessel);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Editing Vessel</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", vessel["imo"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>Imo<br /><input type=\"text\" name=\"vessel[imo]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vessel["imo"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Name<br /><input type=\"text\" name=\"vessel[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vessel["name"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Build Year<br /><input type=\"text\" name=\"vessel[buildYear]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vessel["buildYear"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Type<br /><input type=\"text\" name=\"vessel[type]\" value=\"");
  responsebody += THttpUtility::htmlEscape(vessel["type"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", vessel["imo"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(vessel_saveView)

#include "vessel_saveView.moc"
