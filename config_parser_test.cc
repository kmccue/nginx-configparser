#include "gtest/gtest.h"
#include "config_parser.h"

TEST(NginxConfigParserTest, SimpleConfig) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("example_config", &out_config);

  EXPECT_TRUE(success);
}

TEST(NginxConfigParserTest, EmptyFile) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("unit_tests/empty_file.txt", &out_config);

  EXPECT_FALSE(success);
}

TEST(NginxConfigParserTest, EmptyBlock) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("unit_tests/empty_block.txt", &out_config);

  EXPECT_FALSE(success);
}

TEST(NginxConfigParserTest, hipsterIpsum) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("unit_tests/hipster_ipsum.txt", &out_config);

  EXPECT_FALSE(success);
}

TEST(NginxConfigParserTest, noListenPort) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("unit_tests/no_listen_port.txt", &out_config);

  EXPECT_FALSE(success);
}