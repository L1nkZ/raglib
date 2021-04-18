#include "raglib/rsw.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <kaitai/exceptions.h>

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <sstream>

namespace {

using testing::ContainerEq;

const std::filesystem::path kTestDataPath(RAGLIB_TEST_DATA_PATH);

TEST(Rsw, CtorEmptyData) {
  std::istringstream is("");
  kaitai::kstream ks(&is);
  EXPECT_THROW(const raglib::rsw_t rsw(&ks), std::ios_base::failure);
}

TEST(Rsw, CtorInvalidData) {
  std::istringstream is("Not an RSW file");
  kaitai::kstream ks(&is);
  EXPECT_THROW(const raglib::rsw_t rsw(&ks), kaitai::kstruct_error);
}

TEST(Rsw, CtorValidRsw201Askald) {
  const auto file_path = kTestDataPath / "rsw" / "201-askald.rsw";
  std::ifstream is(file_path, std::ios::binary);
  kaitai::kstream ks(&is);
  const raglib::rsw_t rsw(&ks);
  EXPECT_EQ(rsw.version(), 0x201);
  EXPECT_STREQ(rsw.ini_file_name().c_str(), "");
  EXPECT_STREQ(rsw.gnd_file_name().c_str(), "askald.gnd");
  EXPECT_STREQ(rsw.gat_file_name().c_str(), "askald.gat");
  EXPECT_STREQ(rsw.src_file_name().c_str(), "");

  EXPECT_EQ(rsw.water_info()->level(), 20.0F);
  if (rsw.version() >= 0x108) {
    EXPECT_EQ(rsw.water_info()->type(), 2);
    EXPECT_EQ(rsw.water_info()->wave_height(), 1.0F);
    EXPECT_EQ(rsw.water_info()->wave_speed(), 3.0F);
    EXPECT_EQ(rsw.water_info()->wave_pitch(), 100.0F);
  }

  EXPECT_EQ(rsw.light_info()->longitude(), 45);
  EXPECT_EQ(rsw.light_info()->latitude(), 45);
  EXPECT_THAT(*rsw.light_info()->diffuse(),
              ContainerEq(std::vector<float>({1.0F, 1.0F, 1.0F})));
  EXPECT_THAT(*rsw.light_info()->ambient(),
              ContainerEq(std::vector<float>({0.3F, 0.3F, 0.3F})));
  if (rsw.version() >= 0x107) {
    EXPECT_EQ(rsw.light_info()->opacity(), 0.5F);
  }

  EXPECT_EQ(rsw.ground_info()->top(), 2);
  EXPECT_EQ(rsw.ground_info()->bottom(), 0);
  EXPECT_EQ(rsw.ground_info()->left(), 19129152);
  EXPECT_EQ(rsw.ground_info()->right(), 19129232);

  EXPECT_EQ(rsw.object_count(), 998);
  EXPECT_EQ(rsw.objects()->size(), 998);
  EXPECT_EQ(rsw.quad_tree_nodes()->size(), 1365);
}

TEST(Rsw, CtorValidRsw201Byako) {
  const auto file_path = kTestDataPath / "rsw" / "201-byako.rsw";
  std::ifstream is(file_path, std::ios::binary);
  kaitai::kstream ks(&is);
  const raglib::rsw_t rsw(&ks);
  EXPECT_EQ(rsw.version(), 0x201);
  EXPECT_STREQ(rsw.ini_file_name().c_str(), "");
  EXPECT_STREQ(rsw.gnd_file_name().c_str(), "byako.gnd");
  EXPECT_STREQ(rsw.gat_file_name().c_str(), "byako.gat");
  EXPECT_STREQ(rsw.src_file_name().c_str(), "");

  EXPECT_EQ(rsw.water_info()->level(), -20.0F);
  if (rsw.version() >= 0x108) {
    EXPECT_EQ(rsw.water_info()->type(), 0);
    EXPECT_EQ(rsw.water_info()->wave_height(), 1.0F);
    EXPECT_EQ(rsw.water_info()->wave_speed(), 2.0F);
    EXPECT_EQ(rsw.water_info()->wave_pitch(), 50.0F);
  }

  EXPECT_EQ(rsw.light_info()->longitude(), 50);
  EXPECT_EQ(rsw.light_info()->latitude(), 30);
  EXPECT_THAT(*rsw.light_info()->diffuse(),
              ContainerEq(std::vector<float>({1.0F, 1.0F, 1.0F})));
  EXPECT_THAT(*rsw.light_info()->ambient(),
              ContainerEq(std::vector<float>({0.3F, 0.3F, 0.3F})));
  if (rsw.version() >= 0x107) {
    EXPECT_EQ(rsw.light_info()->opacity(), 0.5F);
  }

  EXPECT_EQ(rsw.ground_info()->top(), 4294064);
  EXPECT_EQ(rsw.ground_info()->bottom(), 4294064);
  EXPECT_EQ(rsw.ground_info()->left(), 4294064);
  EXPECT_EQ(rsw.ground_info()->right(), 4294064);

  EXPECT_EQ(rsw.object_count(), 165);
  EXPECT_EQ(rsw.objects()->size(), 165);
  EXPECT_EQ(rsw.quad_tree_nodes()->size(), 1365);
}

}  // namespace