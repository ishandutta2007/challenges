/*

The objective is to write java code that detects the JVM version relying in compatibility changes, side effects, bugs and/or undefined behavior that works in a way in one version and another way in another version.
Further, the code should be at least a bit readable, without sacrificing whitespaces and legible variable names.

To ensure that objective, the exact formal rules are:

    The code must be written in java and should output the JRE version in which it is running.

    The code must not use any JDK or JRE API provided specifically for detecting the java version or which gives the JDK or JRE version for free.

    The code must not use reflection.

    The code is only required to work in Hotspot Java SE 5, 6 and 7, but may work in other JVMs.

    The code must not use any third-party libraries in the classpath.

    The code must not start any other process, java or not.

    The code must not use environment variables.

    The code must not search the file system looking for pre-existing files or folders.

    The code must be contained in a single file and be called via public static void main(String[] args) or public static void main(String... args).

    The code must not use any non-public API present in the JRE.

    The code must not generate any NoClassDefFoundError, NoSuchMethodError, ClassNotFoundException or NoSuchMethodException during its execution.

    The code should run in a system disconnected from the internet or from any local network.

    You should provide an explanation of why it behaves in one way in a version and another way in another version.

Scoring

The method used for measuring the best solution is max(n/s), where n is the number of different java versions detected without violating any of these rules (at least versions 5, 6 and 7) and s is the number of lexical tokens in the solution.

*/

import java.lang.System.*;

class Version {
	public static void main(String[] args) {
		sysinfo();
	}

	public static void sysinfo() {
		final String[] keys = {
			"java.version",
			"java.version.date",
			"java.vendor",
			"java.vendor.version",
			"java.vendor.url",
			"java.vendor.url.bug",
			"java.specification.name",
			"java.specification.vendor",
			"java.specification.version",
			"java.vm.name",
			"java.vm.vendor",
			"java.vm.version",
			"java.vm.info",
			"java.vm.specification.name",
			"java.vm.specification.vendor",
			"java.vm.specification.version",
			"java.runtime.name",
			"java.runtime.version",
			"java.class.version",
			"jdk.debug",
			"sun.java.launcher",
			"sun.management.compiler",
		};

		for (String key : keys) {
			String val = System.getProperty(key);
			System.out.printf("%-32s %-32s\n", key, val);
		}
	}
}
