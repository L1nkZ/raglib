#include "raglib/spr.h"

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

TEST(Spr, CtorEmptyData) {
  std::istringstream is("");
  kaitai::kstream ks(&is);
  EXPECT_THROW(const raglib::spr_t spr(&ks), std::ios_base::failure);
}

TEST(Spr, CtorInvalidData) {
  std::istringstream is("Not an SPR file");
  kaitai::kstream ks(&is);
  EXPECT_THROW(const raglib::spr_t spr(&ks), kaitai::kstruct_error);
}

TEST(Spr, CtorValidSpr200DarkMoon) {
  const auto file_path = kTestDataPath / "spr" / "200-dark-moon.spr";
  std::ifstream is(file_path, std::ios::binary);
  kaitai::kstream ks(&is);
  const raglib::spr_t spr(&ks);
  EXPECT_EQ(spr.version(), 0x200);
  EXPECT_EQ(spr.indexed_image_count(), 3);
  EXPECT_EQ(spr.rgba_image_count(), 0);
  EXPECT_EQ(spr.indexed_images()->size(), 3);
  EXPECT_EQ(spr.indexed_rle_images(), nullptr);
  EXPECT_EQ(spr.rgba_images()->size(), 0);

  EXPECT_EQ((*spr.indexed_images())[0]->width(), 85);
  EXPECT_EQ((*spr.indexed_images())[0]->height(), 119);
  EXPECT_EQ((*spr.indexed_images())[2]->width(), 45);
  EXPECT_EQ((*spr.indexed_images())[2]->height(), 47);

  EXPECT_EQ(spr.palette().size(), 1024);
}

TEST(Spr, CtorValidSpr201WeirdBox) {
  const auto file_path = kTestDataPath / "spr" / "201-weird-box.spr";
  std::ifstream is(file_path, std::ios::binary);
  kaitai::kstream ks(&is);
  const raglib::spr_t spr(&ks);
  EXPECT_EQ(spr.version(), 0x201);
  EXPECT_EQ(spr.indexed_image_count(), 0);
  EXPECT_EQ(spr.rgba_image_count(), 3);
  EXPECT_EQ(spr.indexed_images(), nullptr);
  EXPECT_EQ(spr.indexed_rle_images()->size(), 0);
  EXPECT_EQ(spr.rgba_images()->size(), 3);

  EXPECT_EQ((*spr.rgba_images())[0]->width(), 77);
  EXPECT_EQ((*spr.rgba_images())[0]->height(), 75);
  EXPECT_EQ((*spr.rgba_images())[2]->width(), 73);
  EXPECT_EQ((*spr.rgba_images())[2]->height(), 75);

  EXPECT_EQ(spr.palette().size(), 0);
}

}  // namespace