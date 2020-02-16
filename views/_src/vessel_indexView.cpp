#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT vessel_indexView : public TActionView
{
  Q_OBJECT
public:
  vessel_indexView() : TActionView() { }
  QString toString();
};

QString vessel_indexView::toString()
{
  responsebody.reserve(1270);
  responsebody += QStringLiteral("<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n    <title>Vessel DB</title>\n    ");
  responsebody += QVariant(styleSheetTag(cssPath("app.css"))).toString();
  responsebody += QStringLiteral("\n</head>\n<body>\n\n<div id=\"vessel\">\n<table class=\"table\">\n<caption>\nVessels\n</caption>\n<tr class=\"table-header\">\n  <th>IMO</th>\n  <th>Name</th>\n  <th>Year</th>\n  <th>Type</th>\n</tr>\n<tbody id=\"tableBody\">\n</tbody>\n</table> \n</div>\n<script>\n\n\n</script>\n\n</body>\n\n<script> \nfunction createRows(data)\n{\n    var htmlItems = [];\n    for(item in data) {\n        htmlItems.push(\"<tr class='table-row'><td>\" + data[item].imo + \"</td><td>\" + data[item].name + \"</td><td>\" + data[item].buildYear + \"</td><td>\" + data[item].type + \"</td></tr>\");\n    }\n\n    return htmlItems.join(\"\");\n}   \n\ndocument.addEventListener(\"DOMContentLoaded\", function(){\n    var request = new XMLHttpRequest();\n    request.open('GET', '/Vessel/getVessels');\n    request.onload = function() {\n        var myArr = JSON.parse(this.responseText);\n        var elements = createRows(myArr);\n        document.getElementById('tableBody').innerHTML += elements;\n    }\n    request.send();\n\n});\n\n</script>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(vessel_indexView)

#include "vessel_indexView.moc"
