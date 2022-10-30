/*

Print the following text and nothing else:

<html>
  <body>

    <p>HTML is kinda annoying</p>

  </body>
</html>
I'm happy I'm not a web developer.

The catch? Your code must fit the template: print(<?>), where ? can be any group of characters. You can paste your completed code (with the print(<>) part) into this Scastie to test it. When posting an answer, please mark it as a spoiler.

Here is the sbt configuration:

scalaVersion := "2.13.6"
addCompilerPlugin("org.typelevel" %% "kind-projector" % "0.13.0" cross CrossVersion.full)

scalacOptions ++= Seq(
  "-language:higherKinds",
  "-Ydelambdafy:inline",
  "-deprecation",
  "-encoding", "UTF-8",
  "-feature",
  "-unchecked",
  "-language:postfixOps"
)
libraryDependencies ++= Seq(
  "org.scala-lang.modules" %% "scala-xml" % "2.0.0",
  "org.scastie" %% "runtime-scala" % "1.0.0-SNAPSHOT"
)

Beware, while the configuration provides one hint, some of these are red herrings.

This is the md5 hash of my solution: 5aa91599e4a8e194b5097b36bdb3dabf. N.B. it looks like the hash didn't work well with newlines and certain other characters - it may have skipped over them entirely.

hyper-neutrino and pxeger found answers, but they use workarounds that I didn't intend to be used and should have thought of while writing the question. I'll award a 500 rep bounty to another answer, provided they meet certain criteria.

*/

#include <stdio.h>

int
main(void)
{
	const char *txt =
	    "<html>\n"
	    "	<body>\n"
	    "		<p>HTML is kinda annoying</p>\n"
	    "	</body>\n"
	    "</html>\n"
	    "I'm happy I'm not a web developer.\n";

	printf("%s", txt);
	return 0;
}
