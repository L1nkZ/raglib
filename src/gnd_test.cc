#include "raglib/gnd.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <kaitai/exceptions.h>

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <sstream>

namespace {

const std::filesystem::path kTestDataPath(RAGLIB_TEST_DATA_PATH);

TEST(Gnd, CtorEmptyData) {
  std::istringstream is("");
  kaitai::kstream ks(&is);
  EXPECT_THROW(const raglib::gnd_t gnd(&ks), std::ios_base::failure);
}

TEST(Gnd, CtorInvalidData) {
  std::istringstream is("Not an GND file");
  kaitai::kstream ks(&is);
  EXPECT_THROW(const raglib::gnd_t gnd(&ks), kaitai::kstruct_error);
}

TEST(Gnd, CtorValidRsm107Askald) {
  const auto file_path = kTestDataPath / "gnd" / "107-askald.gnd";
  std::ifstream is(file_path, std::ios::binary);
  kaitai::kstream ks(&is);
  const raglib::gnd_t gnd(&ks);
  EXPECT_EQ(gnd.version(), 0x107);
  EXPECT_EQ(gnd.width(), 130);
  EXPECT_EQ(gnd.height(), 130);
  EXPECT_EQ(gnd.zoom(), 10.0F);
  EXPECT_EQ(gnd.texture_count(), 417);
  EXPECT_EQ(gnd.texture_name_size(), 80);
  EXPECT_EQ(gnd.lightmap_cell_count(), 17722);
  EXPECT_EQ(gnd.lightmap_grid_size_x(), 8);
  EXPECT_EQ(gnd.lightmap_grid_size_y(), 8);
  EXPECT_EQ(gnd.lightmap_cell_size(), 1);
  EXPECT_EQ(gnd.tile_count(), 17723);
  EXPECT_EQ(gnd.surfaces()->size(), 16900);
}

TEST(Gnd, CtorValidRsm107Byako) {
  const auto file_path = kTestDataPath / "gnd" / "107-byako.gnd";
  std::ifstream is(file_path, std::ios::binary);
  kaitai::kstream ks(&is);
  const raglib::gnd_t gnd(&ks);
  EXPECT_EQ(gnd.version(), 0x107);
  EXPECT_EQ(gnd.width(), 134);
  EXPECT_EQ(gnd.height(), 150);
  EXPECT_EQ(gnd.zoom(), 10.0F);
  EXPECT_EQ(gnd.texture_count(), 11);
  EXPECT_EQ(gnd.texture_name_size(), 80);
  EXPECT_EQ(gnd.lightmap_cell_count(), 20366);
  EXPECT_EQ(gnd.lightmap_grid_size_x(), 8);
  EXPECT_EQ(gnd.lightmap_grid_size_y(), 8);
  EXPECT_EQ(gnd.lightmap_cell_size(), 1);
  EXPECT_EQ(gnd.tile_count(), 20399);
  EXPECT_EQ(gnd.surfaces()->size(), 20100);
}

}  // namespace