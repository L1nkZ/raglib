#include "raglib/gat.h"

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

TEST(Gat, CtorEmptyData) {
  std::istringstream is("");
  kaitai::kstream ks(&is);
  EXPECT_THROW(const raglib::gat_t gat(&ks), std::ios_base::failure);
}

TEST(Gat, CtorInvalidData) {
  std::istringstream is("Not a GAT file");
  kaitai::kstream ks(&is);
  EXPECT_THROW(const raglib::gat_t gat(&ks), kaitai::kstruct_error);
}

TEST(Gat, CtorValidGat102Askald) {
  const auto file_path = kTestDataPath / "gat" / "102-askald.gat";
  std::ifstream is(file_path, std::ios::binary);
  kaitai::kstream ks(&is);
  const raglib::gat_t gat(&ks);

  EXPECT_EQ(gat.version(), 0x102);
  EXPECT_EQ(gat.width(), 260);
  EXPECT_EQ(gat.height(), 260);

  const auto& cells = *gat.cells();
  EXPECT_EQ(cells.size(), 260 * 260);
  EXPECT_EQ(cells[0]->type(), 1);
  EXPECT_THAT(*cells[0]->height(),
              ContainerEq(std::vector<float>({0.0F, 0.0F, 0.0F, 0.0F})));
  EXPECT_EQ(cells[cells.size() - 1]->type(), 1);
  EXPECT_THAT(*cells[cells.size() - 1]->height(),
              ContainerEq(std::vector<float>({99.5F, 99.5F, 99.0F, 99.0F})));
}

TEST(Gat, CtorValidGat102Byako) {
  const auto file_path = kTestDataPath / "gat" / "102-byako.gat";
  std::ifstream is(file_path, std::ios::binary);
  kaitai::kstream ks(&is);
  const raglib::gat_t gat(&ks);

  EXPECT_EQ(gat.version(), 0x102);
  EXPECT_EQ(gat.width(), 268);
  EXPECT_EQ(gat.height(), 300);

  const auto& cells = *gat.cells();
  EXPECT_EQ(cells.size(), 268 * 300);
  EXPECT_EQ(cells[0]->type(), 1);
  EXPECT_THAT(*cells[0]->height(),
              ContainerEq(std::vector<float>({0.0F, 0.0F, 0.0F, 0.0F})));
  EXPECT_EQ(cells[cells.size() - 1]->type(), 1);
  EXPECT_THAT(*cells[cells.size() - 1]->height(),
              ContainerEq(std::vector<float>({0.0F, 0.0F, 0.0F, 0.0F})));
}

}  // namespace