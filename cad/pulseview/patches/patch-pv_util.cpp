$NetBSD$

Qt 5.14 moved the QTextStream manipulators into the Qt namespace while
keeping deprecated global versions, making bare "forcesign" ambiguous
when "using namespace Qt" is in effect.  Qualify the name.

--- pv/util.cpp.orig	2020-04-14 20:19:29.000000000 +0000
+++ pv/util.cpp
@@ -138,7 +138,7 @@ QString format_time_si(const Timestamp&
 	QString s;
 	QTextStream ts(&s);
 	if (sign && !v.is_zero())
-		ts << forcesign;
+		ts << Qt::forcesign;
 	ts << qSetRealNumberPrecision(precision) << (v * multiplier);
 	ts << ' ' << prefix << unit;
 
@@ -175,7 +175,7 @@ QString format_value_si(double v, SIPref
 	QString s;
 	QTextStream ts(&s);
 	if (sign && (v != 0))
-		ts << forcesign;
+		ts << Qt::forcesign;
 	ts.setRealNumberNotation(QTextStream::FixedNotation);
 	ts.setRealNumberPrecision(precision);
 	ts << (v * multiplier) << ' ' << prefix << unit;
