#include "CppUTest/TestHarness.h"
#include "lib/Logger.h"


TEST_GROUP(FirstTestGroup)
{
	void setup() {
	}

	void teardown() {

	}
};

TEST(FirstTestGroup, infoLogTest)
{
	Logger Logger;
	CHECK(Logger.info("info"));
}

TEST(FirstTestGroup, debugLogTest)
{
	Logger Logger;
	CHECK(Logger.debug("debug"));
}

TEST(FirstTestGroup, errorLogTest)
{
	Logger Logger;
	CHECK(Logger.error("error"));
}

TEST(FirstTestGroup, cleanLogTest)
{
	Logger Logger;
	CHECK(Logger.cleanLog());
}
